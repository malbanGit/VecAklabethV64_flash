                    .module  printstringsync.pre.s 
                    .area    .text 
Vec_Str_Ptr         =        0xC82C 
Vec_Text_Width      =        0xC82B 
VIA_port_b          =        0xD000                       ;VIA port B data I/O register 
VIA_port_a          =        0xD001                       ;VIA port A data I/O register (handshaking) 
VIA_DDR_b           =        0xD002                       ;VIA port B data direction register (0=input 1=output) 
VIA_DDR_a           =        0xD003                       ;VIA port A data direction register (0=input 1=output) 
VIA_t1_cnt_lo       =        0xD004                       ;VIA timer 1 count register lo (scale factor) 
VIA_t1_cnt_hi       =        0xD005                       ;VIA timer 1 count register hi 
VIA_t1_lch_lo       =        0xD006                       ;VIA timer 1 latch register lo 
VIA_t1_lch_hi       =        0xD007                       ;VIA timer 1 latch register hi 
VIA_t2_lo           =        0xD008                       ;VIA timer 2 count/latch register lo (refresh) 
VIA_t2_hi           =        0xD009                       ;VIA timer 2 count/latch register hi 
VIA_shift_reg       =        0xD00A                       ;VIA shift register 
VIA_aux_cntl        =        0xD00B                       ;VIA auxiliary control register 
VIA_cntl            =        0xD00C                       ;VIA control register 
VIA_int_flags       =        0xD00D 
                    .globl   font5a_line1 
font5a_line1: 
                    .byte    0b00000000, 0b00001000, 0b00101000, 0b00101000, 0b00011110, 0b10010100, 0b01000000, 0b00001000, 0b00010000, 0b00001000, 0b00101010, 0b00001000 
                    .byte    0b00000000, 0b00000000, 0b00000000, 0b00000100, 0b00010100, 0b00011000, 0b00111100, 0b00111100, 0b00011000, 0b00111100, 0b00111100, 0b01111100 
                    .byte    0b00111100, 0b00111110, 0b00000000, 0b00000000, 0b00000110, 0b00000000, 0b01100000, 0b00111000, 0b00111100, 0b00011000, 0b01110000, 0b00111000 
                    .byte    0b01111000, 0b01111100, 0b01111000, 0b01111100, 0b01000010, 0b00111110, 0b00011100, 0b01001000, 0b01000000, 0b01100110, 0b01100010, 0b00011100 
                    .byte    0b01111000, 0b00011100, 0b01111000, 0b00011100, 0b00111110, 0b01000010, 0b01000010, 0b01000010, 0b01000010, 0b00100010, 0b01111110, 0b00111000 
                    .byte    0b00100000, 0b00111000, 0b00010000, 0b00000000, 0b00001000, 0b00111100, 0b01000000, 0b00000000, 0b00000010, 0b00111100, 0b00011000, 0b00110100 
                    .byte    0b00100000, 0b00001000, 0b00001000, 0b00100000, 0b00010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00011100 
                    .byte    0b00010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00011000, 0b00001000, 0b00011000, 0b00000000, 0b01100000 
                    .globl   font5a_line2 
