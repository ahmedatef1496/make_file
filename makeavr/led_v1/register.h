/*
 * Registers.h
 *
 * Created: 4/3/2023 
 * Author : Ahmed Atef
 * email  : ahmedaatf15@gmail.com
 */ 
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Stdtyps.h"

/************************************************************************/
/*							DIO_REGISTERS								*/
/************************************************************************/

// PORTA registers
#define  PORTA   (*(volatile unsigned char*)0X3B)
#define  DDRA   (*(volatile unsigned char*)0X3A)
#define  PINA   (*(volatile unsigned char*)0X39)
// PORTB registers
#define  PORTB   (*(volatile unsigned char*)0X38)
#define  DDRB  (*(volatile unsigned char*)0X37)
#define  PINB   (*(volatile unsigned char*)0X36)
// PORTC registers
#define  PORTC   (*(volatile unsigned char*)0X35)
#define  DDRC  (*(volatile unsigned char*)0X34)
#define  PINC   (*(volatile unsigned char*)0X33)
// PORTD registers
#define  PORTD   (*(volatile unsigned char*)0X32)
#define  DDRD  (*(volatile unsigned char*)0X31)
#define  PIND   (*(const volatile unsigned char*)0X30)
/**********************************************************/
/**              External Interrupt Registers             */
/**********************************************************/
/* MCUCR: MCU Control Register */
#define MCUCR *((volatile unsigned char* )0x55)  // 8-bit register

/* General Interrupt Control Register */
#define GICR *((volatile unsigned char* )0x5B)  // 8-bit register

/* General Interrupt Flag Register */
#define GIFR *((volatile unsigned char* )0x5A)  // 8-bit register

#define MCUCSR *((volatile unsigned char* )0x54)  // 8-bit register

/**********************************************************/
/**                 ATmega32 registers                   **/
/**********************************************************/

/* Status Register */
#define SREG *((volatile unsigned char* )0x5F) // 8-bit register

#endif // !REGISTERS_H_