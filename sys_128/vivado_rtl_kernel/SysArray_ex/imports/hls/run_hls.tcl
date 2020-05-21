# This is a generated file. Use and modify at your own risk.
################################################################################

open_project prj
open_solution sol
set_part  xcu250-figd2104-2L-e
add_files ../SysArray_cmodel.cpp
set_top SysArray
config_sdx -optimization_level none -target xocc
config_rtl -auto_prefix=0
csynth_design
exit

