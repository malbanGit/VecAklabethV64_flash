 .module veccyasm.pre.s
 .area .text

SPRITE_SCALE        =        20;0x0d; 80 highest possible value
SHITREG_POKE_VALUE  =        0x01 


; PC not usable :-)

; cmpx #4
; pshs d,y,x,pc,u,cc;16
; puls d,y,x,pc,u,cc; 16
; pshs y,x,pc,u,d;15
; puls y,x,pc,u,d; 15
; pshs y,x,pc,u,cc;14
; puls y,x,pc,u,cc; 14
; pshs a,x,pc,u,cc;13
; puls a,x,pc,u,cc;13
; pshs x,pc,u,cc;12
; puls x,pc,u,cc;12
; pshs pc,u,d;11
; puls pc,u,d;11
; pshs pc,u,cc;10
; puls pc,u,cc;10
; pshs u,d;9
; puls u,d;9
; pshs u,cc;8
; puls u,cc;8
; pshs u;7
; puls u;7
; pshs cc;6
; puls cc;6
; tfr a,a; 6
; brn 0; 3
; NOP ; 2


 

;/* HIGHEST SCALE FOR SMARTLIST + CONTINUE is 16!

;***************************************************************************
; DEFINE SECTION
;***************************************************************************
Vec_Pattern         =      0xC829                        ;Dot pattern (bits) 
music1              =      0xFD0D 
VIA_port_b          =      0xD000                        ;VIA port B data I/O register 
VIA_port_a          =      0xD001                        ;VIA port A data I/O register (handshaking) 
VIA_t1_cnt_lo       =      0xD004                        ;VIA timer 1 count register lo (scale factor) 
VIA_t1_cnt_hi       =      0xD005                        ;VIA timer 1 count register hi 
VIA_shift_reg       =      0xD00A                        ;VIA shift register 
VIA_cntl            =      0xD00C                        ;VIA control register 
VIA_int_flags       =      0xD00D                        ;VIA interrupt flags register 
Intensity_5F        =      0xF2A5                        ; 
Wait_Recal          =      0xF192                        ; 
Moveto_d            =      0xF312                        ; 
Vec_Joy_1_X         =      0xC81B                        ;Joystick 1 left/right 
Joy_Digital         =      0xF1F8 
;***************************************************************************
; HEADER SECTION
;***************************************************************************
; The cartridge ROM starts at address 0
                    .area .text     

;***************************************************************************
; ROUTINE SECTION
;***************************************************************************
; Warning - direct line found!
;                    direct   0xd0 
;***************************************************************************


; for scale 7 
; we need WAIT6 after a poke to hi
; followd directly by a set_y_int
; todo 
; last draw could contain 0xF in A
; than load not needed - attention 
; when cycles are not done for load, than shift value might be needed 2 higher!
; also in X could be some sensible value in X for one of the other 
;SMVB_lastDraw_rts2                                ;#isfunction  
; list format
; y pos byte -> REG A
; VIA_B for x reg = 01 *256 + x pos byte -> REG X
; pointer to draw function -> PC
; 5 bytes per "position" (except continuous)
; reg A must be constantly == 0!
; opti finding
; a)  Findings T1 can be 2 cycles "off" -> smartlist max scale of "optimium" reduced from 9 to 7 scale :-(
; b ) y and z sampling need up to 4 cycles to bare fruit (poke b reg)
;     90% vectrex (guess) need 0 cycles
;     95% vectrex are content with 2 cycles (1 nop)
;     some few vectrex NEED 4 cycles!!! ARGH!
; c)  std to reg b of via (Y Reg) does not always / everywhere work
;
;
; delays needed for 5% of vectrex
; cost on a "full" screen
; about 2000 cycles
;VECTREX_SAVE_DELAY  =        1 
SHITREG_POKE_VALUE  =        0x01 




;

;
  
                    .setdp   0xd000,_DATA 



VB_SPRITE_SCALE     =        SPRITE_SCALE 
; NOPS add one less, since PULL X is one cycle more than pull a!
;***************************************************************************
 .globl _Draw_VLp_lessGap
_Draw_VLp_lessGap:
 pshs u
; macro call ->  Draw_VLp_lessGap
                    LDD      1,X                          ;Get next coordinate pair 
                    STA      *VIA_port_a                  ;Send Y to A/D 
                    CLR      *VIA_port_b                  ;Enable mux 
                    LDA      ,X                           ;Get pattern byte 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Send X to A/D 
                    ldb      #0 
                    STA      *VIA_shift_reg               ;Store pattern in shift register 
                    STB      *VIA_t1_cnt_hi               ;Clear T1H 
                    LDA      #0x40                         ;B-reg = T1 interrupt bit 
; 0 is ok
;
                    LEAX     3,X                          ;Advance to next point in list 
 .globl LF425_lg_11
LF425_lg_11: 
                    BITA     VIA_int_flags               ;Wait for T1 to time out 
                    BEQ      LF425_lg_11 
                    LDA      ,X                           ;Get next pattern byte 
                    bgt      macroEnd1 
 .globl Draw_VLp_lessGap_11
Draw_VLp_lessGap_11: 
                    STB      *VIA_shift_reg               ;Clear shift register (blank output) 
                    LDD      1,X                          ;Get next coordinate pair 
                    STA      *VIA_port_a                  ;Send Y to A/D 
                    CLR      *VIA_port_b                  ;Enable mux 
                    LDA      ,X                           ;Get pattern byte 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Send X to A/D 
                    ldb      #0 
                    STA      *VIA_shift_reg               ;Store pattern in shift register 
                    STB      *VIA_t1_cnt_hi               ;Clear T1H 
                    LDA      #0x40                         ;B-reg = T1 interrupt bit 
; 0 is ok
;
                    LEAX     3,X                          ;Advance to next point in list 
 .globl LF425_lg1
LF425_lg1: 
                    BITA     VIA_int_flags               ;Wait for T1 to time out 
                    BEQ      LF425_lg1 
                    LDA      ,X                           ;Get next pattern byte 
                    BLE      Draw_VLp_lessGap_11         ;Go back if high bit of pattern is set 
 .globl macroEnd1
macroEnd1: 
                    STB      *VIA_shift_reg               ;Clear shift register (blank output) 
                    puls     u,pc 

ZERO_DELAY          =      1                            ; delay 7 counter is exactly 111 cycles delay between zero SETTING and zero unsetting (in moveto_d) 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;U = address of vectorlist
;X = (y,x) position of vectorlist (this will be point 0,0), positioning on screen
;A = scalefactor "Move" (after sync)
;B = scalefactor "Vector" (vectors in vectorlist)
;
;     mode, rel y, rel x,                                             
;     mode, rel y, rel x,                                             
;     .      .      .                                                
;     .      .      .                                                
;     mode, rel y, rel x,                                             
;     0x02
; where mode has the following meaning:         
; negative draw line                    
; 0 move to specified endpoint                              
; 1 sync (and move to list start and than to place in vectorlist)      
; 2 end
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 .globl _draw_synced_list
_draw_synced_list: 





draw_synced_list2: 
                    pshs     u 
                    lda      2+2,s                        ; calling from C 
                    ldu      3+2,s                        ; than parameters are on stack 
                    sta      *VIA_t1_cnt_lo               ; to timer t1 (lo= 
                                                          ; first list entry (first will be a sync + moveto_d, so we just stay here!) 
                    lda      ,u+                          ; this will be a "1" 
                    bra      sync 

 .globl nextIsSyncTo
nextIsSyncTo: 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                         ; 
 .globl LF33D11
LF33D11:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D11                      ; 
 .globl sync
sync: 
; zero integrators
                    ldb      #0xCC                         ; zero the integrators 
                    stb      *VIA_cntl                    ; store zeroing values to cntl 
                    clr      *VIA_port_a                  ; reset integrator offset 
                    ldb      #0b10000010 
                    stb      *VIA_port_b                  ; while waiting, zero offsets 
                    deca                                  ; test if real sync - or end of list (2) 
                    bne      drawdone                     ; if end of list -> jump 
                    inc      *VIA_port_b 
                    tfr      x,d                          ; load our coordinates of "entry" of vectorlist 
;                    MY_MOVE_TO_D_START  
; we know B = 0
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                         ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
;                    CLRA     
                    STB      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
 nop ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STB      *VIA_t1_cnt_hi               ;enable timer 


 .globl nextIsMoveTo
nextIsMoveTo: 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                         ; 
 .globl LF33D22
LF33D22:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D22                      ; 
 .globl moveTo
moveTo: 
                    ldd      ,u                           ; do our "internal" moveto d 
; macro call ->                     MY_MOVE_TO_D_START  
                    STA      *VIA_port_a                  ;Store Y in D/A register 
                    LDA      #0xCE                         ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
                    CLRA     
                    STA      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
 nop ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STA      *VIA_t1_cnt_hi               ;enable timer 
                    leau     2,u 
                    lda      ,u+                          ; load next "mode" byte 
                    beq      nextIsMoveTo                 ; if 0, than we should move somewhere 
                    bpl      nextIsSyncTo                 ; if still positive it is a 1 pr 2 _> goto sync 

                    lda      ,u+                           ;Get next coordinate pair 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                         ; 
 .globl LF33D44
LF33D44:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D44                      ; 
 .globl nextListEntry
nextListEntry: 
; now we should draw a vector 
                    STA      *VIA_port_a                  ;Send Y to A/D 
                    LDD      #0x0001                           ;Get pattern byte 
                    STA      *VIA_port_b                  ;Enable mux 
 nop 
                    STB      *VIA_port_b                  ;Disable mux 
                    ldb      ,u                           ;Get next coordinate pair 
                    STB      *VIA_port_a                  ;Send X to A/D 
                    DEC      *VIA_shift_reg               ;Store pattern in shift register 
                    STA      *VIA_t1_cnt_hi               ;Clear T1H 
                    LDB      #0x40                         ;B-reg = T1 interrupt bit 
                    leau     1,u 
                    lda      ,u+                          ; load next "mode" byte 
                    beq      nextIsMove 
                    bpl      nextIsSync 
                    lda      ,u+                           ;Get next coordinate pair 
 .globl setPatternLoop
setPatternLoop: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop               ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      nextListEntry 

 .globl nextIsMove
nextIsMove: 
 .globl setPatternLoop2
setPatternLoop2: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop2              ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      moveTo 

 .globl nextIsSync
nextIsSync: 
 .globl setPatternLoop3
setPatternLoop3: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop3              ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      sync 

 .globl drawdone
drawdone: 
                    puls     u                            ; correct stack and go back 
                    rts      
