module dataMemory(aluOut,ch,rtContent,dataOut);
	input [31:0]aluOut;
	input [1:0]ch;
	input [31:0] rtContent;
	output reg[31:0] dataOut;
	
	reg [7:0] dataArr [0:2047];
	parameter size = 11;
	reg [size - 1 : 0] adress;
	
	initial begin
		adress = aluOut[size -1 : 0];	
	end
	
	always @(ch)begin
		if(ch == 2'b1)
			 dataOut = {dataArr[adress],dataArr[adress+1],dataArr[adress+2],dataArr[adress+3]};  // LW
		else
			{dataArr[adress],dataArr[adress+1],dataArr[adress+2],dataArr[adress+3]} = rtContent; // SW
	end	

endmodule