 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//输入一个整数序列，判断是否是有序序列，有序，
//指序列中的整数从小到大排序或者从大到小排序(相同元素也视为有序)。
//输出为一行，如果序列有序输出sorted，否则输出unsorted。
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[50] = { 0 };
//    int i = 0;
//    int flag = 1;//记录说明数组从小到大的次数
//    int ret = 1;//记录说明数组从大到小的次数
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
//字符串左旋
//实现一个函数，可以左旋字符串中的k个字符
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
//杨氏矩阵
//在矩阵中找到输入的k的值，并返回下标
//以为杨氏矩阵是每行从左到右递增，每列从上到下递增，所以跟第一行最大的比
//2，还可以通过结构体进行返回下标
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
//            *pa = x;//通过地址改变下标
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
//        printf("找到了,下标为 %d %d\n", a, b);
//    }
//    else
//    {
//        printf("没找到");
//    }
//
//    return 0;
//}
//实现qsort函数的功能,判断升序的函数
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