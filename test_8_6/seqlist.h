#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLdataType;//创造类型，是更改更加方便


//动态顺序表
typedef struct seqlist
{
	SLdataType* a;//数组存储的元素数组
	size_t size;//表示数组存储的元素个数
	size_t capacity;//表示顺序表的容量
}SL;

//接口函数
//初始化顺序表
void SeqListInit(SL* ps);
//插入函数
void SeqListPushBack(SL* ps, SLdataType x);
//尾删函数
void SqqListPopBack(SL* ps);
//头插函数
void SeqListPushFront(SL* ps, SLdataType x);
//尾插函数
void SeqListPopFront(SL* ps, SLdataType x);

//创建打印函数
void SeqListprint(SL* ps);

//指定下标插入函数
void SeqListMidInsert(SL* ps, SLdataType pos, SLdataType x);

//创建是否扩容函数
void SeqListrealloc(SL* ps);

//创建查找函数
int SeqListFind(SL* ps,SLdataType x);

//删除指定位置的函数
void SeqListErase(SL* ps, SLdataType pos);



