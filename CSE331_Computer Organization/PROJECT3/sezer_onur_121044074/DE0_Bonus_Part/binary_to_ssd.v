module binary_to_ssd(ssd_bits, input_bits);
	output reg [6:0] ssd_bits;
	input [3:0] input_bits;
	
	always @(input_bits) begin
		case (input_bits)
			4'b0000 : ssd_bits = 7'b1000000; // 0
			4'b0001 : ssd_bits = 7'b1001111; // 1
			4'b0010 : ssd_bits = 7'b0100100; // 2
			4'b0011 : ssd_bits = 7'b0110000; // 3
			4'b0100 : ssd_bits = 7'b0011001; // 4
			4'b0101 : ssd_bits = 7'b0010010; // 5	
			4'b0110 : ssd_bits = 7'b0000010; // 6
			4'b0111 : ssd_bits = 7'b0000111; // 7
			4'b1000 : ssd_bits = 7'b0000000; // 8
			4'b1001 : ssd_bits = 7'b1101000; // 9
			4'b1010 : ssd_bits = 7'b0100011; // A
			4'b1011 : ssd_bits = 7'b0000011; // B
			4'b1100 : ssd_bits = 7'b0100111; // C
			4'b1101 : ssd_bits = 7'b0100001; // D
			4'b1110 : ssd_bits = 7'b0000100; // E
			4'b1111 : ssd_bits = 7'b0001110; // F
			default : $display("Error in selection of intruction in mux16x1!");
		endcase
	end
	
endmodule