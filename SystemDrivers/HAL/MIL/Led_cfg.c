/*
 * Led_cfg.c
 *
 *  Created on: Apr 25, 2022
 *      Author: lenovo2
 */




#include <Helpers/STD_TYPES.h>
#include <HAL/HLed/Led.h>
#include <HAL/HLed/Led_cfg.h>
#include <MCAL/GPIO/Gpio.h>
#include <MCAL/RCC/RCC.h>

/****************CONFIGURE EACH LED PORT,PIN AND STATUS****************/
const Led_Cnfg_t Leds[NUM_OF_LEDS] = {
		[0] = {
				.Port = GPIOA_BASE_ADDRESS,
				.Pin = GPIO_PIN_00,
				.RCC_Enable = RCC_u32AHB1_GPIOA,
				.Active_State = LED_u8ACTIVE_STATE_HIGH,
		}
};
