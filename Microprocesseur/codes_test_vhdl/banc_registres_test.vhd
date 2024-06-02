
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
-- Déclaration des signaux de test
    SIGNAL Address_A_sig : STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
    SIGNAL Address_B_sig : STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
    SIGNAL Address_W_sig : STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
    SIGNAL Data_in_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL Reset_sig : STD_LOGIC := '0';
    SIGNAL Clock_sig : STD_LOGIC := '0';
    SIGNAL WriteEnable_sig : STD_LOGIC := '0';
    SIGNAL Data_out_A_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL Data_out_B_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');

begin

-- Instanciation du banc de registres avec mappage des ports
test_BDR : banc_registres PORT MAP (
            Ad_A => Address_A_sig,
            Ad_B => Address_B_sig,
            Ad_W => Address_W_sig,
            Data => Data_in_sig,
            RST => Reset_sig,
            CLK => Clock_sig,
            W => WriteEnable_sig,
            QA => Data_out_A_sig,
            QB => Data_out_B_sig
            );

--tests
-- Configuration des signaux de test
    Address_A_sig <= "1100";
    Address_B_sig <= "1111";
    Address_W_sig <= "1101";
    Data_in_sig <= "10101110";

    Reset_sig <= '1' after 30 ns; -- Actif à 0
    WriteEnable_sig <= '1' after 100 ns;
    Clock_sig <= not Clock_sig after 10 ns;



end Behavioral;