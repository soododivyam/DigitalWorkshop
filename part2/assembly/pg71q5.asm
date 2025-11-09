;logical AND, OR and XOR operations
;output displayed using 7447 IC

.include "/home/ubuntu/DigitalWorkshop/part2/m328Pdef.inc"

ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output

ldi r16,0b00000111	;number stored as 0b0000ZYXW

mov r11,r16	;make a copy of input to store Z'Y'X'W'
rcall not
;we not have 0b0000Z'Y'X'W' in r11

;define A
ldi r18,0b00000001
and r18,r11
mov r13,r18
ldi r17,0b00000010	;count2
rcall loopw	;calling the loopw routine
mov r12,r13


;define B
ldi r17,0b00000010
and r17,r16
lsr r17		;r17 now has X
and r18,r17	;r18 now has W'X
ldi r19,0b00000001
and r19,r16
ldi r20,0b00000010
and r20,r11
lsr r20
ldi r21,0b00001000
and r21,r11
lsr r21
lsr r21
lsr r21
and r21,r20
and r21,r19
or r18,r21	;r18 now has B
ldi r17,0b00000011	;count3
mov r13,r18
rcall loopw
or r12,r13

;define C
ldi r17,0b00000100
and r17,r16	
lsr r17
lsr r17		;r17 now has Y
ldi r18,0b00000010
and r18,r11
lsr r18		
ldi r19,0b00000001
and r19,r11
or r18,r19
and r17,r18	;r17 now has (X'+W')Y
ldi r18,0b00000001
and r18,r16	;r18 has W
ldi r19,0b00000010
and r19,r16
lsr r19		;r19 has X
ldi r20,0b00000100
and r20,r11
lsr r20
lsr r20		;r20 now has Y'
and r20,r19
and r20,r18	
or r20,r17	;r20 now has C
mov r13,r20
ldi r17,0b00000100	;count4
rcall loopw
or r12,r13

;define D
ldi r17,0b00000100
and r17,r16
lsr r17
lsr r17		;r17 has Y
ldi r18,0b00000001
and r18,r16	;r18 now has W
ldi r19,0b00000010
and r19,r16
lsr r19		;r19 now has X
and r17,r18
and r17,r19	;r17 now has WXY
ldi r18,0b00001000
and r18,r16
lsr r18
lsr r18
lsr r18		;r18 now has Z
ldi r19,0b00000001
and r19,r11	;r19 now W'
and r19,r18	;r19 now has W'Z
or r19,r17	;r19 now has D
ldi r17,0b00000101	;count5
mov r13,r19
rcall loopw
or r12,r13	;r12 should now have the final output

out PORTD,r12		;writing output to pins 2,3,4,5


Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r13			;left shift
	dec r17			;counter --
	brne	loopw	;if counter != 0
	ret

not:	ldi r18,0b00001111
	eor r11,r18
	ret
