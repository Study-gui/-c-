#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;//存放头节点
	QueueNode* tail;//存放尾节点
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//插入队列
void QueuePush(Queue* pq, QDataType x);

//销毁队头结点
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//返回队列的数据数量
int QueueSize(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

