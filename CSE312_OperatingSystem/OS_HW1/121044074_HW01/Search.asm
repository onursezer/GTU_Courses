        ; 8080 assembler code
        .hexfile part4.hex
        .binfile part4.com
        ; try "hex" for downloading in hex format
        .download bin  
        .objcopy gobjcopy
        .postbuild echo "OK!"
        ;.nodump

    ; OS call list
PRINT_B     equ 1
PRINT_MEM   equ 2
READ_B      equ 3
READ_MEM    equ 4
PRINT_STR   equ 5
READ_STR    equ 6

    ; Position for stack pointer
stack   equ 0F000h

    org 000H
    jmp begin

    ; Start of our Operating System
GTU_OS: PUSH D
    push D
    push H
    push psw
    nop ; This is where we run our OS in C++, see the CPU8080::isSystemCall()
        ; function for the detail.
    pop psw
    pop h
    pop d
    pop D
    ret
    ; ---------------------------------------------------------------
    ; YOU SHOULD NOT CHANGE ANYTHING ABOVE THIS LINE         


    array  dw 12H, 34H, 23H, 2AH, 5BH, 6FH, 33H, 21H, 7CH, $FFH, $BAH, $CBH, $A1H, 1AH, 3BH, $C3H, 4AH, 5DH, 62H, $A3H, $B1H, 5CH, 7FH, $CCH, $AAH, 34H
    
    string dw 'ERROR',00AH,00H ;
    newline dw 10 ;

begin:
    LXI SP,stack    ; always initialize the stack pointer

    
    MVI A, READ_B
    call GTU_OS

    ;MVI A, PRINT_B
    ;call GTU_OS

    MVI H, 26
    LXI D, array
    MOV L, B

START:
    LDAX D
    CMP L    
    JZ bulundu 
    INX D
    INX D
    DCR H
    JNZ START
    
    ;;; Bulunmazsa ekrara 'error' yazar
    LXI B, string   
    MVI A, PRINT_STR    
    call GTU_OS 
    JMP NOFIND

bulundu:    
    MVI A, 26   
    SUB H       ; index bulunur
    
    MOV B, A    ; b ye konur
    MVI A, PRINT_B
    call GTU_OS
   
    
NOFIND:    

    hlt     ; end program