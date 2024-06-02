----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/24/2024 04:37:44 PM
-- Design Name: 
-- Module Name: Data_path - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: Implementation of a data path with multiple pipeline stages and hazard detection.
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Data_path is
  Port ( CLK : in STD_LOGIC;
         RST : in STD_LOGIC);
end Data_path;

architecture Behavioral of Data_path is

    -- Component declarations
    component pipeline 
       Port (
        in_A : in STD_LOGIC_VECTOR (7 downto 0);
        in_OP : in STD_LOGIC_VECTOR (7 downto 0);
        in_B : in STD_LOGIC_VECTOR (7 downto 0);
        in_C : in STD_LOGIC_VECTOR (7 downto 0);
        out_A : out STD_LOGIC_VECTOR (7 downto 0);
        out_B : out STD_LOGIC_VECTOR (7 downto 0);
        out_OP : out STD_LOGIC_VECTOR (7 downto 0);
        out_C : out STD_LOGIC_VECTOR (7 downto 0);
        CLK : in STD_LOGIC;
        rst : in STD_LOGIC;
        nop : in STD_LOGIC 
       );
    end component;

    component Instructions_memory
        Port ( ad : in std_logic_vector (7 downto 0);
               CLK : in std_logic;
               S : out std_logic_vector (31 downto 0);
               ad_branch  : in STD_LOGIC_VECTOR (7 downto 0);
               lock : in STD_LOGIC;
               branch_taken : in STD_LOGIC 
       );
    end component;

    component banc_registres 
        Port ( Ad_A : in STD_LOGIC_VECTOR (3 downto 0);
               Ad_B : in STD_LOGIC_VECTOR (3 downto 0);
               Ad_W : in STD_LOGIC_VECTOR (3 downto 0);
               W : in STD_LOGIC;
               DATA : in STD_LOGIC_VECTOR (7 downto 0);
               RST : in STD_LOGIC;
               CLK : in STD_LOGIC;
               QA : out STD_LOGIC_VECTOR (7 downto 0);
               QB : out STD_LOGIC_VECTOR (7 downto 0));
    end component;

    component ALU
        Port (
            A : in STD_LOGIC_VECTOR (7 downto 0);
            B : in STD_LOGIC_VECTOR (7 downto 0);
            N : out STD_LOGIC;
            O : out STD_LOGIC;
            Z : out STD_LOGIC;
            C : out STD_LOGIC;
            S : out STD_LOGIC_VECTOR (7 downto 0);
            Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0) 
       );
    end component;

    component Data_memory
        Port ( ad: in std_logic_vector (7 downto 0);
               I : in std_logic_vector (7 downto 0);
               RW : in std_logic;
               RST : in std_logic;
               CLK : in std_logic;
               S : out std_logic_vector (7 downto 0));
    end component;

    -- Signal declarations
    signal IP : STD_LOGIC_VECTOR (7 downto 0) := x"00";           -- Instruction Pointer
    signal OUT_InstMemory : STD_LOGIC_VECTOR (31 downto 0);                -- Current Instruction

    -- Pipeline stage signals
    signal li_di_A, li_di_B_OUT, li_di_OP, li_di_C_OUT : STD_LOGIC_VECTOR (7 downto 0);   -- LI/DI stage
    signal di_ex_A, di_ex_B, di_ex_OP, di_ex_C : STD_LOGIC_VECTOR (7 downto 0);   -- DI/EX stage
    signal di_ex_nop : std_logic := '1';                        -- DI/EX NOP signal
    signal li_di_nop : std_logic := '1';                        -- LI/DI NOP signal

    signal LC_UAL : STD_LOGIC_VECTOR (2 downto 0);              -- ALU control signal
    signal N, O, Z, C : STD_LOGIC;                              -- ALU status flags
    signal S_UAL : STD_LOGIC_VECTOR (7 downto 0);               -- ALU result

    signal ex_mem_A, ex_mem_B, ex_mem_OP, ex_mem_C : STD_LOGIC_VECTOR (7 downto 0);  -- EX/MEM stage
    signal ex_mem_nop : std_logic := '1';                       -- EX/MEM NOP signal

    signal LC_DM : STD_LOGIC;                                   -- Data Memory control signal
    signal OUT_DM, in_MEM, Mux_DM_OUT, Mux_DM_IN : STD_LOGIC_VECTOR (7 downto 0);  -- Data Memory signals

    signal mem_re_A, mem_re_B, mem_re_OP, mem_re_C : STD_LOGIC_VECTOR (7 downto 0);  -- MEM/RE stage
    signal mem_re_nop : std_logic := '1';                       -- MEM/RE NOP signal
    signal QA, QB : STD_LOGIC_VECTOR (7 downto 0);              -- Register File outputs

    signal LC : STD_LOGIC;                                      -- General control signal
    signal di_ex_B_IN, di_ex_OP_IN, ex_mem_B_IN : STD_LOGIC_VECTOR (7 downto 0);  -- Intermediate signals

    -- Hazard detection signals
    signal li_di_Read, di_ex_Write, ex_mem_Write : STD_LOGIC;   -- Hazard detection signals
    signal alea : std_logic := '1';                             -- Hazard detected flag

    -- Branch hazard signals
    signal uncond_branch, cond_branch, branch_taken : std_logic;  -- Branch control signals

