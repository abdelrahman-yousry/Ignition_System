/*
 *      RCC.c
 *      Created on: Mar 11, 2022
 *      Author: Mostafa Adel
 *      Version: V0.0
 */

#include "Std_types.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


#define     RCC_HSI_SW_MASK 	    	0x00000000
#define     RCC_HSI_SWS_MASK 	    	0x00000000
#define     RCC_HSE_SW_MASK 	    	0x00000001
#define     RCC_HSE_SWS_MASK 	    	0x00000004
#define     RCC_PLL_SW_MASK 	    	0x00000002
#define     RCC_PLL_SWS_MASK 	    	0x00000008
#define     RCC_SCR_PIN 				22
/*****************************************************/




RCC_ErrorStatus RCC_InitSysClk()
{
	RCC_ErrorStatus Error=RCC_OK;

	#if   RCC_SYSCLK==RCC_HSI
		RCC->RCC_CR &= ~RCC_HSEBYP_MASK;
	#elif RCC_SYSCLK==RCC_HSE_Crystal
		RCC->RCC_CR &= ~RCC_HSEBYP_MASK;
	#elif RCC_SYSCLK==RCC_HSE_RC
		RCC->RCC_CR |= RCC_HSEBYP_MASK;
	#elif RCC_SYSCLK==RCC_PLL

	#elif RCC_SYSCLK==RCC_HSE
	#else
		#error("Wrong sysclk type")
	#endif


		/*Sysclk ON*/
	Error=RCC_ControlClk(RCC_SYSCLK,RCC_ON);
	if(Error==RCC_Error)
		return Error;
	/*Set system clk*/
	Error=RCC_SelectSysClk(RCC_SYSCLK);
	if(Error==RCC_Error)
			return Error;

	return Error;
}


RCC_ErrorStatus RCC_SelectSysClk(u8 Copy_u8clkId)
{
	RCC_ErrorStatus ErrorStatus = RCC_OK;
	u8 TimeOut=50;
	u32 temp;
	switch(Copy_u8clkId)
		{
		case RCC_HSI:
			RCC->RCC_CFGR &=~RCC_SW_MASK;
			while(TimeOut && !( (RCC->RCC_CFGR&RCC_SWS_MASK) == RCC_HSI_SWS_MASK))
				--TimeOut; //wait until HSIRDY became 0
			break;
		case RCC_HSE:

			temp=RCC->RCC_CFGR;
			temp &=~RCC_SW_MASK;
			temp |=RCC_HSE_SW_MASK;
			RCC->RCC_CFGR=temp;
			while(TimeOut && !((RCC->RCC_CFGR&RCC_SWS_MASK) == RCC_HSE_SWS_MASK))
			--TimeOut;

			break;
		case RCC_PLL:

			temp=RCC->RCC_CFGR;
			temp &=~RCC_SW_MASK;
			temp |=RCC_PLL_SW_MASK;
			RCC->RCC_CFGR=temp;
			while(TimeOut && !((RCC->RCC_CFGR&RCC_SWS_MASK) == RCC_PLL_SWS_MASK))
				--TimeOut;
			break;
		default:
			ErrorStatus=RCC_Error;
		}



	return ErrorStatus;
}


RCC_ErrorStatus RCC_ControlClk(u8 Copy_u8clkId,u8 Copy_stateId)
{
	RCC_ErrorStatus ErrorStatus = RCC_OK;
	if (Copy_stateId == RCC_OFF )
	{
		/*trying to stop sysclk*/
		/*if sysclk is HSI or is PLL and it's src is HSI*/
		if( ( (RCC->RCC_CR &RCC_SW_MASK )==RCC_HSI ||( Copy_u8clkId==RCC_PLL && (RCC->RCC_PLLCFGR & RCC_PLLCGF_SRC_MASK )==RCC_HSI ))&& Copy_u8clkId == RCC_HSI   )
		{
			ErrorStatus=RCC_Error;
		}
		/*if sysclk is HSE or is PLL and it's src is HSE*/
		else if( ( (RCC->RCC_CR &RCC_SW_MASK )==RCC_HSE ||( Copy_u8clkId==RCC_PLL && (RCC->RCC_PLLCFGR & RCC_PLLCGF_SRC_MASK )==RCC_HSE ))&& Copy_u8clkId == RCC_HSE )
		{
			ErrorStatus=RCC_Error;
		}else if((RCC->RCC_CR &RCC_SW_MASK)==RCC_PLL && Copy_u8clkId == RCC_PLL )
		{
			ErrorStatus=RCC_Error;
		}
		else
		{
			/*turn off the selected clk*/
      
			switch(Copy_u8clkId)
			{
			case RCC_HSI:
				RCC->RCC_CR &=~RCC_HSION_MASK; 
			//	while(RCC->RCC_CR |=RCC_HSIRDY_MASK); //wait until HSIRDY became 0
				break;
			case RCC_HSE:
				RCC->RCC_CR &=~RCC_HSEON_MASK;
			//	while(RCC->RCC_CR |=RCC_HSERDY_MASK); //wait until HSIRDY became 0
				break;
			case RCC_PLL:
				RCC->RCC_CR &=~RCC_PLLON_MASK;
			//	while(RCC->RCC_CR |=RCC_PLLRDY_MASK); //wait until HSIRDY became 0
				break;
			}
		}

	}
	else
	{ /*stateId == RCC_ON*/
		u8 TimeOut = 50;
    switch(Copy_u8clkId)
		{
		case RCC_HSI:
			RCC->RCC_CR |= RCC_HSION_MASK;
			while(TimeOut&& !(RCC->RCC_CR |=RCC_HSIRDY_MASK)) //wait until HSIRDY became 1
        --TimeOut; 
			break;
		case RCC_HSE:
			RCC->RCC_CR |=RCC_HSEON_MASK;
			while(TimeOut&& !(RCC->RCC_CR |=RCC_HSERDY_MASK))  //wait until HSIRDY became 1
        --TimeOut;
			break;
		case RCC_PLL:
			RCC->RCC_CR |=RCC_PLLON_MASK;
			while(TimeOut&& !(RCC->RCC_CR |=RCC_PLLRDY_MASK)) //wait until HSIRDY became 1
      --TimeOut;
			break;
		}
    if (!(RCC->RCC_CR |=RCC_PLLRDY_MASK))
      ErrorStatus=RCC_Error;


	}
	return ErrorStatus;
}

