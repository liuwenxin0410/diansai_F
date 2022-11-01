#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
void USART1_IRQHandler(void);
void USART1_Send_Byte(u8 ch);   			//�����ֽ�		  
void openmv_control(void);

extern int openmv[12];
extern int16_t OpenMV_Q;
extern int16_t OpenMV_W;
extern int16_t OpenMV_E;
extern int16_t OpenMV_R;
extern int16_t OpenMV_T;
extern int16_t OpenMV_Y;
extern int16_t OpenMV_U;
extern int16_t OpenMV_I;
extern int16_t isten;

void Openmv_Data(void);//����Openmv���յ�����
void Openmv_Receive_Data(int16_t data);//����Openmv������������
#endif


