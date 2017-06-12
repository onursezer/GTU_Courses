module regMemory(readRegister1,readRegister2,writeRegister,data,ch,rsContent,rtContent);

	input [4:0] readRegister1;
   input [4:0] readRegister2;
   input [4:0] writeRegister;
	input [31:0] data;
	input [1:0] ch;
	output reg [31:0] rsContent;
	output reg [31:0] rtContent;
	
	reg [31:0] arr [0:31];
	
	always @(readRegister1 or readRegister2 or writeRegister or ch or data)
	begin
		rsContent = arr[readRegister1];
		rtContent = arr[readRegister2];
		
		if(ch == 2'b1) 
		begin
			arr[writeRegister] = data;
		end	
	end
endmodule