
#include "LED.h"

          /********************************* LED0 **************************************/
		  
void LED0_Init(void)
{
	
	DIO_SetPinDir  (DIO_PORTD,DIO_PIN0,DIO_PIN_OUTPUT);
	
}

void LED0_ON(void)
{
	DIO_WritePin	(DIO_PORTD,DIO_PIN0,DIO_PIN_HIGH);	
}

void LED0_OFF(void)
{
	DIO_WritePin    (DIO_PORTD,DIO_PIN0,DIO_PIN_LOW);
}

void LED0_toggle(void)
{
	DIO_TogglePin	(DIO_PORTD,DIO_PIN0);
	
}

          /********************************* LED1 **************************************/
		  
void LED1_Init(void)
{
	
	DIO_SetPinDir   (DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	
}

void LED1_ON(void)
{
	DIO_WritePin    (DIO_PORTD,DIO_PIN1,DIO_PIN_HIGH);
}

void LED1_OFF(void)
{
	DIO_WritePin    (DIO_PORTD,DIO_PIN1,DIO_PIN_LOW);
}

void LED1_toggle(void)
{
	DIO_TogglePin	(DIO_PORTD,DIO_PIN1);
	
}
		  
		  /********************************* LED2 **************************************/
		  
void LED2_Init(void)
{
	DIO_SetPinDir	(DIO_PORTD,DIO_PIN2,DIO_PIN_OUTPUT);
}

void LED2_ON(void)
{
	DIO_WritePin	(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
}

void LED2_OFF(void)
{
	DIO_WritePin    (DIO_PORTD,DIO_PIN2,DIO_PIN_LOW);
}

void LED2_toggle(void)
{
	DIO_TogglePin   (DIO_PORTD,DIO_PIN2);
	
}