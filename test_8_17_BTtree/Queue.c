#include"Queue.h"


//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;

}


//销毁队列
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
//插入队列
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

//销毁队头结点
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

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}


//返回队列的数据数量
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

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

