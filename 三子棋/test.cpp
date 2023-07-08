#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
#include"game.c"
//编写一个三子棋的游戏程序
//编写进入游戏的函数
void menu()
{
	printf("********************\n");
	printf("****1,进入游戏 *****\n");
	printf("****0,退出游戏 *****\n");
	printf("********************\n");
}//编写游戏的函数
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	isboard(board, ROW, COL);
	displayboard(board,ROW,COL);
	//对游戏进行操作
	while (1)
	{
		//玩家操作
		playmove(board, ROW, COL);
		//判断输赢
		ret = is_win(board, ROW, COL);
			if (ret != 'b')
			{
				break;
			}
		//打印棋盘
		displayboard(board, ROW, COL);
		//电脑操作
		computmove(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'b')
		{
			break;
		}
		//打印棋盘
		displayboard(board, ROW, COL);

	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
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
		printf("请输入：>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			    game();  //游戏
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
			printf("输入错误，请重新输入\n");
			    break;
		}
	} while (a);
	return 0;
}
