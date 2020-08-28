
#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include "STD.h"


/******************************************* External Registers **************************************/


#define SREG   (*(volatile uint8*)(0x5F))

#define GICR   (*(volatile uint8*)(0x5B))

#define GIFR   (*(volatile uint8*)(0x5A))

#define MCUCR  (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))


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

/*********************************    ADC    *********************************************/

#define ADMAX           (*(volatile uint8 *)(0x27))
#define ADCSRA          (*(volatile uint8 *)(0x26))
#define ADCH            (*(volatile uint8 *)(0x25))
#define ADCL            (*(volatile uint8 *)(0x24))
#define ADC_data        (*(volatile uint16*)(0x24))
#define SFIOR           (*(volatile uint8 *)(0x50))



/*********************************  SPI  ************************************/



typedef struct
{
	uint8 SPCR ;
	uint8 SPSR ;
	uint8 SPDR ;
	
}SPI_REGISTERS;

#define SPI ((volatile SPI_REGISTERS*)(0x2D))

#endif /* ATMEGA32_H_ */