 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>



//单词拆分
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 
//则返回 true。
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

//利用动态规划，找到与字典中的字符串相同的字符数，进行遍历
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < wordDict.size(); j++)
            {
                int len = wordDict[j].size();
                int ret = i - len;//表示对应是哪个字符串
                if (ret < 0)//说明没有到一个完整的字符串
                {
                    continue;
                }
                dp[i] = (dp[ret] && !strncmp(s.c_str() + ret, wordDict[j].c_str(), len) || dp[i]);//表示这个字符串与前面的字符匹配才为真
            }
        }
        return dp[n];
    }
};


//最长回文子序列
//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

//子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

//利用动态规划，dp[i][j]表示i位置到j位置的最大回文序列
//因为i一定大于j所以左下部分没有意义，保证的dp[i][j]，只能斜着或者反着遍历
//如果相等，回文序列就等于dp[i+1][j-1]+2
//如果不相等，就等于max(dp[i+1][j],dp[i][j-1])
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};


//最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 
//是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。

//利用动态规划，巧妙利用两层循环，找到严格递增得序列
//dp[i]表示i位置为尾数的最大递增数
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);//比较时dp[i]和递增前面的个数加上本身的数
                }

            }
            res = max(dp[i], res);//找到最大递增数
        }
        return res;
    }
}