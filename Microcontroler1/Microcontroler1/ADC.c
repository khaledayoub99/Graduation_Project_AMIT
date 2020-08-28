#include "ADC.h"
//#include <avr/interrupt.h>
void ADC_Init(void)
{
	#if    ADC_Voltage_REF==ADC_AREF
	CLR_BIT(ADMAX,6);
	CLR_BIT(ADMAX,7);
	
	#elif  ADC_Voltage_REF==ADC_AVCC
	SET_BIT(ADMAX,6);
	CLR_BIT(ADMAX,7);
	
	#elif  ADC_Voltage_REF==ADC_EX_V
	SET_BIT(ADMAX,6);
	SET_BIT(ADMAX,7);

    #endif
	
	
	
	#if   ADC_Channel==ADC_Channel_0
	
	#elif ADC_Channel==ADC_Channel_1
	SET_BIT(ADMAX,0);
	
	#elif ADC_Channel==ADC_Channel_2
	SET_BIT(ADMAX,1);
	
	#elif ADC_Channel==ADC_Channel_3
	SET_BIT(ADMAX,0);
	SET_BIT(ADMAX,1);
	
	#elif ADC_Channel==ADC_Channel_4
	SET_BIT(ADMAX,2);
	
	#elif ADC_Channel==ADC_Channel_5
	SET_BIT(ADMAX,0);
	SET_BIT(ADMAX,2);
	
	#elif ADC_Channel==ADC_Channel_6
	SET_BIT(ADMAX,1);
	SET_BIT(ADMAX,2);
	
	#elif ADC_Channel==ADC_Channel_7
	SET_BIT(ADMAX,0);
	SET_BIT(ADMAX,1);
	SET_BIT(ADMAX,2);
	
	#endif
	
	
	
	#if   ADC_Adjust==ADC_Right_ADJUST
	CLR_BIT(ADMAX,5);
	
	#elif ADC_Adjust==ADC_left_ADJUST
	SET_BIT(ADMAX,5);	

	#endif
	
	
	#if   ADC_CONVERSION_Trigger==ADC_AUTO_TRIGGER
	
	SET_BIT(ADCSRA,2);
	
	#elif ADC_CONVERSION_Trigger==ADC_Analog_Comparator
	
	SET_BIT(SFIOR,5);
	
	#elif ADC_CONVERSION_Trigger==ADC_EX_INT0 
	
	SET_BIT(SFIOR,6);
	
	#elif ADC_CONVERSION_Trigger==ADC_TIMER0_COMPARE_M
	
	SET_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	
	#elif ADC_CONVERSION_Trigger==ADC_TIMER0_Overflow
	
	SET_BIT(SFIOR,7);
	
	#elif ADC_CONVERSION_Trigger==ADC_TIMER_COMPARE_M_B
	
	SET_BIT(SFIOR,5);
	SET_BIT(SFIOR,7);
	
	#elif ADC_CONVERSION_Trigger==ADC_TIMER1_Overflow
	
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);
	
	#elif ADC_CONVERSION_Trigger==ADC_TIMER1_Capture
	
	SET_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,7);
	
	#endif
	
	#if   ADC_PRESCALER==ADC_PRESCALER_2
	
	SET_BIT(ADCSRA,0);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_4
	
	SET_BIT(ADCSRA,1);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_8
	
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_16
	
	SET_BIT(ADCSRA,2);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_32
	
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,2);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_64
	
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	#elif ADC_PRESCALER==ADC_PRESCALER_128
	
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	#endif
	
	
	
	#if   ADC_INT_STATUS==ADC_INT_DS
	
	CLR_BIT(ADCSRA,3);
	
	#elif ADC_INT_STATUS==ADC_INT_EN
	
	SET_BIT(ADCSRA,3);
	SET_BIT(SREG,7);

	#endif
	
	
	SET_BIT(ADCSRA,7);
}
void ADC_Read(uint16 *value)
{
	
	uint16 Digital_val =0;
	
	//start conversion
	
	SET_BIT(ADCSRA,6);
	#if ADC_INT_STATUS==ADC_INT_DS
	
	while(!GET_BIT(ADCSRA,4));
	
	Digital_val = ADC_data ; 
	
	*value = ((Digital_val*500)/1024);
	
	#endif
}