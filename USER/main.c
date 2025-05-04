
#include "include.h"



int main(void)
{
	SystemInit(); 			 //系统时钟初始化为72M	  SYSCLK_FREQ_72MHz
	InitDelay(72);	     //延时初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	InitPWM();
	InitTimer2();//用于产生100us的定时中断
	InitUart1();//用于与PC端进行通信
	InitUart3();//外接模块的串口
	InitADC();//用于检测电压
	InitLED();
	InitKey();
	InitBuzzer();
	InitPS2();//PS2游戏手柄接收器初始化
	InitFlash();
	InitMemory();
	InitBusServoCtrl();
	LED = LED_ON;
	while(1)
	{
		TaskRun();
	}
}

