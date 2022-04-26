/*
 *      RCC.h
 *      Created on: Mar 11, 2022
 *      Author: Mostafa Adel
 *      Version: V0.0
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/*PLL configuration options*/

/*PLL SRC*/
#define     RCC_HSI_PLLSCR_MASK     	0x00000000
#define     RCC_HSE_PLLSCR_MASK     	0x00400000

/* PLL M mask */
#define RCC_PLLM_2_MASK     2
#define RCC_PLLM_3_MASK     3
#define RCC_PLLM_4_MASK     4
#define RCC_PLLM_5_MASK     5
#define RCC_PLLM_6_MASK     6
#define RCC_PLLM_7_MASK     7
#define RCC_PLLM_8_MASK     8
#define RCC_PLLM_9_MASK     9
#define RCC_PLLM_10_MASK    10
#define RCC_PLLM_11_MASK    11
#define RCC_PLLM_12_MASK    12
#define RCC_PLLM_13_MASK    13
#define RCC_PLLM_14_MASK    14
#define RCC_PLLM_15_MASK    15
#define RCC_PLLM_16_MASK    16
#define RCC_PLLM_17_MASK    17
#define RCC_PLLM_18_MASK    18
#define RCC_PLLM_19_MASK    19
#define RCC_PLLM_20_MASK    20
#define RCC_PLLM_21_MASK    21
#define RCC_PLLM_22_MASK    22
#define RCC_PLLM_23_MASK    23
#define RCC_PLLM_24_MASK    24
#define RCC_PLLM_25_MASK    25
#define RCC_PLLM_26_MASK    26
#define RCC_PLLM_27_MASK    27
#define RCC_PLLM_28_MASK    28
#define RCC_PLLM_29_MASK    29
#define RCC_PLLM_30_MASK    30
#define RCC_PLLM_31_MASK    31
#define RCC_PLLM_32_MASK    32
#define RCC_PLLM_33_MASK    33
#define RCC_PLLM_34_MASK    34
#define RCC_PLLM_35_MASK    35
#define RCC_PLLM_36_MASK    36
#define RCC_PLLM_37_MASK    37
#define RCC_PLLM_38_MASK    38
#define RCC_PLLM_39_MASK    39
#define RCC_PLLM_40_MASK    40
#define RCC_PLLM_41_MASK    41
#define RCC_PLLM_42_MASK    42
#define RCC_PLLM_43_MASK    43
#define RCC_PLLM_44_MASK    44
#define RCC_PLLM_45_MASK    45
#define RCC_PLLM_46_MASK    46
#define RCC_PLLM_47_MASK    47
#define RCC_PLLM_48_MASK    48
#define RCC_PLLM_49_MASK    49
#define RCC_PLLM_50_MASK    50
#define RCC_PLLM_51_MASK    51
#define RCC_PLLM_52_MASK    52
#define RCC_PLLM_53_MASK    53
#define RCC_PLLM_54_MASK    54
#define RCC_PLLM_55_MASK    55
#define RCC_PLLM_56_MASK    56
#define RCC_PLLM_57_MASK    57
#define RCC_PLLM_58_MASK    58
#define RCC_PLLM_59_MASK    59
#define RCC_PLLM_60_MASK    60
#define RCC_PLLM_61_MASK    61
#define RCC_PLLM_62_MASK    62
#define RCC_PLLM_63_MASK    63

