 #define _CRT_SECURE_NO_WARNINGS





//673. ����������еĸ���
//����һ��δ������������� nums �� ��������������еĸ��� ��
//
//ע�� ������б����� �ϸ� �����ġ�

//�������������(1)ʱ(dp[j]+1 > dp[i]),ֻ��Ҫ��LISLISLIS�ĳ��ȼ�һ�����ҽ��������Ϊ��nums[j]nums[j]nums[j]һ������

//�������������(2)ʱ(dp[j]+1 == dp[i]),ֻ��Ҫ��nums[j]nums[j]nums[j]������������ȥ����
//���ö�̬�滮
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