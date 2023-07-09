 #define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include"game.c"

void menu()
{
	printf("*******************\n");
	printf("**** 1,进入游戏****\n");
	printf("**** 0,退出游戏****\n");
	printf("*******************\n");
}
//构建游戏的函数
void game()
{
	//构建有雷的数组
	char mine[ROWS][COLS] = { 0 };
	//构建排雷数组
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	displayboard(mine, ROWS, COLS ,'0');
	displayboard(show, ROWS, COLS ,'*');
	//打印棋盘
	//is_board(mine, ROW, COL);
	is_board(show, ROW, COL);
	//布置有雷的棋盘
	set_mine(mine, ROW, COL);
	//is_board(mine, ROW, COL);
	//玩家进行操作的扫雷游戏
	playboard(mine, show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (a);
	return 0;
}