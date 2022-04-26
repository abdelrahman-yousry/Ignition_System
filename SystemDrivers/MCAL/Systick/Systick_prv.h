/*
 * Systick_prv.h
 *
 *  Created on: Apr 13, 2022
 *      Author: Abdelrahman Yousry
 */

#ifndef SYSTICK_PRV_H_
#define SYSTICK_PRV_H_

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}t_SystickReg;

static pfunc CallBackfunc ;

#define SYSTEICK_BASE_ADDRESS		0xE000E010
#define SYSTICK						((t_SystickReg*)SYSTEICK_BASE_ADDRESS)

#define MAX_SYSTICK_COUNTS			16777216	//2^24
#endif /* SYSTICK_PRV_H_ */
