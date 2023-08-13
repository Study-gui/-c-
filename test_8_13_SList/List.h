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
//初始化双向带环链表
LTNode* ListInit();

//尾插
void ListPushBack(LTNode* phead, LTDateType x);

//尾删
void ListPopBack(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDateType x);

//头删
void ListPopFront(LTNode* phead);

//输出函数
void Listprint(LTNode* phead);

//找到指定x的位置
LTNode* ListFind(LTNode* phead, LTDateType x);

//在指定pos位置前插入
void ListInsert(LTNode* pos, LTDateType x);

//删除指定位置pos的结点
void ListErase(LTNode* pos);

//销毁释放空间
void ListDestroy(LTNode* phead);