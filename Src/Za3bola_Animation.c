/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Za3bola_Animation.c
 *        Author: Mohamed Osama
 *		   Date:  Mar 26, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"../Za3bola_Animation.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const u8 Za3bola_Animation1_Frame1[8]={4, 14, 4, 14, 13, 4, 46, 17};
static const u8 Za3bola_Animation1_Frame2[8]={4, 14, 4, 14, 13, 36, 14, 9};
static const u8 Za3bola_Animation1_Frame3[8]={4, 14, 4, 14, 45, 4, 14, 9};

static const u8 Za3bola_Animation2_Frame1[8]={0, 4, 4, 4, 14, 4, 10, 0};
static const u8 Za3bola_Animation2_Frame2[8]={4, 0, 0, 4, 4, 14, 4, 10};

static const u8 Za3bola_Animation3_Frame1[8]={4, 14, 4, 14, 13, 4, 46, 17};
static const u8 Za3bola_Animation3_Frame2[8]={4, 14, 4, 14, 13, 68, 14, 9};
static const u8 Za3bola_Animation3_Frame3[8]={4, 14, 4, 14, 141, 4, 14, 9};
static const u8 Za3bola_Animation3_Frame4[8]={4, 14, 4, 78, 13, 4, 14, 9};
static const u8 Za3bola_Animation3_Frame5[8]={4, 14, 36, 14, 13, 4, 14, 9};
static const u8 Za3bola_Animation3_Frame6[8]={8, 28, 4, 14, 13, 4, 14, 9};

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
void Za3bola_Animations_Init(void)
{
	HLEDMAT_voidInit(&ledmat_obj);
}
void Za3bola_WelcomeMessage(void){
	HLEDMAT_voidDisplayScrollingString(&ledmat_obj,"ZA3BOLA",180);
}
void Za3bola_Animation1(void)
{
	u8 Local_AnimationCounter = ZERO_INIT;
	for(Local_AnimationCounter = ZERO_INIT;Local_AnimationCounter<=6;Local_AnimationCounter++)
	{
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation1_Frame1,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation1_Frame2,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation1_Frame3,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation1_Frame2,200);
	}
}
void Za3bola_Animation2(void){
	u8 Local_AnimationCounter = ZERO_INIT;
	for(Local_AnimationCounter = ZERO_INIT;Local_AnimationCounter<=6;Local_AnimationCounter++)
	{
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation2_Frame1,400);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation2_Frame2,400);
	}
}

void Za3bola_Animation3(void)
{
	u8 Local_AnimationCounter = ZERO_INIT;
	for(Local_AnimationCounter = ZERO_INIT;Local_AnimationCounter<3;Local_AnimationCounter++)
	{
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame1,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame2,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame3,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame4,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame5,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame6,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame5,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame4,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame3,200);
		HLEDMAT_voidDisplayFrameWithDelay(&ledmat_obj, Za3bola_Animation3_Frame2,200);
	}
}



/**********************************************************************************************************************
 *  END OF FILE: Za3bola_Animation.c
 *********************************************************************************************************************/
