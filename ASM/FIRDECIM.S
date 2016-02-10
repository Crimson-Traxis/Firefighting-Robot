;*********************************************************************
;                                                                    *
;                       Software License Agreement                   *
;                                                                    *
;   The software supplied herewith by Microchip Technology           *
;   Incorporated (the "Company") for its dsPIC controller            *
;   is intended and supplied to you, the Company's customer,         *
;   for use solely and exclusively on Microchip dsPIC                *
;   products. The software is owned by the Company and/or its        *
;   supplier, and is protected under applicable copyright laws. All  *
;   rights are reserved. Any use in violation of the foregoing       *
;   restrictions may subject the user to criminal sanctions under    *
;   applicable laws, as well as to civil liability for the breach of *
;   the terms and conditions of this license.                        *
;                                                                    *
;   THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION.  NO           *
;   WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING,    *
;   BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND    *
;   FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE     *
;   COMPANY SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,  *
;   INCIDENTAL OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.  *
;                                                                    *
;   (c) Copyright 2003 Microchip Technology, All rights reserved.    *
;*********************************************************************

	; Local inclusions.
	.nolist
	.include	"dspcommon.inc"		; fractsetup,FIRStruct,
						; CORCON,PSVPAG
	.list

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.section .libdsp, code

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; _FIRDecimate: Ratio R:1 decimation by FIR (low pass) filtering.
;
; Operation:
;	y[n] = H(x[R*n])
;
; x[n] defined for 0 <= n < N*R,
; y[n] defined for 0 <= n < N, (N = p*R, p integer),
; h[k] defined for 0 <= k < M (M = q*R, q integer).
;
; Input:
;	w0 = N, number of output samples (N = p*R, p integer)
;	w1 = y, ptr output samples (0 <= n < N)
;	w2 = x, ptr input samples (0 <= n < N*R)
;	w3 = filter structure (FIRStruct, h)
;	w4 = R, rate of decimation R (to 1)
; Return:
;	w0 = y, ptr output samples (0 <= n < N)
;
; System resources usage:
;	{w0..w7}	used, not restored
;	{w8..w12}	saved, used, restored
;	 AccuA		used, not restored
;	 CORCON		saved, used, restored
;	 PSVPAG		saved, used, restored (if coeffs in P memory)
;
; DO and REPEAT instruction usage.
;	1 level DO intruction
;	1 level REPEAT intruction
;
; Program words (24-bit instructions):
;	48
;
; Cycles (including C-function call and return overheads):
;	45 + N*(10 + 2*M), or
;	48 + N*(13 + 2*M) if coefficients in P memory
; Note that timming with simulator:
;	45 + N*(9 + 2*M), or
;	48 + N*(11 + 2*M) if coefficients in P memory
;............................................................................

	.global	_FIRDecimate	; export
_FIRDecimate:

;............................................................................

	; Save working registers.
	push.d	w8				; {w8,w9} to TOS
	push.d	w10				; {w10,w11} to TOS
	push	w12				; {w12} to TOS

;............................................................................

	; Prepare CORCON for fractional computation.
	push	CORCON
	fractsetup	w7

;............................................................................

	; Prepare CORCON and PSVPAG for possible access of data
	; located in program memory, using the PSV.
	push	PSVPAG

	mov	[w3+oCoeffsPage],w10		; w10= coefficients page
	mov	#COEFFS_IN_DATA,w8		; w8 = COEFFS_IN_DATA
	cp	w8,w10				; w8 - w10
	bra	z,_noPSV			; if w10 = COEFFS_IN_DATA
						; no PSV management
						; else
	psvaccess	w8			; enable PSV bit in CORCON
	mov	w10,PSVPAG			; load PSVPAG with program
						; space page offset
_noPSV:

;............................................................................

	push	w1				; save return value (y)

;............................................................................

	; Get parameters from filter structure.
	mov	w4,w6				; w6 = R
	mov	[w3+oCoeffsBase],w4		; w4-> h[0]
	mov	[w3+oDelayBase],w5		; w5-> d[0]
	mov	[w3+oNumCoeffs],w3		; w3 = M

;............................................................................

	; Set up filtering.
	sl	w6,w11				; w11= R*sizeof(sample)
	sub	w3,w6,w12			; w12= M-R
	dec	w0,w0				; w0 = N-1
	dec2	w3,w3				; w3 = M-2
	dec	w6,w9				; w9= R-1
						; w6 available for reuse
	dec	w12,w12				; w12= M-R-1

	; Generate the N output samples from the N*R input samples.
	do	w0,_endDecim		; {	; do (N-1)+1 times
						; w0 available for reuse

	; Make room in delay for next R input samples.
	mov	w5,w8				; w8-> d[0]
	add	w5,w11,w10			; w10->d[R]
	repeat	w12			; {	; do (M-R-1)+1 times
	mov	[w10++],[w8++]			; d[k] <- d[R+k]
						; w8-> d[k+1]
						; w10->d[R+k+1]
; }
						; now:
						; w8-> d[M-1-R]
						; w10->d[M]

	; Place next R input samples in delay.
	repeat	w9			; {	; do (R-1)+1 times
	mov	[w2++],[w8++]			; d[M-1-R+k] <- x[n+k]
						; w2-> x[n+k+1]
						; w8-> d[M-1-R+k+1]
; }
						; now:
						; w2-> x[n+R]
						; w8-> d[M]

	; Set up next output.
	mov	w4,w8				; w8-> h[0]
	dec2	w10,w10				; w10->d[M-1] = x[n+R-1]
	clr	a,[w8]+=2,w6,[w10]-=2,w7	; a  = 0
						; w6 = h[0]
						; w8-> h[1]
						; w7 = d[M-1] = x[n+R-1]
						; w10->d[M-2] = x[n+R-2]

	; Generate next output.
	; (Perform all but last MAC.)
	repeat	w3				; do (M-2)+1 times
	mac	w6*w7,a,[w8]+=2,w6,[w10]-=2,w7	; a += h[k]*d[M-1-k]
						;    = h[k]*x[n+R-1-k]
						; w6 = h[k+1]
						; w8-> h[k+2]
						; w7 = d[M-1-k-1] = x[n+R-1-k-1]
						; w10->d[M-1-k-2] = x[n+R-1-k-2]
	; (Perform last MAC.)
	mac	w6*w7,a				; a += h[M-1]*d[0]
_endDecim:
	sac.r	a,[w1++]			; store y[n]
						; w1-> y[n+1]
						; now:
						; w8-> h[M+1]
						; w10->d[-2] = x[n+R-M-1]
; }
						; now:
						; w1-> y[N]
						; w2-> x[N*R]

;............................................................................

	pop	w0				; restore return value

;............................................................................

	; Restore PSVPAG and CORCON.
	pop	PSVPAG
	pop	CORCON

;............................................................................

	; Restore working registers.
	pop	w12				; {w12} from TOS
	pop.d	w10				; {w10,w11} from TOS
	pop.d	w8				; {w8,w9} from TOS

;............................................................................

	return	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.end

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; OEF
