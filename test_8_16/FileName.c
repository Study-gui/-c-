 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
typedef int STDataType;
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
	assert(ps->top > 0);
	ps->top--;
}

//����ջ��������
STDataType stackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
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

//˼·�����Ǵ�������ջ��pushst����������ݣ�popst���������ݣ�pushst��ջ�׾���popstջ��������
//������ʵ����һ�����еĹ���


typedef struct {
	ST pushst;//�������
	ST popst;//���յ�������
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* p = (MyQueue*)malloc(sizeof(MyQueue));//���г�ʼ��
	StackInit(&p->pushst);
	StackInit(&p->popst);
	return p;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushst, x);//�������

}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popst))//�ж�popst�Ƿ������ݣ�û�н��е�����
	{
		while (!StackEmpty(&obj->pushst))//��pushst�����ݵ���popst�У��ٽ�pushst�����ݽ���ɾ��
		{
			StackPush(&obj->popst, stackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	int top = stackTop(&obj->popst);
	StackPop(&obj->popst);
	return top;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, stackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	int top = stackTop(&obj->popst);
	//StackPop(&obj->popst);
	return top;
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushst);//�����ͷŶ����������ռ�
	StackDestroy(&obj->popst);
	free(obj);

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/