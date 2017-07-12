avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lcd.o lcd.c
avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o BPM.o BPM.c
avr-gcc -w -mmcu=atmega328p BPM.o lcd.o -o BPM
avr-objcopy -O ihex -R .eeprom BPM BPM.hex
avrdude -c stk500v1 -b 19200 -P /dev/ttyACM0 -p ATmega328P -U flash:w:BPM.hex:i
