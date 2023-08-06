#include"seqlist.h"

//��ʼ��˳���
void SeqListInit(SL* ps)
{
	ps->a=NULL;
	ps->capacity= ps->size = 0;
}
//���ݺ���
void SeqListrealloc(SL* ps)
{
	assert(ps);
	//���û�пռ���߿ռ䲻�㣬�ͽ�������
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
		printf("���ݳɹ�\n");
	}
}


void SeqListPushBack(SL* ps, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//ͷ�庯��
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


//βɾ����
void SqqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}
//ͷ�庯��
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
//β�庯��
void SeqListPopFront(SL* ps, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//�������Һ���
int  SeqListFind(SL* ps,SLdataType x)
{
	assert(ps);
	int pos = 0;
	for (pos = 0; pos < ps->size; pos++)
	{
		if (ps->a[pos] == x)
		{
			return pos;//�ҵ��˷��������±�
		}
	}
	return -1;
}
//ָ��λ�ò��뺯��
void SeqListMidInsert(SL* ps,SLdataType pos, SLdataType x)
{
	assert(ps);
	SeqListrealloc(ps);
	if (pos >= ps->size)//��ָ��λ�ý����жϣ�
	{
		ps->a[ps->size] = x;
		ps->size++;
	}
	else {
		int end = ps->size;//��ָ��λ�ý��б�ǣ����ֵ
		while (end > pos)
		{
			ps->a[end] = ps->a[end - 1];
			end--;
		}
		ps->a[pos] = x;
		ps->size++;
	}
}

//ɾ��ָ��λ�õĺ���
void SeqListErase(SL* ps, SLdataType pos)
{
	assert(ps);
	if (pos > ps->size - 1)//��ָ��λ�ý����жϣ�
	{
		printf("�޿�ɾ������\n");
	}
	else {
		int mid = pos;//��ָ��λ�ý��б�ǣ���ǰ��ֵ
		while (mid < ps->size-1)
		{
			ps->a[mid] = ps->a[mid + 1];
			mid++;
		}
		ps->size--;
	}
}





