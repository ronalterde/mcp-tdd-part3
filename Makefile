MCU = atmega32
CXX = avr-g++
CXXFLAGS = -mmcu=$(MCU) -std=c++11 -O0 -fno-rtti -Wall

.PHONY: all
all: main.hex

%.hex: %.elf
	avr-objcopy -O ihex $< $@

main.elf: main.o spi.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp boilerplate.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

spi.o: spi.cpp spi.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.hex

.PHONY: fuse
fuse:
	avrdude -p $(MCU) -c usbtiny -U lfuse:w:0xe1:m -U hfuse:w:0x99:m 

.PHONY: program
program: main.hex
	avrdude -p $(MCU) -c usbtiny -U flash:w:$<
