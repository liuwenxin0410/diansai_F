#include "LoAl.h"
#include "sys.h"
/*λ���㷨*/
extern int circle_count;
extern int circle_count_1;
extern int num,num_1;
extern int Test_Distance;
extern int record;
extern int num_record;//Ŀ��ֵ
extern int F1,F2,F3,F4,F5,TotalF;
extern int YaoP;
extern u8 CheckYP;
extern u8 WXZFlag,BXZFlag;//������־λ
extern u8 WJCFlag,BJCFlag;//�Ƿ������ı�־λ

/************************************
  5					8

  7					6


		3			4


		1			2

************************************/


void Goto1(void)
{
		OLED_Clear();
		OLED_ShowString(0,0,"GET:1");
		YaoP = 0;
		CheckYP = '1';//�������ҩƷ
		while(YaoP == 0);//�ȴ���ҩƷ ��
		R();
		CheckYP = '0';//�رռ��ҩƷ
		delay_ms(1000);
		WXZFlag = '1';//��������
		WJCFlag = '1';//�������
		delay_ms(500);
		TotalF = 0;
		while(TotalF < 3)//�ȴ�ʶ��·��
		{Wforward(SetSpeed);}		
		WXZFlag = '0';//�ر�����
		Distance(ds,SetSpeed);//�ȴ��������ĵ���·��
		Brake();
		WTurnLeft90();//��ת
		WXZFlag = '1';//��������
		delay_ms(200);
		Distance(3400,SetSpeed);//������ر�������		
		Brake();		
		CheckYP = '1';//�������ҩƷ
		YaoP = 1;
		delay_ms(500);//���ҩƷ
		while( YaoP == 1);//�ȴ�ҩƷ�ƿ�
		CheckYP = '0';
		BEEP_ON();
		delay_ms(1000);
		BEEP_OFF();
		//��ͷ
		WTurnLeft90();//��ת
		delay_ms(450);
		WTurnLeft90();//��ת		
		WXZFlag = '1';//��������
		delay_ms(500);
		while(TotalF < 3)//�ȴ�ʶ��·��
		{Wforward(SetSpeed);}
		WXZFlag = '0';//�ر�����
		Distance(ds,SetSpeed);//�ȴ��������ĵ���·��
		delay_ms(200);
		WTurnRight90();//��ת
		WXZFlag = '1';//��������
		delay_ms(200);
		Distance(4800,300);//������ر�������		
		Brake();
		G();
}

void Goto2(void)
{
	OLED_Clear();
	OLED_ShowString(0,0,"GET:2");
	YaoP = 0;
	CheckYP = '1';//�������ҩƷ
	while(YaoP == 0);//�ȴ���ҩƷ
	R();
	CheckYP = '0';//�رռ��ҩƷ
	delay_ms(1000);
	WXZFlag = '1';//��������
	WJCFlag = '1';//�������
	delay_ms(500);
	TotalF = 0;
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';//�ر�����
	Distance(ds,SetSpeed);
	WTurnRight90();//��ת
	WXZFlag = '1';//��������
	Distance(3400,SetSpeed);//�����￪��������
	Brake();
	CheckYP = '1';//�������ҩƷ
	YaoP = 1;
	delay_ms(500);
	while( YaoP == 1);//�ȴ�ҩƷ�ƿ�
	CheckYP = '0';
	BEEP_ON();
	delay_ms(1000);
	BEEP_OFF();
	//��ͷ
	WTurnLeft90();//��ת
	delay_ms(450);
	WTurnLeft90();//��ת
	WXZFlag = '1';//��������
	delay_ms(500);
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';//�ر�����
	Distance(ds,SetSpeed);
	WTurnLeft90();//��ת
	WXZFlag = '1';//��������		
	Distance(4800,SetSpeed);//�����￪��������		
	Brake();
	G();
}

