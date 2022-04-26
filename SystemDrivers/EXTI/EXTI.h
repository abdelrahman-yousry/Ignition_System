/*
 * EXTI.h
 *
 *  Created on: Apr 24, 2022
 *      Author: Abdelrahman Yousry
 */

#ifndef EXTI_H_
#define EXTI_H_


/**************Typedef*************/

typedef enum
{
	Exti_enuOk,
	Exti_enuWromgChannel,
	Exti_enuNullPtr,
}EXTI_tenuErrorStatus;


typedef enum
{
	PINA,//0000
	PINB,//0001
	PINC,
	PIND,
	PINE,
	PINH=7,//0111

}EXTI_tenuPin;

typedef enum
{
	Ext0,
	Ext1,
	Ext2,
	Ext3,
	Ext4,
	Ext5,
	Ext6,
	Ext7,
	Ext8,
	Ext9,
	Ext10,
	Ext11,
	Ext12,
	Ext13,
	Ext14,
	Ext15,
}EXTI_tenuChannelId;

typedef enum
{
	InterruptReq,
	EventReq
}EXTI_tenuMode;

typedef struct
{
	u32 mode;
	EXTI_tenuPin Pin;
	EXTI_tenuChannelId Channel;
	u8 TriggerSelectionRising;
	u8 TriggerSelectionFalling;
	u8 InterruptControl;

}EXTI_tcfg;

typedef void (*Exti_Cbf)(void);


#define INTERRUPT_REQ				0U
#define EVENT_REQ					1U



#define RISING_TRIGGER_ENABLED		1U
#define RISING_TRIGGER_DISABLED		0U
#define FALLING_TRIGGER_ENABLED		1U
#define FALLING_TRIGGER_DISABLED	0U

#define INTERRUPT_ENABLED		1U
#define INTERRUPT_DISABLED		1U

/*****************PROTOTYPES*******************/

extern EXTI_tenuErrorStatus EXTI_enuInit(EXTI_tcfg * copy_ExtChannelCfg);
extern EXTI_tenuErrorStatus EXTI_enuInterruptEnable(EXTI_tenuChannelId copy_enuChannel);
extern EXTI_tenuErrorStatus EXTI_enuInterruptDisable(EXTI_tenuChannelId copy_enuChannel);
void EXTI_RegCbf(Exti_Cbf Cbf, EXTI_tenuChannelId Channel);

#endif /* EXTI_H_ */
