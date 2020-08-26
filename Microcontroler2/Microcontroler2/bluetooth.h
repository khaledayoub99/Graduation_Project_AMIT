
#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "DIO.h"
#include "UART.h"


void bluetooth_Init(void);

void bluetooth_SendByte(uint8 data);

void bluetooth_SendString(uint8* data);

uint8 bluetooth_ReceiveByte(void);



#endif /* BLUETOOTH_H_ */