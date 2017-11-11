#include "spi.h"

#include <stdint.h>
#include <assert.h>
#include <avr/io.h>

#define SPI_DDR DDRB
#define SS_DD DDB4
#define MOSI_DD DDB5
#define MISO_DD DDB6
#define SCK_DD DDB7

#define SPI_PORT PORTB
#define SS_P PB4
#define MOSI_P PB5
#define MISO_P PB6
#define SCK_P PB7

AvrSpiDriver::AvrSpiDriver() {
	SPI_DDR |= (1<<SS_DD) | (1<<MOSI_DD) | (1<<SCK_DD);
	SPI_DDR &= ~(1<<MISO_DD);
	
	SPCR =	(1<<SPE) |		// Enable
			(1<<MSTR) |		// Master
			(1<<SPR0);		// Clock rate
}

void AvrSpiDriver::select() {
	SPI_PORT &= ~(1<<SS_P);
}

void AvrSpiDriver::deselect() {
	SPI_PORT |= (1<<SS_P);
}

uint8_t AvrSpiDriver::read() {
	SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

void AvrSpiDriver::write(uint8_t value) {
	SPDR = value;
	while(!(SPSR & (1<<SPIF)))
		;
}
