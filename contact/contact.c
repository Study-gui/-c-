#include"contact.h"
void initcontact(contact* pc)
{
	pc->ret = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void add_contact(contact* pc)
{
	assert(pc);
	if (pc->ret == max)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������:");
	scanf("%s", pc->data[pc->ret].name);		
	printf("�������Ա�:");
	scanf("%s", pc->data[pc->ret].sex);
	printf("����������:");
	scanf("%d", &pc->data[pc->ret].age);
	printf("������绰����:");
	scanf("%s", pc->data[pc->ret].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pc->ret].addre);
	pc->ret++;
	printf("���ӳɹ�\n");
}
void show_contact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("% -20s\t % -10s\t % -5s\t % -12s\t % -30s\n", "����", "�Ա�", "����", "����", "��ַ");
	for (i = 0; i < pc->ret; i++)
	{
		printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n",
			                 pc->data[i].name,
			                 pc->data[i].sex,
			                 pc->data[i].age,
			                 pc->data[i].tele,
			                 pc->data[i].addre);
	}
}
//�������ҵĺ���
int find_contact(contact* pc, char arr[])
{
	int j = 0;
	for (j = 0; j < pc->ret; j++)
	{
		if (0==strcmp(pc->data[j].name,arr))
		{
			return j;
		}
	}
	return -1;
}

void del_contact(contact* pc)
{
	assert(pc);
	int i = 0;
	char arr[max_name] = { 0 };
	if (pc->ret == 0)
	{
		printf("û����ϵ�˿���ɾ��\n");
		return;
	}
	printf("������Ҫɾ�������֣�");
	scanf("%s", arr);
//�������ҵĺ���
	int pos = find_contact(pc, arr);
	if (pos >= 0)
	{
		for (i = pos; i < pc->ret - 1; i++)
		{
			pc->data[pos] = pc->data[pos + 1];
		}
	}
	else
	{
		printf("��ϵ�˲�����\n");
	}
	pc->ret--;
}

void seek_contact(contact* pc)
{
	assert(pc);
	char arr[max_name] = { 0 };
	printf("��������ϵ������");
	scanf("%s", arr);
	int pos = find_contact(pc, arr);
	if (pos >= 0)
	{
		printf("�������\n");
		printf("% -20s\t % -10s\t % -5s\t % -12s\t % -30s\n", "����", "�Ա�", "����", "����", "��ַ");
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n",
				pc->data[pos].name,
				pc->data[pos].sex,
				pc->data[pos].age,
				pc->data[pos].tele,
				pc->data[pos].addre);
	}
	else
	{
		printf("��ϵ�˲�����\n");
	}
}

void seq_contact(contact* pc)
{
	assert(pc);
	char arr[max_name] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ�ˣ�");
		scanf("%s", arr);
		int pos = find_contact(pc, arr);
		if (pos >= 0)
		{
			printf("����������:");
			scanf("%s", pc->data[pos].name);
			printf("�������Ա�:");
			scanf("%s", pc->data[pos].sex);
			printf("����������:");
			scanf("%d", &pc->data[pos].age);
			printf("������绰����:");
			scanf("%s", pc->data[pos].tele);
			printf("�������ַ:");
			scanf("%s", pc->data[pos].addre);
			printf("�޸ĳɹ�\n");
		}
		else
		{
			printf("�޴���ϵ��\n");
		}
}
//����һ���ȽϺ���
int cmp(const void* e1, const void* e2)
{
	return  *((contact*)e1)->data->name - *((contact*)e2)->data->name;
}
void ait_contact(contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->ret, sizeof(peo), cmp);
	printf("�������\n");
}