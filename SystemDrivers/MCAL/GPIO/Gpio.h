/*
 * Gpio.h
 *
 *  Created on: Apr 4, 2022
 *      Author: Abdelrahman Yousry
 */

#ifndef GPIO_H_
#define GPIO_H_


typedef u8	alternative_func;

typedef struct
{
	u8 pin;		//to get the pin
	volatile void* port;	// to get the base address
	u8 mode;
	u8 speed;
	alternative_func AF;
}GpioPinCfg_t;



typedef enum
{
	Gpio_enuNok,
	Gpio_enuOk,
	Gpio_enuErrorPin,
	Gpio_enuErrorPort,
	Gpio_enuPinValError,
	Gpio_enuNullPtr
}GpioErrorStatus_t;

/*GPIO PINS*/
#define GPIO_u8PIN_0     (u8)0
#define GPIO_u8PIN_1     (u8)1
#define GPIO_u8PIN_2     (u8)2
#define GPIO_u8PIN_3     (u8)3
#define GPIO_u8PIN_4     (u8)4
#define GPIO_u8PIN_5     (u8)5
#define GPIO_u8PIN_6     (u8)6
#define GPIO_u8PIN_7     (u8)7
#define GPIO_u8PIN_8     (u8)8
#define GPIO_u8PIN_9     (u8)9
#define GPIO_u8PIN_10    (u8)10
#define GPIO_u8PIN_11    (u8)11
#define GPIO_u8PIN_12    (u8)12
#define GPIO_u8PIN_13    (u8)13
#define GPIO_u8PIN_14    (u8)14
#define GPIO_u8PIN_15    (u8)15



#define GPIO_u8MODE_INPUT_PU   		 		(u32)0b00001000
#define GPIO_u8MODE_INPUT_PD			 	(u32)0b00010000
#define GPIO_u8MODE_INPUT					(u32)0b00000000
/*Output*/
#define GPIO_u8MODE_OUTPUT_PP_PU    		(u32)0b01001
#define GPIO_u8MODE_OUTPUT_PP_PD  			(u32)0b10001
#define GPIO_u8MODE_OUTPUT_PP   			(u32)0b00001
#define GPIO_u8MODE_OUTPUT_OD_PU  			(u32)0b01101
#define GPIO_u8MODE_OUTPUT_OD_PD 			(u32)0b10101
#define GPIO_u8MODE_OUTPUT_OD  				(u32)0b00101

/*Alternate Function*/
#define GPIO_u8MODE_AF_PP 				 	(u8)0b00010
#define GPIO_u8MODE_AF_PP_PU				(u8)0b01010
#define GPIO_u8MODE_AF_PP_PD				(u8)0b10010
#define GPIO_u8MODE_AF_OD					(u8)0b00110
#define GPIO_u8MODE_AF_OD_PU				(u8)0b01110
#define GPIO_u8MODE_AF_OD_PD				(u8)0b10110


#define GPIO_u8SPEED_LOW				(u8)0b00
#define GPIO_u8SPEED_MEDIUM				(u8)0b01
#define GPIO_u8SPEED_HIGH				(u8)0b10
#define GPIO_u8SPEED_VHIGH				(u8)0b11

/*Analog*/
#define GPIO_u8MODE_ANALOG		        (u8)

/*Macros for AF if we select the pin as an Alternative Function mode*/
#define GPIO_u8ALTERNATE_FUNC_00		((u8) 0x00)
#define GPIO_u8ALTERNATE_FUNC_01		((u8) 0x01)
#define GPIO_u8ALTERNATE_FUNC_02		((u8) 0x02)
#define GPIO_u8ALTERNATE_FUNC_03		((u8) 0x03)
#define GPIO_u8ALTERNATE_FUNC_04		((u8) 0x04)
#define GPIO_u8ALTERNATE_FUNC_05		((u8) 0x05)
#define GPIO_u8ALTERNATE_FUNC_06		((u8) 0x06)
#define GPIO_u8ALTERNATE_FUNC_07		((u8) 0x07)
#define GPIO_u8ALTERNATE_FUNC_08		((u8) 0x08)
#define GPIO_u8ALTERNATE_FUNC_09		((u8) 0x09)
#define GPIO_u8ALTERNATE_FUNC_10		((u8) 0x0A)
#define GPIO_u8ALTERNATE_FUNC_11		((u8) 0x0B)
#define GPIO_u8ALTERNATE_FUNC_12		((u8) 0x0C)
#define GPIO_u8ALTERNATE_FUNC_13		((u8) 0x0D)
#define GPIO_u8ALTERNATE_FUNC_14		((u8) 0x0E)
#define GPIO_u8ALTERNATE_FUNC_15		((u8) 0x0F)


