#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
#include"game.c"
//��дһ�����������Ϸ����
//��д������Ϸ�ĺ���
void menu()
{
	printf("********************\n");
	printf("****1,������Ϸ *****\n");
	printf("****0,�˳���Ϸ *****\n");
	printf("********************\n");
}//��д��Ϸ�ĺ���
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	isboard(board, ROW, COL);
	displayboard(board,ROW,COL);
	//����Ϸ���в���
	while (1)
	{
		//��Ҳ���
		playmove(board, ROW, COL);
		//�ж���Ӯ
		ret = is_win(board, ROW, COL);
			if (ret != 'b')
			{
				break;
			}
		//��ӡ����
		displayboard(board, ROW, COL);
		//���Բ���
		computmove(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'b')
		{
			break;
		}
		//��ӡ����
		displayboard(board, ROW, COL);

	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	displayboard(board, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		printf("�����룺>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			    game();  //��Ϸ
				break;
		case 0:
				printf("�˳���Ϸ\n");
				break;
		default:
			printf("�����������������\n");
			    break;
		}
	} while (a);
	return 0;
}
