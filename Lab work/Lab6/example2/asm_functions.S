#include "avr/io.h"
.global setpin
setpin:
sbi _SFR_IO_ADDR(DDRB), 7 ; sets bit 7 of DDRB to 1 - output
ret
.global turnspecified
turnspecified:
tst r24 ; r24 will hold the parameter of the
; function, test it for zero
breq set0 ; if zero, go set the pin to 0
sbi _SFR_IO_ADDR(PORTB), 7 ; otherwise set it to 1
rjmp finish
set0:
cbi _SFR_IO_ADDR(PORTB), 7 ; set to zero
finish:
ret