/*GPIOs Base Address*/
#define GPIO_A							( void*)0x40020000
#define GPIO_B							( void*)0x40020400
#define GPIO_C							( void*)0x40020800
#define GPIO_D							( void*)0x40020C00
#define GPIO_E							( void*)0x40021000
#define GPIO_H							( void*)0x40021C00



/*macros for pin value*/
#define GPIO_u8PIN_HIGH					(u8)1
#define GPIO_u8PIN_LOW					(u8)0


/*It will be like port init in avr*/
/****************************************************************
 * Description: 		this function to init GPIO pin
 *
 * input args: 			copy_strAdd --> struct contain of :-
 * 						1-u8 pin	-->> the pin number
						2-u32 port  -->> the port (BASE ADDRESS:- GPIO_x which x may be A,B,C,D,E,H)
						3-u8 mode	-->> the mode to determine the mode of the pin
						and it is a macro contain of 3 modes like : -Input/Output -- Push Pull/Open Drain -- pull up/ pull down ..
						 and they are in different regs

						4-u8 speed: - the speed of pin and it is option of: -
						LOW	/MEDIUM /HIGH /VHIGH
 *
 * Return type: 		GpioErrorStatus_t for checking and make validation on the input arg
 * 						if it correct it will return Rcc_enuOk
 * 						else will return one of these options
 * 						Rcc_enuNok /Gpio_enuNok /Gpio_enuErrorPin /Gpio_enuPinValError /Gpio_enuNullPtr
 *
 * */
GpioErrorStatus_t Gpio_enuInit(GpioPinCfg_t * copy_strAdd);


/****************************************************************
 * Description: 		this function to set GPIO pin
 *
 * input args: 			1-*copy_u8port -->> the port (BASE ADDRESS:- GPIO_x which x may be A,B,C,D,E,H)
						2-copy_u8pin   -->>	the pin number
						3-copy_u8Value -->> the pin value (High/ Low)

 * Return type: 		GpioErrorStatus_t for checking and make validation on the input arg
 * 						if it correct it will return Rcc_enuOk
 * 						else will return one of these options
 * 						Rcc_enuNok /Gpio_enuNok /Gpio_enuErrorPin /Gpio_enuPinValError /Gpio_enuNullPtr
 *
 * */
GpioErrorStatus_t Gpio_enuSetPinValue(void* copy_u8port,u8 copy_u8pin ,u8 copy_u8Value);
/****************************************************************
 * Description: 		this function to set GPIO pin
 *
 * input args: 			1-*copy_u8port -->> the port (BASE ADDRESS:- GPIO_x which x may be A,B,C,D,E,H)
						2-copy_u8pin   -->>	the pin number
						3-*copy_u8Value -->> to get the pin val (High/ Low)

 * Return type: 		GpioErrorStatus_t for checking and make validation on the input arg
 * 						if it correct it will return Rcc_enuOk
 * 						else will return one of these options
 * 						Rcc_enuNok /Gpio_enuNok /Gpio_enuErrorPin /Gpio_enuPinValError /Gpio_enuNullPtr
 * */
GpioErrorStatus_t Gpio_enuGetPinValue(void* copy_u8port,u8 copy_u8pin ,u8* copy_u8Value);

GpioErrorStatus_t Gpio_enuSetAlternativeFunc(GpioPinCfg_t *PinCfg);
#endif /* GPIO_H_ */
