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
; _FIRLattice: FIR filtering with lattice implementation.
;
; Operation:
;	e_(0)[n] = e'_(0)[n] = x[n],
;	e_(m)[n] =  e_(m-1)[n] - k_(m-1)*e'_(m-1)[n-1],
;      e'_(m)[n] = -k_(m-1)*e_(m-1)[n] + e'_(m-1)[n-1],
; and	    y[n] = e_(M)[n];
;
; x[n] defined for 0 <= n < N,
; y[n] defined for 0 <= n < N,
; k[m] defined for 0 <= m < M, and
; e'_(m)[n] defined for 0 <= m < M, for -M <= n < N.
;
; Input:
;	w0 = N, number of input samples (N)
;	w1 = y, ptr output samples (0 <= n < N)
;	w2 = x, ptr input samples (0 <= n < N)
;	w3 = h, ptr filter structure (see included file)
; Return:
;	w0 = y, ptr output samples (0 <= n < N)
;
; System resources usage:
;	{w0..w7}	used, not restored
;	{w8..w12}	saved, used, restored
;	 AccuA		used, not restored
;	 AccuB		used, not restored
;	 CORCON		saved, used, restored
;	 PSVPAG		saved, used, restored (if coeffs in program memory)
;
; DO and REPEAT instruction usage.
;	2 level DO intruction
;	no REPEAT intructions
;
; Program words (24-bit instructions):
;	50
;
; Cycles (including C-function call and return overheads):
;	41 + N*(4 + 7*M), or
;	44 + N*(4 + 8*M) if coefficients in program memory.
;............................................................................

	.global	_FIRLattice	; export
_FIRLattice:

;............................................................................

	; Save working registers.
	push.d	w8				; {w8,w9} to TOS
	push.d	w10				; {w10,w11} to TOS
	push	w12				; w12 to TOS

;............................................................................

	; Prepare CORCON for fractional computation.
	push	CORCON
	fractsetup	w12

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

	; Set up filter structure.
	mov	[w3+oNumCoeffs],w12		; w12= M
	mov	[w3+oCoeffsBase],w8		; w8-> k[0]
	mov	w8,w10				; w10->k[0] (for rewind)
	mov	[w3+oDelayBase],w9		; w9-> del[0]
	mov	w9,w11				; w11->del[0] (for rewind)

	; Set up filtering.
	dec	w0,w0				; w0 = N-1
	dec2	w12,w12				; w12 = M-2

	; Filter the N input samples.
	; Note that at this point, we have x-> x[0], and del[m] = e'_(m)[n-1].
	do	w0,_endFilter		; {	; do (N-1)+1 times
						; w0 available for reuse

	; For m = 0 (recursion set up).
	lac	[w2++],a			; e_(0)[n] = x[n] (via accuA)
						; w2-> x[n+1]
	sac.r	a,w7				; w7 = x[n] (tmp = e_(0)[n])
	mov	[w9],w6				; w6 = e'_(0)[n-1]
	sac.r	a,[w9++]			; e'_(0)[n] = x[n]
						; w9-> del[m+1] (e'_(1)[n-1])

	; For 1 <= m < M (recursion proper).
	do	w12,_endRecurse		; {	; do (M-2)+1 times
						; w12 available for reuse
	; Compute recursive terms.
	mov	[w8++],w5			; w5 = k[m-1]
						; w8-> k[m]

	; Upper branch: e_(m)[n] = e_(m-1)[n] - k_(m-1)*e'_(m-1)[n-1].
	msc	w5*w6,a				; a  = e_(m)[n]

	; Lower branch: e'_(m)[n] = -k_(m-1)*e_(m-1)[n] + e'_(m-1)[n-1].
	lac	w6,b				; b  = e'_(m-1)[n-1]
	msc	w5*w7,b				; b  = e'_(m)[n]

	; Update.
	mov	[w9],w6				; w6 = e'_(m)[n-1]
	sac.r	b,[w9++]			; save e'_(m)[n]
						; w9-> del[m+1] (e'_(m+1)[n-1])
_endRecurse:
	sac.r	a,w7				; w7 = e_(m)[n]
; }

	; For m = M (generate output).
	; y[n] = e_(M)[n] = e_(M-1)[n] - k_(M-1)*e'_(M-1)[n-1].
	mov	[w8],w5				; w5 = k[M-1]
	msc	w5*w6,a				; a  = e_(M)[n]

	sac.r	a,[w1++]			; save y[n] = e_(M)[n]
						; w1-> y[n+1]

	; Rewind pointers.
	mov	w10,w8				; w8-> k[0]
_endFilter:
	mov	w11,w9				; w9-> del[0]
; }

	pop	w0				; restore return value

;............................................................................

	; Restore PSVPAG and CORCON.
	pop	PSVPAG
	pop	CORCON

;............................................................................

	; Restore working registers.
	pop	w12				; w12 from TOS
	pop.d	w10				; {w10,w11} from TOS
	pop.d	w8				; {w8,w9} from TOS

;............................................................................

	return	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.end

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; OEF
