/*
 * Systick.h
 *
 *  Created on: Apr 13, 2022
 *      Author: Abdelrahman Yousry
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


/*this is the Error options which will be the return of the functions below*/
typedef enum
{
	Systick_enuOk,
	Systick_enuInvalidTime,
	Systick_enuNullPointer
}Systick_tenuErrorStatus;

typedef void(*pfunc)(void);

#define AHB_CLOCK_DEVIDED_BY_8		(u16)0x0000
#define AHB_PROCESSOR_CLOCK			0x04

#define SYSTICK_INTERRUPT_ENABLE	(u16)0x02
#define SYSTICK_INTERRUPT_DISABLE	(u16)0x00

#define SYSTICK_ENABLED				(u16)0x01
#define SYSTICK_DISAPLED			(u16)0xfE


/****************************************************************
 * Description: 		this function to Init SysTick timer
 *
 * input args: 			copy_u8TimeMs -- > the time in ms
 *
 * Return type: 		Systick_tenuErrorStatus for checking and make validation on the input arg
 * 						if it correct it will return Rcc_enuOk
 * 						else one of these options: -
 * 						1-	Systick_enuOk,
						2-  Systick_enuInvalidTime,
						3-	Systick_enuNullPointer
 * */
Systick_tenuErrorStatus Systick_enuInit(u8 copy_u8TimeMs);
/****************************************************************
 * Description: 		this function to start counting
 *
 * input args: 			void
 *
 * Return type: 		void
 * */
void Systickv_vidStart(void);
/****************************************************************
 * Description: 		this function to Disable Systick
 *
 * input args: 			void
 *
 * Return type: 		void
 * */
void Systickv_vidDisable(void);
Systick_tenuErrorStatus Systick_vidRegcbf(pfunc copy_pCbf);
//Systick_tenuErrorStatus Systick_enuDelay(u32 copy_TimeMs);



#endif /* SYSTICK_H_ */
