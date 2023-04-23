/*
 * sensor.c
 *
 * Created: 4/23/2023 9:49:12 AM
 *  Author: ebrahem
 */ 


#include "sensor.h"

void sensor_init(PIn_name channel)
{
	ADC_init( channel , AVCC,Single_ended, ADCLL , FACTOR_2,0);
}


uint32_t sensor_Read(PIn_name channel)
{
	uint8_t result = ADC_Read(channel);
	
	return result;
}
