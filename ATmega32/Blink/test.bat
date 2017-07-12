avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o LCD.o LCD.c
avr-gcc -w -mmcu=atmega32 LCD.o -o LCD
avr-objcopy -O ihex -R .eeprom LCD LCD.hex
avrdude -c stk500v1 -b 19200 -p ATmega32 -P /dev/ttyACM0 -U flash:w:LCD.hex:i

