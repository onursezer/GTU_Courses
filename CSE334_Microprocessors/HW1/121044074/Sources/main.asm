;**********************************************
;*          ONUR SEZER                                                          *
;*           121044074                                                           *
;*                                                                                        *
;*       PROGRAM TOPLAMA VE CIKARMA ISLEMI YAPAR         *  
;*        3  Tane SUBROUTINE Kullanildi                                   *                      
;*                                                                                        *
;*              INPUT BOSLUKLU GIRILMELEDIR                          *
;*                                                                                        * 
;*   Birinci sayi ile operator arasina ve operatorle ikinci sayi    *
;*                    arasina bosluk girilmeli                                   * 
;***********************************************

; export symbols
            XDEF Entry, _Startup            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point



; Include derivative-specific definitions 
		INCLUDE 'derivative.inc' 

ROMStart    EQU  $4000  ; absolute address to place my code/constant data

; variable/data section

PROG                 EQU   $1000
INPUT_AD          EQU   $1500        ; inputun adresi
OUTPUT_AD       EQU   $1600        ; output adresi
NUM1_SIZE        EQU   $200          ; ilk sayinin basamak sayisi  
NUM2_SIZE        EQU   $204          ; ikinci sayinin basamak sayisi
OPERATOR          EQU   $208
COUNT               EQU   $320  
TEMP                  EQU   $330 
TEMPI                  EQU   $350
COUNT2             EQU   $390 
CARRY                EQU   $400
MAXSIZE             EQU   $500
SAYAC                EQU    $520
BORROW            EQU     $530
 
                ORG  INPUT_AD            ; $1500 adresinden itibaren string yazilir   
INPUT       FCC "218 + 15"              ; input initialize edildi
                  DC.B    0                       ; stringin sonuna geldigini kontrol etmek icin yuklendi 
                
; code section
               ORG   PROG                  ; program $1000 adresinden baslatildi

Entry:
_Startup:
            LDS   #RAMEnd+1       ; initialize the stack pointer
mainLoop:
            CLI
            
            LDAA     #0
            STAA     NUM1_SIZE      ; birinci sayinin basamak sayisina 0 atandi 
            STAA     NUM2_SIZE      ; ikinci sayinin basamak sayisina 0 atandi 
                                                 
            LDX   #INPUT                 ; X registerina input yuklendi

LOOP:    
            LDAA  0,X                    ; inputun ilk karekteri aculamator a ya yuklenir
            INC    NUM1_SIZE       ; ilk sayinin basamak sayisini artirir
            INX                             ; diger karektere gecilir
            SUBA  #$20                
            BNE   LOOP                   ; bosluga kadar olan ilk sayiyi alir
            
            DEC   NUM1_SIZE             ; dongude bir tane fazla artan basamak sayisi azaltirilir                  
            LDAA  0,X                         ; operatoru  alir
            STAA  OPERATOR              ; operator adrese yuklenir
            
            INX   ; operatorle ikinci sayi arasindaki boslugu atlar
            INX   ; ikinci sayinin basina gecer
            
LOOP2:
            LDAA  0,X                 ; inputun ilk karekteri aculamator a ya yuklenir
            INC   NUM2_SIZE     ; ikinci sayinin basamak sayisi artirilir
            INX                          ; diger karektere gecilir
            SUBA  #$0               
            BNE    LOOP2              ; inputun sonuna gelirse donguden cikar
            
            DEC   NUM2_SIZE             ; dongude bir tane fazla artan basamak sayisi azaltirilir         
                         
            JSR bringEnd      ; x ve y registerlarinin  birinci ve ikinci sayinin son rakamlarinin adresini tutmasi saglanir
            
            MOVB     NUM1_SIZE,    COUNT    ; count = num1_size
            MOVB     NUM2_SIZE,    COUNT2    ; count2 = num1_size
            
            LDAA  OPERATOR
            CMPA #43                    ; operatorun toplama olup olmadigi kontrol edilir
            BEQ  TOPLAMA
            JMP   EXIT2

TOPLAMA:            
            MOVB     #$0,  CARRY    ; carry ilk basta 0 ile initialize edildi                               
DONGU:
            JSR    FONK             ; fonksiyon cagirir    ascii to decimal
            JSR    FONK2           ; fonksiyon cagirir     ascii to decimal
            STAA TEMP
            
            LDAA COUNT
            ADDA  COUNT2           ;  count ve count2  toplami sifir olursa birinci ve ikinci sayinin basamaklari bitmistir
            CMPA #$0
            BEQ  C3
            
            LDAA TEMP
            ABA                           ; a = temp
            ADDA CARRY              ; a += carry
            
            CMPA #10
            BHS C1                    ; a >= 10 olursa carry 1   yapilir

            MOVB  #$0,  CARRY      ; carry = 0
            JMP C2
C1:
            MOVB  #$1,  CARRY        ; carry = 1
            JMP C2

C3:
            LDAA TEMP
            ABA                    ; a += b
            ADDA CARRY       ; a += carry
            CMPA #10
            BHS C6               ; a >= 10   carry 1   yapilir
            
            JMP C7
