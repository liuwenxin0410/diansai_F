#include "timer.h"

//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_Init(unsigned int arr,unsigned int psc)
{  
 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//ʹ�ܶ�ʱ��1ʱ��
 
   //��ʼ��TIM1
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //������ʼ��
  TIM_ClearFlag(TIM1, TIM_FLAG_Update);//���жϱ�־λ
	TIM_ITConfig(TIM1, TIM_IT_Update|TIM_IT_Trigger,ENABLE ); //ʹ��ָ����TIM1�ж�,��������ж� �������ж�Դ 
	
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
 
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1	
 
}
 
//��ʱ��1�жϷ������
//void TIM1_UP_IRQHandler(void)   //TIM8�ж�
//{  	     
//	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)//���ָ����TIM�жϷ������:TIM �ж�Դ 
//	{
//		//Ӧ�ô����д��
//		
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);//���TIMx���жϴ�����λ:TIM �ж�Դ 
//	}	     
//}














