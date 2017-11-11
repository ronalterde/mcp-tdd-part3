#include "can.h"
#include "spi.h"
#include "boilerplate.h"

int main() {
	AvrSpiDriver spiDriver;
	Mcp2515Core<AvrSpiDriver> mcpCore{spiDriver};

	while(1) {
		mcpCore.reset();
	}
	return 0;
}
