/*
//注释点03
#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

//注释点02

void main()
{
	while(1)
	{
		P2=0xFE;//1111 1110
		Delay500ms;
		P2=0xFD;//1111 1101
		Delay500ms;
		P2=0xFB;//1111 1110
		Delay500ms;
		P2=0xF7;//1111 1110
		Delay500ms;
		P2=0xEF;//1111 1110
		Delay500ms;
		P2=0xDF;//1111 1110
		Delay500ms;
		P2=0x7F;//1111 1110
		Delay500ms;
	}//缺点代码冗长，cpu死等（delay期间什么也干不了，按键、串口全废）
}
//注释点02
//注释点01
//A方案：移位循环法(delay依旧阻塞）
void main(){
	P2 = 0xFE;
	while(1){
		Delay500ms();
		P2 = _crol_(P2, 1);//左移，右移用_cror_
	}


}

//注释点13
*/
//注释点02
//B方案：定时器中断法
#include<REGX52.H>
#include<INTRINS.H>

#define LED P2//P2是串口号，需要看原理图

unsigned char timerCount = 0;

void Timer0_Init(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void main(){
	LED = 0xFE;
	Timer0_Init();
	while(1){
		//主循环空闲，可以放按键扫描、串口处理等
	}
}


void Timer_ISR() interrupt 1 {
	TH0 = 0x3C;
	TL0 = 0xB0;
	if(++timerCount >= 10){
		timerCount = 0;
		LED = _crol_(LED, 1);
	}	

}
//注释点11
//注释点12