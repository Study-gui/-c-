#include"sList.h"



void SListtist1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPushFront(&plist, 5);
	SListPushFront(&plist, 6);
	SListPushFront(&plist, 7);
	SListPushFront(&plist, 8);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);




}




int main()
{
	SListtist1();

	return 0;
}