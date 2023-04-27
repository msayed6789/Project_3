/*
 * sensor.h
 *
 * Created: 4/20/2023 11:17:16 AM
 *  Author: ebrahem
 */


#ifndef SENSOR_H_
#define SENSOR_H_

#include "adc.h"
#include "dio.h"

void Temp_init(PIn_name channel);

void Temp_Read(PIn_name channel,f32* temp);



#endif /* SENSOR_H_ */
