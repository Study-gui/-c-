#include"stack.h"

//��ʼ��ջ
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//���ݺ���
void stackrelloc(ST* ps,STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (ST*)realloc(ps->a, sizeof(ST) * newcapacity);
		if (tmp != NULL)
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}



//��������
void StackPush(ST* ps, STDataType x)
{
	stackrelloc(ps, x);


}

//�ͷſռ�
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;

}

//ɾ���ռ�ջ��������
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->a > 0);
	ps->top--;
}

//����ջ��������
STDataType stackTop(ST* ps)
{
	assert(ps);
	assert(ps->a > 0);
	return ps->a[ps->top - 1];
}

//����ջ������
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}