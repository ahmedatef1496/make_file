/*
 * DIO_Private.h
 *
 * Created: 4/7/2023 4:29:30 AM
 *  Author: atef
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS];
EN_dioError_t DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);



#endif /* DIO_PRIVATE_H_ */