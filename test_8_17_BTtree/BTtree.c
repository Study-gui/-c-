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

//前序，访问根结点在前
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


//中序，访问根结点在中
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
//后序，访问根结点在后
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
//查找有多少个节点
int  TreeSize(BTNOde* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;//利用分治算法，层层递归
}

//查找叶节点
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

	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);//利用分治算法，就是递归
}

//层序查找
void LevelOrder(BTNOde* root)
{
	Queue q;//利用队列实现层序查找
	QueueInit(&q);//初始化
	if (root)//判断不为空，把根节点放进队列
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNOde* front = QueueFront(&q);//取队头的结点，放进二叉树类型里
		QueuePop(&q);//删除队头元素
		printf("%c ", front->data);//打印访问的元素
		if (front->left)//判断访问的左子树结点，不为空放入队列
		{
			QueuePush(&q, front->left);

		}
		if (front->right)//判断右子树结点，不为空放入队列
		{
			QueuePush(&q, front->right);

		}
	}
	QueueDestroy(&q);//释放队列空间
	
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