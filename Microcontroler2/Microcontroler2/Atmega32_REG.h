
#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include "STD.h"


/******************************************* DIO Registers **************************************/


#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*(volatile uint8*)(0x35))
#define PINC  (*(volatile uint8*)(0x33))
#define DDRC  (*(volatile uint8*)(0x34))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))


/***********************************   UART  **********************************/


#define UBRRL   (*(volatile uint8*)(0x29))
#define UCSRA   (*(volatile uint8*)(0x2B))
#define UCSRB   (*(volatile uint8*)(0x2A))
#define UCSRC   (*(volatile uint8*)(0x40))
#define UDR     (*(volatile uint8*)(0x2C))

/*********************************  SPI  ************************************/

/*
typedef struct
{
	uint8 SPR0 : 1;
	uint8 SPR1 : 1;
	uint8 CPHA : 1;
	uint8 CPOL : 1;
	uint8 MSTR : 1;
	uint8 DORD : 1;
	uint8 SPE :  1;
	uint8 SPIE : 1;
	
}SPCR_REG;*/

typedef struct
{
	uint8 SPCR ;
	uint8 SPSR ;
	uint8 SPDR ;
	
}SPI_REGISTERS;

#define SPI ((volatile SPI_REGISTERS*)(0x2D))

#endif /* ATMEGA32_H_ */