/*
 * Gpio.c
 *
 *  Created on: Apr4, 2022
 *      Author: Abdelrahman Yousry
 */
#include "Std_types.h"
#include "Gpio.h"
#include "Gpio_prv.h"

/*
 * GpioPinCfg_t pincfg;
 * pincfg.pin  = PIN_0;
 * pincfg.port = GPIO_A;
 * pincfg.mode = GPIO_u8MODE_OUTPUT_PP_PU;
 * pincfg.speed= GPIO_u8SPEED_LOW;
 * */

GpioErrorStatus_t Gpio_enuInit(GpioPinCfg_t * copy_strAdd)
{
	GpioErrorStatus_t Loc_ErrorStatus = Gpio_enuNok;
	if(copy_strAdd == NULL)
	{
		Loc_ErrorStatus = Gpio_enuNullPtr;
	}
	else if(copy_strAdd->pin> GPIO_u8PIN_15)
	{
		Loc_ErrorStatus = Gpio_enuErrorPin;
	}
	else if(copy_strAdd->port !=GPIO_A
			&&copy_strAdd->port!=GPIO_B
			&&copy_strAdd->port!=GPIO_C
			&&copy_strAdd->port!=GPIO_D
			&&copy_strAdd->port!=GPIO_E
			&&copy_strAdd->port!=GPIO_H)
	{
		Loc_ErrorStatus = Gpio_enuErrorPort;
	}
	else
	{
		Loc_ErrorStatus = Gpio_enuOk;
		u32 Loc_temp;
		//*Moder*//
		Loc_temp  = ((GpioReg_t*)copy_strAdd->port)->GPIOx_MODER;
		//we should first clear the two bits want to be assigned
		Loc_temp &=(u32)~((TWO_BIT_MASK) << ((copy_strAdd->pin)*2));
		//then assign your value after getting it by make |
		Loc_temp |=(u32) (MODER_MASK&(copy_strAdd->mode))<<((copy_strAdd->pin)*2);
		//put your config in the register
		((GpioReg_t*)copy_strAdd->port)->GPIOx_MODER = Loc_temp;

		//*OTYPER*//
		Loc_temp  = ((GpioReg_t*)copy_strAdd->port)->GPIOx_OTYPER;
		//we should first clear bit want to be assigned
		Loc_temp &= (u32)~((ONE_BIT_MASK) << (copy_strAdd->pin));
		//then assign your value after getting it by make |
		Loc_temp |=(u32) ((OTYPER_MASK&copy_strAdd->mode)>>2)<<((copy_strAdd->pin));
		//put your config in the register
		((GpioReg_t*)copy_strAdd->port)->GPIOx_OTYPER = Loc_temp;


		//*PUPDR*//
		Loc_temp  = ((GpioReg_t*)copy_strAdd->port)->GPIOx_PUPDR;
		//we should first clear the two bits want to be assigned
		Loc_temp &=(u32) ~((TWO_BIT_MASK) << ((copy_strAdd->pin)*2));
		//then assign your value after getting it by make |
		Loc_temp |= (u32)((PUPDR_MASK&copy_strAdd->mode)>>3)<<((copy_strAdd->pin)*2);//11011 // shifting pos of the bit -1
		//put your config in the register
		((GpioReg_t*)copy_strAdd->port)->GPIOx_PUPDR = Loc_temp;


		//*OSPEEDR*//
		Loc_temp  = ((GpioReg_t*)copy_strAdd->port)->GPIOx_OSPEEDR;
		//we should first clear the two bits want to be assigned
		Loc_temp &=(u32) ~((TWO_BIT_MASK) << ((copy_strAdd->pin)*2));
		//then assign your value after getting it by make |
		Loc_temp |=(u32) (copy_strAdd->speed)<<((copy_strAdd->pin)*2);
		//put your config in the register
		((GpioReg_t*)copy_strAdd->port)->GPIOx_OSPEEDR = Loc_temp;

		/*In case the mode is selected to be AF*/
		/*Then this condition will be true and inside it the specific AF will be selected
		 * from GPIO_u8ALTERNATE_FUNC_00 --> GPIO_u8ALTERNATE_FUNC_15
		 * */
		if((MODER_MASK&(copy_strAdd->mode) == ALTERNATIVE_FUNCTION_MODE))
		{
			if(copy_strAdd->pin <=7)
			{
				((GpioReg_t*)copy_strAdd->port)->GPIOx_AFRL &=~(( FOUR_BIT_MASK)<<((copy_strAdd->pin))*4);
				((GpioReg_t*)copy_strAdd->port)->GPIOx_AFRL |= (copy_strAdd->AF) <<(copy_strAdd->pin)*4;
			}
			else if(copy_strAdd->pin >7)
			{

				((GpioReg_t*)copy_strAdd->port)->GPIOx_AFRH &=~(( FOUR_BIT_MASK)<<((copy_strAdd->pin)-8)*4);
				((GpioReg_t*)copy_strAdd->port)->GPIOx_AFRH |= copy_strAdd->AF << ((copy_strAdd->pin)-8)*4;
			}
		}
	}
	return Loc_ErrorStatus;
}