font5a_line2: 
                    .byte    0b00000000, 0b00001000, 0b00000000, 0b01111100, 0b00101000, 0b01101000, 0b01000000, 0b00000000, 0b00100000, 0b00000100, 0b00011100, 0b00001000 
                    .byte    0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00100010, 0b00001000, 0b01000010, 0b01000010, 0b00101000, 0b01000000, 0b01000000, 0b00001000, 0b01000010 
                    .byte    0b01000010, 0b00001000, 0b00001000, 0b00011000, 0b01111110, 0b00011000, 0b01000100, 0b01000100, 0b00100100, 0b01001000, 0b01000100, 0b01000100, 0b01000000 
                    .byte    0b01000000, 0b10000000, 0b01000010, 0b00001000, 0b00000100, 0b01010000, 0b01000000, 0b01011010, 0b01010010, 0b00100010, 0b01000100, 0b00100010, 0b01000100 
                    .byte    0b00100000, 0b00001000, 0b01000010, 0b01000010, 0b01011010, 0b00100100, 0b00010100, 0b00000100, 0b00100000, 0b00010000, 0b00001000, 0b00101000, 0b00000000 
                    .byte    0b00001000, 0b00000010, 0b01111100, 0b00011100, 0b00111110, 0b01000010, 0b00010000, 0b01001100, 0b00111000, 0b00000000, 0b00000000, 0b00100100, 0b00010000 
                    .byte    0b01100110, 0b00101110, 0b00111100, 0b01111100, 0b00111110, 0b00101100, 0b00100000, 0b00111100, 0b00100010, 0b01000010, 0b10000010, 0b01000010, 0b01000010 
                    .byte    0b00111100, 0b00010000, 0b00001000, 0b00001000, 0b00000000, 0b01100000 
                    .byte    0b00000000, 0b00001000, 0b00000000, 0b00101000, 0b00011100, 0b00010100, 0b00110010, 0b00000000, 0b00100000, 0b00000100, 0b00111110, 0b00111110 
                    .byte    0b00000000, 0b00111100, 0b00000000, 0b00010000, 0b00100010, 0b00001000, 0b00011100, 0b00001100, 0b01001000, 0b00111100, 0b01111110, 0b00010000, 0b00111100 
                    .byte    0b00111110, 0b00000000, 0b00000000, 0b01100000, 0b00000000, 0b00000110, 0b00011000, 0b10011100, 0b00111100, 0b01111000, 0b10000000, 0b01000100, 0b01110000 
                    .byte    0b01110000, 0b10011100, 0b01111110, 0b00001000, 0b00000100, 0b01110000, 0b01000000, 0b01011010, 0b01001010, 0b00100010, 0b01111000, 0b00101010, 0b01101000 
                    .byte    0b00011100, 0b00001000, 0b01000010, 0b00100100, 0b01011010, 0b00011000, 0b00001000, 0b00011000, 0b00100000, 0b00001000, 0b00001000, 0b00000000, 0b00000000 
                    .byte    0b00000000, 0b00111110, 0b01000010, 0b00100000, 0b01000010, 0b01111110, 0b00111000, 0b00110100, 0b00100100, 0b00001000, 0b00001000, 0b00101000, 0b00010000 
                    .byte    0b01011010, 0b00110010, 0b01000010, 0b01000010, 0b01000010, 0b00110010, 0b00011000, 0b00010000, 0b00100010, 0b01000010, 0b10000010, 0b00101100, 0b00110100 
                    .byte    0b00001000, 0b00100000, 0b00001000, 0b00000100, 0b00110010, 0b01110000 
                    .byte    0b00000000, 0b00000000, 0b00000000, 0b01111100, 0b00001010, 0b00101010, 0b01001100, 0b00000000, 0b00100000, 0b00000100, 0b00011100, 0b00001000 
                    .byte    0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b00100010, 0b00001000, 0b00100000, 0b01000010, 0b01111100, 0b00000010, 0b01000010, 0b00100000, 0b01000010 
                    .byte    0b00000010, 0b00000000, 0b00001000, 0b00011000, 0b01111110, 0b00011000, 0b00000000, 0b10010100, 0b01000010, 0b01000100, 0b01000100, 0b01000100, 0b01000000 
                    .byte    0b01000000, 0b10000100, 0b01000010, 0b00001000, 0b01000100, 0b01001000, 0b01000000, 0b01000010, 0b01000110, 0b00100010, 0b01000000, 0b00100110, 0b01011000 
                    .byte    0b00000010, 0b00001000, 0b01000010, 0b00100100, 0b01100110, 0b00100100, 0b00001000, 0b00100000, 0b00100000, 0b00000100, 0b00001000, 0b00000000, 0b00000000 
                    .byte    0b00000000, 0b01000110, 0b01100010, 0b00100000, 0b01000110, 0b01000000, 0b00010000, 0b00000100, 0b00100100, 0b00001000, 0b00101000, 0b00110000, 0b00010000 
                    .byte    0b01000010, 0b00100010, 0b01000010, 0b01111100, 0b00111110, 0b00100000, 0b00000100, 0b00010000, 0b00100110, 0b00100100, 0b01010100, 0b00110100, 0b00001000 
                    .byte    0b00010000, 0b00010000, 0b00001000, 0b00001000, 0b01001100, 0b01101000 
                    .byte    0b00000000, 0b00001000, 0b00000000, 0b00101000, 0b00111100, 0b00000100, 0b00110010, 0b00000000, 0b00010000, 0b00001000, 0b00101010, 0b00001000 
                    .byte    0b00001000, 0b00000000, 0b00001000, 0b01000000, 0b00010100, 0b00011100, 0b01111110, 0b00111100, 0b00001000, 0b00111100, 0b00111100, 0b01000000, 0b00111100 
                    .byte    0b00111100, 0b00001000, 0b00010000, 0b00000110, 0b00000000, 0b01100000, 0b00010000, 0b01011100, 0b01000010, 0b01111000, 0b00111000, 0b01111000, 0b01111100 
                    .byte    0b01000000, 0b01111000, 0b01000010, 0b00111110, 0b00111000, 0b01000100, 0b01111100, 0b01000010, 0b01000010, 0b00011100, 0b01000000, 0b00011100, 0b01000100 
                    .byte    0b00011100, 0b00001000, 0b00111100, 0b00011000, 0b01000010, 0b01000010, 0b00001000, 0b01111110, 0b00111000, 0b00000010, 0b00111000, 0b00000000, 0b01111110 
                    .byte    0b00000000, 0b00111010, 0b01011100, 0b00011100, 0b00111010, 0b00111100, 0b00010000, 0b00011100, 0b00100100, 0b00001000, 0b00011000, 0b00101100, 0b00011000 
                    .byte    0b01000010, 0b00100010, 0b00111100, 0b01000000, 0b00000010, 0b00100000, 0b00111000, 0b00011000, 0b00011010, 0b00011000, 0b01101100, 0b01000010, 0b00001000 
                    .byte    0b00111100, 0b00011000, 0b00001000, 0b00011000, 0b00000000, 0b01100000 
