#include"stack.h"
//ջ�����Ƚ������ԭ�򣬲���ȡ��һ��ɾ��һ������ȥȡһ��
void stacktest()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st,6);

	while (!StackEmpty(&st))
	{
		printf("%d ", stackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);



}


int main()
{
	stacktest();
	return 0;
}