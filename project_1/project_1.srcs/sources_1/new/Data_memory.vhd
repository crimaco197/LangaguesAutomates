----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/17/2024 08:22:45 AM
-- Design Name: 
-- Module Name: Data_memory - Behavioral
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

entity Data_memory is
 Port ( ad: in std_logic_vector (7 downto 0);
        I : in std_logic_vector (7 downto 0);
        RW :in std_logic ;
        RST :in std_logic ;
        CLK :in std_logic ;
        S : out std_logic_vector (7 downto 0));
end Data_memory;

architecture Behavioral of Data_memory is
type myTab is array(0 to 255) of std_logic_vector(7 downto 0);
signal register_memory : myTab := (
  0 => "00000001",
  1 => "00000010",
  2 => "00000011",
  3 => "00000100",
  4 => "00000101",
  5 => "00000110",
  6 => "00000111",
  7 => "00001000",
  8 => "00001001",
  10 => "00001010",
  -- Ajoutez d'autres valeurs ici selon vos besoins
  others => (others => '0')
);
signal Aux : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');

begin
--O <= Aux;

process 
begin
    wait until CLK'event and CLK='1';
   
        if RW = '0' then 
        -- écriture
            register_memory(to_integer(unsigned(ad))) <= I;
            
        end if;
         if RST ='0' then
         reset :for i IN 255 downto 0 LOOP
                   register_memory(i) <= (others => '0');
                   end loop reset;
    end if;
        
   
    
end process;
S <= register_memory(to_integer(unsigned(ad)));

end Behavioral;
