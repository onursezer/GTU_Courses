module xorop( a, b, c);
	output [3:0] c;
	
	input [3:0] a;
	input [3:0] b;
	
	xor(c[0],a[0],b[0]);
	xor(c[1],a[1],b[1]);
	xor(c[2],a[2],b[2]);
	xor(c[3],a[3],b[3]);
endmodule