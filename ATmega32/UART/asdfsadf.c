#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void main(){
	
	DDRD |= 1 << 6;

	while(1){
	PORTD ^= 1 << 6;
	_delay_ms(500);
	}
}
