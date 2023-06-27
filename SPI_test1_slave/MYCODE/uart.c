/* Includes ------------------------------------------------------------------*/
#include "uart.h"
#include "usart.h"

/* printf重映射 */
#include <stdio.h>
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    //具体哪个串口可以更改huart1为其它串口
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1 , 0xffff);
    return ch;
}



 /*	
		串口接收中断
		定长接收	
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		if(huart == &huart1)
		{
			HAL_UART_Transmit(&huart1,(uint8_t *)&Uart1_RxData,1,0xffff);//原样返回
			while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);//检测UART发送结
			HAL_UART_Receive_IT(&huart1,(uint8_t *)&Uart1_RxData, 1); //&取地址
		}
}


 /*	
		串口接收中断
		不定长接收	
*/
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  /* Prevent unused argument(s) compilation warning */
//  UNUSED(huart);
//	
//	if(huart == &huart1)
//	{
//		if(Uart1_Rx_Cnt >= 255)  //溢出判断
//		{
//			Uart1_Rx_Cnt = 0;
//			memset(Uart1_RxBuffer,0x00,sizeof(Uart1_RxBuffer));
//			HAL_UART_Transmit(&huart1, (uint8_t *)"数据溢出", 10,0xFFFF); 	
//		}
//		else
//		{
//			Uart1_RxBuffer[Uart1_Rx_Cnt++] = Uart1_RxData;   //接收数据转存
//		
//			if((Uart1_RxBuffer[Uart1_Rx_Cnt-1] == 0x0A)&&(Uart1_RxBuffer[Uart1_Rx_Cnt-2] == 0x0D)) //判断结束位\r\n。0x0D是\r，0x0A是\n
//			{
//				/*	此处添加用户代码	*/

//				HAL_UART_Transmit(&huart1, (uint8_t *)&Uart1_RxBuffer, Uart1_Rx_Cnt,0xFFFF); //将收到的信息发送出去
//				while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束

//				/*	此处添加用户代码	*/
//				Uart1_Rx_Cnt = 0;
//				memset(Uart1_RxBuffer,0x00,sizeof(Uart1_RxBuffer)); //清空数组
//			}
//		}
//		HAL_UART_Receive_IT(&huart1, (uint8_t *)&Uart1_RxData, 1);   //再开启接收中断
//	}
//}

