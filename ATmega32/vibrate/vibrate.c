#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void main(){
	DDRB &= ~(1 << 0);
	PORTB &= ~(1 << 0);
	
	lcd_init(LCD_DISP_ON_CURSOR);
	lcd_home();
	lcd_clrscr();

	lcd_puts("Hellow LCD!");
	lcd_gotoxy(0,1);
	lcd_puts("Bring it in guys");
	_delay_ms(5000);

	while(1){
		lcd_gotoxy(0,1);
		lcd_puts("^_^");
		_delay_ms(1000);
		lcd_gotoxy(0,1);
		lcd_puts("^_-");
		_delay_ms(500);
	}
}
