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

/*
void Delay1ms(unsigned int xms)
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

*/
void main()
{
 	
	while(1)
	{
		P2=0xFE;
		Delay500ms();//Delay1ms(500)//能有同样效
		P2=0xFF;
		Delay500ms();
	}
}