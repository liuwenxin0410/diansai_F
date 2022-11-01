#include "sys.h"
#include "usart.h"	 
#include "led.h"
#include "control.h"	
#include "delay.h"

////////////////////////////////////////////////////////////////////////////////// 	 
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//重定义fputc函数 
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (unsigned char) ch);
	while (!(USART1->SR & USART_FLAG_TXE));
	return (ch);
}

int openmv[13];
int16_t OpenMV_Q;
int16_t OpenMV_W;
int16_t OpenMV_E;
int16_t OpenMV_R;
int16_t OpenMV_T;
int16_t OpenMV_Y;
int16_t OpenMV_U;
int16_t OpenMV_I;
int16_t isten;
(0, 99, -128, 18, -110, 124)
unsigned int centre=0,left1=0,left2=0,right1=0,right2=0,left3=0,right3=0;

void Openmv_Data(void)//处理Openmv接收的数据
{
    OpenMV_Q=openmv[2];
    OpenMV_W=openmv[3];
	  OpenMV_E=openmv[4];
    OpenMV_R=openmv[5];
	  OpenMV_T=openmv[6];//centre
    OpenMV_Y=openmv[7];//centre
	  OpenMV_U=openmv[8];//left
    OpenMV_I=openmv[9];//left
	  isten = openmv[10];
}
void openmv_control(void)
{
	 
	if(OpenMV_T&&OpenMV_Y) //中值 直行
	{		
		centre=1;
	}
	else
	{
		centre=0;
	}
	if(OpenMV_T&&OpenMV_R)//左微偏 微向右调
	{
		right1=1;
		if(OpenMV_E||OpenMV_W)//左偏 向右调
		{
			right2=1;
		}
	}
	if(OpenMV_W)  //偏离赛道 
	{
		right3=1;
	//	right1=0;
	}
	if(OpenMV_Y&&OpenMV_U)//右微偏 微调		
	{
		left1=1;
		if(OpenMV_U||OpenMV_I)
		{
			left2=1;
		}
	}
	if(OpenMV_I)	//偏离赛道 
	{
		left3=1;
		//left1=0;
	}
	if(OpenMV_E&&OpenMV_R&&OpenMV_T&&OpenMV_Y)//	十字路口
	{
		
	}
//	if(!(OpenMV_E&&OpenMV_T))
//	{
//	//	led3_off;
//		led4_on;
//		//delay_ms(500);
//		led3_off;
//	}
}

void deal()
{
if(centre==1&&right1==0&&left1==0)//正常直行
	{
	
	}
if(right1==1&&right2==1)					//向右微转
	{

	}
if(centre==0&&right2==1)					//向右转
	{

	}
if(right3==1)											//右转大弯
	{

	} 
if(left1==1&&left2==1)					//向左微转
	{

	}
if(centre==0&&left2==1)					  //向左转
	{

	}
if(left3==1)											//左转大弯
	{

	}
}
u8 i;
void Openmv_Receive_Data(int16_t data)//接收Openmv传过来的数据
{
	static u8 state = 0;
	if(state==0&&data==0xb3)//第一个帧头
	{
		
		state=1;
		openmv[0]=data;
		 
	}
	else if(state==1&&data==0xb3)//第二个帧头
	{
		state=2;
		openmv[1]=data;
	}
	else if(state==2)//第一个有效数据
	{
		state=3;
		openmv[2]=data;
	}
	else if(state==3)//第二个有效数据
	{
		state = 4;
		openmv[3]=data;
	}
  else if(state==4)//第三个有效数据
	{
		state = 5;
		openmv[4]=data;
	} 
	  else if(state==5)
	{
		state = 6;
		openmv[5]=data;
	} 
	  else if(state==6)
	{
		state = 7;
		openmv[6]=data;
	} 
	  else if(state==7)
	{
		state = 8;
		openmv[7]=data;
	} 
	  else if(state==8)
	{
		state = 9;
		openmv[8]=data;
	} 
	  else if(state==9)
	{
		state = 10;
		openmv[9]=data;
	} 
	  else if(state==10)
	{
		state = 11;
		openmv[10]=data;
	} 
	else if(state==11&&data==0x0b)		//检测是否接受到结束标志，检测接收帧尾
	{
		state=12;
		openmv[11]=data;
	}
	else if(state==12)
	{
        		if(data == 0x0a)
      		  {
	 	 led4_on;
           	 state = 0;
           	 openmv[11]=data;
         		  // Openmv_Data();
       		 }
       		 else if(data != 0x0a)
      		  {
            	state = 0;
           	 for(i=0;i<13;i++)
          	  {
              		  openmv[i]=0x00;
           	 }           
       	}    
	else
		{
			state = 0;
            for(i=0;i<13;i++)
            {
                openmv[i]=0x00;
            }
		}
}

void uart_init(u32 bound)
{
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}

void USART_Send_END(void)//发送结束符（串口屏）
{
  USART1_Send_Byte(0xFF);
	USART1_Send_Byte(0xFF);
	USART1_Send_Byte(0xFF);	
}

void USART1_Send_Byte(u8 ch)	   			//发送字节		   
{
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	USART_SendData(USART1, (u8)ch);
}
void USART1_Send_Len_Str(u8 *str, u8 len)//发送字符
{
	u8 i;
	for(i=0; i<len; i++)
	USART1_Send_Byte(*str ++);
}
/**************************************************************************
函数功能：串口1接收中断
入口参数：无
返回  值：无
**************************************************************************/
void USART1_IRQHandler(void)
{	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //接收到数据
	{	
		u8 temp; 	
		USART_ClearFlag(USART1, USART_IT_RXNE); //清除标志位；			
		temp=USART1->DR;
		led1_on;
		Openmv_Receive_Data(temp);
		Openmv_Data();	
	}  											 
} 


