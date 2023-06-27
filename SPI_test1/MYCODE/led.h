#ifndef __LED_H
#define __LED_H 
#include "main.h" 


/*����Ϊ�������ţ�ֻ�����LED�˿ںź�����PIN*/
#define LED_GPIO_PORT		GPIOC			/* GPIO�˿� */
#define LED_Pin			GPIO_PIN_13			/* PIN */

#define LED_SET()  HAL_GPIO_WritePin(LED_GPIO_PORT,LED_Pin,GPIO_PIN_SET);		
#define LED_RESET()  HAL_GPIO_WritePin(LED_GPIO_PORT,LED_Pin,GPIO_PIN_RESET);	//����


/* LED��ת��ƽ */
void LED_Contrary();




#endif

