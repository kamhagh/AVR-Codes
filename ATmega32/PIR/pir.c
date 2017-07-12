#define note 5405
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/delay.h>


void main(){

	DDRB &= ~(1 << 0); 
	DDRB |= 1 << 1;
	while(1){
		
		if(bit_is_set(PINB,0)){
			PORTB |= 1 << 1;
				} else {
				PORTB &= ~(1 << 1);
			}
		}			
}	
