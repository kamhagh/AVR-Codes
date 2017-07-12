avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o lcd.o lcd.c

avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o vibrate.o vibrate.c

avr-gcc -w -mmcu=atmega32 vibrate.o lcd.o -o vibrate


avr-objcopy -O ihex -R .eeprom vibrate vibrate.hex


avrdude -c arduino -p atmega32 -P COM3 -b 19200 -U flash:w:vibrate.hex