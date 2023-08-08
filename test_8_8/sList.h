#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;

//����ṹ��
typedef struct SListNode
{
	SLDateType* data;
	struct SListNode* next;
}SLTNode;

//��ӡ����
void SListPrint(SLTNode* phead);


//β��������
void SListPushBack(SLTNode** phead, SLDateType* x);

//ͷ������
void SListPushFront(SLTNode** phead, SLDateType* x);

//β�ϵ�ɾ��
void SListPopBack(SLTNode** pphead);

//ͷ�ϵ�ɾ��
void SListPopFront(SLTNode** pphead);