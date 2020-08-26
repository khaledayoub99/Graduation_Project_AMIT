
#include "UART.h"
#include <util/delay.h>


void UART_Init(void)
{	
	
	uint32 UBRRL_Value = 0 ;
	
	//Receiver Enable
	SET_BIT(UCSRB,4);
	
	//UCSRC Select && Select 8 BITS
	UCSRC |= 0x86 ;
	
	
	// Baud Rate Setting
	UBRRL_Value = ((F_CPU) / ( Baud_Rate*(uint32)16 ))-1 ;
	UBRRL = UBRRL_Value ;
}


void UART_SendByte(uint8 data)
{
	while(GET_BIT(UCSRA,5) == 0);
	
	UDR = data ;
}

void UART_SendString(uint8* data)
{
	
	uint8 coun = 0 ;
	while(data[coun] != '\0')
	{
		UART_SendByte (data[coun]);
		coun ++;
	}

	
}

uint8 UART_ReceiveByte(void)
{
	uint8 data = 0 ;
	
	while(GET_BIT(UCSRA,7) == 0);
	
	data = UDR ;
	
	return data ;
}