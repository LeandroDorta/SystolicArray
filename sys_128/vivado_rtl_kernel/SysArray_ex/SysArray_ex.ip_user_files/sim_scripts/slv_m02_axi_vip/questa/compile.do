vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xilinx_vip
vlib questa_lib/msim/xpm
vlib questa_lib/msim/axi_infrastructure_v1_1_0
vlib questa_lib/msim/xil_defaultlib
vlib questa_lib/msim/axi_vip_v1_1_6

vmap xilinx_vip questa_lib/msim/xilinx_vip
vmap xpm questa_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 questa_lib/msim/axi_infrastructure_v1_1_0
vmap xil_defaultlib questa_lib/msim/xil_defaultlib
vmap axi_vip_v1_1_6 questa_lib/msim/axi_vip_v1_1_6

vlog -work xilinx_vip -64 -sv -L axi_vip_v1_1_6 -L xilinx_vip "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm -64 -sv -L axi_vip_v1_1_6 -L xilinx_vip "+incdir+../../../ipstatic/hdl" "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -64 -93 \
"/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0 -64 "+incdir+../../../ipstatic/hdl" "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"../../../ipstatic/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_6 -L xilinx_vip "+incdir+../../../ipstatic/hdl" "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"../../../../SysArray_ex.srcs/sources_1/ip/slv_m02_axi_vip/sim/slv_m02_axi_vip_pkg.sv" \

vlog -work axi_vip_v1_1_6 -64 -sv -L axi_vip_v1_1_6 -L xilinx_vip "+incdir+../../../ipstatic/hdl" "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"../../../ipstatic/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -sv -L axi_vip_v1_1_6 -L xilinx_vip "+incdir+../../../ipstatic/hdl" "+incdir+/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/include" \
"../../../../SysArray_ex.srcs/sources_1/ip/slv_m02_axi_vip/sim/slv_m02_axi_vip.sv" \

vlog -work xil_defaultlib \
"glbl.v"

