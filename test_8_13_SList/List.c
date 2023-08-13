#include"List.h"
//��д���ٿռ�ĺ���
LTNode* BuyList(LTDateType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//��ʼ������
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}






//β��
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


//�������
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

//βɾ
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


//ͷ��
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

//ͷɾ
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

//�ҵ�ָ��λ��pos
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

//��ָ��λ��posǰ����
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


//ɾ��ָ�����pos
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

//�����ͷſռ�
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