/*
 * EXTI.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Abdelrahman Yousry
 */

#include "Std_types.h"
#include "Exti_prv.h"
#include "EXTI.h"

// in stm data sheet --> stm is support only 5 Ext interrupt
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
/*This array of 5 callbackfn --> ptr to function represent the 5 handlers of each interrupt*/
static Exti_Cbf CallBackFunc[5] ;

/*Init the EXTI by passing the configuration in a struct */
extern EXTI_tenuErrorStatus EXTI_enuInit(EXTI_tcfg * copy_ExtChannelCfg)
{
	/*Error status variable initizlized by Exti_enuOk */
	EXTI_tenuErrorStatus Loc_enuStatusError = Exti_enuOk;
	if(copy_ExtChannelCfg == NULL)
	{
		/*If *copy_ExtChannelCfg having nothing passed from the user*/
		Loc_enuStatusError= Exti_enuNullPtr;
	}
	/*In case of Interrupt req*/
	if(copy_ExtChannelCfg->mode == INTERRUPT_REQ)
	{
		EXTI->EXTI_IMR  =(u32) (copy_ExtChannelCfg->InterruptControl)<<copy_ExtChannelCfg->Channel;
	}
	/*In case of Event req*/
	else if(copy_ExtChannelCfg->mode == EVENT_REQ)
	{
		EXTI->EXTI_EMR  = (copy_ExtChannelCfg->InterruptControl)<<copy_ExtChannelCfg->Channel;
	}
	/*if the user select that the trigger will be Rising only, he should pass in the other arg TriggerSelectionFalling --> 0
	 *if the user select that the trigger will be Falling only, he should pass in the other arg TriggerSelectionRising --> 0
	 *if the user select that the trigger to be both Falling and Rising, it will be handled
	 * */
	EXTI->EXTI_RTSR = 	(copy_ExtChannelCfg->TriggerSelectionRising) << copy_ExtChannelCfg->Channel;
	EXTI->EXTI_FTSR = 	(copy_ExtChannelCfg->TriggerSelectionFalling) << copy_ExtChannelCfg->Channel;

	/*Enable the channel with one of these values PAx --> 0000, PBx --> 0010 ,etc...
	 * according to this value it will be shifted according to the channel number
	 * */
	SYSCFG->SYSCFG_EXTICR[(copy_ExtChannelCfg->Channel)/4] = (copy_ExtChannelCfg->Pin) << ((copy_ExtChannelCfg->Channel)%4)*4;
	return Loc_enuStatusError;
}


/*Enable the interrupt bit according to the channel number*/
extern EXTI_tenuErrorStatus EXTI_enuInterruptEnable(EXTI_tenuChannelId copy_enuChannel)
{
	/*Error status variable initizlized by Exti_enuOk */
	EXTI_tenuErrorStatus Loc_enuStatusError = Exti_enuOk;
	if(copy_enuChannel>Ext15)
	{
		Loc_enuStatusError = Exti_enuWromgChannel;
	}
	else
	{
		EXTI->EXTI_IMR |= INTERRUPT_ENABLED<< copy_enuChannel;
	}
	return Loc_enuStatusError;
}
/*Disable the interrupt bit according to the channel number*/
extern EXTI_tenuErrorStatus EXTI_enuDisableEnable(EXTI_tenuChannelId copy_enuChannel)
{
	/*Error status variable initizlized by Exti_enuOk */
	EXTI_tenuErrorStatus Loc_enuStatusError = Exti_enuOk;
	if(copy_enuChannel>Ext15)
	{
		Loc_enuStatusError = Exti_enuWromgChannel;
	}
	else
	{

		EXTI->EXTI_IMR &= ~(INTERRUPT_DISABLED<< copy_enuChannel);
	}
	return Loc_enuStatusError;
}



/*This function is for the user to register the callback fn*/
void EXTI_RegCbf(Exti_Cbf Cbf, EXTI_tenuChannelId Channel)
{
	if(Cbf)
	{
		CallBackFunc [Channel]= Cbf ;
	}
}


void EXTI0_IRQHandler(void)
{
	 /* EXTI0 line interrupt detected */
	if(CallBackFunc[Ext0])
	{
		CallBackFunc[Ext0]();
		EXTI->EXTI_PR|= 1 <<Ext0 ; // clearing pending bit of channel 0 (EXT0)
	}
}
void EXTI1_IRQHandler(void)
{
	/* EXTI1 line interrupt detected */
	if(CallBackFunc[Ext1])
	{
		CallBackFunc[Ext1]();
		EXTI->EXTI_PR|= 1 <<Ext1 ; // clearing pending bit of channel 1 (EXT1)
	}
}
void EXTI2_IRQHandler(void)
{
	/* EXTI2 line interrupt detected */
	if(CallBackFunc[Ext2])
	{
		CallBackFunc[Ext2]();
		EXTI->EXTI_PR|= 1 <<Ext2 ; // clearing pending bit of channel 2 (EXT2)
	}
}
void EXTI3_IRQHandler(void)
{
	/* EXTI3 line interrupt detected */
	if(CallBackFunc[Ext3])
	{
		CallBackFunc[Ext3]();
		EXTI->EXTI_PR|= 1 <<Ext3 ; // clearing pending bit of channel 3 (EXT3)
	}
}
void EXTI4_IRQHandler(void)
{
	/* EXTI4 line interrupt detected */
	if(CallBackFunc[Ext4])
	{
		CallBackFunc[Ext4]();
		EXTI->EXTI_PR|= 1 <<Ext4 ; // clearing pending bit of channel 4 (EXT4)
	}
}
