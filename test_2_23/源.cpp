 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>



//���ʲ��
//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣������������ֵ��г��ֵ�һ����������ƴ�ӳ� s 
//�򷵻� true��
//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�

//���ö�̬�滮���ҵ����ֵ��е��ַ�����ͬ���ַ��������б���
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
                int ret = i - len;//��ʾ��Ӧ���ĸ��ַ���
                if (ret < 0)//˵��û�е�һ���������ַ���
                {
                    continue;
                }
                dp[i] = (dp[ret] && !strncmp(s.c_str() + ret, wordDict[j].c_str(), len) || dp[i]);//��ʾ����ַ�����ǰ����ַ�ƥ���Ϊ��
            }
        }
        return dp[n];
    }
};


//�����������
//����һ���ַ��� s ���ҳ�������Ļ��������У������ظ����еĳ��ȡ�

//�����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�

//���ö�̬�滮��dp[i][j]��ʾiλ�õ�jλ�õ�����������
//��Ϊiһ������j�������²���û�����壬��֤��dp[i][j]��ֻ��б�Ż��߷��ű���
//�����ȣ��������о͵���dp[i+1][j-1]+2
//�������ȣ��͵���max(dp[i+1][j],dp[i][j-1])
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


//�����������
//����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
//
//������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3, 6, 2, 7] 
//������[0, 3, 1, 6, 2, 2, 7] �������С�

//���ö�̬�滮��������������ѭ�����ҵ��ϸ����������
//dp[i]��ʾiλ��Ϊβ������������
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
                    dp[i] = max(dp[i], dp[j] + 1);//�Ƚ�ʱdp[i]�͵���ǰ��ĸ������ϱ������
                }

            }
            res = max(dp[i], res);//�ҵ���������
        }
        return res;
    }
}