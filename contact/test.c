#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
//实现通讯录
//1，创建界面
//2，创建自定义类型人的信息
//3，对通讯录进行初始化
//4, add增加通讯录人数
//5，show对通讯录进行打印
//6,delet对通讯录进行删除
//7,seek查找联系人
//8,seq修改联系人
//9,ait排序联系人
void menu()
{
	printf("*******    1.add   2.del       ********\n");
	printf("*******    3.see   4.seq       ********\n");
	printf("*******    5.show  6.ait       ********\n");
	printf("***********0 .lea      ****************\n");
	printf("***************************************\n");
}
int main()
{
	int input = 0;
	contact con;
	initcontact(&con);
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			add_contact(&con);
			break;
		case 2:
			del_contact(&con);
			break;
		case 3:
			seek_contact(&con);
			break;
		case 4:
			seq_contact(&con);
			break;
		case 5:
			show_contact(&con);
			break;
		case 6:
			ait_contact(&con);
			break;
		case 0://推出程序
			//先保存在退出
			preserve_contact(&con);
			delet_contact(&con);
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}