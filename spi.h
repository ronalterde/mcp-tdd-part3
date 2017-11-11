#pragma once

#include <stdint.h>

class AvrSpiDriver {
public:
	AvrSpiDriver();
	void select();
	void deselect();
	uint8_t read();
	void write(uint8_t value);
};