FONT_HEIGHT         =        5 
FONT_LENGTH         =        ((font5a_line2-font5a_line1)) 
FONT_START_A        =        font5a_line1 - 32            ;' ' ; // space is 1 
FONT_END            =        FONT_START_A+(FONT_HEIGHT-1)*FONT_LENGTH 
; bank 1 + 2 + 0 (from dodger)
; zero delay is needed for zeroing to work correctly
; depends on the distance of the current integrator position to actual zero point
; experiment with my vectri:
;ZERO ing the integrators takes time. Measures at my vectrex show e.g.:
;If you move the beam with a to x = -127 and y = -127 at diffferent scale values, the time to reach zero:
;- scale 0xff -> zero 110 cycles
;- scale 0x7f -> zero 75 cycles
;- scale 0x40 -> zero 57 cycles
;- scale 0x20 -> zero 53 cycles
ZERO_DELAY_P2       =        2                            ;2 ; delay 7 counter is exactly 111 cycles delay between zero SETTING and zero unsetting (in moveto_d) 
; Warning - direct line found!
;                    direct   0xd0 
;-----------------------------------------------------------------------;
;       F38A    Print_List                                              ;
;       F38C    Print_List_chk                                          ;
;                                                                       ;
; This displays the group of strings described by the parameter block   ;
; which is pointed to by the U register.  The string parameter block    ;
; has the following format:                                             ;
;                                                                       ;
;       rel y, rel x, string, 0x80,                                     ;
;       rel y, rel x, string, 0x80,                                     ;
;       0x00                                                            ;
;                                                                       ;
; The current string height and width to which the hardware is = will ;
; be used.                                                              ;
;                                                                       ;
; Print_List routine will first print the passed-in string, and THEN    ;
; check for the end of the string list.  Print_List_Chk will check for  ;
; the end of the string list first.                                     ;
;                                                                       ;
; ENTRY DP = 0xD0                                                        ;
;       U-reg points to string list                                     ;
;                                                                       ;
; EXIT: U-reg points to null terminator byte                            ;
;                                                                       ;
;       D-reg, X-reg trashed                                            ;
;-----------------------------------------------------------------------;
                    .setdp   0xd000,_DATA 
                    .globl   _syncPrintList 
                    .globl   syncPrintList 
_syncPrintList: 
syncPrintList: 
                    tfr      x,u 
syncPrintList2: 
                    LDD      ,U++ 
                    bsr      sync_Print_Str_d_int 
                    LDA      ,U 
                    BNE      syncPrintList2 
                    RTS      

                    .globl   _syncPrintStrd 
_syncPrintStrd: 
                    .globl   syncPrintStrd 
