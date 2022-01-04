                    .module  veccyasm.pre.s 
                    .area    .text 
SPRITE_SCALE        =        20                           ;0x0d; 80 highest possible value 
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
Vec_Pattern         =        0xC829                       ;Dot pattern (bits) 
music1              =        0xFD0D 
VIA_port_b          =        0xD000                       ;VIA port B data I/O register 
VIA_port_a          =        0xD001                       ;VIA port A data I/O register (handshaking) 
VIA_t1_cnt_lo       =        0xD004                       ;VIA timer 1 count register lo (scale factor) 
VIA_t1_cnt_hi       =        0xD005                       ;VIA timer 1 count register hi 
VIA_shift_reg       =        0xD00A                       ;VIA shift register 
VIA_cntl            =        0xD00C                       ;VIA control register 
VIA_int_flags       =        0xD00D                       ;VIA interrupt flags register 
Intensity_5F        =        0xF2A5                       ; 
Wait_Recal          =        0xF192                       ; 
Moveto_d            =        0xF312                       ; 
Vec_Joy_1_X         =        0xC81B                       ;Joystick 1 left/right 
Joy_Digital         =        0xF1F8 
;***************************************************************************
; HEADER SECTION
;***************************************************************************
; The cartridge ROM starts at address 0
                    .area    .text 
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

                    .globl   _drawAkalabeth 
_drawAkalabeth: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_AkaList
                    clra     
                    pulu     b,x,pc 

                    .globl   _drawMountain 
_drawMountain: 
                    pshs     u 
                    ldu      #_SM_MountainList 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTown 
_drawTown: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_TownList 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTree 
_drawTree: 
                    pshs     u 
                    ldu      #_SM_TreeList 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawCastle 
_drawCastle: 
                    pshs     u 
                    ldu      #_SM_CastleList 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawDungeon 
_drawDungeon: 
                    pshs     u 
                    ldu      #_SM_DungeonList 
                    clra     
                    pulu     b,x,pc 


                    .globl   _drawMountain3 
_drawMountain3: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_MountainList3 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTown3 
_drawTown3: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_TownList3 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTree3 
_drawTree3: 
                    pshs     u 
                    ldu      #_SM_TreeList3 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawCastle3 
_drawCastle3: 
                    pshs     u 
                    ldu      #_SM_CastleList3 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawDungeon3 
_drawDungeon3: 
                    pshs     u 
                    ldu      #_SM_DungeonList3
                    clra     
                    pulu     b,x,pc 



                    .globl   _drawMan7 
_drawMan7: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_Man7 
                    clra     
                    pulu     b,x,pc 






                    .globl   _drawMountainA 
_drawMountainA: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_MountainListA 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTownA 
_drawTownA: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_TownListA
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTreeA 
_drawTreeA: 
                    pshs     u 
                    ldu      #_SM_TreeListA 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawCastleA 
_drawCastleA: 
                    pshs     u 
                    ldu      #_SM_CastleListA
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawDungeonA 
_drawDungeonA: 
                    pshs     u 
                    ldu      #_SM_DungeonListA
                    clra     
                    pulu     b,x,pc 






                    .globl   _drawMountain3A 
_drawMountain3A: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_MountainList3A 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTown3A 
_drawTown3A: 
                                                          ;#isfunction 
                    pshs     u 
                    ldu      #_SM_TownList3A
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawTree3A 
_drawTree3A: 
                    pshs     u 
                    ldu      #_SM_TreeList3A 
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawCastle3A 
_drawCastle3A: 
                    pshs     u 
                    ldu      #_SM_CastleList3A
                    clra     
                    pulu     b,x,pc 
                    .globl   _drawDungeon3A 
_drawDungeon3A: 
                    pshs     u 
                    ldu      #_SM_DungeonList3A
                    clra     
                    pulu     b,x,pc 


                    .globl   _Draw_VLp_lessGap 
_Draw_VLp_lessGap: 
                    pshs     u 
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
                    LDA      #0x40                        ;B-reg = T1 interrupt bit 
; 0 is ok
;
                    LEAX     3,X                          ;Advance to next point in list 
                    .globl   LF425_lg_11 
LF425_lg_11: 
                    BITA     VIA_int_flags                ;Wait for T1 to time out 
                    BEQ      LF425_lg_11 
                    LDA      ,X                           ;Get next pattern byte 
                    bgt      macroEnd1 
                    .globl   Draw_VLp_lessGap_11 
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
                    LDA      #0x40                        ;B-reg = T1 interrupt bit 
; 0 is ok
;
                    LEAX     3,X                          ;Advance to next point in list 
                    .globl   LF425_lg1 
LF425_lg1: 
                    BITA     VIA_int_flags                ;Wait for T1 to time out 
                    BEQ      LF425_lg1 
                    LDA      ,X                           ;Get next pattern byte 
                    BLE      Draw_VLp_lessGap_11          ;Go back if high bit of pattern is set 
                    .globl   macroEnd1 
macroEnd1: 
                    STB      *VIA_shift_reg               ;Clear shift register (blank output) 
                    puls     u,pc 
ZERO_DELAY          =        1                            ; delay 7 counter is exactly 111 cycles delay between zero SETTING and zero unsetting (in moveto_d) 
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
                    .globl   _draw_synced_list 
