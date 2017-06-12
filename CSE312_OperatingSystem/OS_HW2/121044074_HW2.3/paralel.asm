; 8080 assembler code
        .hexfile paralel.hex
        .binfile paralel.com
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

child1: dw 'PrintNumbers.com',00H 
child2: dw 'sum.com',00H 
child3: dw 'PrintNumbersRev.com',00H 
begin:
  LXI SP,stack   ; always initialize the stack pointer
  
loop:


  MVI A, FORK
  call GTU_OS

  MVI A,1
  CMP B
  JZ  FAIL_CHILD    


  MVI A,0
  CMP B
  JZ  CHILD_PROCESS   
  ;;;;;;;;;;;;;;;;;;;;;;;;; parent

  
  MVI A, FORK
  call GTU_OS

  MVI A,1
  CMP B
  JZ  FAIL_CHILD   


  MVI A,0
  CMP B
  JZ  CHILD_PROCESS2    
  ;;;;;;;;;;;;;;;;;;;;;;;;;;; parent


  MVI A, FORK
  call GTU_OS

  MVI A,1
  CMP B
  JZ  FAIL_CHILD    


  MVI A,0
  CMP B
  JZ  CHILD_PROCESS3    
  ;;;;;;;;;;;;;;;;;;;;;;;;,;;; parent


  hlt ------>> parent's end
CHILD_PROCESS:
  LXI B,  child1
  MVI A, EXEC
  call GTU_OS
  hlt

CHILD_PROCESS2:
  LXI B,  child2
  MVI A, EXEC
  call GTU_OS
  hlt

CHILD_PROCESS3:
  LXI B,  child3
  MVI A, EXEC
  call GTU_OS
  hlt


FAIL_CHILD:
  hlt
      
