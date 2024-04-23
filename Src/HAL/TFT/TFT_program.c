/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TFT_program.c
 *        Author: Mohamed Osama
 *		   Date:  Apr 23, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "HAL/TFT/TFT_interface.h"
#include "HAL/TFT/TFT_private.h"

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
static void TFT_GPIO_PinsInit(port_index_t port, pin_index_t pin)
{
	switch (port)
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
	GPIO_voidSetPinMode(port,pin,GPIO_OUTPUT_PIN_MODE);
}

static void TFT_ResetSequence(TFT_t* TFT_Config)
{
	GPIO_voidSetPinValue(TFT_Config->TFT_RESET_Port,TFT_Config->TFT_RESET_Pin, GPIO_HIGH);
	Delay_us(100);
	GPIO_voidSetPinValue(TFT_Config->TFT_RESET_Port,TFT_Config->TFT_RESET_Pin, GPIO_LOW);
	Delay_us(1);
	GPIO_voidSetPinValue(TFT_Config->TFT_RESET_Port,TFT_Config->TFT_RESET_Pin, GPIO_HIGH);
	Delay_us(100);
	GPIO_voidSetPinValue(TFT_Config->TFT_RESET_Port,TFT_Config->TFT_RESET_Pin, GPIO_LOW);
	Delay_us(100);
	GPIO_voidSetPinValue(TFT_Config->TFT_RESET_Port,TFT_Config->TFT_RESET_Pin, GPIO_HIGH);
	Delay_ms(120);
}
static void TFT_voidSendCommand(TFT_t* TFT_Config, u8 Command)
{
	GPIO_voidSetPinValue(TFT_Config->TFT_DC_Port,TFT_Config->TFT_DC_Pin, GPIO_LOW);
	MSPI_TransmitByte(&TFT_Config->TFT_SPI_Config, Command , 1000);
}
static void TFT_voidSendData(TFT_t* TFT_Config, u8 Data){
	GPIO_voidSetPinValue(TFT_Config->TFT_DC_Port,TFT_Config->TFT_DC_Pin, GPIO_HIGH);
	MSPI_TransmitByte(&TFT_Config->TFT_SPI_Config, Data , 1000);
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void TFT_voidInit(TFT_t* TFT_Config)
{
	TFT_GPIO_PinsInit(TFT_Config->TFT_RESET_Port, TFT_Config->TFT_RESET_Pin);
	TFT_GPIO_PinsInit(TFT_Config->TFT_DC_Port, TFT_Config->TFT_DC_Pin);
	MSPI_voidInit(&TFT_Config->TFT_SPI_Config);
	TFT_ResetSequence(TFT_Config);
	TFT_voidSendCommand(TFT_Config,SLPOUT_CMD);
	Delay_ms(150);
	TFT_voidSendCommand(TFT_Config,COLMOD_CMD);
	TFT_voidSendData(TFT_Config,RGB565_COLOR_MODE);
	TFT_voidSendCommand(TFT_Config,INVON_CMD);
	TFT_voidSendCommand(TFT_Config,DISPON_CMD);
}

void TFT_voidSetWindow(TFT_t* TFT_Config ,u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    // Send Set X Addresses Command
    TFT_voidSendCommand(TFT_Config,CASET_CMD);
    TFT_voidSendData(TFT_Config,0);
    TFT_voidSendData(TFT_Config , Copy_u8X0);
    TFT_voidSendData(TFT_Config , 0);
    TFT_voidSendData(TFT_Config,Copy_u8X1);
    // Send Set Y Addresses Command
    TFT_voidSendCommand(TFT_Config,RASET_CMD);
    TFT_voidSendData(TFT_Config,0);
    TFT_voidSendData(TFT_Config,Copy_u8Y0);
    TFT_voidSendData(TFT_Config,0);
    TFT_voidSendData(TFT_Config,Copy_u8Y1);
    TFT_voidSendCommand(TFT_Config,RAM_WR_CMD);
}

void TFT_voidDisplayImage(TFT_t* TFT_Config, const u16 * Copy_pu8Image)
{
    TFT_voidSetWindow(TFT_Config,0, 127, 0, 159);
    GPIO_voidSetPinValue(TFT_Config->TFT_DC_Port,TFT_Config->TFT_DC_Pin, GPIO_HIGH);
    MSPI_DMA_Transmit(&TFT_Config->TFT_SPI_Config, Copy_pu8Image, 40960);
}

/**********************************************************************************************************************
 *  END OF FILE: TFT_program.c
 *********************************************************************************************************************/
