#include "l298n.h"

/***********************************
				TIM2 CH1	CH2						TIM2	CH3		CH4
***********************************/

void TIM2_PWM_Init(u16 arr,u16 psc)
{
	//**�ṹ������**//
	GPIO_InitTypeDef GPIO_InitStructure;            //����GPIO
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure; //������ʱ��
	TIM_OCInitTypeDef  TIM_OCInitStructure;         //����PWMͨ��
	
	//**ʱ��ʹ��**//
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//ʹ�ܶ�ʱ��TIM2ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
	
	//****//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //TIM2_CH1 --> PA0 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.0
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	//****//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //TIM2_CH2 --> PA1 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.1
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
		//****//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //TIM2_CH3 --> PA2 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.2
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	//****//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				 //TIM2_CH4 --> PA3 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.3
	GPIO_SetBits(GPIOA,GPIO_Pin_3);
	
  //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	//��ʼ��TIM2 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC1
	
	//��ʼ��TIM2 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC2
	
		//��ʼ��TIM2 Channel3 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC3
	
	//��ʼ��TIM2 Channel4 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC4

	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH1Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH2Ԥװ�ؼĴ���
  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH3Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2_CH4Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2	
}


void Wforward(u16 speed)
{
	TIM_SetCompare1(TIM2,XiuZhengValue * speed );
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare4(TIM2,speed );
	TIM_SetCompare3(TIM2,0);
}

void Wback(u16 speed)
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,speed);
	TIM_SetCompare4(TIM2,0);
	TIM_SetCompare3(TIM2,speed);	
}

void LWcorect()//ǰ����zuo����
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,SetSpeed);
	TIM_SetCompare4(TIM2,SetSpeed + 160);
	TIM_SetCompare3(TIM2,0);
	delay_ms(3);
}

void RWcorect ()//ǰ����you����
{
	TIM_SetCompare1(TIM2,SetSpeed + 160);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare4(TIM2,0 );
	TIM_SetCompare3(TIM2,SetSpeed);
	delay_ms(3);
}

void BLWcorect()//ǰ����zuo����
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,SetSpeed);
	TIM_SetCompare4(TIM2,SetSpeed + 250);
	TIM_SetCompare3(TIM2,0);
	delay_ms(5);
}

void BRWcorect ()//ǰ����you����
{
	TIM_SetCompare1(TIM2,SetSpeed + 250);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare4(TIM2,0 );
	TIM_SetCompare3(TIM2,SetSpeed);
	delay_ms(5);
}


void Brake()
{
	TIM_SetCompare1(TIM2,999);
	TIM_SetCompare2(TIM2,999);
	TIM_SetCompare3(TIM2,999);
	TIM_SetCompare4(TIM2,999);
}

void WTurnLeft()//ǰ��ʱ��ת
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,XiuZhengValue * 450);
	TIM_SetCompare4(TIM2,450);
	TIM_SetCompare3(TIM2,0);
}

void WTurnRight()//ǰ��ʱ��ת
{
	TIM_SetCompare1(TIM2,XiuZhengValue * 450);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare4(TIM2,0);
	TIM_SetCompare3(TIM2,450);
}

