#include"game.h"
//����һ����ά����
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

//����һ������
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
//��Ҳ����ĺ���
void playmove(char board[ROW][COL], int row, int col)
{
	printf("�������\n");
	int i = 0, j = 0;
	printf("����������:>");
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
				printf("��ռ�ã�����������\n");

		}
		else
		{
			printf("�����������������\n");
		}
	}
}
//���Բ����ĺ���
void computmove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
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
//�ж������Ƿ�����
//���˷��أ�1
//û�����أ�0
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

//��дһ������
//��һ�ʤ���أ�*
// ���Ի�ʤ���أ�#
// ƽ�ַ��أ�a
// �������أ�b
//�ж���Ӯ
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
	//��Ϸ����
	return 'b';
}