/* PLL N mask */
#define RCC_PLLN_192_MASK    12288
#define RCC_PLLN_193_MASK    12352
#define RCC_PLLN_194_MASK    12416
#define RCC_PLLN_195_MASK    12480
#define RCC_PLLN_196_MASK    12544
#define RCC_PLLN_197_MASK    12608
#define RCC_PLLN_198_MASK    12672
#define RCC_PLLN_199_MASK    12736
#define RCC_PLLN_200_MASK    12800
#define RCC_PLLN_201_MASK    12864
#define RCC_PLLN_202_MASK    12928
#define RCC_PLLN_203_MASK    12992
#define RCC_PLLN_204_MASK    13056
#define RCC_PLLN_205_MASK    13120
#define RCC_PLLN_206_MASK    13184
#define RCC_PLLN_207_MASK    13248
#define RCC_PLLN_208_MASK    13312
#define RCC_PLLN_209_MASK    13376
#define RCC_PLLN_210_MASK    13440
#define RCC_PLLN_211_MASK    13504
#define RCC_PLLN_212_MASK    13568
#define RCC_PLLN_213_MASK    13632
#define RCC_PLLN_214_MASK    13696
#define RCC_PLLN_215_MASK    13760
#define RCC_PLLN_216_MASK    13824
#define RCC_PLLN_217_MASK    13888
#define RCC_PLLN_218_MASK    13952
#define RCC_PLLN_219_MASK    14016
#define RCC_PLLN_220_MASK    14080
#define RCC_PLLN_221_MASK    14144
#define RCC_PLLN_222_MASK    14208
#define RCC_PLLN_223_MASK    14272
#define RCC_PLLN_224_MASK    14336
#define RCC_PLLN_225_MASK    14400
#define RCC_PLLN_226_MASK    14464
#define RCC_PLLN_227_MASK    14528
#define RCC_PLLN_228_MASK    14592
#define RCC_PLLN_229_MASK    14656
#define RCC_PLLN_230_MASK    14720
#define RCC_PLLN_231_MASK    14784
#define RCC_PLLN_232_MASK    14848
#define RCC_PLLN_233_MASK    14912
#define RCC_PLLN_234_MASK    14976
#define RCC_PLLN_235_MASK    15040
#define RCC_PLLN_236_MASK    15104
#define RCC_PLLN_237_MASK    15168
#define RCC_PLLN_238_MASK    15232
#define RCC_PLLN_239_MASK    15296
#define RCC_PLLN_240_MASK    15360
#define RCC_PLLN_241_MASK    15424
#define RCC_PLLN_242_MASK    15488
#define RCC_PLLN_243_MASK    15552
#define RCC_PLLN_244_MASK    15616
#define RCC_PLLN_245_MASK    15680
#define RCC_PLLN_246_MASK    15744
#define RCC_PLLN_247_MASK    15808
#define RCC_PLLN_248_MASK    15872
#define RCC_PLLN_249_MASK    15936
#define RCC_PLLN_250_MASK    16000
#define RCC_PLLN_251_MASK    16064
#define RCC_PLLN_252_MASK    16128
#define RCC_PLLN_253_MASK    16192
#define RCC_PLLN_254_MASK    16256
#define RCC_PLLN_255_MASK    16320
#define RCC_PLLN_256_MASK    16384
#define RCC_PLLN_257_MASK    16448
#define RCC_PLLN_258_MASK    16512
#define RCC_PLLN_259_MASK    16576
#define RCC_PLLN_260_MASK    16640
#define RCC_PLLN_261_MASK    16704
#define RCC_PLLN_262_MASK    16768
#define RCC_PLLN_263_MASK    16832
#define RCC_PLLN_264_MASK    16896
#define RCC_PLLN_265_MASK    16960
#define RCC_PLLN_266_MASK    17024
#define RCC_PLLN_267_MASK    17088
#define RCC_PLLN_268_MASK    17152
#define RCC_PLLN_269_MASK    17216
#define RCC_PLLN_270_MASK    17280
#define RCC_PLLN_271_MASK    17344
#define RCC_PLLN_272_MASK    17408
#define RCC_PLLN_273_MASK    17472
#define RCC_PLLN_274_MASK    17536
#define RCC_PLLN_275_MASK    17600
#define RCC_PLLN_276_MASK    17664
#define RCC_PLLN_277_MASK    17728
#define RCC_PLLN_278_MASK    17792
#define RCC_PLLN_279_MASK    17856
#define RCC_PLLN_280_MASK    17920
#define RCC_PLLN_281_MASK    17984
#define RCC_PLLN_282_MASK    18048
#define RCC_PLLN_283_MASK    18112
#define RCC_PLLN_284_MASK    18176
#define RCC_PLLN_285_MASK    18240
#define RCC_PLLN_286_MASK    18304
#define RCC_PLLN_287_MASK    18368
#define RCC_PLLN_288_MASK    18432
#define RCC_PLLN_289_MASK    18496
#define RCC_PLLN_290_MASK    18560
#define RCC_PLLN_291_MASK    18624
#define RCC_PLLN_292_MASK    18688
#define RCC_PLLN_293_MASK    18752
#define RCC_PLLN_294_MASK    18816
#define RCC_PLLN_295_MASK    18880
#define RCC_PLLN_296_MASK    18944
#define RCC_PLLN_297_MASK    19008
#define RCC_PLLN_298_MASK    19072
#define RCC_PLLN_299_MASK    19136
#define RCC_PLLN_300_MASK    19200
#define RCC_PLLN_301_MASK    19264
#define RCC_PLLN_302_MASK    19328
#define RCC_PLLN_303_MASK    19392
#define RCC_PLLN_304_MASK    19456
#define RCC_PLLN_305_MASK    19520
#define RCC_PLLN_306_MASK    19584
#define RCC_PLLN_307_MASK    19648
#define RCC_PLLN_308_MASK    19712
#define RCC_PLLN_309_MASK    19776
#define RCC_PLLN_310_MASK    19840
#define RCC_PLLN_311_MASK    19904
#define RCC_PLLN_312_MASK    19968
#define RCC_PLLN_313_MASK    20032
#define RCC_PLLN_314_MASK    20096
#define RCC_PLLN_315_MASK    20160
#define RCC_PLLN_316_MASK    20224
#define RCC_PLLN_317_MASK    20288
#define RCC_PLLN_318_MASK    20352
#define RCC_PLLN_319_MASK    20416
#define RCC_PLLN_320_MASK    20480
#define RCC_PLLN_321_MASK    20544
#define RCC_PLLN_322_MASK    20608
#define RCC_PLLN_323_MASK    20672
#define RCC_PLLN_324_MASK    20736
#define RCC_PLLN_325_MASK    20800
#define RCC_PLLN_326_MASK    20864
#define RCC_PLLN_327_MASK    20928
#define RCC_PLLN_328_MASK    20992
#define RCC_PLLN_329_MASK    21056
#define RCC_PLLN_330_MASK    21120
#define RCC_PLLN_331_MASK    21184
#define RCC_PLLN_332_MASK    21248
#define RCC_PLLN_333_MASK    21312
#define RCC_PLLN_334_MASK    21376
#define RCC_PLLN_335_MASK    21440
#define RCC_PLLN_336_MASK    21504
#define RCC_PLLN_337_MASK    21568
#define RCC_PLLN_338_MASK    21632
#define RCC_PLLN_339_MASK    21696
#define RCC_PLLN_340_MASK    21760
#define RCC_PLLN_341_MASK    21824
#define RCC_PLLN_342_MASK    21888
#define RCC_PLLN_343_MASK    21952
#define RCC_PLLN_344_MASK    22016
#define RCC_PLLN_345_MASK    22080
#define RCC_PLLN_346_MASK    22144
#define RCC_PLLN_347_MASK    22208
#define RCC_PLLN_348_MASK    22272
#define RCC_PLLN_349_MASK    22336
#define RCC_PLLN_350_MASK    22400
#define RCC_PLLN_351_MASK    22464
#define RCC_PLLN_352_MASK    22528
#define RCC_PLLN_353_MASK    22592
#define RCC_PLLN_354_MASK    22656
#define RCC_PLLN_355_MASK    22720
#define RCC_PLLN_356_MASK    22784
#define RCC_PLLN_357_MASK    22848
#define RCC_PLLN_358_MASK    22912
#define RCC_PLLN_359_MASK    22976
#define RCC_PLLN_360_MASK    23040
#define RCC_PLLN_361_MASK    23104
#define RCC_PLLN_362_MASK    23168
#define RCC_PLLN_363_MASK    23232
#define RCC_PLLN_364_MASK    23296
#define RCC_PLLN_365_MASK    23360
#define RCC_PLLN_366_MASK    23424
#define RCC_PLLN_367_MASK    23488
#define RCC_PLLN_368_MASK    23552
#define RCC_PLLN_369_MASK    23616
#define RCC_PLLN_370_MASK    23680
#define RCC_PLLN_371_MASK    23744
#define RCC_PLLN_372_MASK    23808
#define RCC_PLLN_373_MASK    23872
#define RCC_PLLN_374_MASK    23936
#define RCC_PLLN_375_MASK    24000
#define RCC_PLLN_376_MASK    24064
#define RCC_PLLN_377_MASK    24128
#define RCC_PLLN_378_MASK    24192
#define RCC_PLLN_379_MASK    24256
#define RCC_PLLN_380_MASK    24320
#define RCC_PLLN_381_MASK    24384
#define RCC_PLLN_382_MASK    24448
#define RCC_PLLN_383_MASK    24512
#define RCC_PLLN_384_MASK    24576
#define RCC_PLLN_385_MASK    24640
#define RCC_PLLN_386_MASK    24704
#define RCC_PLLN_387_MASK    24768
#define RCC_PLLN_388_MASK    24832
#define RCC_PLLN_389_MASK    24896
#define RCC_PLLN_390_MASK    24960
#define RCC_PLLN_391_MASK    25024
#define RCC_PLLN_392_MASK    25088
#define RCC_PLLN_393_MASK    25152
#define RCC_PLLN_394_MASK    25216
#define RCC_PLLN_395_MASK    25280
#define RCC_PLLN_396_MASK    25344
#define RCC_PLLN_397_MASK    25408
#define RCC_PLLN_398_MASK    25472
#define RCC_PLLN_399_MASK    25536
#define RCC_PLLN_400_MASK    25600
#define RCC_PLLN_401_MASK    25664
#define RCC_PLLN_402_MASK    25728
#define RCC_PLLN_403_MASK    25792
#define RCC_PLLN_404_MASK    25856
#define RCC_PLLN_405_MASK    25920
#define RCC_PLLN_406_MASK    25984
#define RCC_PLLN_407_MASK    26048
#define RCC_PLLN_408_MASK    26112
#define RCC_PLLN_409_MASK    26176
#define RCC_PLLN_410_MASK    26240
#define RCC_PLLN_411_MASK    26304
#define RCC_PLLN_412_MASK    26368
#define RCC_PLLN_413_MASK    26432
#define RCC_PLLN_414_MASK    26496
#define RCC_PLLN_415_MASK    26560
#define RCC_PLLN_416_MASK    26624
#define RCC_PLLN_417_MASK    26688
#define RCC_PLLN_418_MASK    26752
#define RCC_PLLN_419_MASK    26816
#define RCC_PLLN_420_MASK    26880
#define RCC_PLLN_421_MASK    26944
#define RCC_PLLN_422_MASK    27008
#define RCC_PLLN_423_MASK    27072
#define RCC_PLLN_424_MASK    27136
#define RCC_PLLN_425_MASK    27200
#define RCC_PLLN_426_MASK    27264
#define RCC_PLLN_427_MASK    27328
#define RCC_PLLN_428_MASK    27392
#define RCC_PLLN_429_MASK    27456
#define RCC_PLLN_430_MASK    27520
#define RCC_PLLN_431_MASK    27584
#define RCC_PLLN_432_MASK    27648

