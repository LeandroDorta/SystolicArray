-makelib ies_lib/xilinx_vip -sv \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib ies_lib/xpm -sv \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
-endlib
-makelib ies_lib/xpm \
  "/opt/xilinx/Xilinx_Vivado_vitis_2019.2/Vivado/2019.2/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib ies_lib/axi_infrastructure_v1_1_0 \
  "../../../ipstatic/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../SysArray_ex.srcs/sources_1/ip/slv_m00_axi_vip/sim/slv_m00_axi_vip_pkg.sv" \
-endlib
-makelib ies_lib/axi_vip_v1_1_6 -sv \
  "../../../ipstatic/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../SysArray_ex.srcs/sources_1/ip/slv_m00_axi_vip/sim/slv_m00_axi_vip.sv" \
-endlib
-makelib ies_lib/xil_defaultlib \
  glbl.v
-endlib

