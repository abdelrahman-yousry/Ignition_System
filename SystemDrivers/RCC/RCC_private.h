/*********************************************************************/
/*      RCC_prv.h                                                    */
/*      Created on: Mar 11, 2022                                     */
/*      Author: Mostafa Adel                                         */
/*      Version: V0.0                                                */
/*********************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



/*RCC_CR bits*/
#define RCC_HSION_MASK  0x00000001
#define RCC_HSIRDY_MASK 0x00000002
#define RCC_HSEON_MASK  0x00010000
#define RCC_HSEBYP_MASK 0x00040000
#define RCC_CSSON_MASK 0x00080000
#define RCC_HSERDY_MASK 0x00020000
#define RCC_HSITRIM_MASK  0x000F8000
#define RCC_HSICAL_MASK  0x00FF0000
#define RCC_PLLON_MASK  0x01000000
#define RCC_PLLRDY_MASK 0x02000000
#define RCC_PLLI2SON_MASK 0x04000000
#define RCC_PLLI2SRDY_MASK 0x08000000
/*********************************/


/*RCC_PLLCFGR bits*/
#define     RCC_PLLCGF_M_MASK 	  	 	0x0000003F
#define     RCC_PLLCGF_N_MASK 	  	 	0x00007FC0
#define     RCC_PLLCGF_P_MASK  	 	    0x00030000
#define     RCC_PLLCGF_SRC_MASK   	    0x00400000
#define     RCC_PLLCGF_Q_MASK  	 	    0x0F000000
/*******************************/

/*RCC_CFGR bits*/
#define	   RCC_SW_MASK 		0x00000003
#define    RCC_SWS_MASK 	0x0000000C
#define	   RCC_HPRE_MASK 		0x000000F0
#define    RCC_PPRE1_MASK		0x00001C00
#define    RCC_PPRE2_MASK 		0x0000E000
//
//
//
//
//
//
/*******************************/

#define     RCC_MAX_M_VAL    	    	63
#define     RCC_MIN_M_VAL    	    	2


/*Registers Definations */
typedef struct{
	u32 RCC_CR;     //enable and disable clk source
	u32 RCC_PLLCFGR;//configure PLL clk source 
	u32 RCC_CFGR;  //configure clk source 
	u32 RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32 RCC_AHB2RSTR;
	u32 RES1[2];
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32 RES2[2];
	u32 RCC_AHB1ENR; // enable and disable peripherals clk source
	u32 RCC_AHB2ENR; // enable and disable peripherals clk source
	u32 RES3[2];
	u32 RCC_APB1ENR; // enable and disable peripherals clk source
	u32 RCC_APB2ENR; // enable and disable peripherals clk source
	u32 RES4[2];
	u32 RCC_AHB1LPENR;
	u32 RCC_AHB2LPENR;
	u32 RES5[2];
	u32 RCC_APB1LPENR;
	u32 RCC_APB2LPENR;
	u32 RES6[2];
	u32 RCC_BDCR;
	u32 RCC_CSR;
	u32 RES7[2];
	u32 RCC_SSCGR;
	u32 RCC_PLLI2SCFGR;
	u32 RES8;
	u32 RCC_DCKCFGR;
}RCC_Registers;

#define RCC  ((RCC_Registers *)(0x40023800))





#endif /* RCC_PRV_H_ */
