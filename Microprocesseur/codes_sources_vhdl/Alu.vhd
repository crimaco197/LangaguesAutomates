
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Déclaration de l'entité ALU
entity ALU is
    Port (
        A : in STD_LOGIC_VECTOR (7 downto 0);      -- Entrée A de 8 bits
        B : in STD_LOGIC_VECTOR (7 downto 0);      -- Entrée B de 8 bits
        N : out STD_LOGIC;                         -- Sortie du drapeau Négatif
        O : out STD_LOGIC;                         -- Sortie du drapeau Overflow
        Z : out STD_LOGIC;                         -- Sortie du drapeau Zero
        C : out STD_LOGIC;                         -- Sortie du drapeau Carry
        S : out STD_LOGIC_VECTOR (7 downto 0);     -- Sortie du résultat de 8 bits
        Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0) -- Signal de contrôle pour choisir l'opération
    );
end ALU;

-- Déclaration de l'architecture comportementale de l'ALU
architecture Behavioral of ALU is
    -- Signal auxiliaire pour stocker les résultats intermédiaires
    signal Aux1 : STD_LOGIC_VECTOR (15 downto 0) := (others => '0');
begin
    -- Processus pour effectuer les opérations de l'ALU en fonction du signal de contrôle
    process (A, B, Ctrl_Alu)
    begin
        -- Sélection de l'opération basée sur Ctrl_Alu
        case Ctrl_Alu is
            -- Addition
            when "001" =>
                Aux1 <= STD_LOGIC_VECTOR(UNSIGNED("00000000" & A) + UNSIGNED("00000000" & B));
           
            -- Soustraction
            when "011" =>
                Aux1 <= STD_LOGIC_VECTOR(UNSIGNED("00000000" & A) - UNSIGNED("00000000" & B));
           
            -- Multiplication
            when "010" =>
                Aux1 <= STD_LOGIC_VECTOR(UNSIGNED(A) * UNSIGNED(B));  -- Taille 16 bits pour le produit
           
            -- Par défaut, Aux1 est mis à zéro
            when others =>
                Aux1 <= (others => '0');
        end case;
    end process;

    -- Mise à jour des drapeaux de statut
    Z <= '1' when Aux1(7 downto 0) = "00000000" else '0'; -- Drapeau Zero
    C <= Aux1(8);                                         -- Drapeau Carry
    O <= '1' when Aux1(15 downto 8) /= "00000000" else '0'; -- Drapeau Overflow
    N <= '1' when (Ctrl_Alu = "011" and UNSIGNED(A) > UNSIGNED(B)) else '0'; -- Drapeau Négatif
   
    -- Mise à jour de la sortie S avec les 8 bits de poids faible du résultat
    S <= Aux1(7 downto 0);
end Behavioral;

