module main(led[9:0],sw[9:0]);

	output [9:0] led;
	input [9:0] sw;
	
	wire [3:0] resultAdder;
	wire [3:0] resultSubt;
	wire [3:0] resultAnd;
	wire [3:0] resultXor;
	
	
	adder o1( sw[3:0]	,sw[7:4] ,resultAdder );
	subtractor o2( sw[3:0]	,sw[7:4] ,resultSubt );
	andop o3( sw[3:0]	,sw[7:4] ,resultAnd );
	xorop o4( sw[3:0]	,sw[7:4] ,resultXor );
	mux_full o5(led[3:0], sw[9:8], resultAdder, resultSubt, resultAnd, resultXor);


endmodule


