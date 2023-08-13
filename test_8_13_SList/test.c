#include"List.h"

void testList()
{
	//��ʼ������
	LTNode* plist = ListInit();
	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	Listprint(plist);
	//βɾ
	ListPopBack(plist);
	Listprint(plist);
	//ͷ��
	ListPushFront(plist, 5);
	ListPushFront(plist, 4);
	ListPushFront(plist, 3);
	Listprint(plist);
	//ͷɾ
	ListPopFront(plist);
	Listprint(plist);

	//�ҵ�ָ�����pos
	LTNode* pos = ListFind(plist, 5);
	if (pos)//�ж�pos��λ��ָ��
	{
		//��ָ��λ��posǰ������
		ListInsert(pos, 8);
		ListInsert(pos, 10);
		Listprint(plist);
		//ɾ��ָ��λ��pos�Ľ��
		ListErase(pos);
		Listprint(plist);
	}
	//�ͷſռ�
	ListDestroy(plist);
	Listprint(plist);






}

int main()
{
	testList();
	return 0;
}