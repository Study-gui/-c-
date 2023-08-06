#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLdataType;//�������ͣ��Ǹ��ĸ��ӷ���


//��̬˳���
typedef struct seqlist
{
	SLdataType* a;//����洢��Ԫ������
	size_t size;//��ʾ����洢��Ԫ�ظ���
	size_t capacity;//��ʾ˳��������
}SL;

//�ӿں���
//��ʼ��˳���
void SeqListInit(SL* ps);
//���뺯��
void SeqListPushBack(SL* ps, SLdataType x);
//βɾ����
void SqqListPopBack(SL* ps);
//ͷ�庯��
void SeqListPushFront(SL* ps, SLdataType x);
//β�庯��
void SeqListPopFront(SL* ps, SLdataType x);

//������ӡ����
void SeqListprint(SL* ps);

//ָ���±���뺯��
void SeqListMidInsert(SL* ps, SLdataType pos, SLdataType x);

//�����Ƿ����ݺ���
void SeqListrealloc(SL* ps);

//�������Һ���
int SeqListFind(SL* ps,SLdataType x);

//ɾ��ָ��λ�õĺ���
void SeqListErase(SL* ps, SLdataType pos);



