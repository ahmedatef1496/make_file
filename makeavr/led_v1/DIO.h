/*
 * DIO.h
 *
 * Created: 4/5/2023 3:26:03 AM
 *  Author: atef
 */ 


#include "Stdtyps.h"

#ifndef DIO_H_
#define DIO_H_
typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	LOW=0,
	HIGH,
}DIO_PinVoltage_type;


typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;

typedef enum dioError{
	DIO_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_VALUE,
	WRONG_DIRECTION
}EN_dioError_t;

// function to initialize all DIO pins referring to PINS  conflagration array ---> DIO_CFG
void DIO_Init(void);

//function to change pin initialization during the program takes pin name and pin status 
EN_dioError_t DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);

//function to write volt on pin  takes pin name and pin volt 
EN_dioError_t DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);

//function to toggle pin  takes pin name 
EN_dioError_t DIO_toggle(DIO_Pin_type pin);	
					
//function to read pin volt  takes pin name and the variable address to put the data in 
EN_dioError_t DIO_ReadPin(DIO_Pin_type pin,DIO_PinVoltage_type *volt);

//function to read pin volt  takes pin name and return the volt on this pin  
DIO_PinVoltage_type DIO_ReadPin2(DIO_Pin_type pin);

#endif /* DIO_H_ */