RCC_ErrorStatus RCC_Enable_Per_Clk(u8 Copy_u8BusId,u8 Copy_u8PerMask)
{
  RCC_ErrorStatus ErrorStatus = RCC_OK;
  if(Copy_u8PerMask>0 )
  {
    switch(Copy_u8BusId)
    {
      case RCC_AHB1:
    	  RCC->RCC_AHB1ENR|=Copy_u8PerMask;
        break;

      case RCC_AHB2:
    	  RCC->RCC_AHB2ENR|=Copy_u8PerMask;
        break; 
        
      case RCC_APB1:  
    	  RCC->RCC_APB1ENR|=Copy_u8PerMask;
        break;
        
      case RCC_APB2:  
    	  RCC->RCC_APB2ENR|=Copy_u8PerMask;
        break;
      default:
    	  ErrorStatus = RCC_Error;
    }
  }
  else
  {
    ErrorStatus = RCC_Error;
  }

	return ErrorStatus;
}

RCC_ErrorStatus RCC_Disable_Per_Clk(u8 Copy_u8BusId,u8 Copy_u8PerMask)
{
  RCC_ErrorStatus ErrorStatus = RCC_OK;
  if(Copy_u8PerMask>0 )
  {
    switch(Copy_u8BusId)
    {
      case RCC_AHB1:
    	  RCC->RCC_AHB1ENR&=~Copy_u8PerMask;
        break;

      case RCC_AHB2:
    	  RCC->RCC_AHB2ENR&=~Copy_u8PerMask;
        break;

      case RCC_APB1:
    	  RCC->RCC_APB1ENR&=~Copy_u8PerMask;
        break;

      case RCC_APB2:
    	  RCC->RCC_APB2ENR&=~Copy_u8PerMask;
        break;
      default:
    	  ErrorStatus = RCC_Error;
    }
  }
  else
  {
    ErrorStatus = RCC_Error;
  }

	return ErrorStatus;
}



RCC_ErrorStatus RCC_IsClkReady(u8 Copy_u8clkId,pu8 ReturnStatus)
{
	RCC_ErrorStatus ErrorStatus=RCC_OK;
	    switch(Copy_u8clkId)
			{
			case RCC_HSI:
				*ReturnStatus = (RCC->RCC_CR |=RCC_HSIRDY_MASK);
				break;
			case RCC_HSE:
				*ReturnStatus = (RCC->RCC_CR |=RCC_HSERDY_MASK);
				break;
			case RCC_PLL:
				*ReturnStatus = (RCC->RCC_CR |=RCC_PLLRDY_MASK);
				break;
			default:
				ErrorStatus=RCC_Error;

			}
	return ErrorStatus;
}

RCC_ErrorStatus RCC_Cfg_Bus_Prescaler(u8 Copy_u8BusId,u8 Copy_u8PrescalerId)
{
	RCC_ErrorStatus ErrorStatus=RCC_OK;
	u32 temp;
	temp=RCC->RCC_CFGR;
	 switch(Copy_u8BusId)
	    {
	      case RCC_AHB1:
	      case RCC_AHB2:
	    	  temp&=~RCC_HPRE_MASK;
	    	  temp|=Copy_u8PrescalerId;
	    	  RCC->RCC_CFGR=temp;
	        break;
	      case RCC_APB1:
	    	  temp&=~RCC_PPRE1_MASK;
	    	  temp|=Copy_u8PrescalerId;
	    	  RCC->RCC_CFGR=temp;
	        break;

	      case RCC_APB2:
	    	  temp&=~RCC_PPRE2_MASK;
	    	  temp|=Copy_u8PrescalerId;
	    	  RCC->RCC_CFGR=temp;
	    	  break;
	      default:
	    	  ErrorStatus = RCC_Error;
	    }
	return ErrorStatus;
}

RCC_ErrorStatus RCC_CfgPll ()
{
	RCC_ErrorStatus ErrorStatus=RCC_OK;
	u32 temp=RCC->RCC_PLLCFGR;

	/*CLR the configuration bits*/
	temp &=~RCC_PLLCGF_M_MASK;
	temp &=~RCC_PLLCGF_N_MASK;
	temp &=~RCC_PLLCGF_P_MASK;
	temp &=~RCC_PLLCGF_Q_MASK;
	temp &=~RCC_PLLCGF_SRC_MASK;
	/******************************/

	/*Configure the bits depends on RCC_config.h*/
	temp |=RCC_PLL_M;
	temp |=RCC_PLL_N;
	temp |=RCC_PLL_P;
	temp |=RCC_PLL_Q;
	temp |=RCC_PLL_SRC;
	/*********************************************/
	RCC->RCC_PLLCFGR=temp;


	return ErrorStatus;
}
