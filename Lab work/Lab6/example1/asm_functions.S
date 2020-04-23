#include "avr/io.h"
.global setpin
setpin:
sbi _SFR_IO_ADDR(DDRB), 7 ; sets bit 7 of DDRB to 1 - output
ret
.global turnon
turnon:
sbi _SFR_IO_ADDR(PORTB), 7 ; sets bit 7 of PORTB to 1
ret
.global turnoff
turnoff:
cbi _SFR_IO_ADDR(PORTB), 7 ; sets bit 7 of PORTB to 0
ret
