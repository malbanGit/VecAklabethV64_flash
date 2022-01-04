
SM_MountainList3
	db  $7A, $01,  $49
	dw SMVB_continue_double
	db -$62, $01,  $00
	dw SMVB_startDraw_single
	db  $00, $01,  $62
	dw SMVB_startMove_newY_eq_oldX_single ; y was  $00, now 0
	db  $00, $01, -$64
	dw SMVB_startDraw_double
	db -$60, $01,  $00
	dw SMVB_continue_double
	db  $00, $01, -$5A
	dw SMVB_startMove_newY_eq_oldX_single ; y was  $00, now 0
	db  $00, $01,  $60
	dw SMVB_startDraw_double
	db -$64, $01,  $00
	dw SMVB_continue_double
	db  $62, $01,  $00
	dw SMVB_startMove_single
	db SHITREG_POKE_VALUE, $01,  $62
	dw SMVB_startDraw_newY_eq_oldX_single ; y was  $00, now SHIFT
	db  $00, $01, -$7A
	dw SMVB_startMove_quadro
	db  SHITREG_POKE_VALUE, $01,  $62
	dw SMVB_startDraw_yStays_single; y was  $00, now SHIFT Poke
	db -$62, $01,  $00
	dw SMVB_startMove_single
	db  $62, $01,  $00
	dw SMVB_startDraw_single
	db  $66, $01,  $66
	dw SMVB_continue3_single
	db  $5A, $01,  $00
	db  $00, $01, -$66
	db  $64, $01,  $00
	dw SMVB_continue_double
	db -$62, $01,  $00
	dw SMVB_startMove_single
	db SHITREG_POKE_VALUE, $01, -$62
	dw SMVB_startDraw_newY_eq_oldX_single ; y was  $00, now SHIFT
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts_puls
SM_TownList3
	db -$61, $01, -$61
	dw SMVB_continue_yEqx_single; y is -$61
	db  $61, $01,  $00
	dw SMVB_startDraw_double
	db  $00, $01, -$4A
	dw SMVB_continue_double
	db  $4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01,  $4A
	dw SMVB_continue_double
	db -$4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01,  $61
	dw SMVB_continue_double
	db  $4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01,  $4A
	dw SMVB_continue_double
	db -$4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01, -$4A
	dw SMVB_continue_double
	db -$61, $01,  $00
	dw SMVB_continue_double
	db  $00, $01,  $4A
	dw SMVB_continue_double
	db -$4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01, -$4A
	dw SMVB_continue_double
	db  $4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01, -$61
	dw SMVB_continue_double
	db -$4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01, -$4A
	dw SMVB_continue_double
	db  $4A, $01,  $00
	dw SMVB_continue_double
	db  $00, $01,  $4A
	dw SMVB_continue_double
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts_puls
SM_TreeList3
	db -$62, $01, -$62
	dw SMVB_continue_double
	db  $62, $01,  $00
	dw SMVB_startDraw_quadro
	db  $00, $01,  $62
	dw SMVB_continue_quadro
	db -$62, $01,  $00
	dw SMVB_continue_quadro
	db  $00, $01, -$62
	dw SMVB_continue_quadro
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts_puls
SM_CastleList3
	db -$5D, $01, -$5D
	dw SMVB_continue_double
	db  $00, $01,  $7C
	dw SMVB_startDraw_tripple
	db  $7C, $01,  $00
	dw SMVB_continue_tripple
	db  $00, $01, -$7C
	dw SMVB_continue_tripple
	db -$7C, $01,  $00
	dw SMVB_continue_tripple
	db  $4E, $01,  $4E
	dw SMVB_startMove_yEqx_single; y is  $4E
	db  $00, $01,  $6D
	dw SMVB_startDraw_double
	db  $6D, $01,  $00
	dw SMVB_startMove_double
	db  $00, $01, -$6D
	dw SMVB_startDraw_double
	db -$6D, $01,  $00
	dw SMVB_continue_double
	db  $6D, $01,  $6D
	dw SMVB_continue_double
	db -$6D, $01,  $00
	dw SMVB_continue_double
	db  $6D, $01, -$6D
	dw SMVB_continue_double
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts_puls
SM_DungeonList3
	db -$61, $01,  $61
	dw SMVB_continue_single
	db  $61, $01, -$61
	dw SMVB_startDraw_double
	db  $00, $01,  $61
	dw SMVB_startMove_double
	db -$61, $01, -$61
	dw SMVB_startDraw_double
	db  $40, $00,  $00
	dw SMVB_lastDraw_rts_puls
