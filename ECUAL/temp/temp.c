/*
 * temp.c
 *
 * Created: 4/23/2023 9:49:12 AM
 *  Author: ebrahem
 */ 


#include "temp.h"

void Temp_init(PIn_name channel)
{
	ADC_init(PINA0 , AVCC,Single_ended, ADCLL , FACTOR_2,channel);
}


uint8_t Temp_Read(PIn_name channel)
{
	uint8_t result = ADC_Read(channel);
	
	return result;
}