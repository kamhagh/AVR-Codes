/*
 * smooth.cpp
 *
 * Created: 15-Jan-14 12:55:38 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= 1 << 5; //OC0 pin as output
	
	TCCR1A |= 1 << WGM10 | 1 << WGM12 | 1 << COM1A1; 
	TCCR1B |= 1 << CS10 ;
	
	OCR1A = 123; //50% duty
	
    while(1)
    {
    }
}