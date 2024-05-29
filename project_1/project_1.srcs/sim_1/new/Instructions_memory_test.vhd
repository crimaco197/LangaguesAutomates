----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.05.2023 11:51:57
-- Design Name: 
-- Module Name: test_ins_memory - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;


entity Instructions_memory_test is
end Instructions_memory_test;

architecture Behavioral of Instructions_memory_test is

    -- Component declaration for the Unit Under Test (UUT)
    component Instructions_memory
        Port (
            ad : in std_logic_vector(7 downto 0);
            CLK : in std_logic;
            S : out std_logic_vector(31 downto 0);
            entre : in std_logic_vector(7 downto 0);
            lock : in std_logic;
            branch_taken : in std_logic
        );
    end component;

    -- Signals to connect to the UUT
    signal ad : std_logic_vector(7 downto 0) := (others => '0');
    signal CLK : std_logic := '0';
    signal S : std_logic_vector(31 downto 0);
    signal entre : std_logic_vector(7 downto 0) := (others => '0');
    signal lock : std_logic := '0';
    signal branch_taken : std_logic := '0';

    -- Clock period definition
    constant CLK_PERIOD : time := 20 ns;

begin

    -- Instantiate the Unit Under Test (UUT)
    uut: Instructions_memory
        Port map (
            ad => ad,
            CLK => CLK,
            S => S,
            entre => entre,
            lock => lock,
            branch_taken => branch_taken
        );

    -- Clock process definitions
    CLK_process :process
    begin
        while true loop
            CLK <= '0';
            wait for CLK_PERIOD/2;
            CLK <= '1';
            wait for CLK_PERIOD/2;
        end loop;
    end process;

    -- Stimulus process
    stimulus: process
    begin
        -- Initialize inputs
        wait for 40 ns;
        
        -- Test case 1: Read from address 'ad' (address 16)
        ad <= x"10";
        lock <= '1';
        branch_taken <= '1';
        wait for CLK_PERIOD;
        assert (S = x"12345678") report "Test case 1 failed: Read from ad (address 16)" severity error;

        -- Test case 2: Read from address 'entre' (address 32)
        entre <= x"20";
        branch_taken <= '0';
        wait for CLK_PERIOD;
        assert (S = x"87654321") report "Test case 2 failed: Read from entre (address 32)" severity error;

        -- Test case 3: Check if the memory is correctly reading after lock is disabled
        lock <= '0';
        wait for CLK_PERIOD;

        -- Test case 4: Check default value read (address 0)
        ad <= x"00";
        entre <= x"00";
        lock <= '1';
        branch_taken <= '1';
        wait for CLK_PERIOD;
        assert (S = x"00000000") report "Test case 4 failed: Read from default address 0" severity error;

        -- End simulation
        wait;
    end process;

end Behavioral;