syncPrintStrd: 
                    .globl   sync_Print_Str_d 
sync_Print_Str_d: 
; put move position on stack put it so, that we can load "d" directly from stack
                    tfr      b,a 
                    ldb      2,s 
                    pshs     u 
                    tfr      x,u 
sync_Print_Str_d_int: 
                    pshs     d ,y 
                    STU      Vec_Str_Ptr                  ;Save string pointer 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; POSITION "EXACT" PATCH assuming x pos is midle alligned, 
; if that is a case we can use neg x pos as "opposite" string pos
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    ldd      #(0b10000010)*256+0xCC       ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
                    ldb      #ZERO_DELAY_P2               ; and wait for zeroing to be actually done 
; reset integrators
                    clr      *VIA_port_a                  ; reset integrator offset 
                                                          ; lda #%10000010 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a_2 
zeroLoop_a_2: 
                    sta      *VIA_port_b                  ; while waiting, zero offsets 
                    decb     
                    bne      zeroLoop_a_2 
                    inca     
                    sta      *VIA_port_b 
                    ldd      ,s 
                    negb     
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    LDX      #FONT_START_A -FONT_LENGTH   ;Point to start of chargen bitmaps 
                    ldb      Vec_Text_Width 
                    lda      #0x81 
                    lda      #0x01 
                    tfr      d,y 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D2_2 
LF33D2_2:            BITB     *VIA_int_flags               ; 
                    BEQ      LF33D2_2                      ; 
                    .globl   printsyncAgain 
printsyncAgain: 
; macro call ->                     NEXT_SYNC_LINE  
; zero
                    ldd      #(ZERO_DELAY_P2)*256+0xCC    ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a3 
zeroLoop_a3: 
                    nop      
                    nop      
                    deca     
                    bne      zeroLoop_a3 
                    ldd      ,s 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    dec      ,s                           ; can be done in move 
 dec      ,s 
                    LEAX     FONT_LENGTH,X                ;[3]Point to next chargen row 
                    lda      #0x18 
                    LDU      Vec_Str_Ptr                  ;Point to start of text string 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D55 
LF33D55:            BITB     *VIA_int_flags               ; 
                    BEQ      LF33D55                      ; 
                    STA      *VIA_aux_cntl                ;Shift reg mode = 110 (shift out under system clock), T1 PB7 disabled, one shot mode 
                                                          ; first entry here, ramp is disabled 
                                                          ; if there was a jump from below 
                                                          ; ramp will be enabled by next line 
                    LDD      #0x0080                      ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
                    sta      *VIA_port_a                  ;Clear D/A output 
                    STb      *VIA_port_b                  ;Enable mux 
; TO FAST EXAMPLE!!! (cranky)
;                    LDD      #0x8000                       ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
; std <VIA_port_b
                    sty      *VIA_port_b 
; assuming first char is NEVER 0x80
                    LDb      ,U+                          ;[+6]Get next character 
; one letter is drawn (one row that is) in 18 cycles
; 13 cycles overhead
; ramp is thus active for #ofLetters*18 + 13 cycles
                    .globl   LF4C7_a3 
LF4C7_a3: 
                    LDb      b,X                          ;[+5]Get bitmap from chargen table 
                    STb      *VIA_shift_reg               ;[+4]rasterout of char bitmap "row" thru shift out in shift register 
                    .globl   LF4CB_a3 
LF4CB_a3: 
                    LDb      ,U+                          ;[+6]Get next character 
                    BPL      LF4C7_a3                     ;[+3]Go back if not terminator 
                    STa      *VIA_port_b                  ; is still 0x80 ;[4]disable RAMP, disable mux don't matter 
                    LDA      #0x98 
                    STA      *VIA_aux_cntl                ;T1?PB7 enabled 
; macro call ->                     NEXT_SYNC_LINE  
; zero
                    ldd      #(ZERO_DELAY_P2)*256+0xCC    ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a6 
zeroLoop_a6: 
                    nop      
                    nop      
                    deca     
                    bne      zeroLoop_a6 
                    ldd      ,s 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    dec      ,s                           ; can be done in move 
 dec      ,s 
                    LEAX     FONT_LENGTH,X                ;[3]Point to next chargen row 
                    lda      #0x18 
                    LDU      Vec_Str_Ptr                  ;Point to start of text string 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D88 
