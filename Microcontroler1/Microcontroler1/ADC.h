
#ifndef ADC_H_
#define ADC_H_

#include "Atmega32_REG.h"
#include "BIT_Math.h"
#include "ADC_Cfg.h"

#define ADC_AREF	0
#define ADC_AVCC	1
#define ADC_EX_V	2

#define ADC_Right_ADJUST	0
#define ADC_left_ADJUST		1

#define ADC_Channel_0	0
#define ADC_Channel_1	1
#define ADC_Channel_2	2
#define ADC_Channel_3	3
#define ADC_Channel_4	4
#define ADC_Channel_5	5
#define ADC_Channel_6	6
#define ADC_Channel_7	7

#define ADC_AUTO_TRIGGER	    0
#define ADC_Analog_Comparator	1
#define ADC_EX_INT0         	2
#define ADC_TIMER0_COMPARE_M	3
#define ADC_TIMER0_Overflow 	4
#define ADC_TIMER_COMPARE_M_B	5
#define ADC_TIMER1_Overflow 	6
#define ADC_TIMER1_Capture  	7

#define ADC_PRESCALER_2	        0
#define ADC_PRESCALER_4	        1
#define ADC_PRESCALER_8		    2
#define ADC_PRESCALER_16	    3
#define ADC_PRESCALER_32	    4
#define ADC_PRESCALER_64	    5
#define ADC_PRESCALER_128	    6

#define ADC_INT_DS	0
#define ADC_INT_EN	1


/******************* APIS *******************************/

void ADC_Init(void);
void ADC_Read(uint16 *value); 


#endif /* ADC_H_ */