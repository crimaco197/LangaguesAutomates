
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/17/2024 08:48:57 AM
-- Design Name: 
-- Module Name: Instructions_memory - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
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
use IEEE.numeric_std.all;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;


entity Instructions_memory is
    Port (
        ad : in std_logic_vector(7 downto 0);          -- Address input
        CLK : in std_logic;                            -- Clock input
        S : out std_logic_vector(31 downto 0) ;      -- Data output
        ad_branch : in std_logic_vector(7 downto 0);       -- Branch address input
        lock : in std_logic;                           -- Lock signal for controlling read
        branch_taken : in std_logic                    -- Signal indicating if branch is taken
    );
end Instructions_memory;

architecture Behavioral of Instructions_memory is

    -- Define memory as an array of 256 entries, each 32 bits wide
    type memory_array is array(0 to 255) of std_logic_vector(31 downto 0);
    signal Mem_inst : memory_array := (
        x"06040300",  -- NOP ou instruction non définie
        x"00000000", 
        x"00000000", 
        x"06060200",     -- AFC 
        x"02080604",
        x"08030800",
        x"06090500",  -- ADD R2, R3, R4
        x"00000000",
 --       x"00000000",
  ---      x"00000000",
     --   x"02050607",  -- MUL R5, R6, R7
      --  x"0308090A",  -- SOU R8, R9, R10
       -- x"00000000",  -- NOP ou instruction non définie
      others => x"00000000"
    );

    -- Auxiliary signal to hold the data to be output
    signal Aux : std_logic_vector(31 downto 0) := (others => '0');

begin

    -- Output the data from the auxiliary signal
    

    -- Process to handle reading from memory
    process 
    begin
        -- Trigger on the rising edge of the clock
       wait until CLK'event and CLK='1';
       
           if (lock ='1') then 
            if (branch_taken='0') then 
            Aux <= Mem_inst(to_integer(unsigned(ad_branch)));   --ad_branch est la ligne de l'instru à lire au cas d'un brancheemnt (jmp)
            else  
             Aux <= Mem_inst(to_integer(unsigned(ad))); 
            
        end if;
        end if;

    end process; 
-- Output the data from the auxiliary signal
   S <= Aux ;  -- Output high-impedance state if lock is not active
end Behavioral;
