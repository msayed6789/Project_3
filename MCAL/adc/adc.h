/*
 * ADC.h
 *
 * Created: 4/19/2023 4:39:23 PM
 *  Author: ebrahem
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "dio.h"
/***********************ADMUX******************************/

////////////////////////////////////
#define AREF			0
#define AVCC			1
#define REVERSED		2
#define INTERNAL		3
/////////////////////////////////////
#define REFS1			7
#define REFS0			6
#define ADLAR			5
#define MUX4			4
#define	MUX3			3
#define MUX2			2
#define MUX1			1
#define MUX0			0
//////////////////////////////////////
#define ADCLL			0
#define ADCHH			1
///////////////////////////////////////
#define Single_ended	0
#define POS_DIFF		1
#define NEG_DIFF		2
///////////////////////////////////////

/*****************************************ADCSRA***************************************/

#define ADEN			7
#define ADSC			6
#define ADATE			5
#define ADIF			4
#define ADIE			3
#define ADPS2			2
#define ADPS1			1
#define ADPS0			0

///////////////////////////////////////////////////////

#define FACTOR_2		"001"
#define FACTOR_4		"010"
#define FACTOR_8		"011"
#define FACTOR_16		"100"
#define FACTOR_32		"101"
#define FACTOR_64		"110"
#define FACTOR_128		"111"

///////////////////////////////////////////////////////

#define Sensor_res		(float)1





void ADC_init(PIn_name channel, u8 V_ref_type , u8 Diff_OR_Single , u8 ADCH_OR_ADCL , u8 *prescaler , u8 INT_init);

u16 ADC_Read(PIn_name channel);



#endif /* ADC_H_ */
