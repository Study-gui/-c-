#include"seqlist.h"

//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->a=NULL;
	ps->capacity= ps->size = 0;
}
//扩容函数
void SeqListrealloc(SL* ps)
{
	assert(ps);
	//如果没有空间或者空间不足，就进行扩容
	if (ps->capacity == ps->size)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLdataType* tmp = (SLdataType*)realloc(ps->a, newcapacity * sizeof(SLdataType));
		if (tmp == NULL)
		{
			perror("SeqListPushBack");
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
		printf("扩容成功\n");
	}
}


void SeqListPushBack(SL* ps, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//头插函数
void SeqListprint(SL* ps) 
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


//尾删函数
void SqqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}
//头插函数
void SeqListPushFront(SL* ps, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
//尾插函数
void SeqListPopFront(SL* ps, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//创建查找函数
int  SeqListFind(SL* ps,SLdataType x)
{
	assert(ps);
	int pos = 0;
	for (pos = 0; pos < ps->size; pos++)
	{
		if (ps->a[pos] == x)
		{
			return pos;//找到了返回数的下标
		}
	}
	return -1;
}
//指定位置插入函数
void SeqListMidInsert(SL* ps,SLdataType pos, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	if (pos >= ps->size)//对指定位置进行判断；
	{
		ps->a[ps->size] = x;
		ps->size++;
	}
	else {
		int end = ps->size;//对指定位置进行标记，向后赋值
		while (end > pos)
		{
			ps->a[end] = ps->a[end - 1];
			end--;
		}
		ps->a[pos] = x;
		ps->size++;
	}
}

//删除指定位置的函数
void SeqListErase(SL* ps, SLdataType pos)
{
	assert(ps);
	if (pos > ps->size - 1)//对指定位置进行判断；
	{
		printf("无可删除的数\n");
	}
	else {
		int mid = pos;//对指定位置进行标记，向前赋值
		while (mid < ps->size-1)
		{
			ps->a[mid] = ps->a[mid + 1];
			mid++;
		}
		ps->size--;
	}
}





