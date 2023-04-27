/*
 * ADC.c
 *
 * Created: 4/20/2023 11:19:14 AM
 *  Author: ebrahem
 */ 

#include "adc.h"


void ADC_init(PIn_name channel, u8 V_ref_type , u8 Diff_OR_Single , u8 ADCH_OR_ADCL , u8 *prescaler , u8 INT_init)
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
		CLR_Bit(ADMUX,ADLAR);
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

#include "LCD.h"
u16 ADC_Read(PIn_name channel)
{
	ADMUX |= (0 & 0x0f);
	
	ADCSRA |= (1<<ADSC);
	
	while((ADCSRA & (1<<ADIF)) == 0);
     
     CLR_Bit(ADCSRA,ADIF);
	u16 digitalVal = (u16)ADCL | ((u16)ADCH<<8);
	
	
	return digitalVal ; 
	
}
