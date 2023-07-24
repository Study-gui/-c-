#define _CRT_SECURE_NO_WARNINGS
// 请实现无重复数字的升序数组的二分查找
//给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 
//target，如果目标值存在返回下标（下标从 0 开始），否则返回 - 1
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @param target int整型
 * @return int整型
 */
//#include<assert.h>
//int search(int* nums, int numsLen, int target) {
//    assert(nums);
//    int left = 0;
//    int right = numsLen - 1;
//    int mid = (left + right) / 2;
//    while (left <= right)
//    {
//        if (target > nums[mid])
//        {
//            left = mid + 1;
//            mid = (left + right) / 2;
//        }
//        else if (target < nums[mid])
//        {
//            right = mid - 1;
//            mid = (left + right) / 2;
//        }
//        else {
//            return mid;
//        }
//    }
//    return -1;
//}
//给定一个长度为 n 的数组，请你编写一个函数，返回该数组按升序排序后的结果。
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 将给定数组排序
 * @param arr int整型一维数组 待排序的数组
 * @param arrLen int arr数组长度
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
#include<assert.h>
int* MySort(int* arr, int arrLen, int* returnSize) {
    int i = 0;
    assert(arr);
    int j = 0;
    *returnSize = arrLen;
    if (arrLen > 1)
    {
        for (i = 0; i < arrLen - 1; i++)
        {
            for (j = 0; j < arrLen - 1 - i; j++)
            {
                if (arr[j + 1] < arr[j])
                {
                    int tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    else {
        return arr;
    }
    return arr;
}