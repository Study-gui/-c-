 #define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include"game.c"

void menu()
{
	printf("*******************\n");
	printf("**** 1,������Ϸ****\n");
	printf("**** 0,�˳���Ϸ****\n");
	printf("*******************\n");
}
//������Ϸ�ĺ���
void game()
{
	//�������׵�����
	char mine[ROWS][COLS] = { 0 };
	//������������
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	displayboard(mine, ROWS, COLS ,'0');
	displayboard(show, ROWS, COLS ,'*');
	//��ӡ����
	//is_board(mine, ROW, COL);
	is_board(show, ROW, COL);
	//�������׵�����
	set_mine(mine, ROW, COL);
	//is_board(mine, ROW, COL);
	//��ҽ��в�����ɨ����Ϸ
	playboard(mine, show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (a);
	return 0;
}