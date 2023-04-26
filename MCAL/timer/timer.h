/*
 * timer.h
 *
 * Created: 4/6/2023 11:16:46 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "memmap.h"
#include "utlise.h"
#include "standard_type.h"


#define normal 0x00
#define no_clk 0x00
#define zero_intial 0x00
#define ticks_250 0x07 
#define ticks_16 0xFB  
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear_T0 0x01
void TIMER_init (u8 Mode,u8 intial_value);
void TIMER_start (u8 prescaler_value);
void TIMER_set(u8 intial_value);
void TIMER_getStatus(u8 *value);
void TIMER_Stop (void);


/**************************************************Timer_2***************************************************************/

#define normal 0x00
#define no_clk 0x00
#define zero_intial 0x00
#define ticks_250 0x07
#define ticks_100 0x9C
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear_T2 0x40
void TIMER2_init (u8 Mode,u8 intial_value);
void TIMER2_start (u8 prescaler_value);
void TIMER2_set(u8 intial_value);
void TIMER2_getStatus(u8 *value);
void TIMER2_Stop (void);













#endif /* TIMER_H_ */