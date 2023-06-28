/* Includes ------------------------------------------------------------------*/
#include "uart.h"
#include "usart.h"

/* printf��ӳ�� */
#include <stdio.h>
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    //�����ĸ����ڿ��Ը���huart1Ϊ��������
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1 , 0xffff);
    return ch;
}



 /*	
		���ڽ����ж�
		��������	
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		if(huart == &huart1)
		{
			HAL_UART_Transmit(&huart1,(uint8_t *)&Uart1_RxData,1,0xffff);//ԭ������
			while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ�
			HAL_UART_Receive_IT(&huart1,(uint8_t *)&Uart1_RxData, 1); //&ȡ��ַ
		}
}


 /*	
		���ڽ����ж�
		����������	
*/
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  /* Prevent unused argument(s) compilation warning */
//  UNUSED(huart);
//	
//	if(huart == &huart1)
//	{
//		if(Uart1_Rx_Cnt >= 255)  //����ж�
//		{
//			Uart1_Rx_Cnt = 0;
//			memset(Uart1_RxBuffer,0x00,sizeof(Uart1_RxBuffer));
//			HAL_UART_Transmit(&huart1, (uint8_t *)"�������", 10,0xFFFF); 	
//		}
//		else
//		{
//			Uart1_RxBuffer[Uart1_Rx_Cnt++] = Uart1_RxData;   //��������ת��
//		
//			if((Uart1_RxBuffer[Uart1_Rx_Cnt-1] == 0x0A)&&(Uart1_RxBuffer[Uart1_Rx_Cnt-2] == 0x0D)) //�жϽ���λ\r\n��0x0D��\r��0x0A��\n
//			{
//				/*	�˴�����û�����	*/

//				HAL_UART_Transmit(&huart1, (uint8_t *)&Uart1_RxBuffer, Uart1_Rx_Cnt,0xFFFF); //���յ�����Ϣ���ͳ�ȥ
//				while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���

//				/*	�˴�����û�����	*/
//				Uart1_Rx_Cnt = 0;
//				memset(Uart1_RxBuffer,0x00,sizeof(Uart1_RxBuffer)); //�������
//			}
//		}
//		HAL_UART_Receive_IT(&huart1, (uint8_t *)&Uart1_RxData, 1);   //�ٿ��������ж�
//	}
//}

