 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//�����������ŷţ�����������
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
// �����������ŷţ��ݹ��㷨��
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
//������a�����ݺ�����b�����ݽ���������һ����
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
//����һ���������飬������������²���
// ����һ������init��������г�ʼ��
// ����һ������print��������д�ӡ
// ����һ������reverse�����������������
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

////��һ�������洢���ڴ��ж�������һ�ĸ���
////��������ĸ���
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
////�Ƚ��������Ķ����ƣ���ͬ��λ�ж��٣������
////int main()
////{
////	int m = 0, n = 0;
////	int ret = 0;
////	scanf("%d %d", &m, &n);
////	int i = 0;
////	int count = 0;
////	//�������ķ�������ͬΪ0����ͬΪ1
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
////����һ�����֣��ֱ��ӡ�����Ƶ�����λ��ż��λ
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
//int main()
//{
//	int a = 0x654321;
//	char   b = (char)a;
//	printf("%d", a);
//	printf("\n%p\n", &a);
//	printf("%0x\n", b);
//}