LF33D88:            BITB     *VIA_int_flags               ; 
                    BEQ      LF33D88                      ; 
                    STA      *VIA_aux_cntl                ;Shift reg mode = 110 (shift out under system clock), T1 PB7 disabled, one shot mode 
                                                          ; first entry here, ramp is disabled 
                                                          ; if there was a jump from below 
                                                          ; ramp will be enabled by next line 
                    LDD      #0x0080                      ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
                    sta      *VIA_port_a                  ;Clear D/A output 
                    STb      *VIA_port_b                  ;Enable mux 
; TO FAST EXAMPLE!!! (cranky)
;                    LDD      #0x8000                       ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
; std <VIA_port_b
                    sty      *VIA_port_b 
; assuming first char is NEVER 0x80
                    LDb      ,U+                          ;[+6]Get next character 
; one letter is drawn (one row that is) in 18 cycles
; 13 cycles overhead
; ramp is thus active for #ofLetters*18 + 13 cycles
                    .globl   LF4C7_a6 
LF4C7_a6: 
                    LDb      b,X                          ;[+5]Get bitmap from chargen table 
                    STb      *VIA_shift_reg               ;[+4]rasterout of char bitmap "row" thru shift out in shift register 
                    .globl   LF4CB_a6 
LF4CB_a6: 
                    LDb      ,U+                          ;[+6]Get next character 
                    BPL      LF4C7_a6                     ;[+3]Go back if not terminator 
                    STa      *VIA_port_b                  ; is still 0x80 ;[4]disable RAMP, disable mux don't matter 
                    LDA      #0x98 
                    STA      *VIA_aux_cntl                ;T1?PB7 enabled 
; macro call ->                     NEXT_SYNC_LINE  
; zero
                    ldd      #(ZERO_DELAY_P2)*256+0xCC    ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a9 
zeroLoop_a9: 
                    nop      
                    nop      
                    deca     
                    bne      zeroLoop_a9 
                    ldd      ,s 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    dec      ,s                           ; can be done in move 
 dec      ,s 

                    LEAX     FONT_LENGTH,X                ;[3]Point to next chargen row 
                    lda      #0x18 
                    LDU      Vec_Str_Ptr                  ;Point to start of text string 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D1111 
LF33D1111:          BITB     *VIA_int_flags               ; 
                    BEQ      LF33D1111                    ; 
                    STA      *VIA_aux_cntl                ;Shift reg mode = 110 (shift out under system clock), T1 PB7 disabled, one shot mode 
                                                          ; first entry here, ramp is disabled 
                                                          ; if there was a jump from below 
                                                          ; ramp will be enabled by next line 
                    LDD      #0x0080                      ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
                    sta      *VIA_port_a                  ;Clear D/A output 
                    STb      *VIA_port_b                  ;Enable mux 
; TO FAST EXAMPLE!!! (cranky)
;                    LDD      #0x8000                       ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
; std <VIA_port_b
                    sty      *VIA_port_b 
; assuming first char is NEVER 0x80
                    LDb      ,U+                          ;[+6]Get next character 
; one letter is drawn (one row that is) in 18 cycles
; 13 cycles overhead
; ramp is thus active for #ofLetters*18 + 13 cycles
                    .globl   LF4C7_a9 
LF4C7_a9: 
                    LDb      b,X                          ;[+5]Get bitmap from chargen table 
                    STb      *VIA_shift_reg               ;[+4]rasterout of char bitmap "row" thru shift out in shift register 
                    .globl   LF4CB_a9 
LF4CB_a9: 
                    LDb      ,U+                          ;[+6]Get next character 
                    BPL      LF4C7_a9                     ;[+3]Go back if not terminator 
                    STa      *VIA_port_b                  ; is still 0x80 ;[4]disable RAMP, disable mux don't matter 
                    LDA      #0x98 
                    STA      *VIA_aux_cntl                ;T1?PB7 enabled 
; macro call ->                     NEXT_SYNC_LINE  
; zero
                    ldd      #(ZERO_DELAY_P2)*256+0xCC    ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a12 
zeroLoop_a12: 
                    nop      
                    nop      
                    deca     
                    bne      zeroLoop_a12 
                    ldd      ,s 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    dec      ,s                           ; can be done in move 
 dec      ,s 

                    LEAX     FONT_LENGTH,X                ;[3]Point to next chargen row 
                    lda      #0x18 
                    LDU      Vec_Str_Ptr                  ;Point to start of text string 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D1414 
