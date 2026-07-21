#include <REGX52.H>

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
	unsigned char LedNum;//unsigned	char 生成的八位变量，与寄存器的位数相同，所以可以直接表示一个寄存器
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LedNum++;
			P2=~LedNum;
		}
	}
}