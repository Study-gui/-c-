#include"Queue.h"
//���У������Ƚ��ȳ���ֻ�ܴӶ�ͷ������β��

void Queuetest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//QueuePop(&q);
	QueuePush(&q, 4);
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueSize(&q));
	printf("%d ", QueueEmpty(&q));
}


int main()
{
	Queuetest();
	return 0;
}