#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/ld443/workspace_debug/sys_128/vivado_rtl_kernel/SysArray_ex/imports/hls/prj/sol/.autopilot/db/a.g.bc ${1+"$@"}
