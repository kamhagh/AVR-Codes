#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void main()
{
		int n;
		char buffer[10];
		DDRB &= ~(1 << 0);
		PORTB |= 1 << 0;
    lcd_init(LCD_DISP_ON_CURSOR);
    lcd_clrscr();
		lcd_home();
		
    while(1)
    {
 
				if(((PINB & 1 << 0) == 1)){
					lcd_gotoxy(0,0);
					lcd_puts("0,0 i am an owl!");
					lcd_gotoxy(0,1);
				lcd_puts("0,0");
				_delay_ms(1000);
				lcd_gotoxy(0,1);
				lcd_puts("~,~");
				_delay_ms(300);

				} else {
					lcd_gotoxy(0,0);
					lcd_puts("i am a cat ! ^_^");
					lcd_gotoxy(0,1);
					lcd_puts("^,^");
					_delay_ms(1000);
					lcd_gotoxy(0,1);
					lcd_puts("-,-");
					_delay_ms(300);
				}
 
    }
}

