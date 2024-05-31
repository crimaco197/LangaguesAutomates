----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/17/2024 09:22:21 AM
-- Design Name: 
-- Module Name: pipeline - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity pipeline is
    Port (
        in_A : in STD_LOGIC_VECTOR (7 downto 0);
        in_B : in STD_LOGIC_VECTOR (7 downto 0);
        in_OP : in STD_LOGIC_VECTOR (7 downto 0);
        in_C : in STD_LOGIC_VECTOR (7 downto 0);
        out_A : out STD_LOGIC_VECTOR (7 downto 0);
        out_B : out STD_LOGIC_VECTOR (7 downto 0);
        out_OP : out STD_LOGIC_VECTOR (7 downto 0);
        out_C : out STD_LOGIC_VECTOR (7 downto 0);
        CLK : in STD_LOGIC;
        RST : in STD_LOGIC;
        nop : in STD_LOGIC
    );
end pipeline;

architecture Behavioral of pipeline is
    signal aux_A : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal aux_B  : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal aux_OP  : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal aux_C  : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
begin

    -- Assign intermediate signals to outputs
    out_A <= aux_A ;
    out_B <= aux_B ;
    out_OP <= aux_OP ;
    out_C <= aux_C ;

    -- Process block for clocked operations
    process (CLK)
    begin
        if rising_edge(CLK) then
            if RST = '0' or nop = '0'  then
                -- Reset or NOP: clear intermediate signals
                aux_A  <= (others => '0');
                aux_B  <= (others => '0');
                aux_OP  <= (others => '0');
                aux_C  <= (others => '0');
            else 
                -- Normal operation: transfer inputs to intermediate signals
                aux_A  <= in_A;
                aux_B <= in_B;
                aux_OP <= in_OP;
                aux_C <= in_C;
            end if;
        end if;
    end process;

end Behavioral;