/* PLL P mask */
#define RCC_PLLP_2_MASK    00
#define RCC_PLLP_4_MASK    65536
#define RCC_PLLP_6_MASK    131072
#define RCC_PLLP_8_MASK    196608

/* PLL Q mask */
#define RCC_PLLQ_2_MASK    33554432
#define RCC_PLLQ_3_MASK    50331648
#define RCC_PLLQ_4_MASK    67108864
#define RCC_PLLQ_5_MASK    83886080
#define RCC_PLLQ_6_MASK    100663296
#define RCC_PLLQ_7_MASK    117440512
#define RCC_PLLQ_8_MASK    134217728
#define RCC_PLLQ_9_MASK    150994944
#define RCC_PLLQ_10_MASK    167772160
#define RCC_PLLQ_11_MASK    184549376
#define RCC_PLLQ_12_MASK    201326592
#define RCC_PLLQ_13_MASK    218103808
#define RCC_PLLQ_14_MASK    234881024
#define RCC_PLLQ_15_MASK    251658240
/****************************/
/****************************/




#define	   RCC_AHB_DIVIDED_BY_1			0x00000000
#define	   RCC_AHB_DIVIDED_BY_2			0x00000080
#define	   RCC_AHB_DIVIDED_BY_4			0x00000090
#define	   RCC_AHB_DIVIDED_BY_8			0x000000A0
#define	   RCC_AHB_DIVIDED_BY_16		0x000000B0
#define	   RCC_AHB_DIVIDED_BY_64		0x000000C0
#define	   RCC_AHB_DIVIDED_BY_128		0x000000D0
#define	   RCC_AHB_DIVIDED_BY_256		0x000000E0
#define	   RCC_AHB_DIVIDED_BY_512		0x000000F0

