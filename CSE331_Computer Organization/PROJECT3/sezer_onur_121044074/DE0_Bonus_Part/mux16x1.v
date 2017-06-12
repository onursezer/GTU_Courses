module mux16x1(output_instruction, input_selection);
	output reg [31:0] output_instruction;
	input [3:0] input_selection;
	
	always @(input_selection) begin
		case (input_selection)
			0 : output_instruction = 32'b00100000000010000000000000000010;
			1 : output_instruction = 32'b00100100000010010000000000000100;
			2 : output_instruction = 32'b00110100000010100000000000001000;
			3 : output_instruction = 32'b00000000000010010101100010000000;
			4 : output_instruction = 32'b00000001011010110110000000100000;
			5 : output_instruction = 32'b00000000000011000110100101000010;
			6 : output_instruction = 32'b00000001001011010111000000100010;
			7 : output_instruction = 32'b00000001110011010111100000100100;
			8 : output_instruction = 32'b00000001110011011100000000100101;
			9 : output_instruction = 32'b00101011000110010000000000000100;
			10 : output_instruction = 32'b00000000000110001000000001000011;
			11 : output_instruction = 32'b00000010000110001000100000101011;
			12 : output_instruction = 32'b00111100000100101111111111111111;
			13 : output_instruction = 32'b00110011000100110000000000000011;
			14 : output_instruction = 32'b00110011000101000000000000000011;
			15 : output_instruction = 32'b00110011000101010000000000000011;
			default : $display("Error in selection of intruction in mux16x1!");
		endcase
	end
endmodule