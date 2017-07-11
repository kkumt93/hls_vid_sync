############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_vid_sync
add_files hls_vid_sync/vid_sync.cpp
add_files -tb hls_vid_sync/sc_main.cpp
open_solution "solution1"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./hls_vid_sync/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
