module mips_core_testbench (result, input_instruction, rs_content, rt_content);
	output reg signed[31:0] result;
	input [31:0] input_instruction;
	input [31:0] rs_content;
	input [31:0] rt_content;
	
	reg [5:0] opcode;
	reg [5:0] funct;
	reg [4:0] shamt;
	reg [4:0] rs;
   reg [4:0] rt;
   reg [4:0] rd;
	reg signed [31:0] imme32;
	reg [15:0] imme16;

	always @(input_instruction) begin
	opcode = input_instruction[31:26];
	rs = input_instruction[25:21];
	rt = input_instruction[20:16];
	rd = input_instruction[15:11];
	shamt = input_instruction[10:6];
	funct = input_instruction[5:0];
	imme16 = input_instruction[15:0];
	imme32 = {{16{imme16[15]}}, input_instruction[15:0]};
	end
	always @(opcode) begin
		if(opcode == 0)
		begin
			if(funct == 6'b100000) // add
			begin
				$display("add");
				result = rs_content + rt_content;
			end
			else if(funct == 6'b100010) // sub
			begin
				$display("sub");
			   result = rs_content - rt_content;
			end
			else if(funct == 6'b100100)  // and
			begin
				$display("and");
				result = rs_content & rt_content;
			end
			else if(funct == 6'b100101)  // or
			begin
				$display("or");
				result = rs_content | rt_content;
			end
			else if(funct == 6'b000011)  // sra
			begin
				$display("sra");
				result = rt_content >> shamt;
			end
			else if(funct == 6'b000010)  // srl
			begin
				$display("srl");
				result = rt_content >>> shamt;
			end
			else if(funct == 6'b000000)  // sll
			begin
				$display("sll");
				result = rt_content << shamt;
			end
			else if(funct == 6'b101001)  // sltu
			begin
				$display("sltu");
				result = rs_content < rt_content;
			end
			else
			begin
				$display("Error");
			end
		end
		else
		begin
			if(opcode == 6'b001000)  // addi
			begin
				$display("addi");
				result = rs_content + imme32;
			end
			else if(opcode == 6'b001001)  // addiu
			begin
				$display("addiu");
				result = rs_content + imme32;
			end
			else if(opcode == 6'b001100)  // andi
			begin
				$display("andi");
				result = rs_content & imme32;
			end
			else if(opcode == 6'b001101)  // ori
			begin
				$display("ori");
			   result = rs_content | imme32;
			end
			else if(opcode == 6'b001010)  // slti
			begin
				$display("slti");
			   result = rs_content < imme32;
			end
			else if(opcode == 6'b001111)  // lui
			begin
				$display("lui");
				result = imme32 << 16;
			end
			else
			begin
				$display("Error");
			end
		end
	end

	
endmodule