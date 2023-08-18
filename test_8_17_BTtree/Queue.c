#include"Queue.h"


//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;

}


//���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head =pq->tail= NULL;

}
//�������
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (pq->head == NULL)
	{
		pq->head =pq->tail= newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}


}

//���ٶ�ͷ���
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next=pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}

}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}


//���ض��е���������
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		cur = cur->next;
		n++;
	}
	return n;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

