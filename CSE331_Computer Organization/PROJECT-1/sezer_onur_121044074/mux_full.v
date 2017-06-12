module mux_full (fout, selector, adder, subtractor, andop, xorop);
	input [1:0] selector;
	input [3:0] adder;
	input [3:0] subtractor;
	input [3:0] andop;
	input [3:0] xorop;
	output [3:0] fout;

mux_base calcbit0 (fout[0], selector[0], selector[1], adder[0], subtractor[0], andop[0], xorop[0]);
mux_base calcbit1 (fout[1], selector[0], selector[1], adder[1], subtractor[1], andop[1], xorop[1]);
mux_base calcbit2 (fout[2], selector[0], selector[1], adder[2], subtractor[2], andop[2], xorop[2]);
mux_base calcbit3 (fout[3], selector[0], selector[1], adder[3], subtractor[3], andop[3], xorop[3]);

endmodule