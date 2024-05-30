#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2023.1 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Wed May 29 04:47:01 CEST 2024
# SW Build 3865809 on Sun May  7 15:04:56 MDT 2023
#
# IP Build 3864474 on Sun May  7 20:36:21 MDT 2023
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim Data_path_test_behav -key {Behavioral:sim_1:Functional:Data_path_test} -tclbatch Data_path_test.tcl -view /home/el-jid/Bureau/project_1/Data_path_test_behav.wcfg -log simulate.log"
xsim Data_path_test_behav -key {Behavioral:sim_1:Functional:Data_path_test} -tclbatch Data_path_test.tcl -view /home/el-jid/Bureau/project_1/Data_path_test_behav.wcfg -log simulate.log
