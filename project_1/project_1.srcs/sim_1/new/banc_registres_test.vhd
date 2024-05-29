
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity banc_registres_test is

end banc_registres_test;

architecture Behavioral of banc_registres_test is
COMPONENT banc_registres

 Port ( Ad_A : in STD_LOGIC_VECTOR (3 downto 0);
           Ad_B : in STD_LOGIC_VECTOR (3 downto 0);
           Ad_W : in STD_LOGIC_VECTOR (3 downto 0);
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           W : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB: out STD_LOGIC_VECTOR (7 downto 0));
end COMPONENT;

          SIGNAL Addr_A_test : STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
          SIGNAL Addr_B_test : STD_LOGIC_VECTOR (3 downto 0):= (others => '0');
          SIGNAL Addr_W_test : STD_LOGIC_VECTOR (3 downto 0):= (others => '0');
          SIGNAL Data_test : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
          SIGNAL RST_test : STD_LOGIC:='0';
          SIGNAL CLK_test : STD_LOGIC:='0';
          SIGNAL W_test : STD_LOGIC:='0';
          SIGNAL QA_test : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
          SIGNAL QB_test : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');

begin

test_BDR : banc_registres PORT MAP (
            Ad_A => Addr_A_test,
            Ad_B => Addr_B_test,
            Ad_W => Addr_W_test,
            Data => Data_test,
            RST => RST_test,
            CLK => CLK_test,
            W => W_test,
            QA => QA_test,
            QB => QB_test);

--tests
Addr_A_test <= "1111";
Addr_B_test <= "1100";
Addr_W_test <= "1101";

Data_test <= "10101010";

RST_test <= '1' after 50ns; --actif à 0

W_test <= '1'after 100ns;



CLK_test <= not CLK_test after 10 ns;



end Behavioral;