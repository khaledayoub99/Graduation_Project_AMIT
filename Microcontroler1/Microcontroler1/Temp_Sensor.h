
#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"

void TempSensor_Init(void);


void TempSensor_Read(uint16 *temp);


#endif /* TEMP_SENSOR_H_ */