 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��һ�������洢���ڴ��ж�������һ�ĸ���
//��������ĸ���
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = 0;
//	int i = 0;
//	for(i=0;i<32;i++)
//	{
//		if (((a>>i)&1)==1)
//		{
//			ret++;
//		}
//	}
//	printf("%d \n", ret);
//	return 0;
//}
//�Ƚ��������Ķ����ƣ���ͬ��λ�ж��٣������
//int main()
//{
//	int m = 0, n = 0;
//	int i = 0;
//	int ret = 0;
//	scanf("%d %d", &m, &n);
//	for (i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			ret++;
//		}
//	}
//	printf("%d", ret);
//	return 0;
//}
//����һ�����֣��ֱ��ӡ�����Ƶ�����λ��ż��λ
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	//��ߵ�����λ��31λ������Ҫ�ƶ�15��
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	printf("\n");
//	//���ż��λ��32���ƶ�15��
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	return 0;
//}