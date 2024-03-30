/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  BUTTON_program.c
 *        Author: Mohamed Osama
 *		   Date:  Mar 30, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_private.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void HButton_init(const button_t *btn)
{
	switch (btn->button_port)
	{
	    case GPIO_PORTA:
	      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOAEN);
	      break;
	    case GPIO_PORTB:
	      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOBEN);
	      break;
	    case GPIO_PORTC:
	      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOCEN);
	      break;
	    default:
	      break;
	  }
	  GPIO_voidSetPinMode(btn->button_port,btn->button_pin,GPIO_INPUT_PIN_MODE);
	  if(btn->button_connection == BUTTON_ACTIVE_HIGH)
	  {
		  GPIO_voidSetPinPullUpDownResistor(btn->button_port,btn->button_pin,GPIO_INPUT_PIN_PULL_DOWN);
	  }
	  else if (btn->button_connection == BUTTON_ACTIVE_LOW)
	  {
		  GPIO_voidSetPinPullUpDownResistor(btn->button_port,btn->button_pin,GPIO_INPUT_PIN_PULL_UP);
	  }
}
button_state_t HButton_ReadState(const button_t *btn)
{
	button_state_t Local_BtnState = ZERO_INIT;
	Local_BtnState = GPIO_u8GetPinValue(btn->button_port,btn->button_pin);
	if(Local_BtnState == GPIO_HIGH)
	{
		if(btn->button_connection == BUTTON_ACTIVE_HIGH)
		{
				  Local_BtnState = BUTTON_PRESSED;
		}
		else if (btn->button_connection == BUTTON_ACTIVE_LOW)
		{
				  Local_BtnState = BUTTON_RELEASED;
		}
	}
	else if(Local_BtnState == GPIO_LOW)
	{
		if(btn->button_connection == BUTTON_ACTIVE_HIGH)
		{
			Local_BtnState = BUTTON_RELEASED;
		}
		else if (btn->button_connection == BUTTON_ACTIVE_LOW)
		{
			Local_BtnState = BUTTON_PRESSED;
		}
	}
	return Local_BtnState;
}


/**********************************************************************************************************************
 *  END OF FILE: BUTTON_program.c
 *********************************************************************************************************************/
