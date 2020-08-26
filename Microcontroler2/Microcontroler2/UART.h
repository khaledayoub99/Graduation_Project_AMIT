

#ifndef UART_H_
#define UART_H_

#include "Atmega32_REG.h"
#include "BIT_MATH.h"

#include "UART_CFG.h"


void UART_Init(void);

void UART_SendByte(uint8 data);

void UART_SendString(uint8* data);

uint8 UART_ReceiveByte(void);


#endif /* UART_H_ */