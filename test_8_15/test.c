 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//ʵ�� MyStack �ࣺ

//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;//���ͷ�ڵ�
//	QueueNode* tail;//���β�ڵ�
//}Queue;
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
////��ʼ������
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//
////���ٶ���
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//
//}
////�������
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	if (newnode != NULL)
//	{
//		newnode->data = x;
//		newnode->next = NULL;
//	}
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else {
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//
//
//}
//
////���ٶ�ͷ���
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//
//}
//
////ȡ��ͷ����
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head != NULL);
//	return pq->head->data;
//}
//
////ȡ��β����
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
//
////���ض��е���������
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	int n = 0;
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		n++;
//	}
//	return n;
//}
//
//
//
////����˼·����ʵ��һ�����У��ڴ����������нṹ�壬
////������ȫ������һ�����У��ٽ������ݵĶ��дӶ�ͷ�����ƶ����ն����У�֪�����һ������ջ����Ԫ��
////ÿ��ȡ�õ�Ԫ�ض�Ҫѭ��������̣�����ʵ�ֺ����ȳ���ջ
//
//typedef struct {
//	Queue p1;//������������
//	Queue p2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* p = (MyStack*)malloc(sizeof(MyStack));//����Ҫ����mallocҪ������ȫ�ֱ���
//	QueueInit(&p->p1);//���������н��г�ʼ��
//	QueueInit(&p->p2);
//	return p;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//	if (!QueueEmpty(&obj->p1))//�Զ��н����жϣ��Ǹ�Ϊ�գ��ʹ����Ǹ�����
//	{
//		QueuePush(&obj->p1, x);
//	}
//	else {
//		QueuePush(&obj->p2, x);
//	}
//
//}
//
//int myStackPop(MyStack* obj) {
//	QueueNode* next = &obj->p1;
//	QueueNode* nonext = &obj->p2;//�϶�next����Ϊ��
//	if (!QueueEmpty(&obj->p1))
//	{
//		next = &obj->p2;
//		nonext = &obj->p1;
//	}
//	while (QueueSize(nonext) > 1)//��nonext���е�Ԫ�ؽ����ƶ���next�����У�����ջ��Ԫ��
//	{
//		QueuePush(next, QueueFront(nonext));
//		QueuePop(nonext);
//	}
//	int top = QueueFront(nonext);//��ջ����Ԫ�ؽ��б���
//	QueuePop(nonext);//ɾ��ջ����Ԫ��
//	return top;//����ջ����Ԫ��
//}
//
//int myStackTop(MyStack* obj) {
//	assert(obj);
//	if (!QueueEmpty(&obj->p1))
//	{
//		return QueueBack(&obj->p1);//ֱ�����ú���ȡ�����ж�β��Ԫ�أ�����ջ����Ԫ��
//	}
//	else {
//		return QueueBack(&obj->p2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	assert(obj);
//	return QueueEmpty(&obj->p1) && QueueEmpty(&obj->p2);//�ж�ջ�Ƿ�Ϊ�գ���Ҫ�ж����������Ƿ�Ϊ��
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->p1);//�ͷſռ䣬Ҫ�����������Ƚ����ͷţ������ͷ�ջ����Ȼ���ڴ�й©
//	QueueDestroy(&obj->p2);
//	free(obj);
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
//���дһ�δ��룬ʵ������������������ĺϲ�
//����������
//��һ��һ��������1 2 3 4 5

//�ڶ���һ��������2 3 4 5 6
//���������
//�����1 2 2 3 3 4 4 5 5 6
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>
typedef struct SL
{
    int data;
    struct SL* next;
}SL;
//��ӡ����
void SListprint(SL* phead)
{
    assert(phead);
    SL* cur = phead;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
//β���뺯��
void SListPush(SL** phead, int x)
{
    assert(phead);
    SL* newnode = (SL*)malloc(sizeof(SL));
    newnode->data = x;
    newnode->next = NULL;
    if (*phead == NULL)
    {
        *phead = newnode;
    }
    else {
        SL* cur = *phead;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}
//������������
SL* mergeTwoLists(SL* list1, SL* list2)
{
    //SL* plist1,*plist2;
    SL* head = NULL, * tail = NULL;
    //plist1=list1,plist2=list2;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    while (list1 && list2)
    {
        if (list1->data > list2->data)
        {
            if (head == NULL)
            {
                head = tail = list2;
                list2 = list2->next;
            }
            else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        else {
            if (head == NULL)
            {
                head = tail = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
        }
    }
    if (list1)
    {
        tail->next = list1;
    }
    if (list2)
    {
        tail->next = list2;
    }
    return head;
}
int main() {
    SL* plist1 = NULL;
    SL* plist2 = NULL;
    //SListprint(plist1);
  //   SListPush(&plist1, 1);
  //    SListPush(&plist1, 2);
  //    SListPush(&plist1, 3);
  //    SListPush(&plist1, 4);
  //    SListPush(&plist1, 5);
    int num = 0, ch = 0;
    while ((scanf("%d%c", &num, &ch)) > 0)
    {
        SListPush(&plist1, num);
        if (ch == '\n')
        {
            break;
        }
    }
    while ((scanf("%d%c", &num, &ch)) > 0)
    {
        SListPush(&plist2, num);
        if (ch == '\n')
        {
            break;
        }
    }
    //   SListPush(&plist2, 2);
    //   SListPush(&plist2, 3);
    //   SListPush(&plist2, 4);
    //   SListPush(&plist2, 5);
    //   SListPush(&plist2, 6);
    SL* list = mergeTwoLists(plist1, plist2);
    SListprint(list);

    return 0;
}