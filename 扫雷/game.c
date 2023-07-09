#include"game.h"
//�������׺��Ų�����麯��
void displayboard(char board[ROWS][COLS], int rows, int cols,char ret)
{
	int i = 0, j = 0;
	for(i=0;i<rows;i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}
//��ӡ����
void is_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("********ɨ����Ϸ*********\n");
	for (i = 0; i <=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("********ɨ����Ϸ*********\n");

}
//�������׵�����
void set_mine(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int ret = easy_saolei;
	while (ret)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			ret--;
		}
	}
}
//������Χ�׵ĸ���
int see_show(char show[ROWS][COLS], int x, int y)
{
	int ret = 0;
	int i = 0, j = 0;
	for (i = x-1; i <= x+1; i++)
	{
		for (j = y-1; j <=y+1; j++)
		{
			if (show[i][j] == '1')
			{
				ret++;
			}
		}
	}
	return ret;
}
//��ҽ��в����ĺ���
void playboard(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int win = 0;//�Ų����
	while (win<row*col-easy_saolei)
	{
		printf("������:>");
		scanf_s("%d%d", &i, &j);
		if (show[i][j] != '*')
		{
			printf("�����Ź��������ظ�\n");
		}
		else
		{
			if (i >= 1 && i <= row && j >= 1 && j <= row)
			{
				if (mine[i][j] != '0')
				{
					printf("������˼������ŵ�����\n");
					is_board(mine, ROW, COL);
					break;
				}
				else
				{
					int ret = see_show(show, i, j);
					show[i][j] = ret + '0';
					is_board(show, ROW, COL);
				}
			}
			else
				printf("�������,����������\n");
		}
	}
	if (win==row*col-easy_saolei)
	{
		printf("���׳ɹ�\n");
		is_board(mine, ROW, COL);
	}
}
