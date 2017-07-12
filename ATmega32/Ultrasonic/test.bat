avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega32 -c -o ultrasonic.o ultrasonic.c
avr-gcc -w -mmcu=atmega32 ultrasonic.o lcd.o -o ultrasonic
avr-objcopy -O ihex -R .eeprom ultrasonic ultrasonic.hex
avrdude -c stk500v1 -P /dev/ttyACM0 -b 19200 -p ATmega32 -U flash:w:ultrasonic.hex:i


