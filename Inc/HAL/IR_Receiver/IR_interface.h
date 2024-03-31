/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IR_interface.h
 *        Author: Mohamed Osama
 *		   Date:  Mar 31, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef HAL_IR_RECEIVER_IR_INTERFACE_H_
#define HAL_IR_RECEIVER_IR_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCAL/GPIO/GPIO_interface.h"
#include"MCAL/SYSTICK/SYSTICK_interface.h"
#include"MCAL/EXTI/EXTI_interface.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define IR_CH_PERV_BUTTON 	    0xFFA25D
#define IR_CH_BUTTON 			0xFF629D
#define IR_CH_NEXT_BUTTON	    0xFFE21D
#define IR_PREV_BUTTON			0xFF22DD
#define IR_NEXT_BUTTON			0xFF02FD
#define IR_PLAY_PAUSE_BUTTON	0xFFC23D
#define IR_VOLUME_DOWN_BUTTON	0xFFE01F
#define IR_VOLUME_UP_BUTTON		0xFFA857
#define IR_EQ_BUTTON			0xFF906F
#define IR_0_BUTTON				0xFF6897
#define IR_100_PLUS_BUTTON		0xFF9867
#define IR_200_PLUS_BUTTON		0xFFB04F
#define IR_1_BUTTON				0xFF30CF
#define IR_2_BUTTON				0xFF18E7
#define IR_3_BUTTON				0xFF7A85
#define IR_4_BUTTON				0xFF10EF
#define IR_5_BUTTON				0xFF38C7
#define IR_6_BUTTON				0xFF5AA5
#define IR_7_BUTTON				0xFF42BD
#define IR_8_BUTTON				0xFF4AB5
#define IR_9_BUTTON				0xFF52AD

#define IR_RECEIVED_DATA_STATUS	 1
#define IR_NOT_RECEIVED_DATA_STATUS 0
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{
	u8 IR_Port;
	u8 IR_Pin;
	u8 IR_Trigger_Mode;

}IR_Config_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IR_voidInit (IR_Config_t *Copy_IR_Config , pCallBackNotification IR_CallbackNotification);

u8 IR_u8GetReceivedStatus(void);

u32  IR_u32GetReceivedData(void);
 
#endif /* HAL_IR_RECEIVER_IR_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IR_interface.h
 *********************************************************************************************************************/

