 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
求两个数的最小公倍数,并输出
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int ret = (a > b ? a : b);
	while (1)
	{
		if (ret%a == 0 && ret % b == 0)
		{
			printf("%d ", ret);
			break;
		}
		ret++;
	}
	return 0;
}
最优解
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int i = 1;
	while ((a*i)%b)
	{
		i++;
	}
	printf("%d ", a * i);
	return 0;
}
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
1将整个字符串逆序 2再将每个单词逆序
 #include <stdio.h>
#include <string.h>

void ReverseString(char* left, char* right)//反转字符串
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
int main()
{
    char str[100] = "0";
    gets_s(str);
    int length = strlen(str);
    将字符串整体翻转
    ReverseString(str, str + length - 1);
    char* start = str;
    将字符串中的每个单词翻转
    while (*start)
    {
        char* end = start;
        while (*end != ' ' && *end)//寻找空格或'\0'
        {
            end++;
        }
        ReverseString(start, end - 1);
        if (*end == ' ')
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    printf("%s", str);
    return 0;
}