#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define max_name 20
#define max_sex  10
#define max_tele 12
#define max_addre 30
#define max 100
#define cheek 3
#define cheek_2 2

//�˵���Ϣ
typedef struct peo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addre[max_addre];
} peo;

//ͨѶ¼��̬�汾
// typedef struct contact
//{
//	peo data[max];
//	int ret;//��¼����
//
//} contact;
//��̬�汾
 typedef struct contact
 {
	 peo* data;
	 int ret;//��¼����
	 int capacity;//��¼ͨѶ¼����
 } contact;

//��ʼ��ͨѶ¼
int  initcontact(contact* pc);

//��ͨѶ¼���д洢
void add_contact(contact* pc);

//��ͨѶ¼��������
void show_contact(contact* pc);

//��ͨѶ¼ָ����ϵ�˽���ɾ��
void del_contact(contact* pc);

//������ϵ��
void seek_contact(contact* pc);

//�޸���ϵ��
void seq_contact(contact* pc);

//������ϵ��
void ait_contact(contact* pc);

//����ͨѶ¼
 void delet_contact(contact* pc);
 
 //����ͨѶ¼
 void preserve_contact(const contact* pc);
