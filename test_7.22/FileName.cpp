 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ���������У��ж��Ƿ����������У�����
//ָ�����е�������С����������ߴӴ�С����(��ͬԪ��Ҳ��Ϊ����)��
//���Ϊһ�У���������������sorted���������unsorted��
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[50] = { 0 };
//    int i = 0;
//    int flag = 1;//��¼˵�������С����Ĵ���
//    int ret = 1;//��¼˵������Ӵ�С�Ĵ���
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    for (i = 1; i < n; i++)
//    {
//        if (arr[i - 1] <= arr[i])
//        {
//            flag++;
//        }
//        else if (arr[i - 1] >= arr[i])
//        {
//            ret++;
//        }
//    }
//    if (flag == n || ret == n)
//    {
//        printf("sorted");
//    }
//    else {
//        printf("unsorted");
//    }
//
//    return 0;
//}
//�ַ�������
//ʵ��һ�����������������ַ����е�k���ַ�
//void is_zuoxuan(char* arr, int k,int sz)
//{
//    int i = 0;
//    int j = 0;
//    k %= sz;
//    for (i = 0; i < k; i++)
//    {
//        char ret =*arr;
//        for (j = 0; j<sz-1; j++)
//        {
//         *(arr + j) = *(arr + j + 1);
//        }
//        *(arr+sz-1) = ret;
//    }
//}
//int main()
//{
//    int k = 0;
//    char arr[10] ="abcdef";
//    scanf("%d", &k);
//    int sz = strlen(arr);
//    is_zuoxuan(arr, k,sz);
//    printf("%s ", arr);
//    return 0;
//}
//���Ͼ���
//�ھ������ҵ������k��ֵ���������±�
//��Ϊ���Ͼ�����ÿ�д����ҵ�����ÿ�д��ϵ��µ��������Ը���һ�����ı�
//2��������ͨ���ṹ����з����±�
//int is_find(int arr[3][3], int* pa, int* pb, int k)
//{
//    int x = 0;
//    int y = *pb - 1;
//    while (x <= 2 && y >= 0)
//    {
//        if (k < arr[x][y])
//        {
//            y--;
//        }
//        else if (k > arr[x][y])
//        {
//            x++;
//        }
//        else
//        {
//            *pa = x;//ͨ����ַ�ı��±�
//            *pb = y;//
//            return 1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//    int a = 3;
//    int b = 3;
//    int k = 0;
//    scanf("%d", &k);
//    int ret=is_find(arr, &a, &b, k);
//    if (ret == 1)
//    {
//        printf("�ҵ���,�±�Ϊ %d %d\n", a, b);
//    }
//    else
//    {
//        printf("û�ҵ�");
//    }
//
//    return 0;
//}
//ʵ��qsort�����Ĺ���,�ж�����ĺ���
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e);
}
int main()
{
    int arr[10] = { 0 };
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort((void*)arr, sz, sizeof(arr[0]), cmp_int);
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}