 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号
typedef char STDataType;

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

bool isValid(char* s) {
	//思路：通过栈来解决问题，对是左括号的进行存入，不是左括号的就取出栈顶的括号进行比较
	ST st;
	StackInit(&st);

	while (*s)
	{
		//对左括号进行存入
		if (*s == '('
			|| *s == '['
			|| *s == '{')
		{
			StackPush(&st, *s);
			s++;
		}
		else {
			//判断栈不能为空，为空就没有括号相匹配就为假
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}//栈不为空，就取出与之比较
			char top = stackTop(&st);
			StackPop(&st);
			//对取出栈的元素，进行比较
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
	//判断栈是否为空，为空就为真，不为空说明里面还有括号，就为假
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}