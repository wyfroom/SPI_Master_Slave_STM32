#ifndef __LED_H
#define __LED_H 
#include "main.h" 


/*更改为其他引脚，只需更改LED端口号和引脚PIN*/
#define LED_GPIO_PORT		GPIOC			/* GPIO端口 */
#define LED_Pin			GPIO_PIN_13			/* PIN */

#define LED_SET()  HAL_GPIO_WritePin(LED_GPIO_PORT,LED_Pin,GPIO_PIN_SET);		
#define LED_RESET()  HAL_GPIO_WritePin(LED_GPIO_PORT,LED_Pin,GPIO_PIN_RESET);	//点亮


/* LED翻转电平 */
void LED_Contrary();




#endif

