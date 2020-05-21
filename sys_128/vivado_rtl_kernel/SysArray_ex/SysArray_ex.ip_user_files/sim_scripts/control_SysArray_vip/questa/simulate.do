onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib control_SysArray_vip_opt

do {wave.do}

view wave
view structure
view signals

do {control_SysArray_vip.udo}

run -all

quit -force
