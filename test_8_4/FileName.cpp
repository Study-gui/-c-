 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，
// 返回任何一个所在位置即可。
//峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @return int整型
 */
//int findPeakElement(int* nums, int numsLen) {
//    int i = 0;
//    for (i = 1; i < numsLen; i++)
//    {
//        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//        {
//            return i;
//        }
//    }
//    if (nums[0] > nums[1])
//        return 0;
//    else if (nums[numsLen - 1] > nums[numsLen - 2])
//        return numsLen - 1;
//    else
//        return -1;
//}
//有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，
//变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @return int整型
 */
int minNumberInRotateArray(int* nums, int numsLen) {
    int i = 0;
    for (i = 0; i < numsLen; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return nums[i + 1];//如果前面你后面打i+1为旋转前首元素
        }
    }
    return nums[0];//无返回说明没有旋转
}