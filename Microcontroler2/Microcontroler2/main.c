/*
 * Microcontroler2.c
 *
 * Created: 8/19/2020 10:29:02 PM
 * Author : khaled mohamed
 */ 


#include "bluetooth.h"
#include "SPI.h"
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	uint8 Uart_data = 0;
	uint8 pass[4]={'1','2','3','4'};
	uint8 pass_try[4]={0};
	
	LCD_Init();
	
	bluetooth_Init();
    
	SPI_Master_Init();
	
	SPI_Master_InitTrans();
	
	LCD_GoTo(0,2);
	LCD_WriteString("w e l c o m e");
	LCD_GoTo(1,2);
	LCD_WriteString("IN SMART HOME");
	_delay_ms(1000);
	while(1){
	LCD_Clear();
	
	LCD_WriteString("    password:    ");
	uint8 i =0;
	LCD_GoTo(1,5);
	while(i<4)
	{
		Uart_data = bluetooth_ReceiveByte();
		LCD_WriteChar(Uart_data);
		LCD_WriteString(" ");
		pass_try[i]=Uart_data ;
		i++;
	}
	
	if (pass_try[0]==pass[0]&&pass_try[1]==pass[1]&&pass_try[2]==pass[2]&&pass_try[3]==pass[3])
	{
		LCD_Clear();
		LCD_WriteString("led1->1 ,led2->2 ");
		LCD_GoTo(1,0);
		LCD_WriteString("led3->3 ,temp->4");
		while (1)
		{
			Uart_data = bluetooth_ReceiveByte();

			SPI_TranSiver(Uart_data);
		}
	}
	else{
		LCD_GoTo(1,2);
		LCD_WriteString("pass is wrong");
		_delay_ms(1000);
	}
  }
}


