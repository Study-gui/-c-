 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵�������
typedef char STDataType;

typedef struct  stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
//��ʼ��ջ
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//���ݺ���
void stackrelloc(ST* ps, STDataType x)
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

bool isValid(char* s) {
	//˼·��ͨ��ջ��������⣬���������ŵĽ��д��룬���������ŵľ�ȡ��ջ�������Ž��бȽ�
	ST st;
	StackInit(&st);

	while (*s)
	{
		//�������Ž��д���
		if (*s == '('
			|| *s == '['
			|| *s == '{')
		{
			StackPush(&st, *s);
			s++;
		}
		else {
			//�ж�ջ����Ϊ�գ�Ϊ�վ�û��������ƥ���Ϊ��
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}//ջ��Ϊ�գ���ȡ����֮�Ƚ�
			char top = stackTop(&st);
			StackPop(&st);
			//��ȡ��ջ��Ԫ�أ����бȽ�
			if ((*s == ')' && top != '(')
				|| (*s == '}' && top != '{')
				|| (*s == ']' && top != '['))
			{
				StackDestroy(&st);
				return false;
			}
			s++;
		}
	}
	//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�վ�Ϊ�棬��Ϊ��˵�����滹�����ţ���Ϊ��
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}