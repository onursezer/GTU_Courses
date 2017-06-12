module test_main();

	wire [9:0]led;
	reg [9:0]sw;
	
	main mainOperation(led, sw);
	initial begin
	
	$monitor("a=%b%b%b%b b=%b%b%b%b res=%b%b%b%b",sw[3],sw[2],sw[1],sw[0],sw[7],sw[6],sw[5],sw[4],led[3],led[2],led[1],led[0]);
		
		sw[3]=1;sw[2]=1;sw[1]=0;sw[0]=0;   // a (1. input)
		sw[7]=1;sw[6]=1;sw[5]=0;sw[4]=1;   // b (2. input)
		sw[9]=1;sw[8]=1;                   // seçme
		
	
	end


endmodule