#include"game.h"
//构建有雷和排查的数组函数
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
//打印棋盘
void is_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("********扫雷游戏*********\n");
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
	printf("********扫雷游戏*********\n");

}
//布置有雷的棋盘
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
//返回周围雷的个数
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
//玩家进行操作的函数
void playboard(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int win = 0;//排查次数
	while (win<row*col-easy_saolei)
	{
		printf("请输入:>");
		scanf_s("%d%d", &i, &j);
		if (show[i][j] != '*')
		{
			printf("坐标排过，不能重复\n");
		}
		else
		{
			if (i >= 1 && i <= row && j >= 1 && j <= row)
			{
				if (mine[i][j] != '0')
				{
					printf("不好意思，你拆着地雷了\n");
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
				printf("输入错误,请重新输入\n");
		}
	}
	if (win==row*col-easy_saolei)
	{
		printf("排雷成功\n");
		is_board(mine, ROW, COL);
	}
}
