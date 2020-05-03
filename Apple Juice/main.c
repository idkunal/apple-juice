#include "sam.h"
#include "gpio.h"



int main(void) {
	// Comfigure the system
	
	
	// Try to turn on the on-board LED
	PIOC->PIO_PER = (1 << 8);
	PIOC->PIO_OER = (1 << 8);
	PIOC->PIO_CODR = (1 << 8);
	
	gpio_write_protection_disable(PIOC);
	
	while (1) {
		
	}
}