LF33D1414:          BITB     *VIA_int_flags               ; 
                    BEQ      LF33D1414                    ; 
                    STA      *VIA_aux_cntl                ;Shift reg mode = 110 (shift out under system clock), T1 PB7 disabled, one shot mode 
                                                          ; first entry here, ramp is disabled 
                                                          ; if there was a jump from below 
                                                          ; ramp will be enabled by next line 
                    LDD      #0x0080                      ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
                    sta      *VIA_port_a                  ;Clear D/A output 
                    STb      *VIA_port_b                  ;Enable mux 
; TO FAST EXAMPLE!!! (cranky)
;                    LDD      #0x8000                       ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
; std <VIA_port_b
                    sty      *VIA_port_b 
; assuming first char is NEVER 0x80
                    LDb      ,U+                          ;[+6]Get next character 
; one letter is drawn (one row that is) in 18 cycles
; 13 cycles overhead
; ramp is thus active for #ofLetters*18 + 13 cycles
                    .globl   LF4C7_a12 
LF4C7_a12: 
                    LDb      b,X                          ;[+5]Get bitmap from chargen table 
                    STb      *VIA_shift_reg               ;[+4]rasterout of char bitmap "row" thru shift out in shift register 
                    .globl   LF4CB_a12 
LF4CB_a12: 
                    LDb      ,U+                          ;[+6]Get next character 
                    BPL      LF4C7_a12                    ;[+3]Go back if not terminator 
                    STa      *VIA_port_b                  ; is still 0x80 ;[4]disable RAMP, disable mux don't matter 
                    LDA      #0x98 
                    STA      *VIA_aux_cntl                ;T1?PB7 enabled 
; zero
                    ldd      #(ZERO_DELAY_P2)*256+0xCC    ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
; wait that zeroing surely has the desired effect!
                    .globl   zeroLoop_a 
zeroLoop_a: 
                    nop      
                    nop      
                    deca     
                    bne      zeroLoop_a 
                    ldd      ,s 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    LEAX     FONT_LENGTH,X                ;[3]Point to next chargen row 
                    lda      #0x18 
                    LDU      Vec_Str_Ptr                  ;Point to start of text string 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDB      #0x40                        ; 
                    .globl   LF33D1616 
LF33D1616:          BITB     *VIA_int_flags               ; 
                    BEQ      LF33D1616                    ; 
                    STA      *VIA_aux_cntl                ;Shift reg mode = 110 (shift out under system clock), T1 PB7 disabled, one shot mode 
                                                          ; first entry here, ramp is disabled 
                                                          ; if there was a jump from below 
                                                          ; ramp will be enabled by next line 
                    LDD      #0x0080                      ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
                    sta      *VIA_port_a                  ;Clear D/A output 
                    STb      *VIA_port_b                  ;Enable mux 
; TO FAST EXAMPLE!!!
; texts have different angles!
;                    LDD      #0x8000                       ;a?AUX: b?ORB: 0x8x = Disable RAMP, Disable Mux, mux sel = 01 (int offsets) 
; std <VIA_port_b
                    sty      *VIA_port_b 
; assuming first character in a string is never 0x80
                    LDA      ,U+                          ;[+6]Get next character 
; one letter is drawn (one row that is) in 18 cycles
; 13 cycles overhead
; ramp is thus active for #ofLetters*18 + 13 cycles
                    .globl   LF4C7_a 
LF4C7_a: 
                    LDA      A,X                          ;[+5]Get bitmap from chargen table 
                    STA      *VIA_shift_reg               ;[+4]rasterout of char bitmap "row" thru shift out in shift register 
                    .globl   LF4CB_a 
LF4CB_a: 
                    LDA      ,U+                          ;[+6]Get next character 
                    BPL      LF4C7_a                      ;[+3]Go back if not terminator 
                    STb      *VIA_port_b                  ; is still 0x81 ;[4]disable RAMP, disable mux 
                    ldd      #0x98 
                    std      *VIA_shift_reg 
;                    sta      <VIA_shift_reg 
;                    STb      <VIA_aux_cntl                ;T1?PB7 enabled 
                    puls     y, d                         ; all done, correct stack 
                    puls     u,pc 
