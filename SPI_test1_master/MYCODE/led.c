#include "led.h"

/* LED��ת��ƽ */
void LED_Contrary()
{
	HAL_GPIO_WritePin(LED_GPIO_PORT,LED_Pin,1-HAL_GPIO_ReadPin(LED_GPIO_PORT,LED_Pin));
}

