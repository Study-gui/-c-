 #define _CRT_SECURE_NO_WARNINGS





//673. 最长递增子序列的个数
//给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
//
//注意 这个数列必须是 严格 递增的。

//当我们遇到情况(1)时(dp[j]+1 > dp[i]),只需要将LISLISLIS的长度加一，并且将组合数设为与nums[j]nums[j]nums[j]一样即可

//当我们遇到情况(2)时(dp[j]+1 == dp[i]),只需要将nums[j]nums[j]nums[j]的组合数添加上去即可
//利用动态规划
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>count(n, 1);
        int m = 0;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] += count[j];
                    }
                }
            }
            m = max(dp[i], m);
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == m)
            {
                len += count[i];
            }
        }
        return len;
    }
};