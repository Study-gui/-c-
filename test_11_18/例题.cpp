 #define _CRT_SECURE_NO_WARNINGS

//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

//����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
        {
            return s;
        }
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));//dp[i][j]��ʾi��jλ�õ��ַ�����ȫ��Ϊ0
        int begin = 0;//�����ַ�����ʼλ��
        int max = 1;//�����ַ����е��ַ�����
        for (int ret = 1; ret < n; ret++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = ret + i;//��ret=1��ʼ����
                if (j == n)//Խ����ֹ
                {
                    break;
                }
                if (s[i] == s[j])//�ַ������
                {
                    if (j - i > 2)//������������ַ��͵����ַ������Ƿ����ַ���
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    else {//С�ڵ���3���ǻ��ĵ�
                        dp[i][j] = 1;
                    }
                }
                else {
                    dp[i][j] = 0;//����ȾͲ��ǻ���
                }
                if (dp[i][j] && max < j - i + 1)//������ʼλ�ú�����ַ�����
                {
                    max = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max);//��ȡ���ĵ��ַ���
    }
};