_draw_synced_list: 
draw_synced_list2: 
                    pshs     u 
                    lda      2+2,s                        ; calling from C 
                    ldu      3+2,s                        ; than parameters are on stack 
                    sta      *VIA_t1_cnt_lo               ; to timer t1 (lo= 
                                                          ; first list entry (first will be a sync + moveto_d, so we just stay here!) 
                    lda      ,u+                          ; this will be a "1" 
                    bra      sync 

                    .globl   nextIsSyncTo 
nextIsSyncTo: 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                        ; 
                    .globl   LF33D11 
LF33D11:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D11                      ; 
                    .globl   sync 
sync: 
; zero integrators
                    ldb      #0xCC                        ; zero the integrators 
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
                    LDA      #0xCE                        ;Blank low, zero high? 
                    STA      *VIA_cntl                    ; 
;                    CLRA     
                    STB      *VIA_port_b                  ;Enable mux ; hey dis si "break integratorzero 440" 
                    nop                                   ; y must be set more than xx cycles on some vectrex 
                    INC      *VIA_port_b                  ;Disable mux 
                    STB      *VIA_port_a                  ;Store X in D/A register 
                    STB      *VIA_t1_cnt_hi               ;enable timer 
                    .globl   nextIsMoveTo 
nextIsMoveTo: 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                        ; 
                    .globl   LF33D22 
LF33D22:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D22                      ; 
                    .globl   moveTo 
moveTo: 
                    ldd      ,u                           ; do our "internal" moveto d 
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
                    leau     2,u 
                    lda      ,u+                          ; load next "mode" byte 
                    beq      nextIsMoveTo                 ; if 0, than we should move somewhere 
                    bpl      nextIsSyncTo                 ; if still positive it is a 1 pr 2 _> goto sync 
                    lda      ,u+                          ;Get next coordinate pair 
; macro call ->                     MY_MOVE_TO_B_END  
                    LDb      #0x40                        ; 
                    .globl   LF33D44 
LF33D44:            BITb     *VIA_int_flags               ; 
                    BEQ      LF33D44                      ; 
                    .globl   nextListEntry 
nextListEntry: 
; now we should draw a vector 
                    STA      *VIA_port_a                  ;Send Y to A/D 
                    LDD      #0x0001                      ;Get pattern byte 
                    STA      *VIA_port_b                  ;Enable mux 
                    nop      
                    STB      *VIA_port_b                  ;Disable mux 
                    ldb      ,u                           ;Get next coordinate pair 
                    STB      *VIA_port_a                  ;Send X to A/D 
                    DEC      *VIA_shift_reg               ;Store pattern in shift register 
                    STA      *VIA_t1_cnt_hi               ;Clear T1H 
                    LDB      #0x40                        ;B-reg = T1 interrupt bit 
                    leau     1,u 
                    lda      ,u+                          ; load next "mode" byte 
                    beq      nextIsMove 
                    bpl      nextIsSync 
                    lda      ,u+                          ;Get next coordinate pair 
                    .globl   setPatternLoop 
setPatternLoop: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop               ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      nextListEntry 

                    .globl   nextIsMove 
nextIsMove: 
                    .globl   setPatternLoop2 
setPatternLoop2: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop2              ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      moveTo 

                    .globl   nextIsSync 
nextIsSync: 
                    .globl   setPatternLoop3 
setPatternLoop3: 
                    BITB     *VIA_int_flags               ;Wait for T1 to time out 
                    beq      setPatternLoop3              ; wait till line is finished 
                    INC      *VIA_shift_reg               ; switch the light off (for sure) 
                    bra      sync 

                    .globl   drawdone 
drawdone: 
                    puls     u                            ; correct stack and go back 
                    rts      

                    .globl   _SM_MountainList 
_SM_MountainList: 
                    .byte    0x7B, 0x01, 0x4A 
                    .word    SMVB_continue_single 
                    .byte    -0x31, 0x01, 0x00 
                    .word    SMVB_startDraw_single 
                    .byte    0x00, 0x01, 0x31 
                    .word    SMVB_startMove_newY_eq_oldX_single ; y was 0x00, now 0 
                    .byte    SHITREG_POKE_VALUE, 0x01, -0x64 
                    .word    SMVB_startDraw_yStays_single ; y was 0x00, now SHIFT Poke 
                    .byte    -0x61, 0x01, 0x00 
                    .word    SMVB_continue_single 
                    .byte    0x00, 0x01, -0x2E 
                    .word    SMVB_startMove_newY_eq_oldX_single ; y was 0x00, now 0 
                    .byte    SHITREG_POKE_VALUE, 0x01, 0x61 
                    .word    SMVB_startDraw_yStays_single ; y was 0x00, now SHIFT Poke 
                    .byte    -0x64, 0x01, 0x00 
                    .word    SMVB_continue_single 
                    .byte    0x31, 0x01, 0x00 
                    .word    SMVB_startMove_single 
                    .byte    SHITREG_POKE_VALUE, 0x01, 0x31 
                    .word    SMVB_startDraw_newY_eq_oldX_single ; y was 0x00, now SHIFT 
                    .byte    0x00, 0x01, -0x7B 
                    .word    SMVB_startMove_double 
                    .byte    SHITREG_POKE_VALUE, 0x01, 0x31 
                    .word    SMVB_startDraw_yStays_single ; y was 0x00, now SHIFT Poke 
                    .byte    -0x31, 0x01, 0x00 
                    .word    SMVB_startMove_single 
                    .byte    0x31, 0x01, 0x00 
                    .word    SMVB_startDraw_single 
                    .byte    0x33, 0x01, 0x33 
                    .word    SMVB_continue4_single 
                    .byte    0x2E, 0x01, 0x00 
                    .byte    0x00, 0x01, -0x33 
                    .byte    0x64, 0x01, 0x00 
                    .byte    -0x31, 0x01, 0x00 
                    .word    SMVB_startMove_single 
                    .byte    SHITREG_POKE_VALUE, 0x01, -0x31 
                    .word    SMVB_startDraw_newY_eq_oldX_single ; y was 0x00, now SHIFT 
                    .byte    0x40, 0x00, 0x00 
                    .word    SMVB_lastDraw_rts_puls 
_SM_TownList: 
                    .byte    -0x31, 0x01, -0x31 
                    .word    SMVB_continue_yEqx_single    ; y is -0x31 
                    .byte    0x62, 0x01, 0x00 
                    .word    SMVB_startDraw_single 
                    .byte    0x00, 0x01, -0x4A 
                    .word    SMVB_continue7_single 
                    .byte    0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, 0x4A 
                    .byte    -0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, 0x62 
                    .byte    0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, 0x4A 
                    .byte    -0x4A, 0x01, 0x00 
                    .word    SMVB_continue7_single 
                    .byte    0x00, 0x01, -0x4A 
                    .byte    -0x62, 0x01, 0x00 
                    .byte    0x00, 0x01, 0x4A 
                    .byte    -0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, -0x4A 
                    .byte    0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, -0x62 
                    .word    SMVB_continue5_single 
                    .byte    -0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, -0x4A 
                    .byte    0x4A, 0x01, 0x00 
                    .byte    0x00, 0x01, 0x4A 
                    .byte    0x40, 0x00, 0x00 
                    .word    SMVB_lastDraw_rts_puls 
_SM_TreeList: 
                    .byte    -0x63, 0x01, -0x63 
                    .word    SMVB_continue_yEqx_single    ; y is -0x63 
                    .byte    0x63, 0x01, 0x00 
                    .word    SMVB_startDraw_double 
                    .byte    0x00, 0x01, 0x63 
                    .word    SMVB_continue_double 
                    .byte    -0x63, 0x01, 0x00 
                    .word    SMVB_continue_double 
                    .byte    0x00, 0x01, -0x63 
                    .word    SMVB_continue_double 
                    .byte    0x40, 0x00, 0x00 
                    .word    SMVB_lastDraw_rts_puls 
_SM_CastleList: 
                    .byte    -0x5E, 0x01, -0x5E 
                    .word    SMVB_continue_yEqx_single    ; y is -0x5E 
                    .byte    0x00, 0x01, 0x5E 
                    .word    SMVB_startDraw_double 
                    .byte    0x5E, 0x01, 0x00 
                    .word    SMVB_continue_double 
                    .byte    0x00, 0x01, -0x5E 
                    .word    SMVB_continue_double 
                    .byte    -0x5E, 0x01, 0x00 
                    .word    SMVB_continue_double 
                    .byte    0x27, 0x01, 0x27 
                    .word    SMVB_startMove_yEqx_single   ; y is 0x27 
                    .byte    0x00, 0x01, 0x6E 
                    .word    SMVB_startDraw_single 
                    .byte    0x00, 0x01, 0x00 
                    .word    SMVB_startMove_newY_eq_oldX_single ; y was 0x6E, now 0 
                    .byte    SHITREG_POKE_VALUE, 0x01, -0x6E 
                    .word    SMVB_startDraw_newY_eq_oldX_single ; y was 0x00, now SHIFT 
                    .byte    -0x6E, 0x01, 0x00 
                    .word    SMVB_continue4_single 
                    .byte    0x6E, 0x01, 0x6E 
                    .byte    -0x6E, 0x01, 0x00 
                    .byte    0x6E, 0x01, -0x6E 
                    .byte    0x40, 0x00, 0x00 
                    .word    SMVB_lastDraw_rts_puls 
_SM_DungeonList: 
                    .byte    -0x31, 0x01, 0x31 
                    .word    SMVB_continue_single 
                    .byte    0x62, 0x01, -0x62 
                    .word    SMVB_startDraw_single 
                    .byte    0x00, 0x01, 0x62 
                    .word    SMVB_startMove_single 
                    .byte    -0x62, 0x01, -0x62 
                    .word    SMVB_startDraw_yEqx_single   ; y is -0x62 
                    .byte    0x40, 0x00, 0x00 
                    .word    SMVB_lastDraw_rts_puls 


 .globl _SM_MountainList3
_SM_MountainList3:
	.byte  0x7A, 0x01,  0x49
	.word SMVB_continue_double
	.byte -0x62, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x62
	.word SMVB_startMove_newY_eq_oldX_single ; y was  0x00, now 0
	.byte  0x00, 0x01, -0x64
	.word SMVB_startDraw_double
	.byte -0x60, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01, -0x5A
	.word SMVB_startMove_newY_eq_oldX_single ; y was  0x00, now 0
	.byte  0x00, 0x01,  0x60
	.word SMVB_startDraw_double
	.byte -0x64, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x62, 0x01,  0x00
	.word SMVB_startMove_single
	.byte SHITREG_POKE_VALUE, 0x01,  0x62
	.word SMVB_startDraw_newY_eq_oldX_single ; y was  0x00, now SHIFT
	.byte  0x00, 0x01, -0x7A
	.word SMVB_startMove_quadro
	.byte  SHITREG_POKE_VALUE, 0x01,  0x62
	.word SMVB_startDraw_yStays_single; y was  0x00, now SHIFT Poke
	.byte -0x62, 0x01,  0x00
	.word SMVB_startMove_single
	.byte  0x62, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x66, 0x01,  0x66
	.word SMVB_continue3_single
	.byte  0x5A, 0x01,  0x00
	.byte  0x00, 0x01, -0x66
	.byte  0x64, 0x01,  0x00
	.word SMVB_continue_double
	.byte -0x62, 0x01,  0x00
	.word SMVB_startMove_single
	.byte SHITREG_POKE_VALUE, 0x01, -0x62
	.word SMVB_startDraw_newY_eq_oldX_single ; y was  0x00, now SHIFT
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_TownList3
_SM_TownList3:
	.byte -0x61, 0x01, -0x61
	.word SMVB_continue_yEqx_single; y is -0x61
	.byte  0x61, 0x01,  0x00
	.word SMVB_startDraw_double
	.byte  0x00, 0x01, -0x4A
	.word SMVB_continue_double
	.byte  0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x4A
	.word SMVB_continue_double
	.byte -0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x61
	.word SMVB_continue_double
	.byte  0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x4A
	.word SMVB_continue_double
	.byte -0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01, -0x4A
	.word SMVB_continue_double
	.byte -0x61, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x4A
	.word SMVB_continue_double
	.byte -0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01, -0x4A
	.word SMVB_continue_double
	.byte  0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01, -0x61
	.word SMVB_continue_double
	.byte -0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01, -0x4A
	.word SMVB_continue_double
	.byte  0x4A, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x4A
	.word SMVB_continue_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_TreeList3
_SM_TreeList3:
	.byte -0x62, 0x01, -0x62
	.word SMVB_continue_double
	.byte  0x62, 0x01,  0x00
	.word SMVB_startDraw_quadro
	.byte  0x00, 0x01,  0x62
	.word SMVB_continue_quadro
	.byte -0x62, 0x01,  0x00
	.word SMVB_continue_quadro
	.byte  0x00, 0x01, -0x62
	.word SMVB_continue_quadro
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_CastleList3
_SM_CastleList3:
	.byte -0x5D, 0x01, -0x5D
	.word SMVB_continue_double
	.byte  0x00, 0x01,  0x7C
	.word SMVB_startDraw_tripple
	.byte  0x7C, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte  0x00, 0x01, -0x7C
	.word SMVB_continue_tripple
	.byte -0x7C, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte  0x4E, 0x01,  0x4E
	.word SMVB_startMove_yEqx_single; y is  0x4E
	.byte  0x00, 0x01,  0x6D
	.word SMVB_startDraw_double
	.byte  0x6D, 0x01,  0x00
	.word SMVB_startMove_double
	.byte  0x00, 0x01, -0x6D
	.word SMVB_startDraw_double
	.byte -0x6D, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x6D, 0x01,  0x6D
	.word SMVB_continue_double
	.byte -0x6D, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x6D, 0x01, -0x6D
	.word SMVB_continue_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_DungeonList3
_SM_DungeonList3:
	.byte -0x61, 0x01,  0x61
	.word SMVB_continue_single
	.byte  0x61, 0x01, -0x61
	.word SMVB_startDraw_double
	.byte  0x00, 0x01,  0x61
	.word SMVB_startMove_double
	.byte -0x61, 0x01, -0x61
	.word SMVB_startDraw_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls


 .globl _SM_MountainListA
_SM_MountainListA:
	.byte -0x7A, 0x01, -0x7C
	.word SMVB_continue_single
	.byte  0x70, 0x01,  0x1E
	.word SMVB_startDraw_single
	.byte  0x75, 0x01,  0x51
	.word SMVB_continue_single
	.byte -0x62, 0x01,  0x13
	.word SMVB_continue_double
	.byte  0x47, 0x01, -0x0A
	.word SMVB_startMove_single
	.byte  0x23, 0x01,  0x23
	.word SMVB_startDraw_yEqx_single; y is  0x23
	.byte -0x26, 0x01,  0x2D
	.word SMVB_continue2_single
	.byte -0x68, 0x01,  0x1B
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_TownListA
_SM_TownListA:
	.byte -0x1E, 0x01, -0x42
	.word SMVB_continue_double
	.byte  0x33, 0x01,  0x2C
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x32
	.word SMVB_continue4_single
	.byte -0x3C, 0x01,  0x30
	.byte  0x14, 0x01, -0x4F
	.byte -0x0D, 0x01, -0x40
	.byte -0x03, 0x01,  0x0C
	.word SMVB_startMove_single
	.byte -0x3E, 0x01,  0x03
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x1E
	.word SMVB_startMove_single
	.byte  0x28, 0x01, -0x01
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x16
	.word SMVB_continue2_single
	.byte -0x29, 0x01,  0x00
	.byte  0x00, 0x01,  0x3E
	.word SMVB_startMove_newY_eq_oldX_single ; y was  0x00, now 0
	.byte  0x3D, 0x01, -0x06
	.word SMVB_startDraw_single
	.byte  0x18, 0x01,  0x74
	.word SMVB_startMove_single
	.byte -0x53, 0x01,  0x10
	.word SMVB_startDraw_single
	.byte -0x03, 0x01, -0x33
	.word SMVB_startMove_single
	.byte  0x29, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x00, 0x01, -0x16
	.word SMVB_continue2_single
	.byte -0x28, 0x01,  0x00
	.byte  0x00, 0x01, -0x23
	.word SMVB_startMove_newY_eq_oldX_single ; y was  0x00, now 0
	.byte  0x5C, 0x01,  0x0F
	.word SMVB_startDraw_single
	.byte  0x00, 0x01, -0x0F
	.word SMVB_startMove_single
	.byte  0x07, 0x01,  0x33
	.word SMVB_startDraw_single
	.byte -0x0C, 0x01,  0x37
	.word SMVB_continue4_single
	.byte  0x4A, 0x01, -0x14
	.byte  0x00, 0x01, -0x31
	.byte -0x46, 0x01, -0x24
	.byte  0x22, 0x01,  0x0F
	.word SMVB_startMove_single
	.byte  0x16, 0x01, -0x06
	.word SMVB_startDraw_single
	.byte  0x02, 0x01,  0x12
	.word SMVB_continue_single
	.byte  0x39, 0x01,  0x01
	.word SMVB_startMove_single
	.byte -0x14, 0x01, -0x04
	.word SMVB_startDraw_single
	.byte -0x15, 0x01, -0x0C
	.word SMVB_startMove_single
	.byte  0x1D, 0x01, -0x04
	.word SMVB_startDraw_single
	.byte  0x09, 0x01,  0x06
	.word SMVB_startMove_single
	.byte  0x1D, 0x01,  0x02
	.word SMVB_startDraw_single
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_TreeListA
_SM_TreeListA:
	.byte  0x12, 0x01, -0x01
	.word SMVB_continue_single
	.byte -0x11, 0x01,  0x35
	.word SMVB_startDraw_single
	.byte  0x6C, 0x01, -0x2C
	.word SMVB_continue3_single
	.byte -0x70, 0x01, -0x49
	.byte  0x15, 0x01,  0x3F
	.byte -0x04, 0x01,  0x0E
	.word SMVB_startMove_single
	.byte -0x69, 0x01,  0x2C
	.word SMVB_startDraw_single
	.byte  0x29, 0x01, -0x45
	.word SMVB_continue3_single
	.byte -0x2D, 0x01, -0x46
	.byte  0x6C, 0x01,  0x3C
	.byte -0x46, 0x01,  0x0F
	.word SMVB_startMove_double
	.byte  0x43, 0x01, -0x03
	.word SMVB_startDraw_single
	.byte -0x02, 0x01, -0x21
	.word SMVB_startMove_single
	.byte -0x3E, 0x01, -0x05
	.word SMVB_startDraw_single
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_CastleListA
_SM_CastleListA:
	.byte  0x4D, 0x01, -0x5F
	.word SMVB_continue_single
	.byte  0x11, 0x01,  0x1C
	.word SMVB_startDraw_single
	.byte  0x0E, 0x01, -0x1C
	.word SMVB_continue2_single
	.byte -0x46, 0x01,  0x00
	.byte -0x34, 0x01,  0x1B
	.word SMVB_startMove_single
	.byte  0x00, 0x01,  0x42
	.word SMVB_startDraw_double
	.byte  0x31, 0x01,  0x1E
	.word SMVB_startMove_single
	.byte  0x46, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte -0x0E, 0x01,  0x1B
	.word SMVB_continue2_single
	.byte -0x11, 0x01, -0x1B
	.byte -0x63, 0x01, -0x6F
	.word SMVB_startMove_double
	.byte  0x51, 0x01,  0x00
	.word SMVB_startDraw_double
	.byte  0x00, 0x01,  0x3B
	.word SMVB_continue_newY_eq_oldX_single ; y is  0x00
	.byte -0x51, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x54, 0x01,  0x42
	.word SMVB_startMove_single
	.byte -0x54, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte -0x02, 0x01, -0x24
	.word SMVB_startMove_single
	.byte  0x4E, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x0C, 0x01,  0x23
	.word SMVB_continue3_single
	.byte -0x0C, 0x01,  0x27
	.byte -0x4E, 0x01,  0x00
	.byte  0x01, 0x01,  0x1B
	.word SMVB_startMove_single
	.byte  0x51, 0x01,  0x00
	.word SMVB_startDraw_double
	.byte  0x00, 0x01,  0x3C
	.word SMVB_continue_newY_eq_oldX_single ; y is  0x00
	.byte -0x51, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls

 .globl _SM_DungeonListA
_SM_DungeonListA:
	.byte -0x7D, 0x01,  0x7C
	.word SMVB_continue_single
	.byte  0x37, 0x01, -0x0A
	.word SMVB_startDraw_single
	.byte  0x2C, 0x01, -0x1F
	.word SMVB_continue2_single
	.byte  0x07, 0x01, -0x3F
	.byte -0x2E, 0x01, -0x55
	.word SMVB_startMove_single
	.byte -0x3D, 0x01, -0x0E
	.word SMVB_startDraw_single
	.byte  0x4C, 0x01,  0x29
	.word SMVB_startMove_single
	.byte -0x10, 0x01, -0x1A
	.word SMVB_startDraw_single
	.byte  0x0A, 0x01,  0x39
	.word SMVB_startMove_single
	.byte  0x05, 0x01, -0x1E
	.word SMVB_startDraw_single
	.byte -0x15, 0x01,  0x28
	.word SMVB_startMove_single
	.byte  0x0F, 0x01, -0x0A
	.word SMVB_startDraw_single
	.byte -0x48, 0x01, -0x48
	.word SMVB_startMove_yEqx_single; y is -0x48
	.byte  0x2D, 0x01,  0x32
	.word SMVB_startDraw_single
	.byte -0x06, 0x01,  0x08
	.word SMVB_startMove_single
	.byte -0x28, 0x01, -0x24
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x16
	.word SMVB_startMove_single
	.byte  0x1F, 0x01,  0x15
	.word SMVB_startDraw_single
	.byte -0x05, 0x01,  0x06
	.word SMVB_startMove_single
	.byte -0x1A, 0x01, -0x08
	.word SMVB_startDraw_single
	.byte  0x05, 0x01,  0x15
	.word SMVB_startMove_single
	.byte  0x34, 0x01, -0x03
	.word SMVB_startDraw_single
	.byte -0x13, 0x01,  0x17
	.word SMVB_startMove_single
	.byte  0x46, 0x01, -0x08
	.word SMVB_startDraw_double
	.byte  0x0F, 0x01, -0x20
	.word SMVB_continue4_single
	.byte -0x12, 0x01, -0x25
	.byte -0x39, 0x01, -0x20
	.byte -0x70, 0x01, -0x1E
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls

 .globl _SM_MountainList3A
_SM_MountainList3A:
	.byte -0x7A, 0x01, -0x7C
	.word SMVB_continue_yd4_double
	.byte  0x70, 0x01,  0x1E
	.word SMVB_startDraw_double
	.byte  0x74, 0x01,  0x51
	.word SMVB_continue_double
	.byte -0x61, 0x01,  0x12
	.word SMVB_continue_yd4_quadro
	.byte  0x47, 0x01, -0x0A
	.word SMVB_startMove_double
	.byte  0x47, 0x01,  0x47
	.word SMVB_startDraw_yEqx_single; y is  0x47
	.byte -0x4C, 0x01,  0x5C
	.word SMVB_continue_yd4_single
	.byte -0x68, 0x01,  0x1C
	.word SMVB_continue_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_TownList3A
_SM_TownList3A:
	.byte -0x28, 0x01, -0x58
	.word SMVB_continue_tripple
	.byte  0x68, 0x01,  0x59
	.word SMVB_startDraw_single
	.byte  0x01, 0x01,  0x66
	.word SMVB_continue_single
	.byte -0x78, 0x01,  0x60
	.word SMVB_continue_yd4_single
	.byte  0x14, 0x01, -0x4F
	.word SMVB_continue_double
	.byte -0x0D, 0x01, -0x40
	.word SMVB_continue_double
	.byte -0x07, 0x01,  0x1A
	.word SMVB_startMove_single
	.byte -0x7E, 0x01,  0x06
	.word SMVB_startDraw_single
	.byte  0x01, 0x01,  0x3E
	.word SMVB_startMove_single
	.byte  0x50, 0x01, -0x03
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x2D
	.word SMVB_continue2_single
	.byte -0x52, 0x01,  0x00
	.byte  0x01, 0x01,  0x7D
	.word SMVB_startMove_single
	.byte  0x7C, 0x01, -0x0C
	.word SMVB_startDraw_single
	.byte  0x19, 0x01,  0x74
	.word SMVB_startMove_double
	.byte -0x53, 0x01,  0x11
	.word SMVB_startDraw_double
	.byte -0x07, 0x01, -0x67
	.word SMVB_startMove_single
	.byte  0x53, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x00, 0x01, -0x2D
	.word SMVB_continue2_single
	.byte -0x50, 0x01,  0x00
	.byte -0x02, 0x01, -0x47
	.word SMVB_startMove_single
	.byte  0x5C, 0x01,  0x0F
	.word SMVB_startDraw_double
	.byte  0x01, 0x01, -0x1F
	.word SMVB_startMove_single
	.byte  0x10, 0x01,  0x66
	.word SMVB_startDraw_single
	.byte -0x19, 0x01,  0x6F
	.word SMVB_continue_single
	.byte  0x4A, 0x01, -0x14
	.word SMVB_continue_double
	.byte  0x01, 0x01, -0x63
	.word SMVB_continue_single
	.byte -0x46, 0x01, -0x24
	.word SMVB_continue_double
	.byte  0x45, 0x01,  0x1F
	.word SMVB_startMove_single
	.byte  0x2D, 0x01, -0x0E
	.word SMVB_startDraw_single
	.byte  0x05, 0x01,  0x26
	.word SMVB_continue_single
	.byte  0x73, 0x01,  0x02
	.word SMVB_startMove_single
	.byte -0x28, 0x01, -0x08
	.word SMVB_startDraw_yd4_single
	.byte -0x2B, 0x01, -0x18
	.word SMVB_startMove_single
	.byte  0x3B, 0x01, -0x08
	.word SMVB_startDraw_single
	.byte  0x13, 0x01,  0x0E
	.word SMVB_startMove_single
	.byte  0x3A, 0x01,  0x05
	.word SMVB_startDraw_single
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls

 .globl _SM_TreeList3A
_SM_TreeList3A:
	.byte  0x24, 0x01, -0x02
	.word SMVB_continue_single
	.byte -0x22, 0x01,  0x6A
	.word SMVB_startDraw_single
	.byte  0x6C, 0x01, -0x2C
	.word SMVB_continue_double
	.byte -0x70, 0x01, -0x49
	.word SMVB_continue_yd4_double
	.byte  0x15, 0x01,  0x40
	.word SMVB_continue_double
	.byte -0x08, 0x01,  0x1D
	.word SMVB_startMove_single
	.byte -0x68, 0x01,  0x2C
	.word SMVB_startDraw_double
	.byte  0x29, 0x01, -0x45
	.word SMVB_continue_double
	.byte -0x2D, 0x01, -0x46
	.word SMVB_continue_double
	.byte  0x6B, 0x01,  0x3C
	.word SMVB_continue_double
	.byte -0x5D, 0x01,  0x15
	.word SMVB_startMove_yd4_tripple
	.byte  0x44, 0x01, -0x04
	.word SMVB_startDraw_double
	.byte -0x06, 0x01, -0x42
	.word SMVB_startMove_single
	.byte -0x7D, 0x01, -0x0B
	.word SMVB_startDraw_single
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_CastleList3A
_SM_CastleList3A:
	.byte  0x4D, 0x01, -0x5F
	.word SMVB_continue_double
	.byte  0x22, 0x01,  0x38
	.word SMVB_startDraw_single
	.byte  0x1E, 0x01, -0x38
	.word SMVB_continue_single
	.byte -0x47, 0x01,  0x00
	.word SMVB_continue_double
	.byte -0x67, 0x01,  0x38
	.word SMVB_startMove_single
	.byte  0x00, 0x01,  0x57
	.word SMVB_startDraw_tripple
	.byte  0x61, 0x01,  0x3E
	.word SMVB_startMove_single
	.byte  0x46, 0x01,  0x00
	.word SMVB_startDraw_double
	.byte -0x1D, 0x01,  0x37
	.word SMVB_continue2_single
	.byte -0x23, 0x01, -0x37
	.byte -0x63, 0x01, -0x6F
	.word SMVB_startMove_quadro
	.byte  0x6C, 0x01,  0x00
	.word SMVB_startDraw_tripple
	.byte  0x00, 0x01,  0x78
	.word SMVB_continue_newY_eq_oldX_single ; y is  0x00

	.byte -0x6C/2, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte -0x6C/2, 0x01,  0x00
	.word SMVB_continue_tripple

	.byte  0x54, 0x01,  0x42
	.word SMVB_startMove_double
	.byte -0x54, 0x01,  0x00
	.word SMVB_startDraw_yd4_double
	.byte -0x05, 0x01, -0x48
	.word SMVB_startMove_single
	.byte  0x4E, 0x01,  0x00
	.word SMVB_startDraw_double
	.byte  0x19, 0x01,  0x48
	.word SMVB_continue2_single
	.byte -0x19, 0x01,  0x4D
	.byte -0x4E, 0x01,  0x00
	.word SMVB_continue_double
	.byte  0x02, 0x01,  0x38
	.word SMVB_startMove_single
	.byte  0x6C, 0x01,  0x00
	.word SMVB_startDraw_tripple
	.byte  0x00, 0x01,  0x78
	.word SMVB_continue_newY_eq_oldX_single ; y is  0x00

	.byte -0x6C/2, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte -0x6C/2, 0x01,  0x00
	.word SMVB_continue_tripple

	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
 .globl _SM_DungeonList3A
_SM_DungeonList3A:
	.byte -0x7D, 0x01,  0x7C
	.word SMVB_continue_yd4_double
	.byte  0x6F, 0x01, -0x16
	.word SMVB_startDraw_single
	.byte  0x59, 0x01, -0x3E
	.word SMVB_continue2_single
	.byte  0x0E, 0x01, -0x7F
	.byte -0x2E, 0x01, -0x55
	.word SMVB_startMove_double
	.byte -0x7B, 0x01, -0x1E
	.word SMVB_startDraw_single
	.byte  0x4D, 0x01,  0x29
	.word SMVB_startMove_double
	.byte -0x20, 0x01, -0x35
	.word SMVB_startDraw_single
	.byte  0x15, 0x01,  0x72
	.word SMVB_startMove_single
	.byte  0x0B, 0x01, -0x3D
	.word SMVB_startDraw_single
	.byte -0x2B, 0x01,  0x52
	.word SMVB_startMove_single
	.byte  0x20, 0x01, -0x15
	.word SMVB_startDraw_single
	.byte -0x48, 0x01, -0x48
	.word SMVB_startMove_double
	.byte  0x5B, 0x01,  0x66
	.word SMVB_startDraw_single
	.byte -0x0E, 0x01,  0x10
	.word SMVB_startMove_single
	.byte -0x50, 0x01, -0x48
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x2D
	.word SMVB_startMove_single
	.byte  0x40, 0x01,  0x2B
	.word SMVB_startDraw_single
	.byte -0x0A, 0x01,  0x0D
	.word SMVB_startMove_single
	.byte -0x36, 0x01, -0x10
	.word SMVB_startDraw_single
	.byte  0x0B, 0x01,  0x2A
	.word SMVB_startMove_single
	.byte  0x68, 0x01, -0x08
	.word SMVB_startDraw_single
	.byte -0x27, 0x01,  0x2F
	.word SMVB_startMove_yd4_single
	.byte  0x5D, 0x01, -0x0B
	.word SMVB_startDraw_tripple
	.byte  0x1E, 0x01, -0x41
	.word SMVB_continue3_single
	.byte -0x25, 0x01, -0x4A
	.byte -0x72, 0x01, -0x42
	.byte -0x70, 0x01, -0x1E
	.word SMVB_continue_double
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls

 .globl _SM_Man7
_SM_Man7:

	.byte  0x32, 0x01, -0x6A
	.word SMVB_continue_single
	.byte  0x00, 0x01,  0x6A
	.word SMVB_startDraw_single
	.byte -0x41, 0x01,  0x00
	.word SMVB_continue4_single
	.byte -0x39, 0x01, -0x36
	.byte  0x39, 0x01, -0x34
	.byte  0x41, 0x01,  0x00
	.byte  0x04, 0x01,  0x40
	.word SMVB_startMove_double
	.byte  0x00, 0x01, -0x46
	.word SMVB_startDraw_single
	.byte  0x51, 0x01,  0x00
	.word SMVB_continue3_single
	.byte  0x00, 0x01,  0x45
	.byte -0x53, 0x01,  0x00
	.byte -0x0F, 0x01, -0x06
	.word SMVB_startMove_single
	.byte  0x01, 0x01,  0x1A
	.word SMVB_startDraw_single
	.byte -0x33, 0x01,  0x20
	.word SMVB_continue_single
	.byte  0x40, 0x01,  0x07
	.word SMVB_continue_double
	.byte -0x42, 0x01,  0x00
	.word SMVB_continue_yd4_double
	.byte  0x05, 0x01,  0x0C
	.word SMVB_continue5_single
	.byte -0x0E, 0x01,  0x04
	.byte -0x04, 0x01, -0x25
	.byte  0x1C, 0x01, -0x25
	.byte -0x08, 0x01, -0x19
	.byte -0x1F, 0x01, -0x15
	.word SMVB_startMove_single
	.byte -0x3A, 0x01,  0x34
	.word SMVB_startDraw_single
	.byte -0x2E, 0x01,  0x13
	.word SMVB_continue4_single
	.byte  0x00, 0x01, -0x25
	.byte  0x1A, 0x01, -0x06
	.byte  0x2F, 0x01, -0x32
	.byte -0x0E, 0x01, -0x01
	.word SMVB_startMove_single
	.byte -0x3B, 0x01, -0x1A
	.word SMVB_startDraw_single
	.byte  0x00, 0x01, -0x2A
	.word SMVB_continue2_single
	.byte  0x4A, 0x01,  0x27
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls




 .globl _SM_AkaList
_SM_AkaList:
	.byte  0x5F, 0x01,  0x02
	.word SMVB_continue_octo
	.byte  0x5F, 0x01,  0x02
	.word SMVB_continue_quadro
	.byte -0x18, 0x01,  0x00
	.word SMVB_startDraw_single
	.byte  0x18, 0x01,  0x18
	.word SMVB_continue_yEqx_single; y is  0x18
	.byte -0x43, 0x01,  0x0C
	.word SMVB_continue_double
	.byte -0x44, 0x01,  0x10
	.word SMVB_continue_double
	.byte -0x40, 0x01, -0x38
	.word SMVB_continue7_single
	.byte  0x78, 0x01, -0x18
	.byte  0x05, 0x01, -0x1A
	.byte  0x0B, 0x01, -0x26
	.byte -0x40, 0x01, -0x18
	.byte -0x48, 0x01, -0x30
	.byte  0x4B, 0x01,  0x1E
	.byte  0x5E, 0x01,  0x17
	.word SMVB_continue_double
	.byte  0x47, 0x01,  0x3C
	.word SMVB_continue_single
	.byte  0x01, 0x01,  0x5D
	.word SMVB_startMove_hex
	.byte -0x34, 0x01, -0x32
	.word SMVB_startDraw_single
	.byte -0x04, 0x01,  0x27
	.word SMVB_continue3_single
	.byte -0x08, 0x01,  0x20
	.byte -0x10, 0x01, -0x13
	.byte -0x77, 0x01, -0x02
	.word SMVB_continue_double
	.byte  0x38, 0x01,  0x38
	.word SMVB_continue7_single
	.byte  0x7B, 0x01,  0x0C
	.byte  0x5C, 0x01, -0x04
	.byte  0x38, 0x01,  0x42
	.byte -0x0F, 0x01, -0x36
	.byte  0x07, 0x01, -0x24
	.byte  0x00, 0x01, -0x25
	.byte -0x57, 0x01, -0x31
	.word SMVB_startMove_tripple
	.byte  0x0B, 0x01,  0x17
	.word SMVB_startDraw_single
	.byte -0x0B, 0x01,  0x11
	.word SMVB_continue7_single
	.byte  0x01, 0x01,  0x1C
	.byte -0x41, 0x01, -0x3C
	.byte  0x00, 0x01, -0x18
	.byte  0x0C, 0x01, -0x10
	.byte -0x04, 0x01, -0x16
	.byte  0x38, 0x01,  0x36
	.byte  0x14, 0x01, -0x67
	.word SMVB_startMove_quadro
	.byte  0x45, 0x01, -0x1A
	.word SMVB_startDraw_single
	.byte -0x53, 0x01, -0x28
	.word SMVB_continue3_single
	.byte  0x03, 0x01,  0x28
	.byte  0x0B, 0x01,  0x1A
	.byte  0x2B, 0x01,  0x63
	.word SMVB_startMove_quadro
	.byte -0x2B, 0x01, -0x38
	.word SMVB_startDraw_single
	.byte -0x5A, 0x01, -0x02
	.word SMVB_continue_tripple
	.byte  0x38, 0x01,  0x39
	.word SMVB_continue7_single
	.byte  0x4B, 0x01, -0x01
	.byte -0x02, 0x01,  0x33
	.byte  0x38, 0x01,  0x36
	.byte  0x03, 0x01, -0x20
	.byte  0x08, 0x01, -0x16
	.byte -0x11, 0x01, -0x2B
	.byte  0x47, 0x01,  0x06
	.word SMVB_continue7_single
	.byte  0x00, 0x01,  0x22
	.byte  0x08, 0x01,  0x10
	.byte  0x38, 0x01,  0x38
	.byte -0x0E, 0x01, -0x1B
	.byte  0x06, 0x01, -0x1A
	.byte  0x00, 0x01, -0x13
	.byte -0x18, 0x01, -0x20
	.word SMVB_continue2_single
	.byte  0x20, 0x01, -0x08
	.byte  0x05, 0x01,  0x7B
	.word SMVB_startMove_tripple
	.byte -0x28, 0x01, -0x41
	.word SMVB_startDraw_single
	.byte -0x62, 0x01, -0x02
	.word SMVB_continue_tripple
	.byte  0x30, 0x01,  0x38
	.word SMVB_continue4_single
	.byte  0x70, 0x01,  0x08
	.byte  0x05, 0x01,  0x1C
	.byte  0x0D, 0x01,  0x1E
	.byte -0x41, 0x01, -0x01
	.word SMVB_continue_double
	.byte -0x30, 0x01, -0x08
	.word SMVB_continue3_single
	.byte  0x28, 0x01,  0x40
	.byte  0x18, 0x01,  0x08
	.byte  0x5A, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte -0x29, 0x01, -0x40
	.word SMVB_continue4_single
	.byte -0x5F, 0x01,  0x00
	.byte -0x03, 0x01, -0x1E
	.byte -0x0D, 0x01, -0x1A
	.byte  0x42, 0x01,  0x02
	.word SMVB_continue_double
	.byte  0x12, 0x01,  0x05
	.word SMVB_continue_single
	.byte -0x02, 0x01, -0x7E
	.word SMVB_startMove_octo
	.byte -0x2A, 0x01, -0x3B
	.word SMVB_startDraw_single
	.byte -0x2C, 0x01,  0x06
	.word SMVB_continue_single
	.byte -0x55, 0x01, -0x01
	.word SMVB_continue_tripple
	.byte  0x10, 0x01,  0x08
	.word SMVB_continue7_single
	.byte  0x10, 0x01,  0x10
	.byte  0x00, 0x01,  0x18
	.byte -0x10, 0x01,  0x10
	.byte -0x06, 0x01,  0x20
	.byte  0x3E, 0x01,  0x30
	.byte  0x06, 0x01, -0x25
	.byte  0x10, 0x01, -0x16
	.word SMVB_continue4_single
	.byte -0x06, 0x01, -0x15
	.byte -0x08, 0x01, -0x10
	.byte  0x48, 0x01,  0x08
	.byte  0x5B, 0x01,  0x04
	.word SMVB_continue_double
	.byte  0x08, 0x01, -0x08
	.word SMVB_continue_single
	.byte  0x04, 0x01, -0x74
	.word SMVB_startMove_quadro
	.byte -0x48, 0x01, -0x30
	.word SMVB_startDraw_single
	.byte -0x5F, 0x01, -0x02
	.word SMVB_continue_tripple
	.byte  0x60, 0x01,  0x38
	.word SMVB_continue3_single
	.byte  0x50, 0x01,  0x00
	.byte  0x10, 0x01,  0x10
	.byte -0x5C, 0x01,  0x18
	.word SMVB_continue_double
	.byte  0x48, 0x01,  0x30
	.word SMVB_continue_single
	.byte  0x5C, 0x01, -0x14
	.word SMVB_continue_double
	.byte -0x10, 0x01, -0x10
	.word SMVB_continue6_single
	.byte  0x47, 0x01,  0x20
	.byte  0x10, 0x01,  0x08
	.byte -0x10, 0x01, -0x10
	.byte -0x30, 0x01, -0x20
	.byte -0x5F, 0x01, -0x30
	.byte  0x5B, 0x01,  0x00
	.word SMVB_continue_double
	.byte -0x0E, 0x01,  0x78
	.word SMVB_startMove_octo
	.byte -0x38, 0x01, -0x38
	.word SMVB_startDraw_yEqx_single; y is -0x38
	.byte -0x09, 0x01,  0x29
	.word SMVB_continue7_single
	.byte -0x15, 0x01,  0x06
	.byte -0x30, 0x01,  0x00
	.byte -0x25, 0x01, -0x22
	.byte -0x0B, 0x01, -0x16
	.byte -0x30, 0x01, -0x28
	.byte -0x10, 0x01, -0x08
	.byte  0x40, 0x01,  0x50
	.word SMVB_continue7_single
	.byte  0x48, 0x01,  0x40
	.byte  0x38, 0x01,  0x18
	.byte  0x18, 0x01,  0x00
	.byte  0x12, 0x01, -0x08
	.byte  0x06, 0x01, -0x10
	.byte  0x06, 0x01, -0x1F
	.byte  0x31, 0x01, -0x12
	.word SMVB_startMove_single
	.byte -0x10, 0x01,  0x01
	.word SMVB_startDraw_single
	.byte -0x0C, 0x01,  0x00
	.word SMVB_continue7_single
	.byte -0x12, 0x01, -0x10
	.byte -0x16, 0x01, -0x15
	.byte -0x0B, 0x01, -0x13
	.byte  0x57, 0x01,  0x00
	.byte  0x02, 0x01,  0x20
	.byte -0x0A, 0x01,  0x17
	.byte  0x40, 0x01,  0x01
	.word SMVB_startMove_single
	.byte -0x28, 0x01, -0x30
	.word SMVB_startDraw_single
	.byte  0x20, 0x01, -0x10
	.word SMVB_continue2_single
	.byte -0x30, 0x01, -0x30
	.byte -0x5D, 0x01,  0x00
	.word SMVB_continue_tripple
	.byte -0x18, 0x01, -0x08
	.word SMVB_continue7_single
	.byte  0x40, 0x01,  0x38
	.byte  0x30, 0x01,  0x08
	.byte  0x50, 0x01,  0x00
	.byte  0x4F, 0x01,  0x50
	.byte  0x10, 0x01,  0x08
	.byte  0x08, 0x01,  0x10
	.byte  0x10, 0x01,  0x08
	.word SMVB_continue5_single
	.byte  0x18, 0x01,  0x00
	.byte  0x18, 0x01, -0x10
	.byte  0x08, 0x01, -0x18
	.byte -0x08, 0x01, -0x10
	.byte -0x2D, 0x01, -0x7D
	.word SMVB_startMove_hex
	.byte  0x30, 0x01,  0x18
	.word SMVB_startDraw_single
	.byte -0x08, 0x01,  0x10
	.word SMVB_continue2_single
	.byte  0x00, 0x01,  0x30
	.byte -0x44, 0x01,  0x10
	.word SMVB_continue_double
	.byte  0x58, 0x01,  0x30
	.word SMVB_continue7_single
	.byte  0x68, 0x01, -0x20
	.byte  0x77, 0x01, -0x18
	.byte  0x20, 0x01, -0x08
	.byte -0x10, 0x01, -0x08
	.byte  0x18, 0x01,  0x00
	.byte -0x30, 0x01, -0x20
	.byte -0x47, 0x01, -0x18
	.word SMVB_continue_double
	.byte -0x68, 0x01, -0x28
	.word SMVB_continue2_single
	.byte  0x28, 0x01,  0x18
	.byte  0x48, 0x01,  0x58
	.word SMVB_startMove_single
	.byte -0x10, 0x01, -0x38
	.word SMVB_startDraw_single
	.byte  0x60, 0x01,  0x20
	.word SMVB_continue3_single
	.byte -0x28, 0x01,  0x10
	.byte -0x28, 0x01,  0x08
	.byte -0x0D, 0x01, -0x5C
	.word SMVB_startMove_hex
	.byte  0x38, 0x01,  0x18
	.word SMVB_startDraw_single
	.byte  0x00, 0x01,  0x20
	.word SMVB_continue2_single
	.byte -0x08, 0x01,  0x28
	.byte -0x44, 0x01,  0x10
	.word SMVB_continue_double
	.byte  0x58, 0x01,  0x30
	.word SMVB_continue7_single
	.byte  0x68, 0x01, -0x20
	.byte  0x77, 0x01, -0x10
	.byte  0x20, 0x01, -0x10
	.byte -0x08, 0x01, -0x08
	.byte  0x10, 0x01,  0x00
	.byte -0x30, 0x01, -0x20
	.byte -0x47, 0x01, -0x18
	.word SMVB_continue_double
	.byte -0x60, 0x01, -0x28
	.word SMVB_continue2_single
	.byte  0x18, 0x01,  0x10
	.byte  0x50, 0x01,  0x60
	.word SMVB_startMove_single
	.byte -0x10, 0x01, -0x40
	.word SMVB_startDraw_single
	.byte  0x60, 0x01,  0x28
	.word SMVB_continue3_single
	.byte -0x28, 0x01,  0x10
	.byte -0x28, 0x01,  0x08
	.byte  0x40, 0x00,  0x00
	.word SMVB_lastDraw_rts_puls
