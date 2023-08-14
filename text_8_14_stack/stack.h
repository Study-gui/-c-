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

//��ʼ��
void StackInit(ST* ps);


//�ͷſռ�
void StackDestroy(ST* ps);

//����ռ�
void StackPush(ST* ps, STDataType x);

//ɾ���ռ�ջ��������
void StackPop(ST* ps);

//����ջ��������
STDataType stackTop(ST* ps);

//����ջ������
int StackSize(ST* ps);


//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);