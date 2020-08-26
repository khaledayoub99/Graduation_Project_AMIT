
#include "SPI.h"



void SPI_Master_Init(void)
{
	
  DIO_SetPinDir(DIO_PORTB ,DIO_PIN4 , DIO_PIN_OUTPUT);
  DIO_SetPinDir(DIO_PORTB ,DIO_PIN5 , DIO_PIN_OUTPUT);
  DIO_SetPinDir(DIO_PORTB ,DIO_PIN6 , DIO_PIN_INPUT);
  DIO_SetPinDir(DIO_PORTB ,DIO_PIN7 , DIO_PIN_OUTPUT);
  
  
  SPI->SPCR = 0X50 ;
  

}

void SPI_Slave_Init(void)
{	
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN4 , DIO_PIN_INPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN5 , DIO_PIN_INPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN6 , DIO_PIN_OUTPUT);
	 DIO_SetPinDir(DIO_PORTB ,DIO_PIN7 , DIO_PIN_INPUT);
	SPI->SPCR = 0X40 ;	
}

void SPI_Master_InitTrans(void)
{
	DIO_WritePin(DIO_PORTB ,DIO_PIN4, DIO_PIN_LOW);
}

void SPI_Master_TermTrans(void)
{
	DIO_WritePin(DIO_PORTB ,DIO_PIN4, DIO_PIN_HIGH);
}

uint8 SPI_TranSiver(uint8 trans_data)
{
	
	uint8 rec_data = 0;
	
	SPI->SPDR = trans_data ; 
	
	while(GET_BIT(SPI->SPSR , 7) == 0);
	
	rec_data = SPI->SPDR ; 
	
	return rec_data ;
	
}