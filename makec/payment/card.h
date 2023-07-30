#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#ifndef CARD_H
#define CARD_H
#include "stdtyps.h"
#include "stdio.h"
#include "string.h"

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAcountNumber[20];
    uint8_t cardExpirationData[6];
}ST_cardData_t;

typedef enum EN_card_Error_t
{
    CARD_OK , WRONG_NAME , WRONG_EXP_DATE ,WRONG_PAN
}EN_card_Error_t;

EN_card_Error_t getCardHolderName(ST_cardData_t * cardData);
EN_card_Error_t getCardExpiryData(ST_cardData_t * cardData);
EN_card_Error_t getCardPAN(ST_cardData_t * cardData);
#endif // !CARD_H


