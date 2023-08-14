#include"stack.h"

//初始化栈
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//扩容函数
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
	assert(ps->a > 0);
	ps->top--;
}

//返回栈顶的数据
STDataType stackTop(ST* ps)
{
	assert(ps);
	assert(ps->a > 0);
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