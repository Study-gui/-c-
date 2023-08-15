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
	QueueNode* head;//���ͷ�ڵ�
	QueueNode* tail;//���β�ڵ�
}Queue;

//��ʼ������
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//�������
void QueuePush(Queue* pq, QDataType x);

//���ٶ�ͷ���
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

//���ض��е���������
int QueueSize(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

