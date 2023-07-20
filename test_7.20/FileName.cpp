 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//请实现有重复数字的升序数组的二分查找
//给定一个 元素有序的（升序）长度为n的整型数组 nums 和一个目标值 target  ，
//写一个函数搜索 nums 中的第一个出现的target，如果目标值存在返回下标，否则返回 -1
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 如果目标值存在返回下标，否则返回 -1
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @param target int整型
 * @return int整型
 */
//int search(int* nums, int numsLen, int target) {
//    int ret = 0;
//    for (ret = 0; ret < numsLen; ret++)
//    {
//        if (*nums == NULL)
//        {
//            break;
//        }
//        if (*(nums + ret) == target)
//        {
//            return ret;
//        }
//    }
//    return -1;
//}
//模拟实现strcpy函数功能
#include<assert.h>
//char* my_strcpy(char* arr2, const char* arr1)
//{
//    assert(arr2);
//    assert(arr1);
//    char* ret = arr2;
//    while (*arr2++ = *arr1++)//即赋值\0又能判断
//    {
//      ;
//    }
//    return ret;
//}
// int main()
// {
//        char arr1[] = "abcdefg";
//        char arr2[20] = { 0 };
//        my_strcpy(arr2, arr1);
//        printf("%s ", arr2);
//        return 0;
//}
//模拟实现strcat函数功能
//char* my_strcat(char* arr1, const char* arr)
//{
//    assert(arr1 && arr);
//    char* ret = arr1;
//    while((*arr1))
//    {
//        arr1++;
//    }
//    while (*arr1++ = *arr++)
//    {
//        ;
//    }
//    return ret;
//}
//int main()
//{
//    char arr1[20] = "hello ";
//    my_strcat(arr1, "wolrd");
//    printf("%s\n", arr1);
//    return 0;
//}
//模拟实现strcmp函数功能
int my_strcmp(const char* arr1, const char* arr2)
{
    assert(arr1 && arr2);
    while (*arr1 == *arr2)
    {
        if (*arr1 == '\0')
        {
            return 0;
        }
        arr1++;
        arr2++;
    }
    return (*arr1 - *arr2);
}
int main()
{
    char arr1[] = "abcddf";
    char arr2[] = "abccccf";
    int ret = my_strcmp(arr1, arr2);
    if (ret > 0)
    {
        printf("arr1>arr2");
    }
    else if (ret < 0)
    {
        printf("arr1<arr2");
    }
    else
    {
        printf("arr1==arr2");
    }
    return 0;
}
