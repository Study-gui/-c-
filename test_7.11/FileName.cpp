 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//������̨�ף�һ��ֻ����һ����������̨���м�������
//����һ����n��0<=n<=30)
//����ж���������
// 
// 
//2�� 2�֣�3�� 3�֣� 4�� 5�� ��5��  8�֣�  
//int is_stps(int n)
//{
//    if (n < 4)
//    {
//        return n;
//    }
//    else
//    {
//        return is_stps(n - 1) + is_stps(n - 2);
//    }
//}
//int main()
//{
//    int n = 0;
//    int ret = 0;
//    scanf("%d", &n);
//    if (n >= 0 && n <= 30)
//    {
//        ret = is_stps(n);
//        printf("%d\n", ret);
//    }
//    return 0;
//}
#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int i = 0;
//    int b = 0;
//    int arr[50] = { 0 };
//    scanf("%d", &a);
//    getchar();
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d ", &arr[i]);
//
//    } 
//    scanf("%d", &b);
//    for (i = 0; i < a; i++)
//    {
//        if (arr[i] != b)
//        {
//            printf("%d ", arr[i]);
// 
//        }
//    }
//    return 0;
//}