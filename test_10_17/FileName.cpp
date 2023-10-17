 #define _CRT_SECURE_NO_WARNINGS

//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。



//bool canJump(int* nums, int numsSize) {
//    //本题思路：就是下标加上自己能走步子，一直维持最大的步子，判断能不能在走到不能走了能否到最后一位
//    if (numsSize == 1)
//    {
//        return true;
//    }
//    int k = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i <= k)//判断是否能向前走
//            k = fmax(i + nums[i], k);//求的最大能走步子
//        if (k >= numsSize - 1)//判断是否能到最后一位
//        {
//            return true;
//        }
//    }
//    return false;
//}


//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

//每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 
//nums[i + j] 处:

//0 <= j <= nums[i] i + j < n返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
int jump(int* nums, int numsSize) {
    //本题思路：也是利用维持最大步子，找到最先到最后一位的数，用计数位进行记录
    if (numsSize == 1)
    {
        return 0;
    }
    if (numsSize == 2)
    {
        return 1;
    }
    int cur = 0;
    int next = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        next = (i + nums[i] > next ? (i + nums[i]) : next);//找到最大的步子
        if (i == cur)//到了一步的极限，走一下步
        {
            count++;
            cur = next;
            if (next >= numsSize - 1)//判断是否能到最后一位
            {
                break;
            }
        }

    }
    return count;
}