 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��������ż��λ�ã�ʹ�������е�������λ��ż��ǰ��
//void is_arr_enve(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	//����������ż���������������������н���
//	while (left < right)
//	{
//		//����ż��ͣ����
//		while ((left<right)&&arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//��������ͣ����
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right++;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right++;
//		}
//	}
//}
//int main()
//{
//	//����
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//����
//	is_arr_enve(arr, sz);
//	//���
//	for(i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//���������������е����У����������кϲ�Ϊһ���������в����
#include <stdio.h>
int main()
{
    //�������������һһ�ȽϽ������
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    int arr[n];
    int brr[m];
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d ", &brr[i]);
    }
    int j = 0;
    int a = 0;

    while (j < n && a < m)
    {
        if (arr[j] < brr[a])
        {
            printf("%d ", arr[j]);
            j++;
        }
        else {
            printf("%d ", brr[a]);
            a++;
        }
    }
    if (j < n)
    {
        for (; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
    }
    else {
        for (; a < m; a++)
        {
            printf("%d ", brr[a]);
        }
    }
    return 0;
}