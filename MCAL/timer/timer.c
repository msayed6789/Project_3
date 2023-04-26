/*
 * timer.c
 *
 * Created: 4/6/2023 11:14:21 PM
 *  Author: MOHAMED ABDELSALAM
 */ 

#include "timer.h"


void TIMER_init (u8 Mode,u8 intial_value){
//choose timer mode
TCCR0 &= Mode;
//TimerSet initial value
TCNT0 = intial_value;
}
void TIMER_start (u8 prescaler_value){

TCCR0 |= prescaler_value;  //Set Pre_scaler, for ex:ck(source)(8MHz)/8 to get,
//T(tick) = 1 microseconds
//Stop after one overflow 250 microseconds
}
void TIMER_set(u8 intial_value){
//TimerSet initial value
TCNT0 = intial_value;
}
void TIMER_getStatus(u8 *value){
	if ((TIFR & clear_T0) == 0)
	{
		*value = 0x01;
	}
	else if ((TIFR & clear_T0) == 1)
	{
		*value = 0x00;
		TIFR |= clear_T0;
	}
}
	void TIMER_Stop (void){
		//Timer Stop
		TCCR0 = no_clk;	
	}
/*****************************************************Timer_2***********************************************************/
void TIMER2_init (u8 Mode,u8 intial_value){
	//choose timer mode
	TCCR2 &= Mode;
	//TimerSet initial value
	TCNT2 = intial_value;
}
void TIMER2_start (u8 prescaler_value){

	TCCR2 |= prescaler_value;  //Set Pre_scaler, for ex:ck(source)(8MHz)/8 to get,
	//T(tick) = 1 microseconds
	//Stop after one overflow 250 microseconds
}
void TIMER2_set(u8 intial_value){
	//TimerSet initial value
	TCNT2 = intial_value;
}
void TIMER2_getStatus(u8 *value){
	if ((TIFR & clear_T2) == 0)
	{
		*value = 0x01;
	}
	else if ((TIFR & clear_T2) == 1)
	{
		*value = 0x00;
		TIFR |= clear_T2;
	}
}
void TIMER2_Stop (void){
	//Timer Stop
	TCCR2 = no_clk;
}
