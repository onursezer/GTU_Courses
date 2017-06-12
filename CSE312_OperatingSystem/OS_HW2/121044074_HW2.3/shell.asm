; 8080 assembler code
        .hexfile shell.hex
        .binfile shell.com
        ; try "hex" for downloading in hex format
        .download bin  
        .objcopy gobjcopy
        .postbuild echo "OK!"
        ;.nodump

  ; OS call list
PRINT_B    equ 1
PRINT_MEM  equ 2
READ_B    equ 3
READ_MEM  equ 4
PRINT_STR  equ 5
READ_STR  equ 6
FORK    equ 7
EXEC     equ 8

  ; Position for stack pointer
stack   equ 3000h

  org 000H
  jmp begin

  ; Start of our Operating System
GTU_OS:  PUSH D
  push D
  push H
  push psw
  nop  ; This is where we run our OS in C++, see the CPU8080::isSystemCall()
    ; function for the detail.
  pop psw
  pop h
  pop d
  pop D
  ret
  ; —-------------------------------------------------------------
  ; YOU SHOULD NOT CHANGE ANYTHING ABOVE THIS LINE        

  ;This program prints a null terminated string to the screen

string: dw 'Enter a command',00H 
begin:
  LXI SP,stack   ; always initialize the stack pointer
  
loop:


  MVI A, FORK
  call GTU_OS

  MVI A,1
  CMP B
  JZ  FAIL_CHILD    ;; esit degilse cocuk olusti


  MVI A,0
  CMP B
  JZ  CHILD_PROCESS    ;; esit degilse cocuk olusti
  ;;; parent

  JMP loop

CHILD_PROCESS:

  MVI A, READ_STR      
  call GTU_OS  

  MVI A, EXEC
  call GTU_OS
  
FAIL_CHILD:
  hlt
      