begin

    

    -- Jump control logic
    uncond_branch <= '0' when OUT_InstMemory(31 downto 24) = x"0c" else '1';        ---gerer jmp
    branch_taken <= '0' when uncond_branch = '0' or cond_branch = '0' else '1';     ---controle de jump (if, while ou main)
    

    -- Instruction Pointer (IP) update process
    process
    begin
        wait until CLK'event and CLK = '1';
        if (RST = '0') then
            IP <= ("00000000");
        else
            if (alea = '1' and uncond_branch = '1') then
                IP <= IP + 1;
            elsif (uncond_branch = '0') then
                IP <= OUT_InstMemory(23 downto 16);
            end if;
        end if;
    end process;
    
    -- Instruction memory instantiation
    INS_MEM : Instructions_memory
        port map ( ad => IP,
                   CLK => CLK,
                   S => OUT_InstMemory,
                   ad_branch  => OUT_InstMemory(23 downto 16),
                   lock => alea,
                   branch_taken => branch_taken );

    -- Pipeline LI/DI stage instantiation
    LVL_LI_DI : pipeline
        port map ( 
                   in_C => OUT_InstMemory(7 downto 0),  -- in B
                   in_B => OUT_InstMemory(15 downto 8), -- in A
                   in_A => OUT_InstMemory(23 downto 16),
                   in_OP => OUT_InstMemory(31 downto 24),
                   
                   out_A => li_di_A,
                   out_B => li_di_B_OUT,
                   out_OP => li_di_OP,
                   out_C => li_di_C_OUT,
                   CLK => CLK,
                   RST => RST,
                   nop => alea );
    
    
                   
    -- Pipeline DI/EX stage instantiation
    LVL_DI_EX : pipeline
        port map ( in_A => li_di_A,
                   in_B => di_ex_B_IN,  -- in A 
                   in_OP => di_ex_OP_IN,  
                   in_C => QB,          -- in B
                   out_A => di_ex_A,
                   out_B => di_ex_B,
                   out_OP => di_ex_OP,
                   out_C => di_ex_C,
                   CLK => CLK,
                   RST => RST,
                   nop => di_ex_nop );

    -- ALU instantiation
    UAL : ALU
        port map ( A => di_ex_B,
                   B => di_ex_C,
                   N => N,
                   O => O,
                   Z => Z,
                   C => C,
                   S => S_UAL,
                   Ctrl_Alu => LC_UAL );
                   
    -- Pipeline EX/MEM stage instantiation               
    LVL_EX_MEM : pipeline
        port map ( in_A => di_ex_A,
                   in_B => ex_mem_B_IN,
                   in_OP => di_ex_OP,
                   in_C => (others => '0'),
                   out_A => ex_mem_A,
                   out_B => ex_mem_B,
                   out_OP => ex_mem_OP,
                   out_C => ex_mem_C,
                   CLK => CLK,
                   RST => RST,
                   nop => ex_mem_nop );
                   
    -- DM : DATA MEMORY instantiation
    Data_Memory_unit : Data_memory
        port map ( ad => Mux_DM_IN,
                   I => ex_mem_B,
                   RW => LC_DM,
                   RST => RST,
                   CLK => CLK,
                   S => OUT_DM );
                   
    -- Pipeline MEM/RE stage instantiation                
    LVL_MEM_RE : pipeline
        port map ( in_A => ex_mem_A,
                   in_B => Mux_DM_OUT,
                   in_OP => ex_mem_OP,
                   in_C => ex_mem_C,
                   out_A => mem_re_A,
                   out_B => mem_re_B,
                   out_OP => mem_re_OP,
                   out_C => mem_re_C,
                   CLK => CLK,
                   RST => RST,
                   nop => mem_re_nop );


    -- Decoding stage: control signals
    di_ex_B_IN <= QA when li_di_OP = x"01" or li_di_OP = x"02" or 
                       li_di_OP = x"03" or li_di_OP = x"05" or 
                       li_di_OP = x"08" else li_di_B_OUT;

    di_ex_OP_IN <= x"06" when li_di_OP = x"05" else li_di_OP;    
    cond_branch <= '0' when  QA = 0 and di_ex_OP_IN = x"0b" else '1';   ---pour gerer jmf 

    
    -- ALU control signal
    LC_UAL <= di_ex_OP(2 downto 0) when di_ex_OP = x"01" or di_ex_OP = x"02" or 
                                     di_ex_OP = x"03" else "000";

    -- Pipeline EX/MEM stage instantiation
    ex_mem_B_IN <= S_UAL when di_ex_OP = x"01" or di_ex_OP = x"02" or 
                            di_ex_OP = x"03"  else di_ex_B;

    

    -- Data memory instantiation
    Mux_DM_IN <= ex_mem_A when ex_mem_OP = x"08" else ex_mem_B;

