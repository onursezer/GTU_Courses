module test;
	wire [31:0] result;	
	reg [31:0] size;
	sezer_onur_121044074 testTop(result);
		
	initial begin
		size = 32'b00000000000000000000000001101100;  // 27*4 Instruction sayisi kadar ilerler
		// dosyadan okuma
		$readmemh("regMemory.hex", testTop.rMemory.arr);
		$readmemb("instMem.txt", testTop.insArr);
		$readmemb("dataMemory.txt", testTop.dMemory.dataArr);
	end
	always begin
		if(testTop.pcModule.pc_in <= size) // size => 108
		begin
			// dosyaya yazma
			$writememh("result_regMemory.hex", testTop.rMemory.arr);
			$writememb("result_instMem.txt", testTop.insArr);
			$writememb("result_dataMemory.txt", testTop.dMemory.dataArr);
			#50;
		end
		#50;
	end
endmodule