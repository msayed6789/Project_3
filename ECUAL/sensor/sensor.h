/*
 * sensor.h
 *
 * Created: 4/20/2023 11:17:16 AM
 *  Author: ebrahem
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include "adc.h"

void Temp_init(PIn_name channel);

uint8_t Temp_Read(PIn_name channel);



#endif /* SENSOR_H_ */
