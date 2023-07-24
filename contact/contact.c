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
		printf("通讯录已满\n");
		return;
	}
	printf("请输入姓名:");
	scanf("%s", pc->data[pc->ret].name);		
	printf("请输入性别:");
	scanf("%s", pc->data[pc->ret].sex);
	printf("请输入年龄:");
	scanf("%d", &pc->data[pc->ret].age);
	printf("请输入电话号码:");
	scanf("%s", pc->data[pc->ret].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->ret].addre);
	pc->ret++;
	printf("增加成功\n");
}
void show_contact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("% -20s\t % -10s\t % -5s\t % -12s\t % -30s\n", "名字", "性别", "年龄", "号码", "地址");
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
//创建查找的函数
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
		printf("没有联系人可以删除\n");
		return;
	}
	printf("请输入要删除的名字：");
	scanf("%s", arr);
//创建查找的函数
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
		printf("联系人不存在\n");
	}
	pc->ret--;
}

void seek_contact(contact* pc)
{
	assert(pc);
	char arr[max_name] = { 0 };
	printf("请输入联系人姓名");
	scanf("%s", arr);
	int pos = find_contact(pc, arr);
	if (pos >= 0)
	{
		printf("查找完成\n");
		printf("% -20s\t % -10s\t % -5s\t % -12s\t % -30s\n", "名字", "性别", "年龄", "号码", "地址");
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n",
				pc->data[pos].name,
				pc->data[pos].sex,
				pc->data[pos].age,
				pc->data[pos].tele,
				pc->data[pos].addre);
	}
	else
	{
		printf("联系人不存在\n");
	}
}

void seq_contact(contact* pc)
{
	assert(pc);
	char arr[max_name] = { 0 };
	printf("请输入要修改的联系人：");
		scanf("%s", arr);
		int pos = find_contact(pc, arr);
		if (pos >= 0)
		{
			printf("请输入姓名:");
			scanf("%s", pc->data[pos].name);
			printf("请输入性别:");
			scanf("%s", pc->data[pos].sex);
			printf("请输入年龄:");
			scanf("%d", &pc->data[pos].age);
			printf("请输入电话号码:");
			scanf("%s", pc->data[pos].tele);
			printf("请输入地址:");
			scanf("%s", pc->data[pos].addre);
			printf("修改成功\n");
		}
		else
		{
			printf("无此联系人\n");
		}
}
//创建一个比较函数
int cmp(const void* e1, const void* e2)
{
	return  *((contact*)e1)->data->name - *((contact*)e2)->data->name;
}
void ait_contact(contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->ret, sizeof(peo), cmp);
	printf("排序完成\n");
}