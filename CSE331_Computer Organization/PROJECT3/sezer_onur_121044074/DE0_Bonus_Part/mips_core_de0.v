module mips_core_de0 (result, input_instruction);
	output reg [31:0] result;
	input [31:0] input_instruction;
	reg [31:0] registers[0:31];
	reg [5:0] opcode;
	reg [5:0] funct;
	reg [4:0] shamt;
	reg [4:0] rs;
   reg [4:0] rt;
   reg [4:0] rd;
	reg signed [31:0] imme32;
	reg [15:0] imme16;

	
	/*initial begin 
		registers[0] = 32'b00100000000010000000000000000010;
		registers[1] = 32'b00100000000010000000000000000010;
		registers[2] = 32'b00100000000010000000000000000010;
		registers[3] = 32'b00100000000010000000000000000010;
		registers[4] = 32'b00100000000010000000000000000010;
		registers[5] = 32'b00100000000010000000000000000010;
		registers[6] = 32'b00100000000010000000000000000010;
		registers[7] = 32'b00100000000010000000000000000010;
		registers[8] = 32'b00100000000010000000000000000010;
		registers[9] = 32'b00100000000010000000000000000010;
		registers[10] = 32'b00100000000010000000000000000010;
		registers[11] = 32'b00100000000010000000000000000010;
		registers[12] = 32'b00100000000010000000000000000010;
		registers[13] = 32'b00100000000010000000000000000010;
		registers[14] = 32'b00100000000010000000000000000010;
		registers[15] = 32'b00100000000010000000000000000010;
		registers[16] = 32'b00100000000010000000000000000010;
		registers[17] = 32'b00100000000010000000000000000010;
		registers[18] = 32'b00100000000010000000000000000010;
		registers[19] = 32'b00100000000010000000000000000010;
		registers[20] = 32'b00100000000010000000000000000010;
		registers[21] = 32'b00100000000010000000000000000010;
		registers[22] = 32'b00100000000010000000000000000010;
		registers[23] = 32'b00100000000010000000000000000010;
		registers[24] = 32'b00100000000010000000000000000010;
		registers[25] = 32'b00100000000010000000000000000010;
		registers[26] = 32'b00100000000010000000000000000010;
		registers[27] = 32'b00100000000010000000000000000010;
		registers[28] = 32'b00100000000010000000000000000010;
		registers[29] = 32'b00100000000010000000000000000010;
		registers[30] = 32'b00100000000010000000000000000010;
		registers[31] = 32'b00100000000010000000000000000010;
	end*/
	
	
	
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
				result = registers[rs] + registers[rt];
				registers[rd] = result;
			end
			else if(funct == 6'b100010) // sub
			begin
			   result = registers[rs] - registers[rt];
				registers[rd] = result;
			end
			else if(funct == 6'b100100)  // and
			begin
				result = registers[rs] & registers[rt];
				registers[rd] = result;
			end
			else if(funct == 6'b100101)  // or
			begin
				result = registers[rs] | registers[rt];
				registers[rd] = result;
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
				result = registers[rs] < registers[rt];
				registers[rd] = result;
			end
		end
		else
		begin
			if(opcode == 6'b001000)  // addi
			begin
				result = registers[rs] + imme32;
				registers[rt] = result;
			end
			else if(opcode == 6'b001001)  // addiu
			begin
				result = registers[rs] + imme32;
				registers[rt] = result;
			end
			else if(opcode == 6'b001100)  // andi
			begin
				result = registers[rs] & imme32;
				registers[rt] = result;
			end
			else if(opcode == 6'b001101)  // ori
			begin
			   result = registers[rs] | imme32;
				registers[rt] = result;
			end
			else if(opcode == 6'b001010)  // slti
			begin
			   result = registers[rs] < imme32;
				registers[rt] = result;
			end
			else if(opcode == 6'b001111)  // lui
			begin
				result = imme32 << 16;
				registers[rt] = result;
			end
		end
	end
	
endmodule