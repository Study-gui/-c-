 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//编写一个宏，实现一个整数的二进制偶数位和奇数位进行交换
//#define swap_int(n)  (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))
//int main()
//{
//	//规定最低位下标位0
//	//实现交换，要进行得到偶数位和奇数位,再把偶数位和奇数位进行相加
//	//得到偶数位：与一个偶数位为1奇数位为0的数相与及能得到，即0x55555555
//	//得到奇数位：与一个偶数位为0奇数位为1的数相与及能得到，即0xaaaaaaaa
//	int n = 0;
//	scanf("%d", &n);
//	//swap_int(n);
//	printf("%d", swap_int(n));
//	return 0;
//}
//求一个数n每次只能n-1或者n+1，问要经过多少步变成斐波那契数
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
//给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
//现在给你一个数N求最少需要多少步可以变为Fibonacci数
#include<math.h>
//主要运用函数abs求绝对值，和确定范围相比较来做
int main()
{
	int n = 0;
	int a = 0;
	int b = 1;
	int c = a + b;
	scanf("%d", &n);
	while (1)
	{
		if (n == b)
		{
			printf("0\n");
			break;
		}
		else if (n < b)
		{
			if (abs(b - n) < abs(a - n))
			{
				printf("%d\n", abs(b - n));
				break;
			}
			else {
				printf("%d\n", abs(a - n));
				break;
			}
		}
		else {
			a = b;
			b = c;
			c = a + b;
		}
	}

	return 0;
}