/*
 * Exti_prv.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Abdelrahman Yousry
 */
#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_

typedef struct
{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;
}EXTI_tReg;

typedef struct
{
	u32 SYSCFG_MEMRMP;
	u32 SYSCFG_PMC;
	u32 SYSCFG_EXTICR[4];
//	u32 SYSCFG_EXTICR2;
//	u32 SYSCFG_EXTICR3;
//	u32 SYSCFG_EXTICR4;
	u32 SYSCFG_CMPCR;
}SYSCFG_tReg;


#define EXTI_BASE_ADDRESS	0x40013C00
#define EXTI				((EXTI_tReg *) EXTI_BASE_ADDRESS)

#define SYSCFG_BASE_ADDRESS	0x40013800
#define SYSCFG				((SYSCFG_tReg *) SYSCFG_BASE_ADDRESS)


#endif /* EXTI_PRV_H_ */
