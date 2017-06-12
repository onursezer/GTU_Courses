transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/organizasyon/PROJECT3/sezer_onur_121044074/Testbench {C:/Users/OnurSezer/Desktop/Notlar/organizasyon/PROJECT3/sezer_onur_121044074/Testbench/mips_core_testbench.v}

