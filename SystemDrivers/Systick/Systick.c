/*
 * Systick.c
 *
 *  Created on: Apr 13, 2022
 *      Author: Abdelrahman yousry
 */
#include "Std_types.h"
#include "Systick.h"
#include "Systick_prv.h"
#include "Systick_cfg.h"

//static flag = 0;

/*YOU SHOULD GO WITH THIS SEQUENCE:-
 * 1.Program reload value.
 * 2.Clear current value.
 * 3.Program Control and Status register.
**/
Systick_tenuErrorStatus Systick_enuInit(u8 copy_u8TimeMs)
{
	Systick_tenuErrorStatus Loc_enuStatusError;
	u32 Loc_u32TimeMs=0;
	u32 Loc_u32NumOfCounts=0;
	u32 Loc_u32temp=0;
#if CLOCK_SOURCE == AHB_PROCESSOR_CLOCK
	/*convert ONE Tcount to ms */
	Loc_u32TimeMs = (SYSTEM_CLOCK_SOURCE)/((u16)1000); //ms 16000
#elif CLOCK_SOURCE == AHB_CLOCK_DEVIDED_BY_8
	Loc_u32TimeMs = (((SYSTEM_CLOCK_SOURCE)/8)/(u16)1000);
#endif
	/*calculate the number of counts needed to get the desired time*/
	Loc_u32NumOfCounts= copy_u8TimeMs*Loc_u32TimeMs;
	/*check if the number of counts exceed the Max register value or not*/
	if(Loc_u32NumOfCounts>MAX_SYSTICK_COUNTS)
	{
		Loc_enuStatusError = Systick_enuInvalidTime;
	}
	else
	{
		SYSTICK->STK_LOAD=Loc_u32NumOfCounts;
//		*copy_u8TimeMs;
	}
//	SYSTICK->STK_VAL = 0;
	Loc_u32temp=SYSTICK->STK_CTRL;
	Loc_u32temp|=(AHB_PROCESSOR_CLOCK|SYSTICK_INTERRUPT);
	SYSTICK->STK_CTRL = Loc_u32temp;
	return Loc_enuStatusError;
}

void Systickv_vidStart(void)
{
	SYSTICK->STK_CTRL|=SYSTICK_ENABLED;
}


void Systickv_vidDisable(void)
{
	SYSTICK->STK_CTRL&=SYSTICK_DISAPLED;
}

Systick_tenuErrorStatus Systick_vidRegcbf(pfunc copy_pCbf)
{
	Systick_tenuErrorStatus Loc_enuStatusError = Systick_enuOk;
	if(copy_pCbf)
	{
		CallBackfunc = copy_pCbf;
	}
	else
	{
		Loc_enuStatusError = Systick_enuNullPointer;
	}
	return Loc_enuStatusError ;
}

void __attribute__ ((section(".after_vectors")))
SysTick_Handler (void)
{
	CallBackfunc();
}

