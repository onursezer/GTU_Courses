module alu(opcode,rs_content,rt_content,imme32,shamt,funct,result);
	input [5:0] opcode,funct;
	input [31:0] rs_content,rt_content,imme32;
	input [4:0] shamt;
	wire [31:0] shamt32 = {{28{shamt[4]}},shamt[3:0]};
	wire [4:0] Shamt = shamt32[4:0];
	wire [31:0] Add,Sub,And,Or,Sra,Srl,Sll,Slt;
	wire [31:0] Addi,Addiu,Andi,Ori,Lui,Slti,Sltu,Sltiu,Beq,Bne,Lw,Sw;
	output [31:0] result;

	//Islemler
	assign Add = rs_content + rt_content;
	assign Sub = rs_content - rt_content;
	assign And = rs_content & rt_content;
	assign Or  = rs_content | rt_content;
	assign Xor  = rs_content ^ rt_content;
	///
	assign Srl = rt_content >> Shamt;
	assign Sra = rt_content >> Shamt;
	assign Sltu = rs_content < rt_content;
	assign Sll = rt_content << Shamt;
	assign Slt = rs_content < rt_content;
	assign Sltiu = rs_content < imme32;
	assign Slti = rs_content < imme32;
	///
	assign Addi = rs_content + imme32;
	assign Addiu = rs_content + imme32;
	assign Andi = rs_content & imme32;
	assign Ori  = rs_content | imme32;
	assign Xori = rs_content ^ imme32;
	assign Lui = {imme32[15:0],16'b0};	
    ///
	assign Beq = rs_content - imme32;
	assign Bne = rs_content - imme32;
	assign Lw  = rs_content + imme32;
	assign Sw  = rs_content + imme32;

	// gelen instructionin tipine gore islemin sonucu result' a atanir
	assign result=
		((opcode == 0) && (funct == 6'b100000)) ? Add:
		((opcode == 0) && (funct == 6'b100010)) ? Sub:
		((opcode == 0) && (funct == 6'b100100)) ? And:
		((opcode == 0) && (funct == 6'b100101)) ? Or:
		((opcode == 0) && (funct == 6'b000011)) ? Sra:
		((opcode == 0) && (funct == 6'b000010)) ? Srl:
		((opcode == 0) && (funct == 6'b000000)) ? Sll:
		((opcode == 0) && (funct == 6'b000000)) ? Sltu:
		((opcode == 0) && (funct == 6'b101010)) ? Slt:
		((opcode == 0) && (funct == 6'b100110)) ? Xor:
		(opcode==6'b001000) ? Addi:
		(opcode==6'b001001) ? Addiu:
		(opcode==6'b001100) ? Andi:
		(opcode==6'b001101) ? Ori:
		(opcode==6'b001111) ? Lui:
		(opcode==6'b001001) ? Sltiu:
		(opcode==6'b001010) ? Slti:
		(opcode==6'b000100) ? Beq:
		(opcode==6'b000101) ? Bne:
		(opcode==6'b100011) ? Lw:
		(opcode==6'b001110) ? Xori:
		(opcode==6'b101011) ? Sw:	rs_content; //hic bi sey degilse rs_content'i doner
	
endmodule