 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//将数组逆序排放（函数做法）
//void reverse(char* string)
//{
//	char tmp = *string;
//	int len = strlen(string);
//	*string = *(string+len - 1);
//	*(string+len- 1) = '\0';
//	if (strlen(string + 1) >= 2)
//		reverse(string + 1);
//	* (string+len- 1) = tmp;
//
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
// 将数组逆序排放（递归算法）
//void fun(char arr[], int left, int right)
//{
//	if(left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		fun(arr , left+1, right-1);
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdefg";
//	int left = 0;
//	int right = 0;
//	right = strlen(arr) - 1;
//	fun(arr, left, right);
//	printf("%s", arr);
//
//	return 0;
//}
//将数组a的内容和数组b的内容交换（数组一样大）
//int main()
//{
//	int a[] = { 1,3,5,7 };
//	int b[] = { 2,4,6,8 };
//	int i = 0;
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}
//创建一个整型数组，对数组进行以下操作
// 创建一个函数init对数组进行初始化
// 创建一个函数print对数组进行打印
// 创建一个函数reverse对数组进行逆序排列
//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i=0;i<sz;i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void resever(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);//1,2,3,4,5
//	resever(arr, sz);//5,4,3,2,1
//	print(arr, sz);
//	init(arr, sz);//0,0,0,0,0
//	print(arr, sz);
//	return 0;
//}

////求一个整数存储在内存中二进制中一的个数
////就是求补码的个数
////int main()
////{
////	int a = 0;
////	scanf("%d", &a);
////	int ret = 0;
////	int i = 0;
////	for(i=0;i<32;i++)
////	{
////		if (((a>>i)&1)==1)
////		{
////			ret++;
////		}
////	}
////	printf("%d \n", ret);
////	return 0;
////}
////比较两个数的二进制，不同的位有多少，并输出
////int main()
////{
////	int m = 0, n = 0;
////	int ret = 0;
////	scanf("%d %d", &m, &n);
////	int i = 0;
////	int count = 0;
////	//运用异或的方法，相同为0，不同为1
////	ret = m ^ n;
////	for (i = 0; i < 32; i++)
////	{
////		if (((ret >> i)&1) == 1)
////		{
////			count++;
////		}
////		printf("%d", count);
////	}
////	return 0;
////}
////int main()
////{
////	int m = 0, n = 0;
////	int i = 0;
////	int ret = 0;
////	scanf("%d %d", &m, &n);
////	for (i = 0; i < 32; i++)
////	{
////		if (((m >> i) & 1) != ((n >> i) & 1))
////		{
////			ret++;
////		}
////	}
////	printf("%d", ret);
////	return 0;
////}
////输入一个数字，分别打印二进制的奇数位和偶数位
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
//int main()
//{
//	int a = 0x654321;
//	char   b = (char)a;
//	printf("%d", a);
//	printf("\n%p\n", &a);
//	printf("%0x\n", b);
//}