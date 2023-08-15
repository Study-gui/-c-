#include"Queue.h"
//队列，就是先进先出，只能从对头出，队尾进

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