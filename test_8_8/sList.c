#include"sList.h"

//��ӡ����
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

//���ٿռ�ĺ���
SLTNode* BuyListNode(SLTNode** pphead, SLDateType* x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x; // �ȶԴ����ֵ���п��ٿռ�
	newnode->next = NULL;
	return  newnode;
}


//β��������
void SListPushBack(SLTNode** pphead, SLDateType* x)
{
	//Ҫ��ı������ֵ����Ҫ����ָ�����
	//assert(phead);
	SLTNode* newnode=BuyListNode(&pphead, x);
	
	if (*pphead == NULL)//�ڽ����ж��������Ƿ�������
	{//Ϊ�գ���ֱ��ֱ�ӽ��в���
		*pphead = newnode;
	}
	else {//��Ϊ�գ��Ͳ������һ��������ַΪ��һ���ĳ�Ա
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}


//ͷ�庯��
void SListPushFront(SLTNode** pphead, SLDateType* x)
{
	assert(*pphead != NULL);
	SLTNode* newnode = BuyListNode(&pphead, x);//���ȿ��ٿռ�
	newnode->next = *pphead;//�ڶ���Ԫ�صĽ���ַ��ֵ������ĳ�Ա
	*pphead = newnode;//�ٰѲ����Ԫ�ص�ַ������ͷ
}

//β�ϵ�ɾ��
void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);//�����жϲ���Ϊ����ָ��
	if ((*pphead)->next == NULL)//����������жϣ���ֻ��һ��������ֱ�ӽ���ɾ��
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {//����Ϊһ������Ҫ�������һλ��ɾ������ǰһλ�Ľ���ַ���
		//����һ��
		//SLTNode* tail = *pphead;//�ҵ�ǰһλ
		//SLTNode* prev = NULL;//�ҵ����һλ
	/*	while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;*/
		//��������
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;

	}
}

//ͷ�ϵ�ɾ��
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);//�ж������Ƿ�Ϊ��
	SLTNode* next = (*pphead)->next;//��õڶ�������ַ
	*pphead = NULL;//�ٽ���һ������ַ��Ϊ��
	*pphead = next;//�ٽ��ڶ�������ַ������ͷ
}