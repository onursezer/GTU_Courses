module full_adder ( a ,b ,c ,sum ,carry );
	output sum ;
	output carry ;

	input a ;
	input b ;
	input c ;
   
	wire w1,w2,w3;
	
	xor o1(sum, a, b, c);  //toplam
	
	and o2(w1,a,b);     // (a&b) | (b&c) | (c&a)
	and o3(w2,b,c);		
	and o4(w3,c,a);
	or o5(carry,w1,w2,w3); // elde
	
endmodule