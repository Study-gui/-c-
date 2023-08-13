#include"List.h"

void testList()
{
	//初始化链表
	LTNode* plist = ListInit();
	//尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	Listprint(plist);
	//尾删
	ListPopBack(plist);
	Listprint(plist);
	//头插
	ListPushFront(plist, 5);
	ListPushFront(plist, 4);
	ListPushFront(plist, 3);
	Listprint(plist);
	//头删
	ListPopFront(plist);
	Listprint(plist);

	//找到指定结点pos
	LTNode* pos = ListFind(plist, 5);
	if (pos)//判断pos部位空指针
	{
		//在指定位置pos前插入结点
		ListInsert(pos, 8);
		ListInsert(pos, 10);
		Listprint(plist);
		//删除指定位置pos的结点
		ListErase(pos);
		Listprint(plist);
	}
	//释放空间
	ListDestroy(plist);
	Listprint(plist);






}

int main()
{
	testList();
	return 0;
}