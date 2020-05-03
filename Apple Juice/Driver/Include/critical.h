// Copyright (c) 2020 Bjørn Brodtkorb
//
// This software is provided without warranty of any kind.
// Permission is granted, free of charge, to copy and modify this
// software, if this copyright notice is included in all copies of
// the software.

#ifndef CRITICAL_H
#define CRITICAL_H

//------------------------------------------------------------------------------------//

#include <stdint.h>

//------------------------------------------------------------------------------------//

// Disable interrupt
// Mutex atomic operating

void cpu_critical_enter(volatile uint32_t* irq_state);

void cpu_critical_leave(volatile uint32_t* irq_state);

// Disable interrupt get the state
// Restore the state

//------------------------------------------------------------------------------------//

#define critical_enter();				\
{										\
	volatile uint32_t irq_state;		\
	cpu_critical_enter(&irq_state);

#define critical_leave();				\
	cpu_critical_leave(&irq_state);		\
}

//------------------------------------------------------------------------------------//

#endif