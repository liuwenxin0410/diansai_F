#include "golo.h"

extern u8 res3;
extern u8 CheckYP;
extern u8 WXZFlag,BXZFlag;//������־λ
extern u8 WJCFlag,BJCFlag;//�Ƿ������ı�־λ
extern int F1,F2,F3,F4,F5,TotalF;
extern int YaoP;

int Destination;

int VisGO(void)
{
	OLED_Clear();
	OLED_ShowString(0,2,"Ready>>");
	BEEP_ON();
	YaoP = 0;
	CheckYP = '1';//�������ҩƷ
	while(YaoP == 0);//�ȴ���ҩƷ ��
	R();
	CheckYP = '0';//�رռ��ҩƷ
	BEEP_OFF();
	delay_ms(1000);
	WXZFlag = '1';//��������
	WJCFlag = '1';//�������
	delay_ms(500);
	TotalF = 0;
	while(TotalF < 3)//�ȴ�ʶ��·��
	{Wforward(SetSpeed);}		
	WXZFlag = '0';//�ر�����
	Distance(ds,SetSpeed);//�ȴ��������ĵ���·��
	/*ǰ��һ�ξ����ٿ�������ʶ�������*/
	
	Distance(TestDistance,SetSpeed);//�ȴ�����ʶ��Χ

	/*�˴����ڲ���TestDistance����*/
	res3 = 'N';//��մ���	
	delay_ms(1500);
	delay_ms(1500);
	delay_ms(1500);
	
	WXZFlag = '1';//��������	
	
	TotalF = 0;
	/*����ڶ���ʮ��·��*/
	while(TotalF < 3)//�ȴ�ʶ��·��
	{Wforward(SetSpeed);}	
	Distance(kCARDDistance,SetSpeed);//�ȴ��������ĵ���·��
	
	/*�ڶ���ʮ��·�ڵ��ж�*/
	if(res3 == 'L')
	{
		Destination = 3;
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
		BackFrom3();
		return Destination;
	}
	if(res3 == 'R')
	{
		Destination = 4;
		WTurnRight90();//��ת
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
		BackFrom4();
		return Destination;
	}	
	
	/*����Զ�˲���*/
	Distance(TestDistance,SetSpeed);//�ȴ�����ʶ��Χ

	/*�˴����ڲ���TestDistance����*/
	res3 = 'N';//��մ���	
	delay_ms(1500);
	delay_ms(1500);
	delay_ms(1500);
	
	WXZFlag = '1';//��������	
	
	TotalF = 0;
	/*���������ʮ��·��*/
	while(TotalF < 3)//�ȴ�ʶ��·��
	{Wforward(SetSpeed);}	
	Distance(kCARDDistance,SetSpeed);//�ȴ��������ĵ���·��
	
	
	/*������ʮ��·�ڵ��ж�*/
	if(res3 == 'L')
	{
		WTurnLeft90();//��ת
		WXZFlag = '1';//��������
		delay_ms(200);
			/*ǰ��һ�ξ����ٿ�������ʶ�������*/
	
		Distance(TestDistance,SetSpeed);//�ȴ�����ʶ��Χ

		/*�˴����ڲ���TestDistance����*/
		res3 = 'N';//��մ���	
		delay_ms(1500);
		delay_ms(1500);
		delay_ms(1500);

		WXZFlag = '1';//��������	
		
		TotalF = 0;
		/*������ߵ��ĸ�ʮ��·��*/
		while(TotalF < 3)//�ȴ�ʶ��·��
		{Wforward(SetSpeed);}	
		Distance(kCARDDistance,SetSpeed);//�ȴ��������ĵ���·��
		if(res3 == 'L')
		{
			Destination = 7;
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
			BackFrom7();
			return Destination;
		}
		if(res3 == 'R')
		{
			Destination = 5;
			WTurnRight90();//��ת
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
			BackFrom5();
			return Destination;
		}	
	}
	/*������ʮ��·�ڵ��ж�*/
	if(res3 == 'R')
	{
		WTurnRight90();//��ת
		WXZFlag = '1';//��������
		delay_ms(200);
			/*ǰ��һ�ξ����ٿ�������ʶ�������*/
	
		Distance(TestDistance,SetSpeed);//�ȴ�����ʶ��Χ

		/*�˴����ڲ���TestDistance����*/
		res3 = 'N';//��մ���	
		delay_ms(1500);
		delay_ms(1500);
		delay_ms(1500);

		WXZFlag = '1';//��������	
		
		TotalF = 0;
		/*������ߵ��ĸ�ʮ��·��*/
		while(TotalF < 3)//�ȴ�ʶ��·��
		{Wforward(SetSpeed);}	
		Distance(kCARDDistance,SetSpeed);//�ȴ��������ĵ���·��
		if(res3 == 'L')
		{
			Destination = 8;
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
			BackFrom8();
			return Destination;
		}
		if(res3 == 'R')
		{
			Destination = 6;
			WTurnRight90();//��ת
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
			BackFrom6();
			return Destination;
		}	
	}
	return 0;
}


