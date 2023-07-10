 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//有一头母牛，它每年年初生一头母牛。每头小母牛从第四个年头开始，
//每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？多组输入，输入0结束程序
//采用的递归的方式解决
//第一年 1头，第二年 2头，第三年 3头，第四年 4头，我五年 6头，第七年 9头
//创建计算奶牛的函数
//int is_cow(int n)
//{
//	if (n < 5)
//	{
//		return n;
//	}
//	else
//	{
//		return is_cow(n - 1) + is_cow(n - 3);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			break;
//		}
//		else
//		{
//			ret = is_cow(n);
//			printf("%d\n", ret);
//		}
//
//	}
//
//	return 0;
//}
//字符串的输入输出处理。
//输入格式
//第一行是一个正整数N，最大为100。之后是多行字符串（行数大于N）,每一行字符串可能含有空格，
// 字符数不超过1000。
//输出格式
//先将输入中的前N行字符串（可能含有空格）原样输出，再将余下的字符串（不含有空格）
//以空格或回车分割依次按行输出。每行输出之间输出一个空行。

int main()
{
    char str[1001] = {0};
    int n;
    scanf("%d", &n);
    getchar();                    //吃掉回车
    for (int i = 0; i < n; i++) {    //输出前N个字符串
        gets_s(str);
        puts(str);
        printf("\n");
    }
    while (~scanf("%s", str)) {        //输出剩余字符串
        printf("%s\n", str);
        printf("\n");
    }
    return 0;
}