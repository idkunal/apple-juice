// Copyright (c) 2020 Bjørn Brodtkorb
//
// This software is provided without warranty of any kind.
// Permission is granted, free of charge, to copy and modify this
// software, if this copyright notice is included in all copies of
// the software.

#include "gpio.h"
#include "critical.h"

//------------------------------------------------------------------------------------//

void gpio_write_protection_disable(Pio* port)
{
	critical_enter();
	port->PIO_WPMR = (PIO_WPMR_WPKEY_PASSWD_Val << PIO_WPMR_WPKEY_Pos);
	critical_leave();
}

//------------------------------------------------------------------------------------//

void gpio_write_protection_enable(Pio* port)
{
	critical_enter();
	 port->PIO_WPMR = (PIO_WPMR_WPKEY_PASSWD_Val << PIO_WPMR_WPKEY_Pos) | 
		(1 << PIO_WPMR_WPEN_Pos);
	critical_leave();
}

//------------------------------------------------------------------------------------//