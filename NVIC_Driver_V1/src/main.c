/*
 * main.c
 *
 *  Created on: Apr 11, 2022
 *      Author: Mohamed Hosny
 */

#include "Std_types.h"
#include "NVIC.h"
#include "diag/trace.h"

int main(void)
{
	u8 result=0;
	NVIC_enuEnableIRQ(NVIC_u8IRQ_NUM_0);
	NVIC_enuDisableIRQ(NVIC_u8IRQ_NUM_0);
	//NVIC_enuEnableIRQ(NVIC_u8IRQ_NUM_0);
	NVIC_enuSetPendingIRQ(NVIC_u8IRQ_NUM_0);
	NVIC_enuClearPendingIRQ(NVIC_u8IRQ_NUM_0);

	NVIC_enuSetSubGroupBitsNum(NVIC_u32SUB_GROUP_BITS_NUM_4);

	result=NVIC_enuEncodePriority( NVIC_u8PREEMT_PRIO_LEVEL_1 ,NVIC_u8SUB_GROUP_PRIO_LEVEL_3,NVIC_u32SUB_GROUP_BITS_NUM_4);
	NVIC_enuSetPriority(NVIC_u8IRQ_NUM_0,result);
	NVIC_enuFilteringInterrupts(NVIC_u8PREEMT_PRIO_LEVEL_7);
	NVIC_enuDisableIRQs();
	NVIC_enuEnableIRQs();
	NVIC_enuEnableFaults();
	NVIC_enuDisableFaults();
	return 0;
}
