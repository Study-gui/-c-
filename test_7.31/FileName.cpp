 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//一个数组中只有两个数字出现一次，其他都了出现两次，找出这两个数字
//通过排序做法
//int main()
//{
//	int arr[10] = { 1,2,2,3,3,4,4,5,5,9 };
//	int i = 0, j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int ret = 0;
//		for (j = 0; j < 10; j++)
//		{
//			if (arr[i] == arr[j]&&i!=j)
//			{
//				ret = 1;
//			}
//		}
//		if (ret == 0)
//		{
//			printf("%d ", arr[i]);
//		}
//
//	}
//	return 0;
//}
//通过二进制的算法
//void find_dog(int arr[], int sz, int* dog1, int* dog2)
//{
//	//筛选出两组含有一个位数字的部分
//	int i = 0, j = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	int pos = 0;
//	for (pos = 0; pos < 32; pos++)
//	{
//		//得到整个数组异或的结果
//		if ((ret >> pos) & 1 == 1)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{//得到两个不一样的数的那位二进制数不同的位
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			//进行一组整体异或的结果就是那个数
//			*dog1 ^= arr[i];
//		}
//		else {
//			//得到第二个数
//			*dog2 ^= arr[i];
//		}
//	}
//}
//int main()
//{
//	//两个相同的数字异或结果为零
//  int arr[10] = { 1,2,2,3,3,4,4,5,5,9 };
//  int sz = sizeof(arr) / sizeof(arr[0]);
//  int dog1 = 0, dog2 = 0;
//  find_dog(arr, sz, &dog1, &dog2);
//  printf("%d %d", dog1, dog2);
//	return 0;
//}
//模拟strncpy函数的实现
//char* my_strncpy(char* arr, const char* brr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		*(arr + i) = *(brr + i);
//	}
//	return arr;
//}
//int main()
//{
//	char arr[100] ;
//	gets_s(arr);
//	char brr[100];
//	gets_s(brr);
//	int n = 0;
//	scanf("%d", &n);
//	my_strncpy(arr, brr, n);
//	printf("%s", arr);
//	return 0;
//}
//模拟实现strncat函数的功能
//char* my_strncat(char* arr, const char* brr, int n)
//{
//	int i = 0;
//	int sz = strlen(arr);
//	for (i = 0; i < n; i++)
//	{
//		*(arr + sz + i) = *(brr + i);
//	}
//	//注意的点是追加后最后以为要进行\0赋值
//	*(arr + sz + n) = '\0';
//	return arr;
//}
//int main()
//{
//	char arr[100];
//	gets_s(arr);
//	char brr[100];
//	gets_s(brr);
//	int n = 0;
//	scanf("%d", &n);
//	my_strncat(arr, brr, n);
//	printf("%s\n", arr);
//	return 0;
//}
//模拟实现atoi函数的功能,atoi的功能就是将字符串的值转化为整数值，遇到不可读取字符返回零
//int main()
//{
//	 char arr[] = "1234";
//	int br = atoi(arr);
//	printf("%d", br);
//
//	return 0;
//}
#include<assert.h>
#include<ctype.h>
enum  str
{
	count1,
	count2
} sta = count2;//判断字符串是否是合法的转换
int my_atoi(const char* arr)
{
	assert(arr);
	int sz = 1;//判断正负号
	long long  ret = 0;
	if (*arr == '\0')
	{
		return 0;
	}
	while (*arr == ' ')//也可以使用函数isspace判断是非为空格
	{
		arr++;
	}
	if (*arr == '-')
	{
		sz = -1;
		arr++;
	}
	else if (*arr == '+')
	{
		sz = 1;
		arr++;
	}
	
	while(*(arr)!='\0')
	{
		if (isdigit(*arr))
		{
			ret = ret * 10 + sz * (*arr - '0');
			arr++;
		}
		else
		{
			return (int)ret;
		}
		if (ret > INT_MAX || ret < INT_MIN)//判断是否大于和小于整形最大值和最小值
		{
			return 0;
		}
		
	}
	if (*arr == '\0')
	{
		sta = count1;
	}
	return (int)ret;
}
int main()
{
	char arr[]="12345";
	//gets_s(arr);
	int b = my_atoi(arr);
	if (sta == count2)
	{
		printf("非法转换：%d", b);
	}
	else
	{
		printf("合理转换：%d", b);
	}
	return 0;
}