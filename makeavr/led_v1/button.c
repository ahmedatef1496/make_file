/*
 * button.c
 *
 * Created: 4/7/2023 3:38:26 AM
 *  Author: atef
 */ 
#include "button.h"
void BUTTON_init (DIO_Pin_type button)
{
	DIO_InitPin(button,INPULL);
}
void BUTTON_read (DIO_Pin_type button,DIO_PinVoltage_type *volt)
{
	DIO_ReadPin(button,volt);
}
DIO_PinVoltage_type BUTTON_read2 (DIO_Pin_type button)
{
	DIO_ReadPin2(button);
}