SM_VectorList
	db  $5F, $01,  $02
	dw SMVB_continue_octo
	db  $5F, $01,  $02
	dw SMVB_continue_quadro
	db -$18, $01,  $00
	dw SMVB_startDraw_single
	db  $18, $01,  $18
	dw SMVB_continue_yEqx_single; y is  $18
	db -$43, $01,  $0C
	dw SMVB_continue_double
	db -$44, $01,  $10
	dw SMVB_continue_double
	db -$40, $01, -$38
	dw SMVB_continue7_single
	db  $78, $01, -$18
	db  $05, $01, -$1A
	db  $0B, $01, -$26
	db -$40, $01, -$18
	db -$48, $01, -$30
	db  $4B, $01,  $1E
	db  $5E, $01,  $17
	dw SMVB_continue_double
	db  $47, $01,  $3C
	dw SMVB_continue_single
	db  $01, $01,  $5D
	dw SMVB_startMove_hex
	db -$34, $01, -$32
	dw SMVB_startDraw_single
	db -$04, $01,  $27
	dw SMVB_continue3_single
	db -$08, $01,  $20
	db -$10, $01, -$13
	db -$77, $01, -$02
	dw SMVB_continue_double
	db  $38, $01,  $38
	dw SMVB_continue7_single
	db  $7B, $01,  $0C
	db  $5C, $01, -$04
	db  $38, $01,  $42
	db -$0F, $01, -$36
	db  $07, $01, -$24
	db  $00, $01, -$25
	db -$57, $01, -$31
	dw SMVB_startMove_tripple
	db  $0B, $01,  $17
	dw SMVB_startDraw_single
	db -$0B, $01,  $11
	dw SMVB_continue7_single
	db  $01, $01,  $1C
	db -$41, $01, -$3C
	db  $00, $01, -$18
	db  $0C, $01, -$10
	db -$04, $01, -$16
	db  $38, $01,  $36
	db  $14, $01, -$67
	dw SMVB_startMove_quadro
	db  $45, $01, -$1A
	dw SMVB_startDraw_single
	db -$53, $01, -$28
	dw SMVB_continue3_single
	db  $03, $01,  $28
	db  $0B, $01,  $1A
	db  $2B, $01,  $63
	dw SMVB_startMove_quadro
	db -$2B, $01, -$38
	dw SMVB_startDraw_single
	db -$5A, $01, -$02
	dw SMVB_continue_tripple
	db  $38, $01,  $39
	dw SMVB_continue7_single
	db  $4B, $01, -$01
	db -$02, $01,  $33
	db  $38, $01,  $36
	db  $03, $01, -$20
	db  $08, $01, -$16
	db -$11, $01, -$2B
	db  $47, $01,  $06
	dw SMVB_continue7_single
	db  $00, $01,  $22
	db  $08, $01,  $10
	db  $38, $01,  $38
	db -$0E, $01, -$1B
	db  $06, $01, -$1A
	db  $00, $01, -$13
	db -$18, $01, -$20
	dw SMVB_continue2_single
	db  $20, $01, -$08
	db  $05, $01,  $7B
	dw SMVB_startMove_tripple
	db -$28, $01, -$41
	dw SMVB_startDraw_single
	db -$62, $01, -$02
	dw SMVB_continue_tripple
	db  $30, $01,  $38
	dw SMVB_continue4_single
	db  $70, $01,  $08
	db  $05, $01,  $1C
	db  $0D, $01,  $1E
	db -$41, $01, -$01
	dw SMVB_continue_double
	db -$30, $01, -$08
	dw SMVB_continue3_single
	db  $28, $01,  $40
	db  $18, $01,  $08
	db  $5A, $01,  $00
	dw SMVB_continue_tripple
	db -$29, $01, -$40
	dw SMVB_continue4_single
	db -$5F, $01,  $00
	db -$03, $01, -$1E
	db -$0D, $01, -$1A
	db  $42, $01,  $02
	dw SMVB_continue_double
	db  $12, $01,  $05
	dw SMVB_continue_single
	db -$02, $01, -$7E
	dw SMVB_startMove_octo
	db -$2A, $01, -$3B
	dw SMVB_startDraw_single
	db -$2C, $01,  $06
	dw SMVB_continue_single
	db -$55, $01, -$01
	dw SMVB_continue_tripple
	db  $10, $01,  $08
	dw SMVB_continue7_single
	db  $10, $01,  $10
	db  $00, $01,  $18
	db -$10, $01,  $10
	db -$06, $01,  $20
	db  $3E, $01,  $30
	db  $06, $01, -$25
	db  $10, $01, -$16
	dw SMVB_continue4_single
	db -$06, $01, -$15
	db -$08, $01, -$10
	db  $48, $01,  $08
	db  $5B, $01,  $04
	dw SMVB_continue_double
	db  $08, $01, -$08
	dw SMVB_continue_single
	db  $04, $01, -$74
	dw SMVB_startMove_quadro
	db -$48, $01, -$30
	dw SMVB_startDraw_single
	db -$5F, $01, -$02
	dw SMVB_continue_tripple
	db  $60, $01,  $38
	dw SMVB_continue3_single
	db  $50, $01,  $00
	db  $10, $01,  $10
	db -$5C, $01,  $18
	dw SMVB_continue_double
	db  $48, $01,  $30
	dw SMVB_continue_single
	db  $5C, $01, -$14
	dw SMVB_continue_double
	db -$10, $01, -$10
	dw SMVB_continue6_single
	db  $47, $01,  $20
	db  $10, $01,  $08
	db -$10, $01, -$10
	db -$30, $01, -$20
	db -$5F, $01, -$30
	db  $5B, $01,  $00
	dw SMVB_continue_double
	db -$0E, $01,  $78
	dw SMVB_startMove_octo
	db -$38, $01, -$38
	dw SMVB_startDraw_yEqx_single; y is -$38
	db -$09, $01,  $29
	dw SMVB_continue7_single
	db -$15, $01,  $06
	db -$30, $01,  $00
	db -$25, $01, -$22
	db -$0B, $01, -$16
	db -$30, $01, -$28
	db -$10, $01, -$08
	db  $40, $01,  $50
	dw SMVB_continue7_single
	db  $48, $01,  $40
	db  $38, $01,  $18
	db  $18, $01,  $00
	db  $12, $01, -$08
	db  $06, $01, -$10
	db  $06, $01, -$1F
	db  $31, $01, -$12
	dw SMVB_startMove_single
	db -$10, $01,  $01
	dw SMVB_startDraw_single
	db -$0C, $01,  $00
	dw SMVB_continue7_single
	db -$12, $01, -$10
	db -$16, $01, -$15
	db -$0B, $01, -$13
	db  $57, $01,  $00
	db  $02, $01,  $20
	db -$0A, $01,  $17
	db  $40, $01,  $01
	dw SMVB_startMove_single
	db -$28, $01, -$30
	dw SMVB_startDraw_single
	db  $20, $01, -$10
	dw SMVB_continue2_single
	db -$30, $01, -$30
	db -$5D, $01,  $00
	dw SMVB_continue_tripple
	db -$18, $01, -$08
	dw SMVB_continue7_single
	db  $40, $01,  $38
	db  $30, $01,  $08
	db  $50, $01,  $00
	db  $4F, $01,  $50
	db  $10, $01,  $08
	db  $08, $01,  $10
	db  $10, $01,  $08
	dw SMVB_continue5_single
	db  $18, $01,  $00
	db  $18, $01, -$10
	db  $08, $01, -$18
	db -$08, $01, -$10
	db -$2D, $01, -$7D
	dw SMVB_startMove_hex
	db  $30, $01,  $18
	dw SMVB_startDraw_single
	db -$08, $01,  $10
	dw SMVB_continue2_single
	db  $00, $01,  $30
	db -$44, $01,  $10
	dw SMVB_continue_double
	db  $58, $01,  $30
	dw SMVB_continue7_single
	db  $68, $01, -$20
	db  $77, $01, -$18
	db  $20, $01, -$08
	db -$10, $01, -$08
	db  $18, $01,  $00
	db -$30, $01, -$20
	db -$47, $01, -$18
	dw SMVB_continue_double
	db -$68, $01, -$28
	dw SMVB_continue2_single
	db  $28, $01,  $18
	db  $48, $01,  $58
	dw SMVB_startMove_single
	db -$10, $01, -$38
	dw SMVB_startDraw_single
	db  $60, $01,  $20
	dw SMVB_continue3_single
	db -$28, $01,  $10
	db -$28, $01,  $08
	db -$0D, $01, -$5C
	dw SMVB_startMove_hex
	db  $38, $01,  $18
	dw SMVB_startDraw_single
	db  $00, $01,  $20
	dw SMVB_continue2_single
	db -$08, $01,  $28
	db -$44, $01,  $10
	dw SMVB_continue_double
	db  $58, $01,  $30
	dw SMVB_continue7_single
	db  $68, $01, -$20
	db  $77, $01, -$10
	db  $20, $01, -$10
	db -$08, $01, -$08
	db  $10, $01,  $00
	db -$30, $01, -$20
	db -$47, $01, -$18
	dw SMVB_continue_double
	db -$60, $01, -$28
	dw SMVB_continue2_single
	db  $18, $01,  $10
	db  $50, $01,  $60
	dw SMVB_startMove_single
	db -$10, $01, -$40
	dw SMVB_startDraw_single
	db  $60, $01,  $28
	dw SMVB_continue3_single
	db -$28, $01,  $10
	db -$28, $01,  $08
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts
