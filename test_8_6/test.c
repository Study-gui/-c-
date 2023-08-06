#include"seqlist.h"
//Ë³Ðò±íµÄÁ·Ï°



int main()
{
	SL ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 10);
	SeqListPushBack(&ps, 20);
	SeqListPushBack(&ps, 30);
	SeqListPushBack(&ps, 40);
	SeqListPushBack(&ps, 50);
	SeqListprint(&ps);
	SqqListPopBack(&ps);
	SeqListprint(&ps);
	SeqListPushFront(&ps,50);
	SeqListprint(&ps);
	SeqListPopFront(&ps, 5);
	SeqListprint(&ps);
	SeqListMidInsert(&ps,2,111);
	SeqListprint(&ps);
	SeqListErase(&ps, 3);
	SeqListprint(&ps);





	return 0;
}