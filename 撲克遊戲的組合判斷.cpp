#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int number_box;	//交換數字
	char color_box;	//交換花色
	int number[5] = {51,10,28,13,1};	//亂數
	char card_color[5];	//花色
	int card_number[5];	//數字

	srand(time(NULL));	//時間亂數

	//產生亂數
	for (int i = 0; i < 5; i++)
	{
		number[i] = (rand() % 52) + 1;

		//避免重複
		while (number[0] == number[1] || number[2] == number[0] || number[0] == number[3] || number[0] == number[4]|| number[1] == number[2]|| number[1] == number[3]|| number[1] == number[4]|| number[2] == number[3]|| number[2] == number[4]|| number[3] == number[4])
		{
			number[i] = (rand() % 52) + 1;
		}
	}

	//判斷花色
	for (int i = 0; i < 5; i++)
	{
		//黑桃
		if (number[i] / 13 == 0)	
		{
			card_color[i] = 'S';
		}
		
		//紅桃
		else if (number[i] / 13 == 1)	
		{
			card_color[i] = 'H';
		}

		//方塊
		else if (number[i] / 13 == 2)	
		{
			card_color[i] = 'D';
		}

		//梅花
		else    
		{
			card_color[i] = 'C';
		}
	}

	//判斷數字
	for (int i = 0; i < 5; i++)
	{
			card_number[i] = (number[i] % 13) + 1;
	}

	//比大小	 小 --> 大
	for (int n = 4; n >= 1; n--)
	{
		for (int t = 1; t <= n; t++)
		{
			if (card_number[t - 1] < card_number[t])
			{
				//交換數字
				number_box = card_number[t - 1];
				card_number[t - 1] = card_number[t];
				card_number[t] = number_box;

				//交換花色
				color_box = card_color[t - 1];
				card_color[t - 1] = card_color[t];
				card_color[t] = color_box;
			}
		}
	}

	//輸出5張牌
	for (int i = 0; i < 5; i++)
	{
		printf("%c%d ", card_color[i], card_number[i]);
	}

	printf("\n此牌型為: ");

	//同花順
	if (card_color[0] == card_color[1] && card_color[1] == card_color[2] && card_color[2] == card_color[3] && card_color[3] == card_color[4])
	{
		if (card_number[0] == (card_number[4] + 4))
			printf("同花順");
	}

	//四條
	else if (card_number[0] == card_number[3] || card_number[1] == card_number[4])
	{
		printf("四條");
	}

	//葫蘆
	else if (card_number[0] == card_number[2] && card_number[3] == card_number[4] || card_number[0] == card_number[1] && card_number[2] == card_number[4])
	{
		printf("葫蘆");
	}

	//順子
	else if (card_number[0] == (card_number[4] + 4))
	{
		printf("順子");
	}
	
	//三條
	else if (card_number[0] == card_number[2] || card_number[1] == card_number[3] || card_number[2] == card_number[4])
	{
		printf("三條");
	}
	
	//兩對
	else if (card_number[0] == card_number[1] && card_number[2] == card_number[3] || card_number[0] == card_number[1] && card_number[3] == card_number[4] || card_number[1] == card_number[2] && card_number[3] == card_number[4])
	{
		printf("兩對");
	}
	
	//一對
	else if (card_number[0] == card_number[1] || card_number[1] == card_number[2] || card_number[2] == card_number[3] || card_number[3] == card_number[4])
	{
		printf("一對");
	}
	
	//雜牌
	else
	{
		printf("雜牌");
	}

	return 0;
}
