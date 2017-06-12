        ; 8080 assembler code
        .hexfile part3.hex
        .binfile part3.com
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

    array  dw 12H, 34H, 23H, 2AH, 5BH, 6FH, 33H, 21H, 7CH, $FFH, $BAH, $CBH, $A1H, 1AH, 3BH, $C3H, 4AH, 5DH, 62H, $A3H, $B1H, 5CH, 7FH, $CCH, $AAH, 34H
    newline dw 10 ;

begin:
    LXI SP,stack 	; always initialize the stack pointer

START:

    LXI B, array   ; array yuklenir
    MVI H, 0       ; swap sayisi tutulur
    MVI L, 25      ; icteki loop'un size'i -> arrayin size'i - 1

BACK:

    LDAX B
    MOV D, A   ; D
    INX B      ; diger indexe gecmek icin cift increment yapilir
    INX B      ; B[++index]
    LDAX B
    MOV E, A   ; E
    MOV A, D
    CMP E      ; D ve E kiyaslanir
    JC SKIP    ; kucukse, swap yok
    JZ SKIP    ; esitse, swap yok
    INR H      ; swap sayisini artirir

    ;;;;; swap ;;;;;;
    DCX B    ;  B[--index]
    DCX B    ;
    MOV A, E
    STAX B
    INX B      ; B[++index]
    INX B      ;
    MOV A, D
    STAX B
    ;;;;; /swap ;;;;;

SKIP:
    DCR L      ; array size-1 kadar inner loop devam eder
    JNZ BACK

    MVI A, 0   ;
    CMP H      ;  swap sayisi sifir degilse devam eder
    JNZ START



;;;********* PRINT  *********
    LXI D, array    ; array yuklenir
    MVI L, 26       ;; arrayin size'ı
print:
    LDAX D
    MOV B,A
    MVI A, PRINT_B
    call GTU_OS

    INX D
    INX D
    DCR L
    JNZ print

    hlt		; end program