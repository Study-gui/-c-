#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;

//定义结构体
typedef struct SListNode
{
	SLDateType* data;
	struct SListNode* next;
}SLTNode;

//打印链表
void SListPrint(SLTNode* phead);


//尾插入链表
void SListPushBack(SLTNode** phead, SLDateType* x);

//头插链表
void SListPushFront(SLTNode** phead, SLDateType* x);

//尾上的删除
void SListPopBack(SLTNode** pphead);

//头上的删除
void SListPopFront(SLTNode** pphead);