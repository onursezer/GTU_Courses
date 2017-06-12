# Onur SEZER
# 121044074

.data  
	str: .space 20    
	msg: .asciiz "----------- A NEW COURT -------------\n"
	message1: .asciiz "The name of the judge: " 
	message2: .asciiz "The number of people in the jury: "  
	message3:.asciiz "Give JURY FEE to "  
	message4: .asciiz " people and no fee to the judge. (Rule 3)\n" 
	message5: .asciiz "You have to spend 200 x "
	message6: .asciiz "NL at least.\n"
	message7: .asciiz " people and FREEDOM WITH JURY FEE to the judge. (Rule 2)\n"
	message9: .asciiz " people and FREEDOM WITH JURY FEE to the judge. (Rule 1)\n"
	message8: .asciiz "You have to spend "
	equal: .asciiz " = "
	plus: .asciiz " + "
	error: .asciiz "THERE IS NO JUDGE NAMED AS "
	space: .asciiz " "  
	name1 : .asciiz "Villain\n"
	name2 : .asciiz "Miscreant\n"
	villain_A: .word 6000
	villain_B: .word 4000
	jury: .word 200
	miscreant_A: .word 8000
	miscreant_B: .word 3000	
.text
.globl main

	main:  
	while3:
		li $v0, 4    # msg basilir
    	la $a0, msg 
    	syscall
    	    	
		li $v0, 4   # message1 basilir  
    	la $a0, message1  
    	syscall
		 	
    	li $v0, 8   		# kullanicidan string alinir
    	la $a0, str 
   	 	addi $a1,$zero, 20  # $a1 e str' nin uzunlugu atilir
    	syscall 
    	addi $t0, $zero, 0     
    	    		 
	while: # 1. Loop
		bne $t0, $zero, label2	 # $t0 sifira esit degilse label2' ye atla	
    	la $a0, str     		 # $a0' a str' nin adresi gecirilir  
    	la $a1, name1         	 # $a1' a name1' in adresi gecirilir 
    	jal compareString     	 # compareString  fonksiyonuna atlar  
    	beq $v1,$zero, eq    	 # str ile name1 ayni ise eq' e atlar  
    	j label3				 # str name1 ile ayný olmadiginda label3' e atlar
    label2:	
    	la $a0, str     		 # $a0' a str' nin adresi gecirilir  
    	la $a1, name2         	 # $a1' a name2' in adresi gecirilir 
    	jal compareString 	
    	beq $v1,$zero, eq2       # str ile name2 ayni ise eq2' ye atlar
    	j label4				 # str name2 ile de ayni olmadiginda label4' e atlar
    label3:
    	addi $t0, $zero, 1	     # $t0' a 1 ekler ve str'yi name2 ile kiyaslar
    	j while
  	label4:  	
    	li $v0, 4   # hem eq' ya hem de eq2' ye atlamazsa o zaman yanlis hakim ismi girilmis olur hata basar 
    	la $a0, error 
    	syscall
    	li $v0, 4  # hatali string basilir
    	la $a0, str 
    	syscall	
    	j exit
	eq:  
		lw $a2, villain_A  # memoryden villain_A' nin degeri $a2' ye atilir
		lw $a3, villain_B  # memoryden villain_B' nin degeri $a3' ye atilir
    	jal result
    	j exit
    eq2:  
		lw $a2, miscreant_A   # memoryden miscreant_A' nin degeri $a2' ye atilir
		lw $a3, miscreant_B   # memoryden miscreant_B' nin degeri $a3' ye atilir
    	jal result
    	j exit	  
	exit: 
		j while3				
    	li $v0, 10  # End Of Main
    	syscall  
	compareString:  # 1. Subroutine
    	move $t1,$a0  	# $t1 = $a0
    	move $t2, $a1   # $t2 = $a1
	while2:  # 2. Loop
    	lb $t3($t1)         			# $t1 byte olarak yuklenir $t3'e  
    	lb $t4($t2)  					# $t2 byte olarak yuklenir $t4'e
    	beq $t3, $zero, checkt2    		# $t3' teki string biterse checkt2' ye atlar 
    	beq $t4, $zero, checkt1  		# $t4' teki string biterse checkt1' e atlar 
    	bne $t4, $t3, checkt1  			# $t4 ve $t3 bibirine esit degilse checkt1' e atlar
    	addi $t1,$t1,1      			# $t1' e stringin bir sonraki elemani atilir 
   		addi $t2,$t2,1  				# $t2' ye stringin bir sonraki elemani atilir
    	j while2  
	checkt1:   
    	addi $v1,$zero,1      	# string' lerin farkli oldugunu gostermek icin $v1' e 1 atilir 
    	j exit2   			  	# exit2' ye atlar
	checkt2:   
   		bne $t4, $zero, checkt1  # $t4 sifira esit degilse checkt1' atlar
    	add $v1, $zero, $zero   # string' lerin ayni oldugunu gostermek icin $v1' e 0 atilir
	exit2:  
    	jr $ra  # compareString fonksiyonundan cikar
    	
    result: # 2. Subroutine
    	li $v0, 4         
    	la $a0, message2  # Jury sayisini girmesi icin ekrana mesaj basar
    	syscall 
    	
    	li $v0, 5 # Jury sayisini kullanicidan alir
    	syscall
    	move $t7, $v0           # Jury sayisini $t7 registirina atilir    	
    	addi $t4, $zero, 10	    # Jury sayisini 10' a bolmek icin $t4' e 10 atilir
		div $t7, $t4            # $t7 / 10
		mflo    $t0             # bolum    
		mfhi    $t1             # kalan
		beq $t1, $zero, exit3    
		addi $t0, $t0, 1 		# kalan sifir degilse bolum yukari yuvarlanir
	exit3:
		move $s0, $t0		# $s0' e $t0' deki bolum atilir
		lw $t1, jury        # jury sayisinin fiyati memoryden $t1' e atinir
		mul $t0, $t0, $t1   # jury sayisin 1 / 10 ile jury'nin fiyati carpilir		
		add	$t0, $t0, $a2	# Rule 1' e gore fiyat
		
		mul $t6, $t7, 4    		# $t7' deki jury sayisi ile 4 carpilir, $t6' ya atlir
		div $t6, $t4       		# $t6 / 10
		mflo    $t1        		# bolum    
		mfhi    $t2        		# kalan
		beq $t2, $zero, exit4    
		addi $t1, $t1, 1        # kalan sifir degilse bolum yukari yuvarlanir
	exit4:
		move $s1, $t1   		# $s1' e $t1' deki bolum atilir 
		lw $t2, jury  			# jury sayisinin fiyati memoryden $t2' e atinir
		mul $t1, $t1, $t2  		#  jury sayisin 4 / 10 'u ile jury sayisinin fiyati carpilir
		add $t1, $t1, $a3  		# Rule 2' ye gore fiyat
						
		mul $t6, $t7, 8  		# $t7' deki jury sayisi ile 8 carpilir, $t6' ya atlir
		div $t6, $t4 			# $t6 / 10
		mflo    $t2   			# bolum    
		mfhi    $t3   			# kalan
		beq $t3, $zero, exit5   
		addi $t2, $t2, 1        # kalan sifir degilse bolum yukari yuvarlanir 
	exit5:
		move $s2, $t2  			# $s2' ye $t2' deki bolum atilir
		lw $t3, jury  			# jury sayisinin fiyati memoryden $t3' e atinir
		mul $t2, $t2, $t3 		#  jury sayisin 8 / 10 'u ile jury sayisinin fiyati carpilir, Rule3' e toplam gore fiyat
														
		slt $t4, $t0, $t1  		# $t0 $t1' den kucuk ise $t4' e 1 atilir
		beq $t4, 1, label  		# $t4 1 ise label' e atlar
		j exit6					# degilse exit6' ya atlar
	label:
		slt $t4, $t0, $t2   	# $t0 $t2' den kucuk ise $t4' e 1 atilir
		beq $t4, 1, exit7   	# degilse exit7' ye atlar
	exit6:
		slt $t4, $t1, $t2  		# $t1 $t2' den kucuk ise $t4' e 1 atilir
		beq $t4, 1, exit8		# degilse exit8' e atlar
		
		# Rule3 sonuclari icin ekrana gereken yazilar basilir 
		li $v0, 4       # messaage3 basilir  
    	la $a0, message3  
    	syscall			
		li $v0, 1   	# jury sayisi basilir 
		move $a0, $s2
		syscall		
		li $v0, 4       # messaage4 basilir 	
    	la $a0, message4  
    	syscall    	
    	li $v0, 4     	# messaage5 basilir  
    	la $a0, message5 
    	syscall    	
    	li $v0, 1   	# jury sayisi basilir 
		move $a0, $s2
		syscall    	
    	li $v0, 4    	#  =  basilir  
    	la $a0, equal 
    	syscall   	
		li $v0, 1 		# Rule3 'e gore toplam fiyat basilir.
		move $a0, $t2
		syscall		
		li $v0, 4     	#  message6 basilir
    	la $a0, message6 
    	syscall   	
		jr $ra			# result fonksiyonundan cikar
	exit7: # Rule1 sonuclari icin ekrana gereken yazilar basilir 
		li $v0, 4      # messaage3 basilir  
    	la $a0, message3  
    	syscall			
		li $v0, 1   	# jury sayisi basilir 
		move $a0, $s0
		syscall		
		li $v0, 4      # messaage9 basilir 	
    	la $a0, message9 
    	syscall    	
    	li $v0, 4     # messaage8 basilir  
    	la $a0, message8 
    	syscall
    	mul $t4, $s0, 200  	# Jury icin gereken para bastirilir    	
    	li $v0, 1   		# jury icin gereken para basilir 
		move $a0, $t4
		syscall    	
    	li $v0, 4       
    	la $a0, plus 
    	syscall   	
    	li $v0, 1   	# hakim icin geren para 
		move $a0, $a2
		syscall 
		li $v0, 4     	#  =  basilir  
    	la $a0, equal 
    	syscall   
		li $v0, 1 		# Rule1 'e gore toplam fiyat basilir.
		move $a0, $t0
		syscall		
		li $v0, 4     	#  message6 basilir
    	la $a0, message6 
    	syscall   	
		jr $ra			# result fonksiyonundan cikar
	exit8:	# Rule2 sonuclari icin ekrana gereken yazilar basilir 
		li $v0, 4       # messaage3 basilir  
    	la $a0, message3  
    	syscall			
		li $v0, 1   	# jury sayisi basilir 
		move $a0, $s1
		syscall		
		li $v0, 4      	# messaage7 basilir 	
    	la $a0, message7
    	syscall    	
    	li $v0, 4     	# messaage8 basilir  
    	la $a0, message8 
    	syscall
    	mul $t4, $s1, 200  	# Jury icin gereken para bastirilir    	
    	li $v0, 1  		    # jury icin gereken para basilir 
		move $a0, $t4
		syscall    	
    	li $v0, 4       
    	la $a0, plus 
    	syscall   	
    	li $v0, 1   	# hakim icin geren para 
		move $a0, $a3
		syscall 
		li $v0, 4     	#  =  basilir  
    	la $a0, equal 
    	syscall   
		li $v0, 1 		# Rule2 'ye gore toplam fiyat basilir.
		move $a0, $t1
		syscall		
		li $v0, 4     	#  message6 basilir
    	la $a0, message6 
    	syscall   	
		jr $ra    	   # result fonksiyonundan cikar
		
    	
    	
    	
    	
