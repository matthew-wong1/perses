#Auto generated by Edalize

TOP_MODULE        := top_earlgrey_verilator
VC_FILE           := lowrisc_systems_top_earlgrey_verilator_0.1.vc
VERILATOR_OPTIONS := --trace --trace-fst --trace-structs --trace-params --trace-max-array 1024 -CFLAGS "-std=c++11 -Wall -DVM_TRACE_FMT_FST -DTOPLEVEL_NAME=top_earlgrey_verilator -g" -LDFLAGS "-pthread -lutil -lelf" -Wall -Wno-PINCONNECTEMPTY -Wno-fatal
MAKE_OPTIONS      := OPT_FAST="-O2"
