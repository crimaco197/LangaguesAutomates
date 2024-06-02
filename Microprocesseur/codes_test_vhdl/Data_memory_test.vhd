
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Data_memory_test is

end Data_memory_test;

architecture Behavioral of Data_memory_test is
COMPONENT Data_memory
Port ( ad : in STD_LOGIC_VECTOR (7 downto 0);
       I : in STD_LOGIC_VECTOR (7 downto 0);
       RW : in STD_LOGIC;
       RST : in STD_LOGIC;
       CLK : in STD_LOGIC;
       S : out STD_LOGIC_VECTOR (7 downto 0));
 end COMPONENT;      
 
       -- Déclaration des signaux de test
    SIGNAL address_test : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL inputData_test : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL readWrite_test : STD_LOGIC := '0';
    SIGNAL reset_test : STD_LOGIC := '0';
    SIGNAL clock_test : STD_LOGIC := '0';
    SIGNAL outputData_test : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');

begin

test_DM : Data_memory PORT MAP (
        ad => address_test,
        I => inputData_test,
        RW => readWrite_test,
        RST => reset_test,
        CLK => clock_test,
        S => outputData_test);

-- Configuration des signaux de test
    address_test <= "00000010";
    inputData_test <= "10101010";
    readWrite_test <= '1' after 100 ns;
    reset_test <= '1' after 30 ns;
    clock_test <= not clock_test after 20 ns;



end Behavioral;