 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//请实现无重复数字的升序数组的二分查找
//给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 - 1
//int my_shuzu(int nums[], int target, int sz)
//{
//    int left = 0;
//    int right =sz - 1;
//    int b = (left + right) / 2;
//    while (left <= right)
//    {
//        if (target > nums[b])
//        {
//            left = b + 1;
//        }
//        else if (target < nums[b])
//        {
//            right = b - 1;
//        }
//        else
//        {
//            return b;
//        }
//        b = (left + right) / 2;
//    }
//    return -1;
//}
//int main()
//{
//    int nums[6] = { 0 };
//    int target = 0;
//    int sz = sizeof(nums) / sizeof(nums[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        scanf("%d", nums + i);
//    }
//    scanf("%d", &target);
//    int ret = my_shuzu(nums, target, sz);
//    printf("%d ", ret);
//    return 0;
//}
//在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
//判断数组中是否含有该整数,有则返回1，没有则返回0
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  * 
//  * @param target int整型 
//  * @param array int整型二维数组 
//  * @param arrayRowLen int array数组行数
//  * @param arrayColLen int* array数组列数
//  * @return bool布尔型
//  */
// bool Find(int target, int** array, int arrayRowLen, int* arrayColLen ) {
//     // write code here
// }
bool Find(int target, int** array, int arrayRowLen, int* arrayColLen)
{
    int i = 0, j = 0;
    for (i = 0; i < arrayRowLen; i++)
    {
        for (j = 0; j < (*arrayColLen); j++)
        {
            if (target == array[i][j])
            {
                return true;
            }
        }
    }
    return false;
}