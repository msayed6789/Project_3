/*
 * ADC.c
 *
 * Created: 4/20/2023 11:19:14 AM
 *  Author: ebrahem
 */ 

#include "ADC.h"


void ADC_init(PIn_name channel, uint8_t V_ref_type , uint8_t Diff_OR_Single , uint8_t ADCH_OR_ADCL , uint8_t *prescaler , uint8_t INT_init)
{
	// choose pin_num
	DIO_InitPin(channel,INPUT);
	
	//choose V_ref
	if(V_ref_type == AVCC || V_ref_type == INTERNAL)
	{
		ADMUX |= (1<<REFS0);
	}
	if(V_ref_type == REVERSED || V_ref_type == INTERNAL)
	{
		ADMUX |= (1<<REFS1);
	}
	
	//choose ADCH or ADCL
	if(ADCH_OR_ADCL == ADCHH)
	{
		ADMUX |= (1<<ADLAR);
	}
	
	
	// ENABLE ADC
	
	ADCSRA |= (1<<ADEN);
	
	//choose prescaler
	
	if(prescaler[0] == '1')
	{
		ADCSRA |= (1<<ADPS0);
	}
	
	if(prescaler[1] == '1')
	{
		ADCSRA |= (1<<ADPS1);
	}
	if(prescaler[2] == '1')
	{
		ADCSRA |= (1<<ADPS2);
	}
	
	//using interrupt or not
	
	if(INT_init == 1)
	{
		ADCSRA |= (1<<ADIE);
	}
	
}


uint8_t ADC_Read(PIn_name channel)
{
	ADMUX |= (0 & 0x0f);
	
	ADCSRA |= (1<<ADSC);
	
	while((ADCSRA & (1<<ADIF)) == 0);
	
	uint16_t digitalVal = ADCL + (ADCH<<8);
	//DDRC = 0xff;
	//DDRD |= (1<<0) | (1<<1);
	//PORTC = (uint8_t)digitalVal;
	//PORTD = (uint8_t)(digitalVal>>8);
	volatile float analogVal = digitalVal * (5.0 / 1024.0);
	
	volatile float SensorVal = analogVal; 
	
	uint8_t result = SensorVal * 100 ;
	
	return result ; 
	
}


