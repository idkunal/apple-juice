// Copyright (c) 2020 Bjørn Brodtkorb
//
// This software is provided without warranty of any kind.
// Permission is granted, free of charge, to copy and modify this
// software, if this copyright notice is included in all copies of
// the software.

#include "critical.h"
#include "cmsis_gcc.h"

//------------------------------------------------------------------------------------//

void cpu_critical_enter(volatile uint32_t* irq_state)
{
	// Save the interrupt state
	uint32_t irq_mask;
	asm volatile("mrs %0, primask" : "=r" (irq_mask) : : "memory");
	*irq_state = irq_mask;
	
	// Disable interrupt but let the fault handlers still run
	asm volatile("cpsid i" : : : "memory");
	
	// Data memory barrier
	asm volatile("dmb sy" : : : "memory");
}

//------------------------------------------------------------------------------------//

void cpu_critical_leave(volatile uint32_t* irq_state)
{
	// Restoring the interrupt state
	asm volatile("msr primask, %0" : : "r"(*irq_state) : "memory");
}

//------------------------------------------------------------------------------------//