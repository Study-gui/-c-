#include"game.h"
//创建一个二维数组
void isboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//构建一个棋盘
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");

				if (j < col-1)
					printf("|");
			}
			printf("\n");
		}
	}
}
//玩家操作的函数
void playmove(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋\n");
	int i = 0, j = 0;
	printf("请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &i,&j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("被占用，请重新输入\n");

		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}
//电脑操作的函数
void computmove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int i = 0;
	int j = 0;

	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}

}
//判断棋盘是否满了
//满了返回：1
//没满返回：0
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//编写一个函数
//玩家获胜返回：*
// 电脑获胜返回：#
// 平局返回：a
// 继续返回：b
//判断输赢
char   is_win(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] !=  ' ')
			return board[i][1];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] ==board[1][j] && board[1][j] ==board[2][j] && board[1][j] !=  ' ')
			return board[1][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] !=' ')
		return board[1][1];
	if (board[0][2] ==board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (is_full(board, ROW, COL))
	{
		return 'a';
	}
	//游戏继续
	return 'b';
}
