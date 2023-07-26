 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//小乐乐最近在课上学习了如何求两个正整数的最大公约数与最小公倍数，但是他竟然不会求两个正整数的
//最大公约数与最小公倍数之和请你帮助他解决这个问题。
//1,暴力求解,通过最大公约数和最小公倍数的性质来计算
//int main()
//{
//	long n = 0, m = 0;
//	scanf("%ld %ld", &n, &m);
//	long min = n < m ? n : m;
//	long max = n > m ? n : m;
//	int i = min;
//	int j = max;
//	while (1)
//	{
//		if (n % min == 0 && m % min==0)
//		{
//			break;
//		}
//		min--;
//	}
//	while (1)
//	{
//		if (max % n == 0 && max % m == 0)
//		{
//			break;
//		}
//		max++;
//	}
//	printf("%ld\n", min + max);
//	return 0;
//}
//利用辗转相除法
int main()
{
	long n = 0, m = 0;
	scanf("%ld %ld", &n, &m);
	long i = n, j = m;
	long r = 0;
	while (r = i % j)
	{
		i = j;
		j = r;
	}
	//最小公倍数等于两数相乘除以最大公约数
	long min = (n * m) / j;
	printf("%ld\n", min + j);
	return 0;
}