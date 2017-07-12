#ifndef _main_h_
#define _main_h_


#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "mydefs.h"


#define	XTAL	16000000UL			// 8MHz

#define F_CPU   XTAL
#include <util/delay.h>


#define	LCD_D4		SBIT( PORTB, 0 )
#define	LCD_DDR_D4	SBIT( DDRB, 0 )

#define	LCD_D5		SBIT( PORTB, 4 )
#define	LCD_DDR_D5	SBIT( DDRB, 4 )

#define	LCD_D6		SBIT( PORTB, 3 )
#define	LCD_DDR_D6	SBIT( DDRB, 3 )

#define	LCD_D7		SBIT( PORTB, 5 )
#define	LCD_DDR_D7	SBIT( DDRB, 5 )

#define	LCD_RS		SBIT( PORTB, 2 )
#define	LCD_DDR_RS	SBIT( DDRB, 2 )

#define	LCD_E0		SBIT( PORTB, 1 )
#define	LCD_DDR_E0	SBIT( DDRB, 1 )


#endif
