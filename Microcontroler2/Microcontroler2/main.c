/*
 * Microcontroler2.c
 *
 * Created: 8/19/2020 10:29:02 PM
 * Author : khaled mohamed
 */ 


#include "bluetooth.h"
#include "SPI.h"
#include "LCD.h"


int main(void)
{
	uint8 Uart_data = 0;
	
	LCD_Init();
	
	bluetooth_Init();
    
	SPI_Master_Init();
	
	SPI_Master_InitTrans();
	
	LCD_GoTo(0,0);
	
	LCD_WriteString("welcome>>");
	LCD_WriteString("led1->1");
	
	LCD_GoTo(1,0);
	
	LCD_WriteString("led2->2 ,led3->3");
    while (1) 
    {
		Uart_data = bluetooth_ReceiveByte();

		SPI_TranSiver(Uart_data);
    }
}

