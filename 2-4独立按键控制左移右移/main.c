#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while (xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		}	while (--i);
		xms--;
	}
}
void main()
{
	unsigned char LedNum = 1;
	//方案1
	P2 = ~LedNum;
	while(1)
	{
		//左移
		if(P3_1==0)
		{
		Delay(20);
		while(P3_1==0);
		Delay(20);

		LedNum<<=1;
		//方案1
		if(LedNum==0)LedNum = 1;
		//方案2
		//LedNum = _crol_(LedNum,1);
		P2 = ~LedNum;
		}
		//右移
		if(P3_0==0)
		{
		Delay(20);
		while(P3_0==0);
		Delay(20);

		LedNum>>=1;
		//方案1
		if(LedNum==0)LedNum = 0x80;
		//方案2
		//LedNum = _cror_(LedNum,1);
		P2 = ~LedNum;
		}
	}
}