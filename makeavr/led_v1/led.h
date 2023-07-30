/*
 * led.h
 *
 * Created: 4/7/2023 3:39:08 AM
 *  Author: atef
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO.h"
typedef enum EN_LED_ERROR_t
{
	LED_OK,
	LED_ERROR
}EN_LED_ERROR_t;

	#define  LED1 PINB0 
	#define  LED2 PINB1 
	#define  LED3 PINB2 
	#define  LED4 PINB3 




void LED_init   (DIO_Pin_type pin);
void LED_on     (DIO_Pin_type pin);
void LED_off    (DIO_Pin_type pin);
void LED_toggel (DIO_Pin_type pin);


#endif /* LED_H_ */