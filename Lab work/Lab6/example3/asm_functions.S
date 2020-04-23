#include "avr/io.h"
.global Serial_Setup
Serial_Setup:
; Configure the parameters of serial interface 0
clr r0
sts UCSR0A, r0
ldi r24, 1<<RXEN0 | 1 << TXEN0 ; enable Rx & Tx
sts UCSR0B, r24
ldi r24, 1 << UCSZ00 | 1 << UCSZ01 ; asynchronous, no parity, 1 stop, 8 bits
sts UBRR0H, r0
ldi r24, 103
sts UBRR0L, r24
ret
.global Print_Hello
Print_Hello:
; load the starting address of the string in the Z pointer
ldi ZL, lo8(the_message) ; r30
ldi ZH, hi8(the_message) ; r31
lpm r18, Z+ ; Load the first character of the string in r18
Loop:
lds r17, UCSR0A
sbrs r17, UDRE0 ; test the data buffer if data can be transmitted
rjmp Loop
sts UDR0, r18 ; send data contained in r18
lpm r18, Z+ ; load the next character
tst r18 ; check if 0 – the string ends
brne Loop
ret
the_message: ; the message itself, followed by LF and CR, and 0
.ascii "Assembly is fun"
.byte 10, 13,0
