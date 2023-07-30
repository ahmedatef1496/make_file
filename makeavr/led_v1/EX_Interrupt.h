/*
 * EX_Interrupt.h
 *
 * Created: 4/8/2023 9:13:01 AM
 *  Author: atef
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_
/////////////////////////////////////////////////////////////////////
#include "Utils.h"
#include  "Stdtyps.h" 
#include "register.h"
/////////////////////////////////////////////////////////////////////
#define  GLOBALE_ENABLE  sei
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0
/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0
/* MCUCSR */
#define JTD     7
#define ISC2    6

/*External Interrupt Request 0*/
#define  INT0_vect				__vector_1

/*External Interrupt Request 1*/
#define  INT1_vect					__vector_2

/*External Interrupt Request 2*/
#define  INT2_vect					__vector_3

/*Timer/Counter2 Compare Match*/
#define TIMER2_COMP_vect					__vector_4

/*Timer/Counter2 Overflow*/
#define TIMER2_OV_vect					__vector_5

/*Timer/Counter1 Capture Event*/
#define TIMER1_ICU_vect					__vector_6

/*Timer/Counter1 Compare Match A*/
#define TIMER1_OCPA_vect				__vector_7

/*Timer/Counter1 Compare Match B*/
#define TIMER1_OCB_vect				__vector_8

/*Timer/Counter1 Overflow*/
#define TIMER1_OVF_vect					__vector_9

/*Timer/Counter0 Compare Match*/
#define TIMER0_OC_vect					__vector_10

/*Timer/Counter0 Overflow*/
#define TIMER0_OVF_vect					__vector_11

/*Serial Transfer Complete*/
#define SPI_STC_vect						__vector_12

/*USART, Rx Complete*/
#define UART_RXC_vect					__vector_13

/*USART, Data Register Empty*/
#define USART_UDRE_vect					__vector_14

/*USART, Tx Complete*/
#define UART_TX_vect					__vector_15

/*ADC Conversion Complete*/
#define ADC_vect							__vector_16

/*EEPROM Ready*/
#define EE_RDY_vect						__vector_17

/*Analog Comparator*/
#define ANA_COMP_vect					__vector_18

/*Two-wire Serial Interface*/
#define TWI_vect							__vector_19

/*Storage Program Memory Ready*/
#define SPM_READY_vect					__vector_20
//////////////////////////////////////////////
#define sei() __asm__ __volatile__ ("sei" ::)
#define cli() __asm__ __volatile__ ("cli" ::)
#define reti() __asm__ __volatile__ ("reti" ::)
#define ret() __asm__ __volatile__ ("ret" ::)
///////////////////////////////////////////////////////
#define ISR(vector,...)	              \
void vector(void) __attribute__((signal))__VA_ARGS__ ; \
void vector(void)
///////////////////////////////////////////////////////
#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

void EXI_Init(void);
void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));




#endif /* EX_INTERRUPT_H_ */