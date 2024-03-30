/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LEDMAT_interface.h
 *        Author: Mohamed Osama
 *		   Date:  Mar 22, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INC_HAL_LEDMAT_LEDMAT_INTERFACE_H_
#define INC_HAL_LEDMAT_LEDMAT_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include"MCAL/SYSTICK/SYSTICK_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include<string.h>
#include"HAL/LEDMAT/LEDMAT_font.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LED_MATRIX_ROW_NUM	8
#define LED_MATRIX_COL_NUM	8

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	port_index_t port;
	pin_index_t  pin ;
	gpio_logic_t state;
}ledmat_column_t;

typedef struct
{
	port_index_t port;
	pin_index_t  pin ;
	gpio_logic_t state;
}ledmat_row_t;

typedef struct
{
	ledmat_row_t row[LED_MATRIX_ROW_NUM];
	ledmat_column_t col[LED_MATRIX_COL_NUM];
	u8	LedMatrix_Buffer[8];
}ledmat_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
void HLEDMAT_voidInit(ledmat_t* ledmat_obj);

void HLED_voidDisplayFrame(ledmat_t* ledmat_obj,u8* Copy_pu8FrameData);

void HLED_voidDisplayFrameWithDelay(ledmat_t* ledmat_obj,u8* Copy_pu8FrameData , u32 time_ms);

void HLED_voidDisplayChar(ledmat_t* ledmat_obj,u8 Copy_u8Chr);

void HLED_voidDisplayString(ledmat_t* ledmat_obj,u8* Copy_pu8Str,u32 time_ms);

void HLED_voidDisplayScrollingString(ledmat_t* ledmat_obj,u8* Copy_pu8Str,u32 time_ms);

void HLED_voidScrollFrameRight(ledmat_t* ledmat_obj,u32 time_ms);

void HLED_voidScrollFrameLeft(ledmat_t* ledmat_obj,u32 time_ms);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* INC_HAL_LEDMAT_LEDMAT_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: LEDMAT_interface.h
 *********************************************************************************************************************/
