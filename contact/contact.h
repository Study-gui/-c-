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

//人的信息
typedef struct peo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addre[max_addre];
} peo;

//通讯录
 typedef struct contact
{
	peo data[max];
	int ret;//记录人数

} contact;

//初始化通讯录
void initcontact(contact* pc);

//对通讯录进行存储
void add_contact(contact* pc);

//对通讯录进行排序
void show_contact(contact* pc);

//对通讯录指定联系人进行删除
void del_contact(contact* pc);

//查找联系人
void seek_contact(contact* pc);

//修改联系人
void seq_contact(contact* pc);

//排序联系人
void ait_contact(contact* pc);