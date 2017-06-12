module mux_base (f, s0, s1, b0, b1, b2, b3);

	input s0, s1, b0, b1, b2, b3;
	output f;

	wire f, f1, f2, f3, f4, ns0, ns1;
	wire s0, s1;
	wire b0, b1, b2, b3;

	not n1 (ns0, s0);
	not n2 (ns1, s1);

	and a1 (f1, ns1, ns0, b0);
	and a2 (f2, ns1, s0, b1);
	and a3 (f3, s1, ns0, b2);
	and a4 (f4, s1, s0, b3);

	or result (f, f1, f2, f3, f4);

endmodule