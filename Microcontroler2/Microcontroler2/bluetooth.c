
#include "bluetooth.h"

void bluetooth_Init(void)
{
	// RX Pin
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	// TX Pin
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	
	UART_Init();
}

void bluetooth_SendByte(uint8 data)
{
	UART_SendByte(data);
}

void bluetooth_SendString(uint8* data)
{
	UART_SendString(data);
}

uint8 bluetooth_ReceiveByte(void)
{
	uint8 data =0 ;
	data = UART_ReceiveByte();	
	return data ;
}