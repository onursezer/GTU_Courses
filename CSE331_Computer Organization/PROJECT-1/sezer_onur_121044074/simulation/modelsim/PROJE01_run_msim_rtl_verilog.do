transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/full_adder.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/adder.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/subtractor.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/andop.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/xorop.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/mux_base.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/mux_full.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/main_demos.v}
vlog -vlog01compat -work work +incdir+C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074 {C:/Users/OnurSezer/Desktop/Notlar/PROJECT_1/sezer_onur_121044074/main.v}