C6:      
            MOVB  #$1,  CARRY        ; carry = 1
            JMP C8      
C7:       
            MOVB  #$0,  CARRY      ; carry = 0
C8:
            LDAA #0      ; donguden cikilmasi icin a = 0
            JMP C4
C2:
            LDAA #1     ; donguden cikmamasi icin a = 1
C4:
            BNE DONGU   
            

            LDAA NUM1_SIZE             ;  a =  NUM1_SIZE
            CMPA NUM2_SIZE            ;  NUM1_SIZE ve NUM2_SIZE    nin size i kiyaslanir
            BCC C9
            LDAA NUM2_SIZE         ; a = NUM2_SIZE
            STAA MAXSIZE              ;  MAXSIZE = a
            JMP C10
C9:
            STAA MAXSIZE            
C10:            
            LDAA CARRY
            CMPA #$1
            BEQ C11         ; CARRY 1 se maxsize 1 artirilir 
            JMP C12
C11:
            LDAA MAXSIZE      ; a = maxsize
            ADDA #$1             ; a += 1
            STAA MAXSIZE       ; maxsize = a
C12:            
                        
            MOVB     NUM1_SIZE,    COUNT    ; count = num1_size
            MOVB     NUM2_SIZE,    COUNT2    ; count2 = num1_size
            MOVB     #$0,  CARRY 
            JSR bringEnd
BACK:
            JSR    FONK             ; fonksiyon cagirir    ascii to decimal
            JSR    FONK2           ; fonksiyon cagirir     ascii to decimal
             
                        
            ABA                        ; a += b 
            ADDA CARRY           ; a += carry
            CMPA #10
            BHS C13                   ; a >= 10 ise carry 1 yapilir
            MOVB     #$0,  CARRY   ; carry = 0
            JMP C14
C13:
            MOVB     #$1,  CARRY    ; carry = 1
            SUBA #10    ; 10 dan buyuk olan rakamdan 10 cikartilir      
C14:           
      
            ADDA  #$30           ;  ascii kodu icin 30 ile toplanir
            
            MOVB MAXSIZE, SAYAC ; SAYAC = MAXSIZE
            
            LDX    #OUTPUT_AD  ; X registerine $1600 adresi yuklenir

            ; bu dongude $1600 uncu adrese sonucun yazilmasi icin X registeri ayarlanir
LOOP6:
            INX                           
            DEC   SAYAC
            BNE  LOOP6
            DEX         
  
            STAA  0,X     ; cikan sonuc yazilir  
            
            
            ; bu dongude kullanilan X registeri na eski konumu yuklenir
            LDAA  MAXSIZE          
            LDX    #INPUT
LOOP7:
            INX                ; x registerinin adresini birinci sayinin son rakamina getirme islemi yapilir
            DECA
            BNE LOOP7
            DEX
            DEX
              
            DEC MAXSIZE      ; MAXSIZE -= 1
            BNE  BACK           ; MAXSIZE sifir olursa donguden cikar

            JMP EXIT 
EXIT2:
            LDAA  OPERATOR      ; a = OPERATOR
            CMPA #45                ; 45 : eksi operatorunu decimal degeri 
            BEQ  CIKARMA          ; operator cikarma islemi oldugunda CIKARMA islemi yapilir
            JMP   EXIT                 ; cikarma islemi degilse programdan cikar
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; CIKARMA
CIKARMA:

            MOVB     NUM1_SIZE,    COUNT    ; count = num1_size
            MOVB     NUM2_SIZE,    COUNT2    ; count2 = num1_size
            MOVB     #$0,  BORROW                                 

DONGU2:
            JSR    FONK             ; fonksiyon cagirir    ascii to decimal
            JSR    FONK2           ; fonksiyon cagirir     ascii to decimal
            STAA TEMP
            
            LDAA COUNT
            ADDA  COUNT2
            CMPA #$0              ;  count ve count2  toplami sifir olursa birinci ve ikinci sayinin basamaklari bitmistir
            BEQ  B3
            
            LDAA TEMP
            CBA             ; A daki B den kucukse elde alinir
            BCS ELDE           
            MOVB     #$0,  BORROW     ;    BORROW = 0
            JMP CIK
ELDE:
            MOVB     #$1,  BORROW      ;    BORROW = 1
CIK:              
            JMP B2

B3:
            LDAA TEMP
            CMPA #$1        ; a == 1 ise     BORROW = 1 yapilir
            BEQ EQ
            MOVB     #$0,  BORROW    ;  BORROW = 0
            JMP B8

EQ:       LDAA BORROW
            CMPA #$1
            BEQ EQ2
            MOVB     #$0,  BORROW    ; BORROW = 0
            JMP B8
EQ2:           
            MOVB     #$1,  BORROW     ; BORROW = 1
                                          
B8:
            LDAA TEMP
            SBA                    ; a -= b
            LDAA #0             ; donguden cikmasi icin a = 0 yapilir
            JMP B4
B2:
            LDAA #1       ;     ; donguden cikmamasi icin a = 1 yapilir
