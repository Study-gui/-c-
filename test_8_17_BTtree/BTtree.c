#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char DataType;

typedef struct BTNOdetree
{
	struct BTNOdetree* left;
	struct BTNOdetree* right;
	DataType data;
} BTNOde;

//ǰ�򣬷��ʸ������ǰ
void PrevBTNOde (BTNOde* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevBTNOde(root->left);
	PrevBTNOde(root->right);
}


//���򣬷��ʸ��������
void PreOrderBTNode(BTNOde* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PreOrderBTNode(root->left);
	printf("%c ", root->data);
	PreOrderBTNode(root->right);

}
//���򣬷��ʸ�����ں�
void PostBTNode(BTNOde* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostBTNode(root->left);
	PostBTNode(root->right);
	printf("%c ", root->data);
}
//�����ж��ٸ��ڵ�
int  TreeSize(BTNOde* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;//���÷����㷨�����ݹ�
}

//����Ҷ�ڵ�
int TreeLeafSize(BTNOde* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL&&root->right==NULL)
	{
		return 1;
	}

	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);//���÷����㷨�����ǵݹ�
}

//�������
void LevelOrder(BTNOde* root)
{
	Queue q;//���ö���ʵ�ֲ������
	QueueInit(&q);//��ʼ��
	if (root)//�жϲ�Ϊ�գ��Ѹ��ڵ�Ž�����
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNOde* front = QueueFront(&q);//ȡ��ͷ�Ľ�㣬�Ž�������������
		QueuePop(&q);//ɾ����ͷԪ��
		printf("%c ", front->data);//��ӡ���ʵ�Ԫ��
		if (front->left)//�жϷ��ʵ���������㣬��Ϊ�շ������
		{
			QueuePush(&q, front->left);

		}
		if (front->right)//�ж���������㣬��Ϊ�շ������
		{
			QueuePush(&q, front->right);

		}
	}
	QueueDestroy(&q);//�ͷŶ��пռ�
	
}

int main()
{
	BTNOde* A = (BTNOde*) malloc(sizeof(BTNOde));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNOde* B = (BTNOde*)malloc(sizeof(BTNOde));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNOde* C = (BTNOde*)malloc(sizeof(BTNOde));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNOde* D = (BTNOde*)malloc(sizeof(BTNOde));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNOde* E = (BTNOde*)malloc(sizeof(BTNOde));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevBTNOde(A);
	printf("\n");

	PreOrderBTNode(A);
	printf("\n");

	PostBTNode(A);
	printf("\n");

	printf("%d\n", TreeSize(A));
	printf("%d\n", TreeLeafSize(A));
	LevelOrder(A);

	return 0;
}