/*
 * NVIC.c
 *
 *  Created on: Apr 10, 2022
 *      Author: Mohamed Hosny
 */
#include"Std_types.h"
#include"NVIC.h"

typedef struct{
	u32 NVIC_ISER[8];
	u32 Reserved0[24];
	u32 NVIC_ICER[8];
	u32 Reserved1[24];
	u32 NVIC_ISPR[8];
	u32 Reserved2[24];
	u32 NVIC_ICPR[8];
	u32 Reserved3[24];
	u32 NVIC_IABR[8];
	u32 Reserved4[56];
	u8	NVIC_IPR[240];
	u32 Reserved5[644];
    u32 NVIC_STIR;
}NVIC_tstrRegisters;

#define IRQS_NUM					239
#define REG_SIZE					32
#define PRIO_REG_SIZE				8
#define HIGH_BIT					1
#define NULL						(void*)(0x00)
#define BIT_0_MASK                  0x00000001
#define SUB_GROUP_BITS_NUM_MASK		0xFFFF0700
#define FIVE						5
#define SIX							6
#define SEVEN						7

static NVIC_tstrRegisters* const NVIC_pstrRegisters = (NVIC_tstrRegisters* const)(0xE000E100);
static u32* const SCB_pu32AIRCR = (u32* const)(0xE000ED0C);

NVIC_tenuErrorStatus NVIC_enuEnableIRQ(u8 Copy_u8IRQNum)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	u8 Loc_u8RegisterNumber;
	u8 Loc_u8BitNumber;
	if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		Loc_u8RegisterNumber = Copy_u8IRQNum / REG_SIZE;
		Loc_u8BitNumber = Copy_u8IRQNum % REG_SIZE;
		NVIC_pstrRegisters -> NVIC_ISER[Loc_u8RegisterNumber] |=  (u32)((u32)HIGH_BIT << Loc_u8BitNumber);
	}
	return Loc_enuErrorStatus;
}

NVIC_tenuErrorStatus NVIC_enuDisableIRQ(u8 Copy_u8IRQNum)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	u8 Loc_u8RegisterNumber;
	u8 Loc_u8BitNumber;
	if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		Loc_u8RegisterNumber = Copy_u8IRQNum / REG_SIZE;
		Loc_u8BitNumber = Copy_u8IRQNum % REG_SIZE;
		NVIC_pstrRegisters -> NVIC_ICER[Loc_u8RegisterNumber] |=  (u32)((u32)HIGH_BIT << Loc_u8BitNumber);
	}
	return Loc_enuErrorStatus;
}

NVIC_tenuErrorStatus NVIC_enuSetPendingIRQ(u8 Copy_u8IRQNum)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		NVIC_pstrRegisters -> NVIC_STIR = Copy_u8IRQNum;
	}
	return Loc_enuErrorStatus;
}

NVIC_tenuErrorStatus NVIC_enuClearPendingIRQ(u8 Copy_u8IRQNum)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	u8 Loc_u8RegisterNumber;
	u8 Loc_u8BitNumber;
	if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		Loc_u8RegisterNumber = Copy_u8IRQNum / REG_SIZE;
		Loc_u8BitNumber = Copy_u8IRQNum % REG_SIZE;
		NVIC_pstrRegisters -> NVIC_ICPR[Loc_u8RegisterNumber] |= (u32)((u32)HIGH_BIT << Loc_u8BitNumber);
	}
	return Loc_enuErrorStatus;
}


NVIC_tenuErrorStatus NVIC_enuGetActiveIRQ(u8 Copy_u8IRQNum,pu8 Add_pu8ActiveStatusReturn)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	u8 Loc_u8RegisterNumber;
	u8 Loc_u8BitNumber;
	u32 Loc_u32TempAciveValue;
	if(Add_pu8ActiveStatusReturn == NULL)
	{
		Loc_enuErrorStatus = NVIC_enuNullPointer;
	}
	else if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		Loc_u8RegisterNumber = Copy_u8IRQNum / REG_SIZE;
		Loc_u8BitNumber = Copy_u8IRQNum % REG_SIZE;
		Loc_u32TempAciveValue = ( NVIC_pstrRegisters -> NVIC_IABR[Loc_u8RegisterNumber] & ((u32)BIT_0_MASK << Loc_u8BitNumber) );
		*Add_pu8ActiveStatusReturn = Loc_u32TempAciveValue >> Loc_u8BitNumber;
	}
	return Loc_enuErrorStatus;
}

