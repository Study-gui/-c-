 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int cmp(const void* x1, const void* x2)
//{
//	return *(int*)x1 - *(int*)x2;
//}
//
//int main()
//{
//	int arr[] = { 9,4,6,7,3,5,2,1,8 };
//	qsort(arr, 9, sizeof(int), cmp);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//��������
//С����һ���Ȱ��ռ���ߵ�С���ӣ���ӵ��n����ͬ����ߡ�
//���죬���� n2����߰��ո߶�˳��Ӱ����߰ڷ����˴�̨�ϣ�Ȼ����ϣ������Щ��߷ֳ�k���Σ�ʹ�����зֶεļ���֮�;�����С��
//������˵������Ҫ��һ������Ϊn�����з�Ϊ �Σ����Ƕ���G
//Ϊ��֮���ֶεļ����Ҫ��С��֮��G��
//���ܰ���С���ҵ���Сֵ�Ƕ�����


#include <stdio.h>
#include <stdlib.h>
//typedef long long ll;
int cmp(const void* x1, const void* x2)
{
    return *(int*)x1 - *(int*)x2;
}
int main(int argc, char* argv[])
{//����˼·���������ð�ÿһ�����֮��Ĳ�ֵ���������Ȼ�����������Ϊn������n-1����ֵ
//��Ϊ��ֵ����������֮��ģ����൱��ȥ��k-1������ֵ��������Ӿ�����С��ֵ�ĺ�
  // ���ڴ��������Ĵ���
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int brr[n - 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        brr[i] = arr[i + 1] - arr[i];
    }
    qsort(brr, n - 1, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < n - k; i++)
    {
        sum += brr[i];
    }
    printf("%d", sum);
    return 0;
}