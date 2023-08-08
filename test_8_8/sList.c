#include"sList.h"

//打印链表
void SListPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur!= NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//开辟空间的函数
SLTNode* BuyListNode(SLTNode** pphead, SLDateType* x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x; // 先对传入的值进行开辟空间
	newnode->next = NULL;
	return  newnode;
}


//尾插入链表
void SListPushBack(SLTNode** pphead, SLDateType* x)
{
	//要想改变链表的值，就要二级指针接收
	//assert(phead);
	SLTNode* newnode=BuyListNode(&pphead, x);
	
	if (*pphead == NULL)//在进行判断链表本身是否含有数据
	{//为空，就直接直接进行插入
		*pphead = newnode;
	}
	else {//不为空，就插入最后一个，结点地址为上一结点的成员
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}


//头插函数
void SListPushFront(SLTNode** pphead, SLDateType* x)
{
	assert(*pphead != NULL);
	SLTNode* newnode = BuyListNode(&pphead, x);//首先开辟空间
	newnode->next = *pphead;//在对首元素的结点地址赋值给插入的成员
	*pphead = newnode;//再把插入的元素地址赋给开头
}

//尾上的删除
void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);//进行判断不能为控制指针
	if ((*pphead)->next == NULL)//对链表进行判断，若只有一个数，就直接进行删除
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {//若不为一个，就要进行最后一位的删除，和前一位的结点地址归空
		//方法一：
		//SLTNode* tail = *pphead;//找到前一位
		//SLTNode* prev = NULL;//找到最后一位
	/*	while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;*/
		//方法二：
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;

	}
}

//头上的删除
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);//判断链表是否为空
	SLTNode* next = (*pphead)->next;//求得第二个结点地址
	*pphead = NULL;//再将第一个结点地址置为空
	*pphead = next;//再将第二个结点地址赋给开头
}