/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32l4xx.h"
#include "stm32l476g_discovery.h"

int main(void)
{
	//initialization
	HAL_Init();
	BSP_LED_Init(0);			 //led red
	BSP_LED_Init(1);			 //led green
	BSP_LCD_GLASS_Init();		 //lcd
	BSP_JOY_Init(JOY_MODE_GPIO); //joystick

	BSP_LCD_GLASS_DisplayString("Init...");
	for (int i = 1; i <= 3; i++)
	{
		BSP_LED_On(0);
		HAL_Delay(500);
		BSP_LED_Off(0);
		HAL_Delay(500);
	}
	BSP_LED_On(1);
	BSP_LCD_GLASS_ScrollSentence("Bonjour!", 3);
	//HAL_Delay(1000);

	BSP_LCD_GLASS_Clear();

	int mode = JOY_NONE;
	while (1)
	{
		switch (mode = BSP_JOY_GetState())
		{
			printf("%d\n", mode);
		case (JOY_NONE):
		{
			BSP_LCD_GLASS_Clear();
			break;
		}
		case (JOY_SEL):
		{
			BSP_LCD_GLASS_Clear();
			BSP_LCD_GLASS_DisplayString("PRESS");
			HAL_Delay(100);
			break;
		}
		case (JOY_DOWN):
		{
			BSP_LCD_GLASS_Clear();
			BSP_LCD_GLASS_DisplayString("DOWN");
			HAL_Delay(100);
			break;
		}
		case (JOY_LEFT):
		{
			BSP_LCD_GLASS_Clear();
			BSP_LCD_GLASS_DisplayString("LEFT");
			HAL_Delay(100);
			break;
		}
		case (JOY_RIGHT):
		{
			BSP_LCD_GLASS_Clear();
			BSP_LCD_GLASS_DisplayString("RIGHT");
			HAL_Delay(100);
			break;
		}
		case (JOY_UP):
		{
			BSP_LCD_GLASS_Clear();
			BSP_LCD_GLASS_DisplayString("UP");
			HAL_Delay(100);
			break;
		}
		default:
			break;
		}
	}

	return 0;
}
