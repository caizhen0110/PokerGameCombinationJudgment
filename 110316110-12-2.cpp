#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int number_box;	//�洫�Ʀr
	char color_box;	//�洫���
	int number[5] = {51,10,28,13,1};	//�ü�
	char card_color[5];	//���
	int card_number[5];	//�Ʀr

	srand(time(NULL));	//�ɶ��ü�

	//���Ͷü�
	for (int i = 0; i < 5; i++)
	{
		number[i] = (rand() % 52) + 1;

		//�קK����
		while (number[0] == number[1] || number[2] == number[0] || number[0] == number[3] || number[0] == number[4]|| number[1] == number[2]|| number[1] == number[3]|| number[1] == number[4]|| number[2] == number[3]|| number[2] == number[4]|| number[3] == number[4])
		{
			number[i] = (rand() % 52) + 1;
		}
	}

	//�P�_���
	for (int i = 0; i < 5; i++)
	{
		//�®�
		if (number[i] / 13 == 0)	
		{
			card_color[i] = 'S';
		}
		
		//����
		else if (number[i] / 13 == 1)	
		{
			card_color[i] = 'H';
		}

		//���
		else if (number[i] / 13 == 2)	
		{
			card_color[i] = 'D';
		}

		//����
		else    
		{
			card_color[i] = 'C';
		}
	}

	//�P�_�Ʀr
	for (int i = 0; i < 5; i++)
	{
			card_number[i] = (number[i] % 13) + 1;
	}

	//��j�p	 �p --> �j
	for (int n = 4; n >= 1; n--)
	{
		for (int t = 1; t <= n; t++)
		{
			if (card_number[t - 1] < card_number[t])
			{
				//�洫�Ʀr
				number_box = card_number[t - 1];
				card_number[t - 1] = card_number[t];
				card_number[t] = number_box;

				//�洫���
				color_box = card_color[t - 1];
				card_color[t - 1] = card_color[t];
				card_color[t] = color_box;
			}
		}
	}

	//��X5�i�P
	for (int i = 0; i < 5; i++)
	{
		printf("%c%d ", card_color[i], card_number[i]);
	}

	printf("\n���P����: ");

	//�P�ᶶ
	if (card_color[0] == card_color[1] && card_color[1] == card_color[2] && card_color[2] == card_color[3] && card_color[3] == card_color[4])
	{
		if (card_number[0] == (card_number[4] + 4))
			printf("�P�ᶶ");
	}

	//�|��
	else if (card_number[0] == card_number[3] || card_number[1] == card_number[4])
	{
		printf("�|��");
	}

	//��Ī
	else if (card_number[0] == card_number[2] && card_number[3] == card_number[4] || card_number[0] == card_number[1] && card_number[2] == card_number[4])
	{
		printf("��Ī");
	}

	//���l
	else if (card_number[0] == (card_number[4] + 4))
	{
		printf("���l");
	}
	
	//�T��
	else if (card_number[0] == card_number[2] || card_number[1] == card_number[3] || card_number[2] == card_number[4])
	{
		printf("�T��");
	}
	
	//���
	else if (card_number[0] == card_number[1] && card_number[2] == card_number[3] || card_number[0] == card_number[1] && card_number[3] == card_number[4] || card_number[1] == card_number[2] && card_number[3] == card_number[4])
	{
		printf("���");
	}
	
	//�@��
	else if (card_number[0] == card_number[1] || card_number[1] == card_number[2] || card_number[2] == card_number[3] || card_number[3] == card_number[4])
	{
		printf("�@��");
	}
	
	//���P
	else
	{
		printf("���P");
	}

	return 0;
}