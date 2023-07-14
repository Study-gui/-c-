 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//求sn=a+aa+aaa+aaaa+aaaaa...前n项的和
//*int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sn = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sn += ret;
//	}
//	printf("%d ", sn);
//	return *
//}
//求一个1到10000之间的水仙花数
//例如153=1^3+5^3+5^3等于n位数的n次方的和
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10001; i++)
//	{
//		//判断i有几位数
//		int a = 0;
//		int ret =i;
//		int sum = 0;
//		while (ret)
//		{
//			a++;
//			ret /= 10;
//		}
//		//得到i的每一位
//		// 1234；
//		//计算n位数的和
//		ret = i;
//		while (ret)
//		{
//			sum += pow((ret  % 10), a);
//			ret /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//喝汽水问题，一瓶汽水一元钱，两个空瓶可以换一瓶汽水，问20块钱可以喝多少汽水
int is_qishui(int n)
{
	int ret = 0;
	while (n >= 2)
	{
		ret++;
		n--;
	}
	return ret;
}
int main()
{
	//n为空瓶数
	int n = 20;
	int tmp = is_qishui(n);
	printf("%d", tmp + 20);
	return 0;
}