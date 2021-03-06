#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

double getDistance(){
uint16_t t1 = 0, t2 = 0;                                     // Containers for two timestamps

	//_delay_ms(100);

	PORTB|=1<<0;          // Simple steps for generating
	_delay_us(12);                    // a trigger pulse at trigger pin
	PORTB&=~(1<<0) ;       //
	TCCR1A = 0;                                                        // Timer operating freq is 		16MHz/64 (from prescalar)
	TCCR1B = 0x43;                                                 // gives min. resolution of 4us
	// ICES1 = 1 for rising edge detection on ICP1
	while((TIFR&(1<<ICF1))==0);                   // polled until rising edge detected

	t1 = ICR1L;                                                           // Storing the timer value
	t1 |= ICR1H<<8;
	
	TIFR |= 1<<ICF1;                                            // Clearing the flag for next use
	TCCR1B = 0x03;   
	//lcd_puts("First");
	//_delay_us(1);                                             // ICES1 = 0 for falling detection
	while((TIFR & (1 << ICF1)) == 0); 
	//lcd_puts("second");                // polled until falling edge detected
	t2 = ICR1L;                                                           // Storing the timer value
	t2 |= ICR1H<<8;
	TIFR |= 1<<ICF1;                                            // Clearing the flag for next use
	TCCR1B = 0;                                                        // Stopping the timer
	 
	return (double)((t2-t1)*4)/58;                   // Measure to give result in terms of cm
	}

void main()
{
	double f;	
	char buffer[10];
	
	DDRB |= 1 << 0;
	DDRD &= ~(1 << 6);
	
	lcd_init(LCD_DISP_ON_CURSOR);
	lcd_home;
	lcd_clrscr;
	lcd_puts("Distance:");
	while(1)
	{
		f = getDistance();
		dtostrf(f,1,3,buffer);
		//sprintf(buffer, "%f", f);
		lcd_gotoxy(0,1);
		lcd_puts(buffer);
		lcd_puts("cm");
		_delay_ms(300);

	}
}
