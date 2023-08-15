 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//实现 MyStack 类：

//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
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
//	QueueNode* head;//存放头节点
//	QueueNode* tail;//存放尾节点
//}Queue;
//
////判断队列是否为空
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
////初始化队列
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//
////销毁队列
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
////插入队列
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
////销毁队头结点
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
////取队头数据
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head != NULL);
//	return pq->head->data;
//}
//
////取队尾数据
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
//
////返回队列的数据数量
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
////本题思路：先实现一个队列，在创造两个队列结构体，
////将数据全部存入一个队列，再将有数据的队列从队头进行移动到空队列中，知道最后一个就是栈顶的元素
////每个取得的元素都要循环这个过程，就能实现后入先出的栈
//
//typedef struct {
//	Queue p1;//创建两个队列
//	Queue p2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* p = (MyStack*)malloc(sizeof(MyStack));//返回要不是malloc要不就是全局变量
//	QueueInit(&p->p1);//对连个队列进行初始化
//	QueueInit(&p->p2);
//	return p;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//	if (!QueueEmpty(&obj->p1))//对队列进行判断，那个为空，就存入那个队列
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
//	QueueNode* nonext = &obj->p2;//认定next队列为空
//	if (!QueueEmpty(&obj->p1))
//	{
//		next = &obj->p2;
//		nonext = &obj->p1;
//	}
//	while (QueueSize(nonext) > 1)//把nonext队列的元素进行移动到next队列中，保留栈顶元素
//	{
//		QueuePush(next, QueueFront(nonext));
//		QueuePop(nonext);
//	}
//	int top = QueueFront(nonext);//对栈顶的元素进行保存
//	QueuePop(nonext);//删除栈顶的元素
//	return top;//返回栈顶的元素
//}
//
//int myStackTop(MyStack* obj) {
//	assert(obj);
//	if (!QueueEmpty(&obj->p1))
//	{
//		return QueueBack(&obj->p1);//直接利用函数取出队列队尾的元素，就是栈顶的元素
//	}
//	else {
//		return QueueBack(&obj->p2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	assert(obj);
//	return QueueEmpty(&obj->p1) && QueueEmpty(&obj->p2);//判断栈是否为空，就要判断两个队列是否都为空
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->p1);//释放空间，要将两个队列先进行释放，才能释放栈，不然会内存泄漏
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
//请编写一段代码，实现两个单向有序链表的合并
//输入描述：
//第一行一个链表，如1 2 3 4 5

//第二行一个链表，如2 3 4 5 6
//输出描述：
//输出：1 2 2 3 3 4 4 5 5 6
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>
typedef struct SL
{
    int data;
    struct SL* next;
}SL;
//打印函数
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
//尾插入函数
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
//排序两个链表
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