-- Register file instantiation
    Banc_registers : banc_registres
        port map ( Ad_A => li_di_B_OUT (3 downto 0),    -- in A
                   Ad_B => li_di_C_OUT (3 downto 0),    -- in B
                   Ad_W => mem_re_A (3 downto 0),
                   W => LC,
                   DATA => mem_re_B,
                   RST => RST,
                   CLK => CLK,
                   QA => QA,
                   QB => QB );
    

    -- Data memory control signal
    LC_DM <= '0' when ex_mem_OP = x"08" else '1'; -- Store operation

    -- Pipeline MEM/RE stage instantiation
    Mux_DM_OUT <= OUT_DM when ex_mem_OP = x"07" else ex_mem_B;


    -- Control signal for register write
    LC <= '1' when mem_re_OP = x"07" or mem_re_OP = x"06" or
                     mem_re_OP = x"03" or mem_re_OP = x"02" or
                     mem_re_OP = x"01" else '0';

    

    -- Detection and management of hazards
    -- Identifies if the current instruction reads from registers
    li_di_Read <= '1' when OUT_InstMemory(31 downto 24) = x"05" or OUT_InstMemory(31 downto 24) = x"02" or
                       OUT_InstMemory(31 downto 24) = x"03" or OUT_InstMemory(31 downto 24) = x"08" or
                       OUT_InstMemory(31 downto 24) = x"01" else '0';

    -- Identifies if the current instruction writes to registers
    di_ex_Write <= '1' when li_di_OP = x"06" or li_di_OP = x"01" or li_di_OP = x"02" or
                         li_di_OP = x"03" or li_di_OP = x"07" else '0';

    -- Identifies if the current instruction writes to registers in EX/MEM stage
    ex_mem_Write <= '1' when di_ex_OP = x"06" or di_ex_OP = x"07" or di_ex_OP = x"01" or
                           di_ex_OP = x"02" or di_ex_OP = x"03" else '0';

    -- Identifies if there is a hazard
    alea <= '0' when ((li_di_Read = '1' and di_ex_Write = '1') and
                      (li_di_A = OUT_InstMemory(15 downto 8) or li_di_A = OUT_InstMemory(7 downto 0))) or
                     ((li_di_Read = '1' and ex_mem_Write = '1') and
                      (di_ex_A = OUT_InstMemory(15 downto 8) or di_ex_A = OUT_InstMemory(7 downto 0))) else '1';

end Behavioral;
