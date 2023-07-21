 #define _CRT_SECURE_NO_WARNINGS
//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。如果某一位是奇数，
//就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
#include <stdio.h>
//暴力求解
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int j = 0;
//    int ret = 0;
//    int a = 1;
//    while (n)
//    {
//        i = n % 10;
//        n = n / 10;
//        if (i % 2 == 0)
//        {
//            i = 0;
//        }
//        else
//        {
//            i = 1;
//        }
//        ret += i * a;
//        a = a * 10;
//    }
//    printf("%d", ret);
//    return 0;
//}
//递归求法
//int is_shuzi(int n)
//{
//	int a = n % 10;
//	int b = n / 10;
//	int c = a % 2;
//	if (n)
//	{
//		return 10 * is_shuzi(n) + c;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int a = is_shuzi(n);
//	printf("%d", a);
//	return 0;
}
//模拟实现strstr函数功能
#include<assert.h>
//char* my_strstr(const char* arr1, const char* arr2)
//{
//    assert(arr1 && arr2);
//    const char* p =  arr1;//记住开始找的起始位置
//    const char* s1 = arr1;//设置被找的变量
//    const char* s2 = arr2;//设置找的变量
//    while (*p)
//    {
//        s1 = p;
//        s2 = arr2;
//        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//        {
//            return (char*)p;
//        }
//        p++;
//    }
//    return NULL;
//
//}
//int main()
//{
//    char arr1[] = "abbbcef";
//    char arr2[] = "bbc";
//    char* ret = my_strstr(arr1, arr2);
//    if (ret == NULL)
//    {
//        printf("没找到\n");
//    }
//    else
//        printf("%s ", ret);
//    return 0;
//}
//模拟实现memcpy函数功能
//void* my_memcpy(void* arr2, const void* arr1, size_t num)
//{
//    assert(arr2 && arr1);
//    void* ret = arr2;
//    while (num--)
//    {
//        *(char*)arr2 = *(char*)arr1;
//       arr2=(char*)arr2+1;
//        arr1=(char*)arr1+1;
//    }
//    return ret;
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7 };
//    int arr2[10] = { 0 };
//    my_memcpy(arr2, arr1, 28);
//   
//    return 0;
//}
//模拟实现memmove函数功能
void* my_memmove(void* arr2, const void* arr1, size_t num)
{
    assert(arr2 && arr1);
    void* ret = arr2;
    if (arr2 < arr1)
    {
        //被拷贝起始位置小于拷贝起始位置
        //从前往后拷贝
        while (num--)
        {
            *(char*)arr2 = *(char*)arr1;
            arr2 = (char*)arr2 + 1;
            arr1 = (char*)arr1 + 1;
        }
    }
    else
    {
        //被拷贝起始位置大于拷贝起始位置
        //从后往前拷贝
        while (num--)
        {
            *((char*)arr2 + num) = *((char*)arr1 + num);
        }
    }
    return ret;
}
int main()
{
    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    /*  int arr2[10] = { 0 };*/
    my_memmove(arr1, arr1 + 2, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}