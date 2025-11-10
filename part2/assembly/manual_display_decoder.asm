;logical AND, OR and XOR operations
;output displayed using 7447 IC

.include "/home/ubuntu/DigitalWorkshop/part2/m328Pdef.inc"

;defining output pins
ldi r20,0b00111111
out DDRB,r20	;pins 8(b) to 13(g) to store () values
ldi r20,0b10000000
out DDRD,r20	;pin7 to store a

ldi r17,0b00000001 ;#complement
ldi r16,0b00000000	
mov r06,r16	;A
mov r11,r06
eor r11,r17	;A'
ldi r16,0b00000000
mov r07,r16	;B
mov r12,r07
eor r12,r17	;B'
ldi r16,0b00000000
mov r08,r16	;C
mov r13,r08
eor r13,r17	;C'
ldi r16,0b00000001
mov r09,r16	;D
mov r14,r09
eor r14,r17	;D'

;defining a
rcall init
or r17,r08
and r17,r12
and r17,r11	;we now have first product CB'A'
or r18,r14
and r18,r13
and r18,r12
and r18,r06	;second product D'C'B'A
or r17,r18
ldi r22,0b00000111	;counter
rcall bitloop
out PORTD,r17 	;value of a sent!

;defining b
rcall init
;we use simplified expression C(A xor B)
or r17,r06
eor r17,r07
and r17,r08	;r17 now has our output
mov r10,r17	;store it safely for the time-being

;defining c
rcall init
or r17,r13
and r17,r07
and r17,r11	;C'BA' in r17
ldi r23,0b00000001	;counter init
mov r22,r23
rcall bitloop
or r10,r17	;stored safely!

;defining d
rcall init
or r17,r06
eor r17,r08
and r17,r12	;now have B'(A xor C)
or r18,r06
and r18,r07
and r18,r08	;now have CBA
or r17,r18	;final expression stored
inc r23		;increment counter
mov r22,r23	;counter transfer for loop
rcall bitloop
or r10,r17	;stored safely

;defining e
rcall init
or r17,r12
and r17,r08
or r17,r06	;now have A+B'C
inc r23
mov r22,r23 ;counter for loop
rcall bitloop
or r10,r17	;stored

;defining f
rcall init
or r17,r06
or r17,r13
and r17,r07	;result of B(A+C')
or r18,r14
and r18,r13
and r18,r06	;result of D'C'A
or r17,r18	;final result
inc r23
mov r22,r23	;temp for loop
rcall bitloop
or r10,r17

;defining g
rcall init
or r17,r14
and r17,r13
and r17,r12	;stored D'C'B'
or r18,r08
and r18,r07
and r18,r06	;stored CBA
or r17,r18
inc r23
mov r22,r23
rcall bitloop
or r10,r17

;we fill finally write the final value as our output
out PORTB,r10

Start:rjmp Start


init:	ldi r17,0b00000000 ;initialises both registers for next round
	ldi r18,0b00000000
	ret
	
	
bitloop:lsl r17
	dec r22
	brne bitloop
	ret
	

