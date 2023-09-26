 #define _CRT_SECURE_NO_WARNINGS

//给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//输入：nums = [10,5,2,6], k = 100
//输出：8
//解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2], 、[6]、[10, 5]、[5, 2]、[2, 6]、[5, 2, 6]。
//需要注意的是[10, 5, 2] 并不是乘积小于 100 的子数组

//解法一：。
//int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
//    //本题思路：通过两次遍历数组滑动窗口，来进行计数
//    int left = 0;
//    int right = 0;
//    int count = 0;
//    for (int left = 0; left < numsSize; left++)
//    {
//        int sum = nums[left];
//        right = left + 1;
//        if (sum < k)
//        {
//            count++;
//            while (right < numsSize)
//            {
//                sum *= nums[right];
//                if (sum < k)
//                {
//                    count++;
//                }
//                else {
//                    break;
//                }
//                right++;
//            }
//        }
//    }
//    return count;
//}

//解法二：
// int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
     //本体思路：暴力解法不同的是采用动态滑动窗口，时间复杂度为O（N）
//if (k <= 1)
//{
//    return 0;
//}
//int left = 0;
//int right = 0;
//int count = 0;
//int sum = 1;
//for (right = 0; right < numsSize; right++)
//{
//    sum *= nums[right];
//    while (sum >= k && left <= right)//利用滑动窗口，left先前走找到最长序列
//    {
//        sum /= nums[left];
//        left++;
//    }
//    count += right - left + 1;//left到right位置的所有情况
//}
//return count;
// }
