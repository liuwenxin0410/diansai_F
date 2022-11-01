#include "zjjm.h"
int circle_count=0;//Ȧ��
int circle_count_1=0;//Ȧ��

void TIM4_Mode_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef TIM_ICInitStructure;   
		NVIC_InitTypeDef NVIC_InitStructure;	

    //PB6 ch1  A,PB7 ch2 
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ��TIM4ʱ��  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��GPIOBʱ��

    GPIO_StructInit(&GPIO_InitStructure);//��GPIO_InitStruct�еĲ�����ȱʡֵ����
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;         
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//PB6 PB7��������  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);                           

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = 1559;  //�趨��������װֵ   TIMx_ARR = 1024*4-1 ����360�ߵ�(����������13*4*30-1=1559)
    TIM_TimeBaseStructure.TIM_Prescaler = 0; //TIM4ʱ��Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;//����ʱ�ӷָ� T_dts = T_ck_int    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ��� 
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);              

    TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//ʹ�ñ�����ģʽ3�������½�������
    TIM_ICStructInit(&TIM_ICInitStructure);//���ṹ���е�����ȱʡ����
    TIM_ICInitStructure.TIM_ICFilter = 0;  //ѡ������Ƚ��˲��� 
    TIM_ICInit(TIM4, &TIM_ICInitStructure);//��TIM_ICInitStructure�е�ָ��������ʼ��TIM3


		//����ж�����
    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //����TIM4����ж�
 
    NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; 
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
 
 
  TIM_SetCounter(TIM4,0); //TIM4->CNT=0
  TIM_Cmd(TIM4, ENABLE); 
}

//������õĻ���Ҫ��װ��ֵ������תһȦ�Ƶ���һ������Ϊ����Ǽ����ж�һ�Ρ�

void TIM4_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET)
    {       
        if((TIM4->CR1>>4 & 0x01)==0) //DIR==0
            circle_count++;
        else if((TIM4->CR1>>4 & 0x01)==1)//DIR==1
            circle_count--;
    }
    TIM_ClearITPendingBit(TIM4,TIM_IT_Update); 
}

void TIM3_Mode_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef TIM_ICInitStructure;   
		NVIC_InitTypeDef NVIC_InitStructure;	

		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	//�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //��������
		GPIO_Init(GPIOA, &GPIO_InitStructure);				//�����趨������ʼ��GPIOA                     

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = 1559;  //�趨��������װֵ   TIMx_ARR = 1024*4-1 ����360�ߵ�(����������13*4*30-1=1559)
    TIM_TimeBaseStructure.TIM_Prescaler = 0; //TIM4ʱ��Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;//����ʱ�ӷָ� T_dts = T_ck_int    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ��� 
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);              

    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//ʹ�ñ�����ģʽ3�������½�������
    TIM_ICStructInit(&TIM_ICInitStructure);//���ṹ���е�����ȱʡ����
    TIM_ICInitStructure.TIM_ICFilter = 0;  //ѡ������Ƚ��˲��� 
    TIM_ICInit(TIM3, &TIM_ICInitStructure);//��TIM_ICInitStructure�е�ָ��������ʼ��TIM3


		//����ж�����
    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����TIM4����ж�
 
    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; 
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
 
 
  TIM_SetCounter(TIM3,0); //TIM4->CNT=0
  TIM_Cmd(TIM3, ENABLE); 
}

//������õĻ���Ҫ��װ��ֵ������תһȦ�Ƶ���һ������Ϊ����Ǽ����ж�һ�Ρ�

void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
    {       
        if((TIM3->CR1>>4 & 0x01)==0) //DIR==0
            circle_count_1--;
        else if((TIM3->CR1>>4 & 0x01)==1)//DIR==1
            circle_count_1++;
    }
    TIM_ClearITPendingBit(TIM3,TIM_IT_Update); 
}
