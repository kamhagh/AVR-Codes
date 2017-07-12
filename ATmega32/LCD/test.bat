avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o LCD.o LCD.c
avr-gcc -w -mmcu=atmega32 LCD.o lcd.o -o LCD
avr-objcopy -O ihex -R .eeprom LCD LCD.hex
