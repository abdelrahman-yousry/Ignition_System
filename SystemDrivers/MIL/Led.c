/*
 * LED.c
 *
 *  Created on: Apr 25, 2022
 *      Author: MARWA ABDULLAH
 */

#include "Helpers/STD_TYPES.h"

#include "MCAL/Gpio/Gpio.h"
#include "MCAL/RCC/RCC.h"

#include "HAL/HLed/Led.h"
#include "HAL/HLed/Led_cfg.h"

/*
 * Name--------> LED INIT function
 * Arguments --> void
 * Returns ----> Error Status , OK -> Everything is OK || NOK --> Error Happened
 * Description-> Initialize All the LEDs so we can set their status whether on or off
 */
Led_enuErrorStatus Led_init(void) {
	/*DECLARE RETURN ERROR STATUS VARIABLE*/
	Led_enuErrorStatus Loc_enuReturnStatus = Led_enuOK;
	/*DECLARE MASK TO BE USED FOR RCC*/
	u32 RCC_GPIOEN = 0;
	/*DECLARE STRUCT TO SET PIN CONFIGS*/
	GpioPinCfg_t Loc_strCfg;
	/*SET PIN CONFIGS*/
	Loc_strCfg.MODE = GPIO_u32MODE_OUTPUT_PP_PD;
	Loc_strCfg.SPEED = GPIO_u8SPEED_VERY_HIGH;
	/*DECLARE ITERATOR FOR LEDS*/
	u8 Loc_u8Iterator;
	/*LOOP TO CHECK USED GPIO TO ENABLE THEIR CLK*/
	for (Loc_u8Iterator = 0; Loc_u8Iterator < NUM_OF_LEDS; Loc_u8Iterator++) {
		RCC_GPIOEN |= (u32)Leds[Loc_u8Iterator].RCC_Enable;
	}
	/*ENABLE CLK FOR USED GPIO*/
	RCC_enuControlPeriph(RCC_AHB1, RCC_GPIOEN, LED_u8_STATE_ON);
	/*LOOP TO SET LED PINS CONFIGURATIONS*/
	for (Loc_u8Iterator = 0; Loc_u8Iterator < NUM_OF_LEDS; Loc_u8Iterator++) {
		Loc_strCfg.PORT = Leds[Loc_u8Iterator].Port;
		Loc_strCfg.PIN = Leds[Loc_u8Iterator].Pin;
		Gpio_enuInit(&Loc_strCfg);
	}
	/*RETURN THHE ERROR STATUS */
	return Loc_enuReturnStatus;

}
/*
 * Name--------> Led Set Status function
 * Arguments --> Led number , Led State
 * Returns ----> Error Status , OK -> Everything is ok || NOK --> Error Happened
 * Description-> turn on or off the LEDS whether they are active low or active high
 */
Led_enuErrorStatus Led_setState(u16 Copy_u16LedNum, u8 Copy_u8LedState) {
	/*DECLARE RETURN ERROR VARIABLE*/
	Led_enuErrorStatus Loc_enuReturnStatus = Led_enuOK;
	/*STRUCT TO SET LED CONFIGURATIONS*/
	GpioPinCfg_t Loc_strCfg;
	Loc_strCfg.PORT = Leds[Copy_u16LedNum].Port;
	Loc_strCfg.PIN = Leds[Copy_u16LedNum].Pin;
	/*SETING PIN VALUE USING XOR METHOD SO WE CAN TURN ON OR OFF LED WHETHER IT'S ACTIVE LOW OR ACTIVE HIGH*/
	Gpio_enuSetPinValue(&Loc_strCfg,
			Copy_u8LedState ^ Leds[Copy_u16LedNum].Active_State);
	return Loc_enuReturnStatus;
}

