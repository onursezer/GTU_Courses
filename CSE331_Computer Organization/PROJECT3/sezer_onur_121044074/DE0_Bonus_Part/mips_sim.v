module mips_sim(ssd_part4, ssd_part3, ssd_part2, ssd_part1, toggle_sw, result_part_selector);
	output reg [6:0] ssd_part1;
	output reg [6:0] ssd_part2;
	output reg [6:0] ssd_part3;
	output reg [6:0] ssd_part4;
	
	input [3:0] toggle_sw;
	input result_part_selector;
	
	wire [31:0] selected_instruction;
	wire [31:0] result;
	wire [27:0] ssd_lo_16_bits;
	wire [27:0] ssd_hi_16_bits;
	// fetch instruction
	mux16x1 sel_in (selected_instruction, toggle_sw);
	// execute instruction
	// the last two results are not necessary
	// since contents of rs and rt registers
	// are (or should be) defined in mips_core.v 
	mips_core_de0 run (result, selected_instruction);
	// convert lo 16bits of result to ssd
	binary_to_ssd a (ssd_lo_16_bits[6:0], result[3:0]);
	binary_to_ssd b (ssd_lo_16_bits[13:7], result[7:4]);
	binary_to_ssd c (ssd_lo_16_bits[20:14], result[11:8]);
	binary_to_ssd d (ssd_lo_16_bits[27:21], result[15:12]);
	// convert hi 16bits of result to ssd
	binary_to_ssd e (ssd_hi_16_bits[6:0], result[19:16]);
	binary_to_ssd f (ssd_hi_16_bits[13:7], result[23:20]);
	binary_to_ssd g (ssd_hi_16_bits[20:14], result[27:24]);
	binary_to_ssd h (ssd_hi_16_bits[27:21], result[31:28]);
	// display
	always @ (result_part_selector or ssd_lo_16_bits or ssd_hi_16_bits)
		case (result_part_selector)
			0 : begin
					// $display("part1");
					ssd_part1 = ssd_lo_16_bits[6:0];
					ssd_part2 = ssd_lo_16_bits[13:7];
					ssd_part3 = ssd_lo_16_bits[20:14];
					ssd_part4 = ssd_lo_16_bits[27:21];
				end
			1 : begin
					// $display("part2");
					ssd_part1 = ssd_hi_16_bits[6:0];
					ssd_part2 = ssd_hi_16_bits[13:7];
					ssd_part3 = ssd_hi_16_bits[20:14];
					ssd_part4 = ssd_hi_16_bits[27:21];
				end
		endcase
		
endmodule