GpioErrorStatus_t Gpio_enuSetPinValue(void* copy_u8port,u8 copy_u8pin ,u8 copy_u8Value)
{
	GpioErrorStatus_t Loc_ErrorStatus = Gpio_enuNok;
	if(copy_u8port == NULL)
	{
		Loc_ErrorStatus = Gpio_enuNullPtr;
	}
	if(copy_u8pin> GPIO_u8PIN_15)
	{
		Loc_ErrorStatus = Gpio_enuErrorPin;
	}
	if(copy_u8Value>GPIO_u8PIN_HIGH)
	{
		Loc_ErrorStatus = Gpio_enuPinValError;
	}
	else{
		Loc_ErrorStatus = Gpio_enuOk;
		switch(copy_u8Value)
		{
		case GPIO_u8PIN_HIGH:
			// goz2yt 2l volatile 3awz 2s2al feehA
			((GpioReg_t*)copy_u8port)->GPIOx_BSRR=(u32)(copy_u8Value<<(copy_u8pin));
			break;
		case GPIO_u8SPEED_LOW:
			((GpioReg_t*)copy_u8port)->GPIOx_BSRR=(u32)((copy_u8Value+1)<<(copy_u8pin+16));
			break;
		default:
			/*do nothing*/
			break;
		}

	}
	return Loc_ErrorStatus;
}


GpioErrorStatus_t Gpio_enuGetPinValue(void* copy_u8port,u8 copy_u8pin ,u8* copy_u8Value)
{
	GpioErrorStatus_t Loc_ErrorStatus = Gpio_enuNok;
	if(copy_u8port == NULL ||copy_u8Value==NULL)
	{
		Loc_ErrorStatus = Gpio_enuNullPtr;
	}
	if(copy_u8pin> GPIO_u8PIN_15)
	{
		Loc_ErrorStatus = Gpio_enuErrorPin;
	}
	else{
		Loc_ErrorStatus = Gpio_enuOk;
		*copy_u8Value=((((GpioReg_t*)copy_u8port)->GPIOx_IDR)>>copy_u8pin)&1;

	}
	return Loc_ErrorStatus;
}

GpioErrorStatus_t Gpio_enuSetAlternativeFunc(GpioPinCfg_t *PinCfg)
{
	GpioErrorStatus_t Loc_ErrorStatus = Gpio_enuNok;
	if(PinCfg == NULL)
	{
		Loc_ErrorStatus = Gpio_enuNullPtr;
	}
	else if(PinCfg->pin> GPIO_u8PIN_15)
	{
		Loc_ErrorStatus = Gpio_enuErrorPin;
	}
	else if(  PinCfg->port !=GPIO_A
			||PinCfg->port!=GPIO_B
			||PinCfg->port!=GPIO_C
			||PinCfg->port!=GPIO_D
			||PinCfg->port!=GPIO_E
			||PinCfg->port!=GPIO_H)
	{
		Loc_ErrorStatus = Gpio_enuErrorPort;
	}
	if(PinCfg->pin <=7)
	{
		((GpioReg_t*)PinCfg->port)->GPIOx_AFRH &=~(( FOUR_BIT_MASK)<<((PinCfg->pin))*4);
		((GpioReg_t*)PinCfg->port)->GPIOx_AFRL |= (PinCfg->AF) <<(PinCfg->pin)*4;
	}
	else if(PinCfg->pin >7)
	{
		((GpioReg_t*)PinCfg->port)->GPIOx_AFRH &=~(( FOUR_BIT_MASK)<<((PinCfg->pin)-8)*4);
		((GpioReg_t*)PinCfg->port)->GPIOx_AFRH |= PinCfg->AF << ((PinCfg->pin)-8)*4;
	}
}

