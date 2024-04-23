/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TFT_interface.h
 *        Author: Mohamed Osama
 *		   Date:  Apr 23, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	SPI_Config_t TFT_SPI_Config;
	port_index_t TFT_RESET_Port;
	pin_index_t  TFT_RESET_Pin;
	port_index_t TFT_DC_Port;
	pin_index_t  TFT_DC_Pin;
}TFT_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void TFT_voidInit(TFT_t* TFT_Config);
void TFT_voidSetWindow(TFT_t* TFT_Config ,u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1);
void TFT_voidDisplayImage(TFT_t* TFT_Config, const u16 * Copy_pu8Image);
 
#endif /* HAL_TFT_TFT_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: TFT_interface.h
 *********************************************************************************************************************/

