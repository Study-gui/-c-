#include"stack.h"
//栈符合先进后出的原则，并且取出一个删除一个才能去取一个
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