B4:
            BNE DONGU2
            
            LDAA BORROW
            CMPA #$1         ;    BORROW == 1 ise  NUM1_SIZE in bir azalttirilir
            BEQ  EQ3
            LDAA NUM1_SIZE
            STAA MAXSIZE       ;     MAXSIZE =  NUM1_SIZE
            JMP EQ4
EQ3:    LDAA NUM1_SIZE  ; a =  NUM1_SIZE
            SUBA #$1             ; a -= 1
            STAA MAXSIZE      ; MAXSIZE = a
EQ4:
                   
          
          
            MOVB     NUM1_SIZE,    COUNT    ; count = num1_size
            MOVB     NUM2_SIZE,    COUNT2    ; count2 = num1_size
            MOVB     #$0,  BORROW 
            JSR bringEnd
BACK2:
            JSR    FONK             ; fonksiyon cagirir    ascii to decimal
            JSR    FONK2           ; fonksiyon cagirir     ascii to decimal
            
            STAA TEMP              ; TEMP = a
            LDAA BORROW        ;  a =   BORROW
            CMPA #$1               ;  a == 1   ise  a  nin degeri 1 azalttirilir
            BEQ EQ5
            LDAA TEMP
            JMP EQ6   
EQ5: 
             LDAA TEMP
             SUBA #$1        ; a -= 1
EQ6:      
            CBA             ; A daki B den kucukse elde alinir
            BCS B_ELDE  
            MOVB     #$0,  BORROW
            JMP  B_ELDE2 
B_ELDE:
            ADDA #10
            MOVB     #$1,  BORROW  
B_ELDE2:                     

           SBA
             
           ADDA  #$30           ;  ascii kodu icin 30 ile toplanir
            
            
           MOVB MAXSIZE, SAYAC ; SAYAC = MAXSIZE
            
           LDX    #OUTPUT_AD  ; X registerine $1600 adresi yuklenir

            ; bu dongude $1600 uncu adrese sonucun yazilmasi icin X registeri ayarlanir
LOOP8:
            INX                           
            DEC   SAYAC
            BNE  LOOP8
            DEX         
  
            STAA  0,X     ; cikan sonuc yazilir  
            
            
            ; bu dongude kullanilan X registeri na eski konumu yuklenir
            LDAA  MAXSIZE          
            LDX    #INPUT
LOOP9:
            INX                ; x registerinin adresini birinci sayinin son rakamina getirme islemi yapilir
            DECA
            BNE LOOP9
            DEX
            DEX
              
            DEC MAXSIZE
            BNE  BACK2 
          
          
EXIT:
            RTS                   ; result in D
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;  SUBROUTINE - 1             

FONK:   
             LDAA COUNT
             CMPA #$0
             BNE B_FONK
             
             LDAA #$0
             JMP B1_FONK               
B_FONK:
             LDAA 0,X
             SUBA  #$30        ; ascii degerinden 30 cikartilip decimal degeri bulunur
             DEX
             DEC COUNT
B1_FONK:
             RTS    
;;;;;;;;;;;;;;;;;;;;;;  SUBROUTINE - 2             

FONK2:
             LDAB COUNT2
             CMPB #$0
             BNE B_FONK2
             
             LDAB #$0
             JMP B1_FONK2              
B_FONK2:   
             LDAB 0,Y
             SUBB  #$30         ; ascii degerinden 30 cikartilip decimal degeri bulunur
             DEY
             DEC COUNT2
B1_FONK2:            
             RTS                 
;;;;;;;;;;;;;;;;;;;;;;  SUBROUTINE - 3             

bringEnd:               
              ; bu dongude X registerina birinci sayinin son rakamini getirme islemi yapilir        
            LDAA  NUM1_SIZE   ; birinci sayinin size i   aculamator a ya yuklenir       
            LDX    #INPUT         ; string X registerina yuklenir
LOOP3:
            INX                ; stringin diger karekterine gecmeyi saglar                 
            DECA            ; size sifir olana kadar devam eder
            BNE LOOP3
            DEX              ; dongude bir tane fazla artan X registeri bir azalttirilir
           
            ; bu dondude ikinci sayiya kadar olan karekterler atlanir 
            LDAA  NUM1_SIZE          
            LDY     #INPUT
LOOP4:
            INY                   ; stringin diger karekterine gecmeyi saglar             
            DECA                ; size sifir olana kadar devam eder
            BNE LOOP4
            INY       ; boslugu atla
            INY       ; operatoru atla
            INY       ; boslugu atla
            
            ; bu dongude Y registerina ikinci sayinin son rakamini getirme islemi yapilir
            LDAA  NUM2_SIZE     ; ikinci sayinin size i   aculamator a ya yuklenir      
LOOP5:
            INY                           ; stringin diger karekterine gecmeyi saglar         
            DECA                        ; size sifir olana kadar devam eder
            BNE LOOP5
            DEY                          ; dongude bir tane fazla artan Y registeri bir azalttirilir
            
            ; LOOP3 den LOOP5 e kadar X ve Y registerlerina birinci ve ikinci sayinin son rakamlarini  yerlestirme islemi yapildi  
            
            RTS                    
;;;;;;;;;;;;;;;;;;;;;;  END of SUBROUTINES                     
              
              
              

;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector