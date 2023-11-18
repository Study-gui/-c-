 #define _CRT_SECURE_NO_WARNINGS

//给你一个字符串 s，找到 s 中最长的回文子串。

//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
        {
            return s;
        }
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));//dp[i][j]表示i到j位置的字符串，全置为0
        int begin = 0;//回文字符串起始位置
        int max = 1;//回文字符串中的字符个数
        for (int ret = 1; ret < n; ret++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = ret + i;//从ret=1开始遍历
                if (j == n)//越界终止
                {
                    break;
                }
                if (s[i] == s[j])//字符串相等
                {
                    if (j - i > 2)//如果超过三个字符就等于字符串里是否是字符串
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    else {//小于等于3就是回文的
                        dp[i][j] = 1;
                    }
                }
                else {
                    dp[i][j] = 0;//不相等就不是回文
                }
                if (dp[i][j] && max < j - i + 1)//更新起始位置和最大字符个数
                {
                    max = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max);//截取回文的字符串
    }
};