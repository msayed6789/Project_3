/*
 * sensor.c
 *
 * Created: 4/23/2023 9:49:12 AM
 *  Author: ebrahem
 */


 #include "sensor.h"

 void Temp_init(PIn_name channel)
 {
 ADC_init(PINA0 , AVCC, Single_ended, ADCHH , FACTOR_64 ,channel);
 }


 void Temp_Read(PIn_name channel,f32* temp)
 {
	u16 adc=ADC_Read(channel);
	 
 *temp= ((f32)adc*150)/307.2;
 
 }
