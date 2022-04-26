#ifndef 	BIT_MATH_H_
#define 	BIT_MATH_H_
	
#define 	SIZE_8    8
#define 	SIZE_16   16
#define 	SIZE_32   32
	
#define 	REG_SIZE  SIZE_32
	
#if     	REG_SIZE == SIZE_8
	
#define 	SET_VAL    0XFF
#define 	CLR_VAL    0X00
	
#elif   	REG_SIZE == SIZE_16
	
#define 	SET_VAL    0XFFFF
#define 	CLR_VAL    0X0000
	
#elif   	REG_SIZE == SIZE_32
	
#define 	SET_VAL    0XFFFFFFFF
#define 	CLR_VAL    0X00000000
	
#endif	
	
#define 	SET_BIT(REG,BITNUM)          ((REG)|= 1<<(BITNUM))
#define 	CLR_BIT(REG,BITNUM)          ((REG)&= ~(1<<(BITNUM)))
#define 	TGL_BIT(REG,BITNUM)       	 ((REG) ^= 1<<(BITNUM))
#define 	GET_BIT(REG,BITNUM)          (((REG)>>(BITNUM))&1)
	
#define 	RSHIFT_REG(REG,NO)           ((REG)=(REG)>>(NO))
#define 	LSHIFT_REG(REG,NO)           ((REG)=(REG)<<(NO))
#define 	CRSHIFT_REG(REG,NO)          ((REG)=(((REG)>>(NO))|((REG)<<(REG_SIZE))))
#define 	CLSHIFT_REG(REG,NO)          ((REG)=(((REG)<<(NO))|((REG)>>(REG_SIZE))))
#define 	ASSIGN_REG(REG,VALUE)        ((REG)=VALUE)
#define 	SET_REG(REG)                 ((REG)=SET_VAL)
#define 	CLR_REG(REG)                 ((REG)=CLR_VAL)
#define 	TGL_REG(REG)                 ((REG)^=SET_VAL)
	
#define 	SET_H_NIB(REG)               ((REG)|=(SET_VAL<<REG_SIZE/2))                             //((REG)|=(0xf0))
#define 	SET_L_NIB(REG)               ((REG)|=(SET_VAL>>REG_SIZE/2))                             //((REG)|=(0x0f))
#define 	CLR_H_NIB(REG)               ((REG)&=(SET_VAL>>REG_SIZE/2))                             //((REG)&=(0x0f))
#define 	CLR_L_NIB(REG)               ((REG)&=(SET_VAL<<REG_SIZE/2))                             //((REG)&=(0xf0))
#define 	GET_H_NIB(REG)               ((REG)>>(REG_SIZE/2))                                      //((REG)&(0xf0))
#define 	GET_L_NIB(REG)               ((REG)&(SET_VAL>>REG_SIZE/2))                              //((REG)&(0x0f))
#define 	ASSIGN_L_NIB(REG,VALUE)      ((REG)|=(VALUE & (SET_VAL>>REG_SIZE/2)))                   //((REG)|=(VALUE & 0x0f))
#define 	ASSIGN_H_NIB(REG,VALUE)      ((REG)|=(VALUE <<REG_SIZE/2))                              //((REG)|=(VALUE & 0xf0))
#define 	TGL_H_NIB(REG)               ((REG)^=(SET_VAL<<REG_SIZE/2))                             //((REG)^=(0xf0))
#define 	TGL_L_NIB(REG)               ((REG)^=(SET_VAL>>REG_SIZE/2))                             //((REG)^=(0x0f))
#define 	SWAP_NIB(REG)                ((REG)=(((REG)>>(SIZE/2))|((REG)<<(SIZE/2))))              //(REG & 0xf0 >>4 )|(REG &0x0f <<4 )

#endif