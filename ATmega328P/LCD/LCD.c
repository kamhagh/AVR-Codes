#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>
#define F_CPU 16000000UL


#include "lcd.h"

void adc_init()
{
    // AREF = AVcc
   ADMUX = (1<<REFS0);
   // ADC Enable and prescaler of 128
   // 16000000/128 = 125000
   ADCSRA = (1<<ADEN)/*| (1<<ADPS2) */| (1<<ADPS1) | (1<<ADPS0); 
}

uint16_t adc_read(uint8_t ch)
{
    // select the corresponding channel 0~7
   // remove the 'old' channel bits
   // add the 'new' channel bits.
   ADMUX = (ADMUX & ~7) | (ch & 7);
   // start single convertion
   // write '1' to ADSC
   ADCSRA |= (1<<ADSC);
   // wait for convertion to complete
   // ADSC becomes '0' again
   // till then, run loop continuously
   while(ADCSRA & (1<<ADSC));
   return (ADC); 
}

void main()
{	
		char buffer[10];
		adc_init();
    lcd_init(LCD_DISP_ON_CURSOR);
    lcd_clrscr();
		lcd_home();
		
		
    while(1)
    {
			lcd_puts("ADC_PIN0 value:");
			lcd_gotoxy(0,1);
			itoa(adc_read(0), buffer, 10);
			lcd_puts(buffer);
			_delay_ms(500);
			lcd_clrscr();
			
    }
}

