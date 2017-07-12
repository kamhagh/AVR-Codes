#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"

	uint8_t OF = 0;
	char BPPSc[3];
	char BPPMc[5];
	uint8_t hits = 0;
	uint8_t BPPS = 0;	
	uint16_t BPPM = 0;

void main (){

	lcd_init(LCD_DISP_ON_CURSOR);
	lcd_clrscr();
	TIMSK1 |= 1 << TOIE1;
	sei();
	TCCR1B |= 1 << CS10;

	while(1)
	{
		if(bit_is_set(PINB,0)){
			hits++;
		while(bit_is_set(PINB,0));
		}
	}
}

ISR(TIMER1_OVF_vect)
{
	OF++;
	if(OF >= 244){
		lcd_clrscr();
		BPPS = hits;
		BPPM = hits * 60 ;
		lcd_puts("BPPS : ");
		itoa(BPPS,BPPSc,10);
		lcd_puts(BPPSc);
		lcd_gotoxy(0,1);
		lcd_puts("BPPM : "); 
		itoa(BPPM,BPPMc,10);
		lcd_puts(BPPMc);	
		hits = 0;
		OF = 0;
		}
}
