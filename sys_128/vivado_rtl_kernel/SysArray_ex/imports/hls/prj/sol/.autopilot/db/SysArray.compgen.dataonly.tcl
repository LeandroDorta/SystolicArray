# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
scalar00 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
scalar01 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
input_matrix { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 32
	offset_end 43
}
weight_matrix { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 44
	offset_end 55
}
output_matrix { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 56
	offset_end 67
}
}
dict set axilite_register_dict control $port_control


