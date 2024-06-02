library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Register_Bank is
    Port ( Address_A : in STD_LOGIC_VECTOR (3 downto 0);
           Address_B : in STD_LOGIC_VECTOR (3 downto 0);
           Address_W : in STD_LOGIC_VECTOR (3 downto 0);
           Input_Data : in STD_LOGIC_VECTOR (7 downto 0);
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           Write_Enable : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end Register_Bank;

architecture Behavior of Register_Bank is
    type Register_Array is array (15 downto 0) of STD_LOGIC_VECTOR (7 downto 0);
    signal Registers : Register_Array := (others => (others => '0'));
--    signal Temp_A : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
--    signal Temp_B : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');

begin
--    QA <= Temp_A;
--    QB <= Temp_B;

    process
    begin
        wait until Clock'event and Clock = '1';
        if Reset = '1' then
            
            if Write_Enable = '1' then
--                if Address_A = Address_W then
--                    Temp_A <= Input_Data;
--                elsif Address_B = Address_W then
--                    Temp_B <= Input_Data;
--                else
                    Registers(to_integer(unsigned(Address_W))) <= Input_Data;
                end if;
--            end if;
        else
            Registers <= (others => (others => '0'));      ----si reset est à 0 , en vide les registres 
        end if;
    end process;
    QA <= Registers(to_integer(unsigned(Address_A)));
    QB <= Registers(to_integer(unsigned(Address_B)));
end Behavior;
