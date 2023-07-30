

#include "Stdtyps.h"
#include "register.h"
#include "Utils.h"
#include "DIO.h"
#include "DIO_Private.h"

void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}

  EN_dioError_t DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{   EN_dioError_t error = DIO_OK;
	if (pin <32){
		DIO_Port_type port = pin/8 ;
		u8 pin_num =pin % 8;
		
		switch(status)
		{
			case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT( DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT( DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT( DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				SET_BIT( DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
				default:		error = WRONG_PORT_NUMBER;	break;
			}
			break;
			case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
				default:		error = WRONG_PORT_NUMBER;	break;
			}
			break;
			
			case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
			}
			break;
			
			default:
			error = WRONG_DIRECTION;
			break;
		}
	}
	else
	{error = WRONG_PIN_NUMBER;}
	return error ;
}


EN_dioError_t DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{   EN_dioError_t error = DIO_OK;
	if (pin <32){
		DIO_Port_type port = pin/8 ;
		u8 pin_num =pin % 8;
		switch (volt)
		{ case HIGH :
			switch(port)
			{
				case PA:
				
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				
				SET_BIT(PORTD,pin_num);
				break;
				default:		error = WRONG_PORT_NUMBER;		break;
			}
			
			break;
			
			case LOW:
			
			switch(port)
			{
				case PA:
				
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				
				CLR_BIT(PORTD,pin_num);
				break;
				default:		error = WRONG_PORT_NUMBER;		break;
			}
			break;
			
			default:
			error = WRONG_VALUE;
			break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;

	
}

DIO_PinVoltage_type DIO_ReadPin2(DIO_Pin_type pin)
{  
	EN_dioError_t error = DIO_OK;
	DIO_PinVoltage_type volt;
	if (pin<32)
	{
		DIO_Port_type port = pin/8 ;
		u8 pin_num =pin % 8;
		volt=LOW;
		
		switch(port)
		{
			case PA:
			
			volt=READ_BIT(PINA,pin_num);
			break;
			case PB:
			
			volt=READ_BIT(PINB,pin_num);
			break;
			case PC:
			
			volt=READ_BIT(PINC,pin_num);
			break;
			case PD:
			
			volt=READ_BIT(PIND,pin_num);
			break;
			default:		error = WRONG_PORT_NUMBER;				break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	
	return volt;
} 
EN_dioError_t DIO_ReadPin(DIO_Pin_type pin,DIO_PinVoltage_type *volt)
{  
	EN_dioError_t error = DIO_OK;
	*volt=LOW;
	if (pin<32)
	{
		DIO_Port_type port = pin/8 ;
		u8 pin_num =pin % 8;
		*volt=LOW;
		
		switch(port)
		{
			case PA:
			
			*volt=READ_BIT(PINA,pin_num);
			break;
			case PB:
			
			*volt=READ_BIT(PINB,pin_num);
			break;
			case PC:
			
			*volt=READ_BIT(PINC,pin_num);
			break;
			case PD:
			
			*volt=READ_BIT(PIND,pin_num);
			break;
			default:		error = WRONG_PORT_NUMBER;				break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	
	return error;
}
// /////////////////////////////////////////////////////////////
void DIO_InitPin2(DIO_Port_type port,u8 pin_num, DIO_PinStatus_type status)
{
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT( DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT( DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT( DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT( DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}


void DIO_WritePin2(DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type volt)
{
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			
			SET_BIT(PORTD,pin_num);
			break;
		}
		
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			
			CLR_BIT(PORTD,pin_num);
			break;
		}
	}
	else
	{
		/* do nothing */
	}
	
}

DIO_PinVoltage_type DIO_ReadPin3(DIO_Port_type port,u8 pin_num)
{
	DIO_PinVoltage_type volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	
	return volt;
}



void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		
		PORTA=value;
		break;
		case PB:
		
		PORTB=value;
		break;
		case PC:
		
		PORTC=value;
		break;
		case PD:
		
		PORTD=value;
		break;
	}
}

// Error_t DIO_ReadPin(DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type*Pvolt)1:54
// {
// 	if (Pvolt==NULLPTR)
// 	{
// 		return NULL_PTR_ERROR;
// 	}
// 	else if ((port>PD)||(pin_num>7))
// 	{
// 	 return OUT_OF_RANGE;
// 	}
// 	else
// 	{
// 		switch(port)
// 		{
// 			case PA:
//
// 			*Pvolt=READ_BIT(PINA,pin_num);
// 			break;
// 			case PB:
//
// 			*Pvolt=READ_BIT(PINB,pin_num);
// 			break;
// 			case PC:
//
// 			*Pvolt=READ_BIT(PINC,pin_num);
// 			break;
// 			case PD:
//
// 			*Pvolt=READ_BIT(PIND,pin_num);
// 			break;
// 		}
// 		return OK;
// 	}
// }



