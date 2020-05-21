// This is a generated file. Use and modify at your own risk.
//////////////////////////////////////////////////////////////////////////////// 
// default_nettype of none prevents implicit wire declaration.
`default_nettype none

module Top_wrapper #(
  parameter integer C_M00_AXI_ADDR_WIDTH = 64 ,
  parameter integer C_M00_AXI_DATA_WIDTH = 128,
  parameter integer C_M01_AXI_ADDR_WIDTH = 64 ,
  parameter integer C_M01_AXI_DATA_WIDTH = 128,
  parameter integer C_M02_AXI_ADDR_WIDTH = 64,
  parameter integer C_M02_AXI_DATA_WIDTH = 128
)
(
  // System Signals
  input  wire                              ap_clk         ,
  input  wire                              ap_rst_n      ,
  // AXI4 master interface m00_axi
  output wire                              m00_axi_awvalid,
  input  wire                              m00_axi_awready,
  output wire [C_M00_AXI_ADDR_WIDTH-1:0]   m00_axi_awaddr ,
  output wire [8-1:0]                      m00_axi_awlen  ,
  output wire                              m00_axi_wvalid ,
  input  wire                              m00_axi_wready ,
  output wire [C_M00_AXI_DATA_WIDTH-1:0]   m00_axi_wdata  ,
  output wire [C_M00_AXI_DATA_WIDTH/8-1:0] m00_axi_wstrb  ,
  output wire                              m00_axi_wlast  ,
  input  wire                              m00_axi_bvalid ,
  output wire                              m00_axi_bready ,
  output wire                              m00_axi_arvalid,
  input  wire                              m00_axi_arready,
  output wire [C_M00_AXI_ADDR_WIDTH-1:0]   m00_axi_araddr ,
  output wire [8-1:0]                      m00_axi_arlen  ,
  input  wire                              m00_axi_rvalid ,
  output wire                              m00_axi_rready ,
  input  wire [C_M00_AXI_DATA_WIDTH-1:0]   m00_axi_rdata  ,
  input  wire                              m00_axi_rlast  ,
  // AXI4 master interface m01_axi
  output wire                              m01_axi_awvalid,
  input  wire                              m01_axi_awready,
  output wire [C_M01_AXI_ADDR_WIDTH-1:0]   m01_axi_awaddr ,
  output wire [8-1:0]                      m01_axi_awlen  ,
  output wire                              m01_axi_wvalid ,
  input  wire                              m01_axi_wready ,
  output wire [C_M01_AXI_DATA_WIDTH-1:0]   m01_axi_wdata  ,
  output wire [C_M01_AXI_DATA_WIDTH/8-1:0] m01_axi_wstrb  ,
  output wire                              m01_axi_wlast  ,
  input  wire                              m01_axi_bvalid ,
  output wire                              m01_axi_bready ,
  output wire                              m01_axi_arvalid,
  input  wire                              m01_axi_arready,
  output wire [C_M01_AXI_ADDR_WIDTH-1:0]   m01_axi_araddr ,
  output wire [8-1:0]                      m01_axi_arlen  ,
  input  wire                              m01_axi_rvalid ,
  output wire                              m01_axi_rready ,
  input  wire [C_M01_AXI_DATA_WIDTH-1:0]   m01_axi_rdata  ,
  input  wire                              m01_axi_rlast  ,
  // AXI4 master interface m02_axi
  output wire                              m02_axi_awvalid,
  input  wire                              m02_axi_awready,
  output wire [C_M02_AXI_ADDR_WIDTH-1:0]   m02_axi_awaddr ,
  output wire [8-1:0]                      m02_axi_awlen  ,
  output wire                              m02_axi_wvalid ,
  input  wire                              m02_axi_wready ,
  output wire [C_M02_AXI_DATA_WIDTH-1:0]   m02_axi_wdata  ,
  output wire [C_M02_AXI_DATA_WIDTH/8-1:0] m02_axi_wstrb  ,
  output wire                              m02_axi_wlast  ,
  input  wire                              m02_axi_bvalid ,
  output wire                              m02_axi_bready ,
  output wire                              m02_axi_arvalid,
  input  wire                              m02_axi_arready,
  output wire [C_M02_AXI_ADDR_WIDTH-1:0]   m02_axi_araddr ,
  output wire [8-1:0]                      m02_axi_arlen  ,
  input  wire                              m02_axi_rvalid ,
  output wire                              m02_axi_rready ,
  input  wire [C_M02_AXI_DATA_WIDTH-1:0]   m02_axi_rdata  ,
  input  wire                              m02_axi_rlast  ,

  // SDx Control Signals
  input  wire                              ap_start       ,
  output wire                              ap_idle        ,
  output wire                              ap_done        ,
  input  wire [32-1:0]                     scalar00       ,
  input  wire [32-1:0]                     scalar01       ,
  output wire                              ap_ready       ,
  input  wire [64-1:0]                     input_matrix   ,
  input  wire [64-1:0]                     weight_matrix  ,
  input  wire [64-1:0]                     output_matrix  ,
  output wire                              all_weights_avail_w,
  output logic                             input_matrix_tvalid,
  output logic                             input_matrix_tready,
  output logic [C_M00_AXI_DATA_WIDTH-1:0]  input_matrix_tdata,
  output logic                             input_matrix_tlast,
  output logic                             weight_matrix_tvalid,
  output logic                             weight_matrix_tready,
  output logic                             weight_matrix_tlast,
  output logic [C_M01_AXI_DATA_WIDTH-1:0]  weight_matrix_tdata,
  output logic                             output_matrix_tvalid,
  output logic                             output_matrix_tready,
  output logic                             output_matrix_tlast,
  output logic [C_M02_AXI_DATA_WIDTH-1:0]  output_matrix_tdata,
  output logic                             weight_done,
  output logic                             reading_done,
  output logic                             write_done, 
  output logic [4-1:0]                     matrix_row_rdy_o                                                                     
);


timeunit 1ps;
timeprecision 1ps;

///////////////////////////////////////////////////////////////////////////////
// Local Parameters
///////////////////////////////////////////////////////////////////////////////
// Large enough for interesting traffic.
localparam integer  LP_DEFAULT_LENGTH_IN_BYTES = 16384;
localparam integer  LP_NUM_EXAMPLES    = 2;

///////////////////////////////////////////////////////////////////////////////
// Wires and Variables
///////////////////////////////////////////////////////////////////////////////
(* KEEP = "yes" *)
logic                                areset                         = 1'b0;
logic                                ap_start_r                     = 1'b0;
logic                                ap_idle_r                      = 1'b1;
logic                                reset_log                      = 1'b0;
logic                                ap_start_pulse                ;
//logic [LP_NUM_EXAMPLES-1:0]          ap_done_i                     ;
//logic [LP_NUM_EXAMPLES-1:0]          ap_done_r                      = {LP_NUM_EXAMPLES{1'b0}};
logic                                ap_done_r                      ;
logic [32-1:0]                       ctrl_xfer_size_in_bytes        = LP_DEFAULT_LENGTH_IN_BYTES;
logic [32-1:0]                       ctrl_constant                  = 32'd1;
/*
logic                                input_matrix_tvalid;
logic                                input_matrix_tready;
logic                                input_matrix_tlast;
logic [C_M00_AXI_DATA_WIDTH-1:0]     input_matrix_tdata;
logic                                weight_matrix_tvalid;
logic                                weight_matrix_tready;
logic                                weight_matrix_tlast;
logic [C_M01_AXI_DATA_WIDTH-1:0]     weight_matrix_tdata;
logic                                output_matrix_tvalid;
logic                                output_matrix_tready;
logic                                output_matrix_tlast;
logic [C_M02_AXI_DATA_WIDTH-1:0]     output_matrix_tdata;
logic                                reading_done;
logic                                weight_done;
logic                                write_done;
*/
logic                                matrix_row_en[4-1:0];
logic [32-1:0]                       matrix_row_msg[4-1:0];
logic                                matrix_row_rdy[4-1:0];
logic                                matrix_col_en[4-1:0];
logic [32-1:0]                       matrix_col_msg[4-1:0];
logic                                matrix_col_rdy[4-1:0];
logic                                weight_in_col_en[4-1:0];
logic                                weight_in_col_rdy[4-1:0];
logic [32-1:0]                       weight_in_col_msg[4-1:0];
logic                                weight_out_col_en[4-1:0];
logic                                weight_out_col_rdy[4-1:0];
logic [32-1:0]                       weight_out_col_msg[4-1:0];
logic                                all_weights_avail;  
logic                                all_weights_avail_r;                       
///////////////////////////////////////////////////////////////////////////////
// Begin RTL
///////////////////////////////////////////////////////////////////////////////
localparam integer LP_DW_BYTES             = C_M01_AXI_DATA_WIDTH/8;
localparam integer LP_AXI_BURST_LEN        = 4096/LP_DW_BYTES < 256 ? 4096/LP_DW_BYTES : 256;
localparam integer LP_LOG_BURST_LEN        = $clog2(LP_AXI_BURST_LEN);
localparam integer LP_BRAM_DEPTH           = 512;
localparam integer LP_RD_MAX_OUTSTANDING   = LP_BRAM_DEPTH / LP_AXI_BURST_LEN;
localparam integer LP_WR_MAX_OUTSTANDING   = 32;
localparam integer C_DATA_BIT_WIDTH        = 32;
//localparam integer NUM_LOOPS               = C_M00_AXI_DATA_WIDTH/C_GCD_BIT_WIDTH;


assign all_weights_avail_w = all_weights_avail_r;

/*always @(posedge ap_clk) begin
  reset_log <= 1;
end */

// Register and invert reset signal.
always @(posedge ap_clk) begin
  areset <= ~ap_rst_n;
end

// create pulse when ap_start transitions to 1
always @(posedge ap_clk) begin
  begin
    ap_start_r <= ap_start;
  end
end

assign ap_start_pulse = ap_start & ~ap_start_r;

// ap_idle is asserted when done is asserted, it is de-asserted when ap_start_pulse
// is asserted
always @(posedge ap_clk) begin
  if (areset) begin
    ap_idle_r <= 1'b1;
  end
  else begin
    ap_idle_r <= ap_done ? 1'b1 :
      ap_start_pulse ? 1'b0 : ap_idle;
  end
end

assign ap_idle = ap_idle_r;

// Done logic
always @(posedge ap_clk) begin
  if (areset) begin
    ap_done_r <= '0;
  end
  else begin
    ap_done_r <= (ap_start_pulse | ap_done) ? '0 : ap_done_r | (write_done /*&& reading_done && weight_done*/);
  end
end

assign ap_done = ap_done_r;

// ready logic 

assign ap_ready = ap_done;

always @(posedge ap_clk) begin
  if (areset) begin
    all_weights_avail_r <= '0;
  end
  else begin
    all_weights_avail_r <= all_weights_avail;
  end
end

genvar row, col;
generate
	for (row=0; row<4; row=row+1) begin
		assign matrix_row_msg[row] = input_matrix_tdata[(4 - row - 1)*C_DATA_BIT_WIDTH+:C_DATA_BIT_WIDTH];
	end
  for (row=0; row<4; row=row+1) begin
    assign matrix_row_en[row] = input_matrix_tvalid && all_weights_avail;
  end
  for (col=0; col<4; col=col+1) begin
		assign weight_in_col_msg[col] = weight_matrix_tdata[(4 - col - 1)*C_DATA_BIT_WIDTH+:C_DATA_BIT_WIDTH];
  end
  for (col=0; col<4; col=col+1) begin
    assign weight_in_col_en[col] = weight_matrix_tvalid && !all_weights_avail;
  end
  for (col=0; col<4; col=col+1) begin
	assign output_matrix_tdata[(4 - col- 1)*C_DATA_BIT_WIDTH+:C_DATA_BIT_WIDTH] = (matrix_col_en[col])? matrix_col_msg[col] : '0;
  end
  for (col=0; col<4; col=col+1) begin
	assign matrix_col_rdy[col] = output_matrix_tready;
  end	
endgenerate

assign input_matrix_tready = matrix_row_rdy[0] & matrix_row_rdy[1] & matrix_row_rdy[2] & matrix_row_rdy[3];
assign weight_matrix_tready = weight_in_col_rdy[0] & weight_in_col_rdy[1] & weight_in_col_rdy[2] & weight_in_col_rdy[3] && !all_weights_avail_r;
assign output_matrix_tvalid = matrix_col_en[0] || matrix_col_en[1] || matrix_col_en[2] || matrix_col_en[3];
assign weight_out_col_rdy[0] = (all_weights_avail === 1'b1)? '0 : '1;
assign weight_out_col_rdy[1] = (all_weights_avail === 1'b1)? '0 : '1;
assign weight_out_col_rdy[2] = (all_weights_avail === 1'b1)? '0 : '1;
assign weight_out_col_rdy[3] = (all_weights_avail === 1'b1)? '0 : '1;


////////////////////////////////////////////////////////////////////////////
axi_read_master #(
  .C_M_AXI_ADDR_WIDTH  ( C_M00_AXI_ADDR_WIDTH    ) ,
  .C_M_AXI_DATA_WIDTH  ( C_M00_AXI_DATA_WIDTH    ) ,
  .C_XFER_SIZE_WIDTH   ( 32                      ) ,
  .C_MAX_OUTSTANDING   ( LP_RD_MAX_OUTSTANDING   ) , // LP_RD_MAX_OUTSTANDING
  .C_INCLUDE_DATA_FIFO ( 1                       )
)
input_matrix_AXI_Read (
  .aclk                    ( ap_clk                    ) ,
  .areset                  ( areset                    ) ,
  .ctrl_start              ( ap_start_pulse            ) ,
  .ctrl_done               ( reading_done              ) ,
  .ctrl_addr_offset        ( input_matrix              ) ,
  .ctrl_xfer_size_in_bytes ( ctrl_xfer_size_in_bytes   ) ,
  .m_axi_arvalid           ( m00_axi_arvalid           ) ,
  .m_axi_arready           ( m00_axi_arready           ) ,
  .m_axi_araddr            ( m00_axi_araddr            ) ,
  .m_axi_arlen             ( m00_axi_arlen             ) ,
  .m_axi_rvalid            ( m00_axi_rvalid            ) ,
  .m_axi_rready            ( m00_axi_rready            ) ,
  .m_axi_rdata             ( m00_axi_rdata             ) ,
  .m_axi_rlast             ( m00_axi_rlast             ) ,
  .m_axis_aclk             ( ap_clk                    ) ,
  .m_axis_areset           ( areset                    ) ,
  .m_axis_tvalid           ( input_matrix_tvalid       ) ,
  .m_axis_tready           ( input_matrix_tready       ) ,
  .m_axis_tlast            ( input_matrix_tlast        ) ,
  .m_axis_tdata            ( input_matrix_tdata        )
);

assign    m00_axi_awvalid   =0;
assign    m00_axi_awaddr    =0;
assign    m00_axi_awlen     =0;
assign    m00_axi_wvalid    =0;
assign    m00_axi_wdata     =0;
assign    m00_axi_wstrb     =0;
assign    m00_axi_wlast     =0;
assign    m00_axi_bready    =0;

////////////////////////////////////////////////////////////////////
axi_read_master #(
  .C_M_AXI_ADDR_WIDTH  ( C_M01_AXI_ADDR_WIDTH    ) ,
  .C_M_AXI_DATA_WIDTH  ( C_M01_AXI_DATA_WIDTH    ) ,
  .C_XFER_SIZE_WIDTH   ( 32                      ) ,
  .C_MAX_OUTSTANDING   ( LP_RD_MAX_OUTSTANDING   ) , // LP_RD_MAX_OUTSTANDING
  .C_INCLUDE_DATA_FIFO ( 1                       )
)
weight_matrix_AXI_Read (
  .aclk                    ( ap_clk                    ) ,
  .areset                  ( areset                    ) ,
  .ctrl_start              ( ap_start_pulse            ) ,
  .ctrl_done               ( weight_done               ) ,
  .ctrl_addr_offset        ( weight_matrix             ) ,
  .ctrl_xfer_size_in_bytes ( ctrl_xfer_size_in_bytes   ) ,
  .m_axi_arvalid           ( m01_axi_arvalid           ) ,
  .m_axi_arready           ( m01_axi_arready           ) ,
  .m_axi_araddr            ( m01_axi_araddr            ) ,
  .m_axi_arlen             ( m01_axi_arlen             ) ,
  .m_axi_rvalid            ( m01_axi_rvalid            ) ,
  .m_axi_rready            ( m01_axi_rready            ) ,
  .m_axi_rdata             ( m01_axi_rdata             ) ,
  .m_axi_rlast             ( m01_axi_rlast             ) ,
  .m_axis_aclk             ( ap_clk                    ) ,
  .m_axis_areset           ( areset                    ) ,
  .m_axis_tvalid           ( weight_matrix_tvalid      ) ,
  .m_axis_tready           ( weight_matrix_tready      ) ,
  .m_axis_tlast            ( weight_matrix_tlast       ) ,
  .m_axis_tdata            ( weight_matrix_tdata       )
);

assign    m01_axi_awvalid   =0;
assign    m01_axi_awaddr    =0;
assign    m01_axi_awlen     =0;
assign    m01_axi_wvalid    =0;
assign    m01_axi_wdata     =0;
assign    m01_axi_wstrb     =0;
assign    m01_axi_wlast     =0;
assign    m01_axi_bready    =0;

//////////////////////////////////////////////////////////////////
// AXI4 Write Master
axi_write_master #(
  .C_M_AXI_ADDR_WIDTH  ( C_M02_AXI_ADDR_WIDTH    ) ,
  .C_M_AXI_DATA_WIDTH  ( C_M02_AXI_DATA_WIDTH    ) ,
  .C_XFER_SIZE_WIDTH   ( 32                    ) ,
  .C_MAX_OUTSTANDING   ( LP_WR_MAX_OUTSTANDING ) , // LP_WR_MAX_OUTSTANDING
  .C_INCLUDE_DATA_FIFO ( 1                     )
)
AXI_write (
  .aclk                    ( ap_clk                    ) ,
  .areset                  ( areset                    ) ,
  .ctrl_start              ( ap_start_pulse            ) ,
  .ctrl_done               ( write_done                ) ,
  .ctrl_addr_offset        ( output_matrix             ) ,
  .ctrl_xfer_size_in_bytes ( ctrl_xfer_size_in_bytes   ) ,
  .m_axi_awvalid           ( m02_axi_awvalid           ) ,
  .m_axi_awready           ( m02_axi_awready           ) ,
  .m_axi_awaddr            ( m02_axi_awaddr            ) ,
  .m_axi_awlen             ( m02_axi_awlen             ) ,
  .m_axi_wvalid            ( m02_axi_wvalid            ) ,
  .m_axi_wready            ( m02_axi_wready            ) ,
  .m_axi_wdata             ( m02_axi_wdata             ) ,
  .m_axi_wstrb             ( m02_axi_wstrb             ) ,
  .m_axi_wlast             ( m02_axi_wlast             ) ,
  .m_axi_bvalid            ( m02_axi_bvalid            ) ,
  .m_axi_bready            ( m02_axi_bready            ) ,
  .s_axis_aclk             ( ap_clk                    ) ,
  .s_axis_areset           ( areset                    ) ,
  .s_axis_tvalid           ( output_matrix_tvalid      ) ,
  .s_axis_tready           ( output_matrix_tready      ) ,
  .s_axis_tdata            ( output_matrix_tdata       )
);

assign m02_axi_arvalid = 0;
assign m02_axi_araddr  = 0;
assign m02_axi_arlen   = 0;
assign m02_axi_rready  = 0;

//////////////////////////////////////////////////////////////////
SysArrayRTL sys_array
(
  .all_weights_avail   ( all_weights_avail ), 
  .clk                 ( ap_clk            ),
  .reset               ( areset            ),
  .matrix_col__en      ( matrix_col_en     ), 
  .matrix_col__msg     ( matrix_col_msg    ), 
  .matrix_col__rdy     ( matrix_col_rdy    ), 
  .matrix_row__en      ( matrix_row_en     ), 
  .matrix_row__msg     ( matrix_row_msg    ), 
  .matrix_row__rdy     ( matrix_row_rdy    ), 
  .weight_in_col__msg  ( weight_in_col_msg ), 
  .weight_in_col__en   ( weight_in_col_en  ), 
  .weight_in_col__rdy  ( weight_in_col_rdy ), 
  .weight_out_col__msg ( weight_out_col_msg), 
  .weight_out_col__en  ( weight_out_col_en ), 
  .weight_out_col__rdy ( weight_out_col_rdy)
);

endmodule : Top_wrapper
`default_nettype wire
