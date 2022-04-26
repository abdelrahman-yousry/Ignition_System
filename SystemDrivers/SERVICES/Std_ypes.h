#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char 		u8;
typedef signed char 		s8;

typedef unsigned short int  u16;
typedef signed short int 	s16;

typedef unsigned long int   u32;
typedef signed long int     s32;

typedef float 				f32;

typedef double 				f64;

typedef long double 		f128, f96; //machine or compiler (platform) dependent

/************************************************************/
typedef unsigned char 		uint8_t;
typedef signed char 		sint8_t;

//typedef unsigned short int  uint16_t;
typedef signed short int    sint16_t;

typedef unsigned long int 	uint32_t;
typedef signed long int 	sint32_t;

typedef float 				float32_t;

typedef double 				float64_t;

typedef long double 		float128_t, float96_t; //machine or compiler (platform) dependent


typedef u8* 				pu8;
typedef s8*					ps8;
typedef f32*				pf32;

typedef u16* 				pu16;
typedef s16*				ps16;
typedef f64*				pf64;

typedef u32* 				pu32;
typedef s32*				ps32;
typedef f128*				pf128, pf96;  //machine or compiler (platform) dependent


typedef void(*pfunc)(void);


typedef enum
{
	OK,
	NOK,
	INVALID_ARG,
	NULL_PTR,
	PENDING,
	TIME_OUT,
	
}Std_enuErrorStatus;

#define NULL ((void*)0)

#endif