NVIC_tenuErrorStatus NVIC_enuSetSubGroupBitsNum(u32 Copy_u32SubGroupBitsNum)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	u32 Loc_u32TempReg;
	if(Copy_u32SubGroupBitsNum > NVIC_u32SUB_GROUP_BITS_NUM_4 ||
			Copy_u32SubGroupBitsNum < NVIC_u32SUB_GROUP_BITS_NUM_1)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		Loc_u32TempReg = *SCB_pu32AIRCR;
		Loc_u32TempReg &= ~(SUB_GROUP_BITS_NUM_MASK);
		Loc_u32TempReg |= Copy_u32SubGroupBitsNum;
		*SCB_pu32AIRCR = Loc_u32TempReg;
	}
	return Loc_enuErrorStatus;
}

u8 NVIC_enuEncodePriority(u8 Copy_u8PreemtLevel,u8 Copy_u8SubGroupLevel,u32 Copy_u32SubGroupBitsNum)
{
	u8 Loc_PrioRegValue=255;
	switch(Copy_u32SubGroupBitsNum)
	{
		case NVIC_u32SUB_GROUP_BITS_NUM_1:
			if(Copy_u8SubGroupLevel > NVIC_u8SUB_GROUP_PRIO_LEVEL_1 || Copy_u8PreemtLevel > NVIC_u8PREEMT_PRIO_LEVEL_7)
			{
				Loc_PrioRegValue=255;
			}
			else
			{
				Loc_PrioRegValue = ( (Copy_u8PreemtLevel << FIVE) | Copy_u8SubGroupLevel );
			}
		break;
		case NVIC_u32SUB_GROUP_BITS_NUM_2:
			if(Copy_u8SubGroupLevel > NVIC_u8SUB_GROUP_PRIO_LEVEL_3 || Copy_u8PreemtLevel > NVIC_u8PREEMT_PRIO_LEVEL_3)
			{
				Loc_PrioRegValue=255;
			}
			else
			{
				Loc_PrioRegValue = ( (Copy_u8PreemtLevel << SIX) | Copy_u8SubGroupLevel );
			}
		break;
		case NVIC_u32SUB_GROUP_BITS_NUM_3:
			if(Copy_u8SubGroupLevel > NVIC_u8SUB_GROUP_PRIO_LEVEL_7 || Copy_u8PreemtLevel > NVIC_u8PREEMT_PRIO_LEVEL_1)
			{
				Loc_PrioRegValue=255;
			}
			else
			{
				Loc_PrioRegValue = ( (Copy_u8PreemtLevel << SEVEN) | Copy_u8SubGroupLevel );
			}
		break;
		case NVIC_u32SUB_GROUP_BITS_NUM_4:
			if(Copy_u8SubGroupLevel > NVIC_u8SUB_GROUP_PRIO_LEVEL_15)
			{
				Loc_PrioRegValue=255;
			}
			else
			{
				Loc_PrioRegValue = Copy_u8SubGroupLevel;
			}
		break;
	}
	return Loc_PrioRegValue;
}
NVIC_tenuErrorStatus NVIC_enuSetPriority(u8 Copy_u8IRQNum,u8 Copy_PrioRegValue)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	if(Copy_u8IRQNum > IRQS_NUM)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		NVIC_pstrRegisters -> NVIC_IPR[Copy_u8IRQNum] = Copy_PrioRegValue;
	}
	return Loc_enuErrorStatus;
}
void NVIC_enuDisableIRQs(void)
{
	__asm("CPSID i");
}
void NVIC_enuEnableIRQs(void)
{
	__asm("CPSIE i");
}
void NVIC_enuEnableFaults(void)
{
	__asm("CPSIE i");
}
void NVIC_enuDisableFaults(void)
{
	__asm("CPSID f");
}
NVIC_tenuErrorStatus NVIC_enuFilteringInterrupts(u8 Copy_u8PreemtLevel)
{
	NVIC_tenuErrorStatus Loc_enuErrorStatus = NVIC_enuOk;
	if(Copy_u8PreemtLevel > NVIC_u8PREEMT_PRIO_LEVEL_7)
	{
		Loc_enuErrorStatus = NVIC_enuWrongIpParameter;
	}
	else
	{
		switch(Copy_u8PreemtLevel)
		{
			case NVIC_u8PREEMT_PRIO_LEVEL_0:
				__asm("MOV r0,#0x00");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_1:
				__asm("MOV r0,#0x10");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_2:
				__asm("MOV r0,#0x20");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_3:
				__asm("MOV r0,#0x30");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_4:
				__asm("MOV r0,#0x40");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_5:
				__asm("MOV r0,#0x50");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_6:
				__asm("MOV r0,#0x60");
				__asm("MSR BASEPRI,r0");
			break;
			case NVIC_u8PREEMT_PRIO_LEVEL_7:
				__asm("MOV r0,#0x70");
				__asm("MSR BASEPRI,r0");
			break;
		}
	}
	return  Loc_enuErrorStatus;
}
