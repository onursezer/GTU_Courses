        ; 8080 assembler code
        .hexfile PrintNumbersRev.hex
        .binfile PrintNumbersRev.com
        ; try "hex" for downloading in hex format
        .download bin  
        .objcopy gobjcopy
        .postbuild echo "OK!"
        ;.nodump

	; OS call list
PRINT_B		equ 1
PRINT_MEM	equ 2
READ_B		equ 3
READ_MEM	equ 4
PRINT_STR	equ 5
READ_STR	equ 6

	; Position for stack pointer
stack   equ 3000h

	org 000H
	jmp begin

	; Start of our Operating System
GTU_OS:	PUSH D
	push D
	push H
	push psw
	nop	; This is where we run our OS in C++, see the CPU8080::isSystemCall()
		; function for the detail.
	pop psw
	pop h
	pop d
	pop D
	ret
	; ---------------------------------------------------------------
	; YOU SHOULD NOT CHANGE ANYTHING ABOVE THIS LINE         


begin:
    LXI SP,stack 	; always initialize the stack pointer
    MVI C, 51	; init C with 51
    MVI D, 100    ; init D with 0
    
loop:
   
    MOV B, D
    MVI A, PRINT_B
    call GTU_OS
    DCR D
    DCR C    
    JNZ loop	; goto loop if C!=0

    hlt		; end program














