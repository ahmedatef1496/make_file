/*
 * button.h
 *
 * Created: 4/7/2023 3:38:17 AM
 *  Author: atef
 */ 
#include "DIO.h"
	#define  button1 PIND7
	#define  button2 PIND2
	
typedef enum EN_ButtonError_t
{
	BUTTON_OK,
	BUTTON_ERROR
}EN_ButtonError_t;

void BUTTON_init (DIO_Pin_type button);
void BUTTON_read (DIO_Pin_type button,DIO_PinVoltage_type *volt);
DIO_PinVoltage_type BUTTON_read2 (DIO_Pin_type button);