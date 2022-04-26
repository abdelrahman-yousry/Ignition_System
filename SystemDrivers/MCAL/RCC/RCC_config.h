/*
 *      RCC_CFG.h
 *      Created on: Mar 11, 2022
 *      Author: Mostafa Adel
 *      Version: V0.0
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* choose your sysclk RCC_HSE_Crystal, RCC_HSE_RC, RCC_HSI, RCC_PLL */
#define RCC_SYSCLK RCC_HSI

/*PLL Configuration*/

/*RCC_HSI_PLLSCR_MASK , RCC_HSE_PLLSCR_MASK */
#define RCC_PLL_SRC RCC_HSI_PLLSCR_MASK
/***********************/

/*Refer to PLL configuration options in RCC_interface.h*/
/*options : RCC_PLLM_X_MASK*/
/*options : RCC_PLLN_X_MASK*/
/*options : RCC_PLLP_X_MASK*/
/*options : RCC_PLLQ_X_MASK*/


#define RCC_PLL_M   RCC_PLLM_10_MASK
#define RCC_PLL_N   RCC_PLLN_192_MASK
#define RCC_PLL_P   RCC_PLLP_4_MASK
#define RCC_PLL_Q   RCC_PLLQ_10_MASK
/*******************************/



#endif /* RCC_CFG_H_ */