#define	   RCC_APB1_DIVIDED_BY_1		0x00000000
#define	   RCC_APB1_DIVIDED_BY_2		0x00000800
#define	   RCC_APB1_DIVIDED_BY_4		0x00000A00
#define	   RCC_APB1_DIVIDED_BY_8		0x00000C00
#define	   RCC_APB1_DIVIDED_BY_16		0x00000E00

#define	   RCC_APB2_DIVIDED_BY_1		0x00000000
#define	   RCC_APB2_DIVIDED_BY_2		0x00004000
#define	   RCC_APB2_DIVIDED_BY_4		0x00005000
#define	   RCC_APB2_DIVIDED_BY_8		0x00006000
#define	   RCC_APB2_DIVIDED_BY_16		0x00007000

#define	   RCC_GPIOA		0x00000001
#define	   RCC_GPIOB		0x00000002
#define	   RCC_GPIOC		0x00000004
#define	   RCC_GPIOD		0x00000008
#define	   RCC_GPIOE		0x00000008
#define	   RCC_GPIOH		0x00000080
#define	   RCC_CRC			0x00001000
#define	   RCC_DMA1			0x00020000
#define	   RCC_DMA2			0x00040000
#define	   RCC_DMA2			0x00040000
#define	   RCC_OTGFS		0x00000080
#define	   RCC_TIM2			0x00000001
#define	   RCC_TIM3			0x00000002
#define	   RCC_TIM4			0x00000004
#define	   RCC_TIM5			0x00000008
#define	   RCC_WWDG			0x00000800
#define	   RCC_SPI2			0x00004000
#define	   RCC_SPI3			0x00008000
#define	   RCC_USART2		0x00020000
#define	   RCC_I2C1			0x00020000
#define	   RCC_I2C2			0x00040000
#define	   RCC_I2C3			0x00080000
#define	   RCC_PWR			0x10000000
#define	   RCC_TIM1			0x00000001
#define	   RCC_USART1		0x00000010
#define	   RCC_USART6		0x00000020
#define	   RCC_ADC1			0x00000100
#define	   RCC_SDIO1		0x00000800
#define	   RCC_SP1			0x00001000
#define	   RCC_SPI4			0x00002000
#define	   RCC_SYSCFG		0x00004000
#define	   RCC_TIM9			0x00010000
#define	   RCC_TIM10		0x00020000
#define	   RCC_TIM11		0x00040000
#define    RCC_PLLSCR_HSI   0x00000000
#define    RCC_PLLSCR_HSE   0x00400000
#define	   RCC_CLK_OFF		0
#define	   RCC_CLK_ON		1
#define	   RCC_PERI_OFF		0
#define	   RCC_PERI_ON		1
/**********************/

