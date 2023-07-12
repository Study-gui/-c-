 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//求一个整数存储在内存中二进制中一的个数
//就是求补码的个数
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
//比较两个数的二进制，不同的位有多少，并输出
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
//输入一个数字，分别打印二进制的奇数位和偶数位
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	//最高的奇数位是31位，所以要移动15次
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	printf("\n");
//	//最高偶数位是32，移动15次
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	return 0;
//}