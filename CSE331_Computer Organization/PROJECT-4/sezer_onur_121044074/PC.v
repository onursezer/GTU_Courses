module PC(pc_in, pc_out);

	input [31:0] pc_in;
	output reg[31:0] pc_out;

	initial pc_out = 32'b0;
	
	always @(pc_in)
	begin
		#50;
		pc_out = pc_in;
	end
	
endmodule