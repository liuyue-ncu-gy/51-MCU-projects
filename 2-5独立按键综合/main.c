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

void Key(unsigned int y)
{
	Delay(20);
	switch(y)
	{
		case 0:
			while(P3_0==0);
			break;
		case 1:
			while(P3_1==0);
			break;
		case 2:
			while(P3_2==0);
			break;
		case 3:
			while(P3_3==0);
			break;
	}
	Delay(20);
}

void main()
{
	unsigned char LedNum = 1;
	unsigned char Switch = 1;
	unsigned char i; 
	while(1)
	{
		//°´¼ü1£¬×óÒÆ
		if(P3_1==0)
		{
			Key(1);
			
			LedNum = _crol_(LedNum,1);
			P2 = ~LedNum;
		}
		//ÓÒÒÆ
		if(P3_0==0)
		{
			Key(0);
			
			LedNum++;
			P2 = ~LedNum;
		}
		//¹Ø±ÕºÍ¿ªÆô
		if(P3_2==0)
		{
			Key(2);

			Switch = !Switch;
			if(Switch)
			{
				P2 = ~LedNum;
			}
			else
				P2 = 0xff;

		}

		if(P3_3==0)
		{
			Key(3);

			Switch = !Switch;
			while(Switch)
			{
				LedNum = _cror_(LedNum,1);
				P2 = ~LedNum;
				for(i = 0;i < 50;i++)
				{
					Delay(10);
					if(P3_0==0)
						{
							Key(0);
							Switch = 0;
							break;	
						}
					if(P3_1==0)
						{
							Key(1);
							Switch = 0;
							break;	
						}
					if(P3_2==0)
						{
							Key(2);
							Switch = 0;
							break;	
						}
					if(P3_3==0)
						{
							Key(3);
							Switch = 0;
							break;	
						}
				}				
			}
			
		}
	}
}