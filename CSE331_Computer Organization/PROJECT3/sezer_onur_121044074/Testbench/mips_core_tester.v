module mips_core_tester();
	
	reg [5:0] opcode;
	reg [5:0] funct;
	reg [4:0] shamt;
	reg [4:0] rs;
   reg [4:0] rt;
   reg [4:0] rd;
	reg signed [31:0] imme32;
	reg [15:0] imme16;
	
	parameter bit_size = 32;
	parameter mem_size = 32;
	reg signed[bit_size-1:0] arr [0:mem_size-1];
	
	reg [31:0] rd_content;
	reg [31:0] rs_content;
	reg [31:0] rt_content;
	wire [31:0] result;
	
	initial 
	begin 
		$readmemh("reg.hex", arr);
	end
	
	integer i;
	initial begin
		for (i=0; i<mem_size; i=i+1) 
			$display("%d:%b", i, arr[i]);
	end
	
	reg [31:0] input_instruction = 32'b00000000000010110110000001000011;
	
	initial begin
		opcode = input_instruction[31:26];
		rs = input_instruction[25:21];
		rt = input_instruction[20:16];
		rd = input_instruction[15:11];
		shamt = input_instruction[10:6];
		funct = input_instruction[5:0];
		imme16 = input_instruction[15:0];
		imme32 = {{16{imme16[15]}}, imme16};
	end

	
	mips_core_testbench testme (result, input_instruction, rs_content, rt_content);
	initial begin
	rs_content = arr[rs];
	rt_content = arr[rt];
	rd_content = arr[rd];
	#3
	if(opcode == 0)
	begin
		arr[rd] = result;
		$display("rs_content : %b",rs_content);
		$display("rt_content : %b",rt_content);
		$display("shamt : %b",shamt);
		$writememh("reg.hex", arr);
	end
	else
	begin
		arr[rt] = result;
		$display("rs_content : %b",rs_content);
		$display("imme32 : %b",imme32);
		$writememh("reg.hex", arr);
	end
	$monitor("result:%b",result);
	end
	
endmodule