        ; 8080 assembler code
        .hexfile part5.hex
        .binfile part5.com
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


begin:
    LXI SP,stack    ; always initialize the stack pointer
    array  dw 12H, 34H


    ;; Test READ_B
    ;; keyboard dan integer deger okur, B registirina o degeri yazar
    MVI A, READ_B
    call GTU_OS


    ;; Test PRINT_B
    ;; PRINT_B, B registirindaki degeri decimal olarak basar
    MVI A, PRINT_B
    call GTU_OS


    ;; Test READ_MEM
    ;; keyboard dan integer deger okur, BC adresine o degeri yazar
    MVI A, READ_MEM
    call GTU_OS
    

    ;; Test PRINT_MEM
    ;; PRINT_MEM, BC registirindaki degeri basar
    MVI A, PRINT_MEM
    call GTU_OS


    ;; Test READ_STR
    ;; keyboard tan string okur BC adresine sonuna null ekleyerek yazar
    MVI A, READ_STR
    call GTU_OS


    ;; Test PRINT_STR
    ;; BC adresinden baslayarak null gorene kadar yazar
    MVI A, PRINT_STR
    call GTU_OS

    hlt     ; end program