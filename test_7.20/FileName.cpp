 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��ʵ�����ظ����ֵ���������Ķ��ֲ���
//����һ�� Ԫ������ģ����򣩳���Ϊn���������� nums ��һ��Ŀ��ֵ target  ��
//дһ���������� nums �еĵ�һ�����ֵ�target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
 * @param nums int����һά����
 * @param numsLen int nums���鳤��
 * @param target int����
 * @return int����
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
//ģ��ʵ��strcpy��������
#include<assert.h>
//char* my_strcpy(char* arr2, const char* arr1)
//{
//    assert(arr2);
//    assert(arr1);
//    char* ret = arr2;
//    while (*arr2++ = *arr1++)//����ֵ\0�����ж�
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
//ģ��ʵ��strcat��������
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
//ģ��ʵ��strcmp��������
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
