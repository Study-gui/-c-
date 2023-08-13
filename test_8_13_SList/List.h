#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int   LTDateType;
 
typedef struct ListNode
{
    LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
//��ʼ��˫���������
LTNode* ListInit();

//β��
void ListPushBack(LTNode* phead, LTDateType x);

//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x);

//ͷɾ
void ListPopFront(LTNode* phead);

//�������
void Listprint(LTNode* phead);

//�ҵ�ָ��x��λ��
LTNode* ListFind(LTNode* phead, LTDateType x);

//��ָ��posλ��ǰ����
void ListInsert(LTNode* pos, LTDateType x);

//ɾ��ָ��λ��pos�Ľ��
void ListErase(LTNode* pos);

//�����ͷſռ�
void ListDestroy(LTNode* phead);