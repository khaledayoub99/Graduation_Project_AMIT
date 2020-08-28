
#include "Temp_Sensor.h"


void TempSensor_Init(void)
{
	ADC_Init();
}


void TempSensor_Read(uint16 *temp)
{
	ADC_Read(temp);
}