/*AHB prescaler*/
#define    RCC_HPRE_2		0x00000080
#define    RCC_HPRE_4		0x00000090
#define    RCC_HPRE_8		0x000000A0
#define    RCC_HPRE_16		0x000000B0
#define    RCC_HPRE_64		0x000000C0
#define    RCC_HPRE_128		0x000000D0
#define    RCC_HPRE_256 	0x000000E0
#define    RCC_HPRE_512		0x000000F0
/******************************************/

/*APB Low speed prescaler*/
#define    RCC_PPRE1_2		0x00001000
#define    RCC_PPRE1_4		0x00001400
#define    RCC_PPRE1_8		0x00001800
#define    RCC_PPRE1_16		0x00001C00
/****************************************/
/*APB high speed prescaler*/
#define    RCC_PPRE2_2		0x00008000
#define    RCC_PPRE2_4		0x0000A000
#define    RCC_PPRE2_8		0x0000C000
#define    RCC_PPRE2_16		0x0000E000
/***********************************/


/*On and Off macros*/
#define RCC_ON 1
#define RCC_OFF 0
/*********************/

/*system clk source*/
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2
#define RCC_HSE_Crystal 3
#define RCC_HSE_RC 4

/********************/


/*System buses*/
#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3
/*****************/

/*Error status*/
/*Description: Every function returns error status, you may use it for validation*/
typedef enum
{
RCC_Error,
RCC_OK
}RCC_ErrorStatus;
/**********************/

