----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/26/2024 09:07:39 PM
-- Design Name: 
-- Module Name: Data_path_test - Behavioral
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

entity Data_path_test is
end Data_path_test;
architecture Behavioral of Data_path_test is

    -- Component declaration for the Unit Under Test (UUT)
    component Data_path
        Port (
            CLK : in STD_LOGIC;
            RST : in STD_LOGIC
        );
    end component;

    -- Signals to connect to the UUT
    signal CLK : std_logic := '0';
    signal RST : std_logic := '1';

    -- Clock period definition
    

begin

    -- Instantiate the Unit Under Test (UUT)
    uut: Data_path
        Port map (CLK, RST );
        
          CLK <= not CLK after 10ns;
           RST <= '0' , '1' after 60ns;
    

end Behavioral;
