----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 01:19:31 PM
-- Design Name: 
-- Module Name: Test_Alu - Behavioral
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
use IEEE.numeric_std.All;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Test_Alu is
--  Port ( );
end Test_Alu;

architecture Behavioral of Test_Alu is
   --Declarations des signaux pour entrées et sorties de Alu
   signal A        :std_logic_vector(7 downto 0);
   signal B        :std_logic_vector(7 downto 0);
   signal Operation        :std_logic_vector(7 downto 0);
   signal C        :std_logic;
   signal O        :std_logic;
   signal N        :std_logic;
   signal S        :std_logic_vector(7 downto 0);
   
   

begin
   ---Instanciation d'Alu
   uut: entity work.Alu
       port map (
          A => A ,
          B => B ,
          Operation => Operation ,
          C => C ,
          O => O ,
          N => N ,
          S => S 
      );
       
    --Processus de stimulation pour tester les operations de l'Alu
    Stimulus_Process: process
    begin 
       --Test de l'operation ADD
       A <= "00000001" ;
       B <= "00000010" ;
       Operation <= "00000001" ; 
       wait for 100 ns;
    
       --Test de l'operation Mul
       A <= "00000010" ;
       B <= "00000010" ;
       Operation <= "00000111" ; 
       wait for 100 ns;
       
       --Test de l'operation Soustraction
       A <= "00000010" ;
       B <= "00000001" ;
       Operation <= "00000110" ; 
       wait for 100 ns;
    
       wait;
       
    end process Stimulus_Process;
    
    
    
    
    
          


end Behavioral;
