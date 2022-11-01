#ifndef __L298N_H
#define __L298N_H 			   
#include "sys.h"  

#define XiuZhengValue 0.975

void TIM2_PWM_Init(u16 arr,u16 psc);
void Wforward(u16 speed);
void Wback(u16 speed);
void RWcorect(void);//ǰ��������
void LWcorect(void);//ǰ����������
void BRWcorect(void);//ǰ��������
void BLWcorect(void);//ǰ����������
void Brake(void);//ͣ��
void WTurnLeft(void);//ǰ��ʱ����ת
void WTurnRight(void);//ǰ��ʱ����ת

#endif
