
#ifndef CONTROLLED_DEV_H_
#define CONTROLLED_DEV_H_

#include "SPI.h"

void Controlled_Dev_Init(void);

uint8 TranSiver_order(uint8 trans_data);

void DEV_1(void(*ptr)(void));

void DEV_2(void(*ptr)(void));

void DEV_3(void(*ptr)(void));

#endif /* CONTROLLED_DEV_H_ */