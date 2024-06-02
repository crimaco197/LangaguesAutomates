
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

entity ALU_Test is

end ALU_Test;

architecture Behavioral of ALU_Test is
COMPONENT ALU 


     Port (A : in STD_LOGIC_VECTOR (7 downto 0);
          B : in STD_LOGIC_VECTOR (7 downto 0);
          N : out STD_LOGIC;
          O : out STD_LOGIC;
          Z : out STD_LOGIC;
          C : out STD_LOGIC;
          S : out STD_LOGIC_VECTOR (7 downto 0);
          Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0)); 
          
  end COMPONENT;
            -- Déclaration des signaux de test
    SIGNAL A_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL B_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL N_sig : std_logic := '0';
    SIGNAL O_sig : std_logic := '0';
    SIGNAL Z_sig : std_logic := '0';
    SIGNAL C_sig : std_logic := '0';
    SIGNAL S_sig : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
    SIGNAL Ctrl_Alu_sig : STD_LOGIC_VECTOR (2 downto 0) := (others => '0');

begin
    -- Instanciation de l'ALU avec mappage des ports
    ALU_Instance : ALU 
        PORT MAP (
            A => A_sig,
            B => B_sig,
            N => N_sig,
            O => O_sig,
            Z => Z_sig,
            C => C_sig,
            S => S_sig,
            Ctrl_Alu => Ctrl_Alu_sig
        );

    -- Test de l'addition
    A_sig <= "00000100";
    B_sig <= "00000010";
    Ctrl_Alu_sig <= "011";

    

    -- Test de la multiplication (cas 1)
    --A_sig <= "10000000";
    --B_sig <= "10000000";
    --Ctrl_Alu_sig <= "010";

    -- Test de la multiplication (cas 2)
    --A_sig <= "11111111";
    --B_sig <= "11111111";
    --Ctrl_Alu_sig <= "010";st <= "010";
    
    -- Test de la soustraction avec résultat zéro
    --A_sig <= "00010000";
    --B_sig <= "00010000";
    --Ctrl_Alu_sig <= "011";

    -- Test de la soustraction avec résultat négatif
    --A_sig <= "00000100";
    --B_sig <= "00010000";
    --Ctrl_Alu_sig <= "011";


end Behavioral;