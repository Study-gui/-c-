#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct  stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* ps);


//释放空间
void StackDestroy(ST* ps);

//插入空间
void StackPush(ST* ps, STDataType x);

//删除空间栈顶的数据
void StackPop(ST* ps);

//返回栈顶的数据
STDataType stackTop(ST* ps);

//返回栈的数量
int StackSize(ST* ps);


//判断栈是否为空
bool StackEmpty(ST* ps);