 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
typedef int STDataType;
typedef struct  stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化栈
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//扩容函数
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



//插入数据
void StackPush(ST* ps, STDataType x)
{
	stackrelloc(ps, x);


}

//释放空间
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;

}

//删除空间栈顶的数据
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//返回栈顶的数据
STDataType stackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//返回栈的数量
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//思路：就是创建两个栈，pushst用来存放数据，popst用来倒数据，pushst的栈底就是popst栈顶的数据
//这样就实现了一个队列的功能


typedef struct {
	ST pushst;//存放数据
	ST popst;//接收倒的数据
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* p = (MyQueue*)malloc(sizeof(MyQueue));//进行初始化
	StackInit(&p->pushst);
	StackInit(&p->popst);
	return p;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushst, x);//存放数据

}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popst))//判断popst是否有数据，没有进行倒数据
	{
		while (!StackEmpty(&obj->pushst))//将pushst的数据倒到popst中，再将pushst的数据进行删除
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
	StackDestroy(&obj->pushst);//需先释放独立的两个空间
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