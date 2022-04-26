/*
 * Led.h
 *
 *  Created on: Apr 25, 2022
 *      Author: lenovo2
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "HAL/HLed/Led_cfg.h"
/**********************************MACROS**********************************/
#define LED_u8ACTIVE_STATE_LOW	((u8) 1)
#define LED_u8ACTIVE_STATE_HIGH	((u8) 0)
#define LED_u8_STATE_ON			((u8) 1)
#define LED_u8_STATE_OFF		((u8) 0)

/*Enum to define the error status of led*/
typedef enum{
	Led_enuOK,
	Led_enuNOK,
}Led_enuErrorStatus;
/*LED STRUCT TO SET EACH LED CONFIGURATIONS*/
typedef struct{
	void * Port;
	u16 Pin;
	u64 RCC_Enable;
	u8 Active_State;
}Led_Cnfg_t;

/*********************************PROTOTYPES********************************/
/*
 * Name--------> LED INIT function
 * Arguments --> void
 * Returns ----> Error Status , OK -> Everything is OK || NOK --> Error Happened
 * Description-> Initialize All the LEDs so we can set their status whether on or off
 */
extern Led_enuErrorStatus Led_init(void);
/*
 * Name--------> Led Set Status function
 * Arguments --> Led number , Led State
 * Returns ----> Error Status , OK -> Everything is ok || NOK --> Error Happened
 * Description-> turn on or off the LEDS whether they are active low or active high
 */
extern Led_enuErrorStatus Led_setState(u16 Copy_u16LedNum , u8 Copy_u8LedState);
/*****************************EXTERN USED VARIABLES*************************/
/*EXTERN LEDS CONFIGURATIONS ARRAY*/
extern const Led_Cnfg_t Leds[NUM_OF_LEDS];
#endif /* HAL_LED_H_ */
