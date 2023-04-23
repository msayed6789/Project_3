/*
 * temp.h
 *
 * Created: 4/20/2023 11:17:16 AM
 *  Author: ebrahem
 */ 


#ifndef TEMP_H_
#define TEMP_H_

#include "ADC.h"

void Temp_init(PIn_name channel);

uint8_t Temp_Read(PIn_name channel);



#endif /* TEMP_H_ */
