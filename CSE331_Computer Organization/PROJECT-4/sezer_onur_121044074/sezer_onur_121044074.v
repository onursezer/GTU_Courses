// Onur SEZER 
// 121044074

module sezer_onur_121044074(result);
	reg [5:0] opcode;
	reg [5:0] funct;
	reg [4:0] shamt;
	reg [4:0] rs,rt,rd;
   reg [4:0] wReg; // registera yazilacak adresi gondermek icin kullanilir( rt ya da rd nin adresi )
	reg [15:0] imme16;
	reg signed [31:0] imme32;
	reg [25:0] targetAddress;
	reg [31:0] instruction;
	
	wire [31:0] writeReg; // registera yazilacak contenti gondermek icin kullanilir
	wire [31:0] rs_content, rt_content, aluResult, pcWire, pc_in, pc_out, aluIn, dataResult;
	reg [1:0] ch, ch2;
	
	output [31:0] result;	
	
   reg [7:0] insArr [0:1023];	 
			 
	
	PC pcModule(pc_in,pc_out);	// pc_out update edilir  
			 
	always @ (pc_out) 
	begin
		instruction = {insArr[pc_out],insArr[pc_out+1],insArr[pc_out+2],insArr[pc_out+3]};			
	end

	always @ (instruction) // instruction ayristirlir
	begin
		opcode = instruction[31:26];
		rs = instruction[25:21];
		rt = instruction[20:16];
		rd = instruction[15:11];
		shamt = instruction[10:6];
		funct = instruction[5:0];
		imme16 = instruction[15:0];
		targetAddress = instruction[25:0];
		imme32 = {{16{imme16[15]}}, imme16};
	end
	
	always @ (opcode or rd or rt) // r-type ise rd'ye yazilir i-type ise rt'ye yazilir
	begin
		if(opcode == 0)
			wReg = rd;
		else
			wReg = rt;
	end
	
	
	always @ (opcode)  // opcode beq, bne, sw ve jump degilse registera yazma var
	begin
		if(opcode != 6'b000100 && opcode != 6'b000101 && opcode != 6'b101011 && opcode != 6'b000010)
			ch = 2'b1;
		else
			ch = 2'b0;
	end
	
	
	regMemory rMemory(rs, rt, wReg, writeReg,ch, rs_content, rt_content);
	

	assign aluIn =(opcode == 0) ? rt_content : imme32;    // r type ise alu' ya rt nin contenti gonderilir
																	// degilse immediate in 32 bite cevrilmis hali gonderilir
 
	
	alu Alu(opcode, rs_content, aluIn, imme32, shamt, funct, aluResult);
	
	
	always @(opcode)  // opcode lw ise memoryden okuma yapilir
        begin
           if (opcode == 6'b100011)
              ch2 = 2'b1;
           else
              ch2 = 2'b0;
        end

	dataMemory dMemory(aluResult,ch2 , rt_content, dataResult);
	
	assign writeReg = (opcode == 6'b100011) ? dataResult : aluResult; 	// opcode lw ise write register'ina  dataMemory'den gelen sonuc gonderilir
																								// degilse alu'dan gelen sonuc gonderilir
	assign pcWire = pc_out + 4;
	
	// opcode'un beq, bnq veya jump  gelmesine gore pc ayarlanir 
	assign pc_in = ( (opcode == 6'b000100)  || (opcode == 6'b000101)) ?  (pc_out + 4 + 4 * imme32) :  
				(opcode == 6'b000010)? {pcWire[31:28],targetAddress,2'b00} : pcWire;
		
		
	assign result = aluResult;

endmodule