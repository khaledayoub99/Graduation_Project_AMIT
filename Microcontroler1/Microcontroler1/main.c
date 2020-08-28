/*
 * Microcontroler1.c
 *
 * Created: 8/19/2020 10:26:49 PM
 * Author : khaled Mohamed
 */ 


#include "SPI.h"
#include "LED.h"
#include "LCD.h"
#include "Temp_Sensor.h"
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	LCD_Init();
	TempSensor_Init();
	SPI_Slave_Init();
	LED0_Init();
	LED1_Init();
	LED2_Init();
	
	uint8 data  = 0 ;
	uint8 coun1 = 0 ;
	uint8 coun2 = 0 ;
	uint8 coun3 = 0 ;
	uint16 temp = 0 ;
	
    

	LCD_GoTo(0,2);
	LCD_WriteString("w e l c o m e");
	LCD_GoTo(1,2);
	LCD_WriteString("IN SMART HOME");
	_delay_ms(1000);
	LCD_Clear();
	
    while (1) 
    {
		data = SPI_TranSiver(0);
		
		if (data == '1')
		{
			
			LED0_toggle();
			LCD_GoTo(0,0);
			coun1 ++ ;
			if (coun1==1)
			{
				LCD_WriteString("LED1 ON ");
			}
			else
			{
				LCD_WriteString("LED1 OFF");
				coun1 = 0;
			}
		}
		else if (data == '2')
		{
			LED1_toggle();
			LCD_GoTo(0,8);
			coun2 ++ ;
			if (coun2==1)
			{
				LCD_WriteString("LED2 ON ");
			}
			else
			{
				LCD_WriteString("LED2 OFF");
				coun2 = 0;
			}
		}
		else if (data == '3')
		{
			LED2_toggle();
			LCD_GoTo(1,0);
			coun3 ++ ;
			if (coun3==1)
			{
				LCD_WriteString("LED3 ON ");
			}
			else
			{
				LCD_WriteString("LED3 OFF");
				coun3 = 0;
			}
			
		}
		else if (data == '4')
		{
			TempSensor_Read(&temp);
			LCD_GoTo(1,9);
			LCD_WriteString("Temp=");
			LCD_WriteInteger(temp);
		}
    }
}

