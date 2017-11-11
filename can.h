/*
 * This little piece of code has been created using TDD
 * in the second episode of the blog series:
 * http://steffen.ronalter.de/2017/10/15/test-driving-the-mcp2515-can-controller-part-2/
 */

#pragma once

#include <stdint.h>

template <typename SpiDriver>
class Mcp2515Core {
public:
	Mcp2515Core(SpiDriver& spiDriver) :
		spiDriver(spiDriver) {
	}

	void reset() {
		spiDriver.select();
		spiDriver.write(0xC0);
		spiDriver.deselect();
	}

private:
	SpiDriver& spiDriver;
};
