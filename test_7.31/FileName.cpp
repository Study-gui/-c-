 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//һ��������ֻ���������ֳ���һ�Σ��������˳������Σ��ҳ�����������
//ͨ����������
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
//ͨ�������Ƶ��㷨
//void find_dog(int arr[], int sz, int* dog1, int* dog2)
//{
//	//ɸѡ�����麬��һ��λ���ֵĲ���
//	int i = 0, j = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	int pos = 0;
//	for (pos = 0; pos < 32; pos++)
//	{
//		//�õ������������Ľ��
//		if ((ret >> pos) & 1 == 1)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{//�õ�������һ����������λ����������ͬ��λ
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			//����һ���������Ľ�������Ǹ���
//			*dog1 ^= arr[i];
//		}
//		else {
//			//�õ��ڶ�����
//			*dog2 ^= arr[i];
//		}
//	}
//}
//int main()
//{
//	//������ͬ�����������Ϊ��
//  int arr[10] = { 1,2,2,3,3,4,4,5,5,9 };
//  int sz = sizeof(arr) / sizeof(arr[0]);
//  int dog1 = 0, dog2 = 0;
//  find_dog(arr, sz, &dog1, &dog2);
//  printf("%d %d", dog1, dog2);
//	return 0;
//}
//ģ��strncpy������ʵ��
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
//ģ��ʵ��strncat�����Ĺ���
//char* my_strncat(char* arr, const char* brr, int n)
//{
//	int i = 0;
//	int sz = strlen(arr);
//	for (i = 0; i < n; i++)
//	{
//		*(arr + sz + i) = *(brr + i);
//	}
//	//ע��ĵ���׷�Ӻ������ΪҪ����\0��ֵ
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
//ģ��ʵ��atoi�����Ĺ���,atoi�Ĺ��ܾ��ǽ��ַ�����ֵת��Ϊ����ֵ���������ɶ�ȡ�ַ�������
//int main()
//{
//	 char arr[] = "1234";
//	int br = atoi(arr);
//	printf("%d", br);
//
//	return 0;
//}
int my_atoi(const char* arr)
{
	int i = 0;
	int sz = 1;//�ж�������
	int ret = 0;
	if (*arr == '\0')
	{
		return 0;
	}
	if (*arr == '-')
	{
		sz = -1;
	}
	while (*arr == ' ')
	{
			arr++;
	}
	while(*(arr+i)!='\0')
	{
		ret = ret * 10 + sz*(*arr-'0');
		arr++;
	}
	return (int)ret;
}
int main()
{
	char arr[]="-12345";
	//gets_s(arr);
	int b = my_atoi(arr);
	int a = atoi(arr);
	printf("%d\n", b);
	printf("%d", a);
	return 0;
}