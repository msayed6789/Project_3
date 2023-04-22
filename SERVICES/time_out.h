/*
 * timer_interrupt.h
 *
 * Created: 4/19/2023 9:59:56 PM
 *  Author: lenovo
 */ 


#ifndef TIMER_INTERRUPT_H_
#define TIMER_INTERRUPT_H_
#include "interrupt_service.h"
#include "Timers.h"
//intial values
#define zero_intial 0x00
#define Intial_value_time_out 0x0F  // ff -0f = 240 * 4 loops = 960 us which there is 40 us consumed by program
//prescaler values
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05

void TIME_out (u32 milliseconds);


#endif /* TIMER_INTERRUPT_H_ */