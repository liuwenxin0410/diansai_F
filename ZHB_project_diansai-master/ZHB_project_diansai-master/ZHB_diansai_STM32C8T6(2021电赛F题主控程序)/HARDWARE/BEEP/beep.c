#include "beep.h"
//////////////////////////////////////////////////////////////////////////////////	 
//��������������							  
////////////////////////////////////////////////////////////////////////////////// 	   

//��������ʼ��
void BEEP_Init(void)
{
	 
 GPIO_InitTypeDef  GPIO_InitStructure; 

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��GPIOA�˿�ʱ��
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //BEEP-->PB8�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOA8
	
 //GPIO_SetBits(GPIOA,GPIO_Pin_8);//���1���رշ��������
}

void BEEP_OFF(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}

void BEEP_ON(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
}