void BackFrom3(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnRight90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

void BackFrom4(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnLeft90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

void BackFrom5(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(F1 == 0 || F2 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnLeft90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(F4 == 0 || F5 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ddds,SetSpeed);
	WTurnRight90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ds,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

void BackFrom6(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(F1 == 0 || F2 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnLeft90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(F1 == 0 || F2 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ddds,SetSpeed);
	WTurnLeft90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ds,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

void BackFrom7(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(F4 == 0 || F5 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnRight90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(F4 == 0 || F5 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ddds,SetSpeed);
	WTurnRight90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ds,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

void BackFrom8(void)
{
	WXZFlag = '1';
	WJCFlag = '1';
	while(F4 == 0 || F5 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(dds,SetSpeed);
	WTurnRight90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(F1 == 0 || F2 == 0)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ddds,SetSpeed);
	WTurnLeft90();
	WXZFlag = '1';
	WJCFlag = '1';
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	WXZFlag = '0';
	WJCFlag = '0';
	Distance(ds,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	Wforward(SetSpeed);
	Distance(cs,SetSpeed);
	WXZFlag = '1';
	WJCFlag = '1';
	while(TotalF < 3)//�ȴ�ʶ��·��
	{
		Wforward(SetSpeed);
	}
	Distance(5400,SetSpeed);//�����￪��������
	Brake();
	WXZFlag = '0';
	WJCFlag = '0';
}

/*���ƹ��ܺ���*/
void WTurnLeft90(void)
{
	int cont;
	Brake();
	delay_ms(300);
	num=TIM4->CNT;
	cont = num - 880;
	if(cont < 0)
	{
		cont = cont + 1560;
	}
//	printf("%d",cont);
	WTurnLeft();
	delay_ms(20);
	while(num < cont - 5 || num >cont + 5)
	{
		num=TIM4->CNT;
	}
//	printf("%d",num);
	Brake();
	delay_ms(300);
}

void WTurnRight90(void)
{
	int cont;
	Brake();
	delay_ms(300);
	num_1=TIM3->CNT;
	cont = num_1 + 950;
	if(cont > 1560)
	{
		cont = cont - 1560;
	}
	WTurnRight();
	delay_ms(20);
	while(num_1 < cont - 5 || num_1 >cont + 5)
	{
		num_1=TIM3->CNT;
	}
	Brake();
	delay_ms(300);
}

void Distance(u16 Dis,u16 Speed)//��Speed = 450
{
	int ago_num,ago_num_1;
//	printf("--\r\n");
	Brake();
	delay_ms(300);
	WXZFlag = '1';
	record = 0;
	circle_count = 0;
	circle_count_1 = 0;
	ago_num=TIM4->CNT;
	ago_num_1=TIM3->CNT;
	num_record = Dis * 2;
	Wforward(Speed);
//	printf("%d	%d	%d\r\n",ago_num,ago_num_1,record);
	while(record < num_record)//�ȴ�ʶ������	
	{
		num=TIM4->CNT;
		num_1=TIM3->CNT;
		record = (circle_count + circle_count_1) * 1560 + num - ago_num + ago_num_1 - num_1;
//		printf("|%d|%d|%d|%d|%d|\r\n",num,num_1,circle_count,circle_count_1,record);
		Wforward(Speed);
	}
//	printf("%d\r\n",record);
	Brake();
	WXZFlag = '0';
	delay_ms(300);
}

//void ShowCircle(void)
//{
//		num=TIM4->CNT;
//		num_1=TIM3->CNT;
//		OLED_ShowString(0,0,"circle:",16);
//		OLED_ShowNum(56,0,circle_count,3,16);
//		OLED_ShowString(0,16,"num:",16);
//		OLED_ShowNum(32,16,num,4,16);
//		OLED_ShowString(0,32,"circle:",16);
//		OLED_ShowNum(56,32,circle_count_1,3,16);
//		OLED_ShowString(0,48,"num:",16);
//		OLED_ShowNum(32,48,num_1,4,16);
//		OLED_Refresh();
//		delay_ms(20);
//}

