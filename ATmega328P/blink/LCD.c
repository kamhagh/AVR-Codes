#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

void main() {
	DDRB |= 1 << 1 | 1 << 3 | 1 << 2;
	DDRB &= ~_BV(PINB0);
	DDRD &= ~_BV(PIND3);
	DDRD &= ~_BV(PIND2);
	TCCR1A |= _BV(WGM10) | _BV(WGM11) | _BV(COM1A1) | _BV(COM1B1);
	TCCR1B |= _BV(WGM12) | _BV(CS20);
	TCCR2A |= _BV(WGM20) | _BV(WGM21) | _BV(COM2A1);
 	TCCR2B |= _BV(WGM12) | _BV(CS10);
	OCR1A = 0;
	OCR2A = 0;
	OCR1B = 0;

	while(1){
	if(bit_is_set(PINB,0)){
		OCR1A++;
		if(OCR1A >= 1024) 
			OCR1A = 0;
		_delay_ms(100);
	}
	if(bit_is_set(PIND,3)){
		OCR1B++;
		if(OCR1B >= 1024)
			OCR1B = 0;
		_delay_ms(100);
	}
	if(bit_is_set(PIND,4)){
		OCR2A++;
		if(OCR2A >= 1024)
			OCR2A = 0;
		_delay_ms(100);
	}

	}
}
