#include"List.h"
//编写开辟空间的函数
LTNode* BuyList(LTDateType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//初始化链表
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}






//尾插
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newNode = BuyList(x);
	LTNode* tail = phead->prev;
		tail->next = newNode;
		newNode->prev = tail;
		newNode->next = phead;
		phead->prev = newNode;
}


//输出函数
void Listprint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->prev;
	LTNode* tail = next->prev;
	phead->prev = tail;
	tail->next = phead;
	free(next);
	next = NULL;
}


//头插
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newNode = BuyList(x);
	LTNode* pheadcur = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next = pheadcur;
	pheadcur->prev = newNode;

}

//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* cur = phead->next;
	LTNode* next = cur->next;
	phead->next = next;
	next->prev = phead;
	free(cur);
	cur = NULL;

}

//找到指定位置pos
LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在指定位置pos前插入
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newNode = BuyList(x);
	LTNode* tail = pos->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = pos;
	pos->prev = newNode;
}


//删除指定结点pos
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* tail = pos->prev;
	LTNode* next = pos->next;
	tail->next = next;
	next->prev = tail;
	free(pos);
	pos == NULL;
}

//销毁释放空间
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}