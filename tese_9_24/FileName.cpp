 #define _CRT_SECURE_NO_WARNINGS
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
int min(int x, int y)
{
    return x > y ? y : x;
}
//int maxArea(int* height, int heightSize) {
//    //本体思路：就是利用双指针进行比遍历数组，找到最大值
//    int i = 0;
//    int j = heightSize - 1;
//    int max = 0;
//    int min = 0;
//    int ret = 0;
//    while (i < j)
//    {
//        if (height[i] < height[j])
//        {
//            min = height[i];
//            i++;
//        }
//        else {
//            min = height[j];
//            j--;
//        }
//        ret = (j - i + 1) * min;
//        if (max < ret)
//        {
//            max = ret;
//        }
//    }
//    return max;
//}

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是
//相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
int rob(int* nums, int numsSize) {
    //本题思路：本题关键就是充分理解dp ，转化为两个问题
    //偷不偷这间房子，取决于当前房子加i-2建房子和前i-1间房子谁大
//    int dp[101];//偷房子金额之和
//    sum[0] = nums[0];//
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (i == 1)
//        {
//            dp[i] = fmax(nums[0], nums[1]);
//        }
//        else {
//            dp[i] = fmax(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//    }
//    return sum[numsSize - 1];
//} 
//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
// 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 今晚能够偷窃到的最高金额。

    int rob(int* nums, int numsSize) {
        //本体思路：本体与第一题不同的是，这个数组是一个环，就有两种情况，如果偷了第一个房子就不能偷最后一个房子
        //所以就有两种情况，1 偷第一个房子，1~n-1
        //2 偷最后一个房子 2~n
        //最后输出最大者
        if (numsSize == 1)
        {
            return nums[0];
        }
        if (numsSize == 2)
        {
            return fmax(nums[1], nums[0]);
        }
        int dp_0, dp_1;
        dp_0 = nums[0];//第一个房子
        dp_1 = 0;//偷房子的前两个房子
        for (int i = 1; i < numsSize - 1; i++)
        {
            int tmp = dp_0;
            dp_0 = fmax(dp_0, dp_1 + nums[i]);//比较出是偷当前房子和不偷当前房子谁大
            dp_1 = tmp;

        }
        int max = fmax(dp_0, dp_1);
        dp_0 = nums[1];
        dp_1 = 0;
        for (int i = 2; i < numsSize; i++)
        {
            int tmp = dp_0;
            dp_0 = fmax(dp_0, dp_1 + nums[i]);
            dp_1 = tmp;

        }
        int max1 = fmax(dp_0, dp_1);

        return  fmax(max, max1);

    }