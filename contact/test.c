#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
//ʵ��ͨѶ¼
//1����������
//2�������Զ��������˵���Ϣ
//3����ͨѶ¼���г�ʼ��
//4, add����ͨѶ¼����
//5��show��ͨѶ¼���д�ӡ
//6,delet��ͨѶ¼����ɾ��
//7,seek������ϵ��
//8,seq�޸���ϵ��
//9,ait������ϵ��
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
		printf("�����룺");
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
		case 0://�Ƴ�����
			//�ȱ������˳�
			preserve_contact(&con);
			delet_contact(&con);
			printf("�˳�\n");
			break;
		default:
			printf("�����������������");
			break;
		}
	} while (input);
	return 0;
}