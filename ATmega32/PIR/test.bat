avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o pir.o pir.c
avr-gcc -w -mmcu=atmega32 pir.o -o pir
avr-objcopy -O ihex -R .eeprom pir pir.hex