/**********************/
/*Description:        */
/*Inputs:             */
/*Return types        */
/**********************/
RCC_ErrorStatus RCC_InitSysClk();


/**********************/
/*Description:        */
/*Inputs:             */
/*Return types        */
/**********************/
RCC_ErrorStatus RCC_SelectSysClk(u8 Copy_u8clkId);

/**********************/
/*Description:        */
/*Inputs:             */
/*Return types        */
/**********************/
RCC_ErrorStatus RCC_ControlClk(u8 Copy_u8clkId,u8 Copy_u8state);
/**********************/
/*Description:        */
/*Inputs:             */
/*Return types        */
/**********************/
RCC_ErrorStatus RCC_CfgPll();

/**********************/
/*Description:        */
/*Inputs:             */
/*Return types        */
/**********************/
RCC_ErrorStatus RCC_IsReady(u8 Copy_u8clkId,pu8 Status);

/**********************/

/*Description:This function used to enable the Buses clock  */
/*Inputs:
 * Copy_u8BusId
 *    options:RCC_AHB1,RCC_AHB2,RCC_APB1,RCC_APB2
 * Copy_u8PerId
 * 	  options: per name
 *
Return type:RCC_ErrorStatus (RCC_ERROR or RCC_OK)         */
/**********************/
RCC_ErrorStatus RCC_Enable_Per_Clk(u8 Copy_u8BusId,u8 Copy_u8PerId);


/**********************/

/*Description:This function used to disable the Buses clock  */
/*Inputs:
 * Copy_u8BusId
 *    options:RCC_AHB1,RCC_AHB2,RCC_APB1,RCC_APB2
 * Copy_u8PerId
 * 	  options: per name
 *
Return type:RCC_ErrorStatus (RCC_ERROR or RCC_OK)         */
/**********************/
RCC_ErrorStatus RCC_Disable_Per_Clk(u8 Copy_u8BusId,u8 Copy_u8PerId);



/**********************/
/*Description:This function used to set the Buses prescaler  */
/*Inputs:
 * Copy_u8BusId
 *    options:RCC_AHB1,RCC_AHB2,RCC_APB1,RCC_APB2
 * Copy_u8PrescalerId
 * 	  options:  RCC_AHB_DIVIDED_BY_X
 * 	  			RCC_APB1_DIVIDED_BY_X
 * 	  			RCC_APB2_DIVIDED_BY_X
 *
Return type:RCC_ErrorStatus (RCC_ERROR or RCC_OK)         */
/**********************/
RCC_ErrorStatus RCC_Cfg_Bus_Prescaler(u8 Copy_u8BusId,u8 Copy_u8PrescalerId);



#endif /* RCC_INTERFACE_H_ */
