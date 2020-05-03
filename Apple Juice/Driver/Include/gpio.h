// Copyright (c) 2020 Bjørn Brodtkorb
//
// This software is provided without warranty of any kind.
// Permission is granted, free of charge, to copy and modify this
// software, if this copyright notice is included in all copies of
// the software.

#ifndef GPIO_H
#define GPIO_H

//------------------------------------------------------------------------------------//

#include "sam.h"

//------------------------------------------------------------------------------------//

#include <stdint.h>

//------------------------------------------------------------------------------------//

enum gpio_direction
{
	GPIO_INPUT,
	GPIO_OUTPUT	
};

enum gpio_function
{
	GPIO_PERIPHERAL_A,
	GPIO_PERIPHERAL_B,
	GPIO_PERIPHERAL_C,
	GPIO_PERIPHERAL_D,
	GPIO_PERIPHERAL_OFF
};

//------------------------------------------------------------------------------------//

void gpio_write_protection_disable(Pio* port);

void gpio_write_protection_enable(Pio* port);

//------------------------------------------------------------------------------------//

#endif