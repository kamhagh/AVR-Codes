avr-gcc -g -Os -mmcu=atmega32 -c Servo.c
avr-gcc -g -mmcu=atmega32 -o Servo.elf Servo.o
avr-objcopy -j .text -j .data -O ihex Servo.elf Servo.hex

