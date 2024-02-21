 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//��������С·����   
//����һ�������� triangle ���ҳ��Զ����µ���С·���͡�
//
//ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ����
////���� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ��
//��ô��һ�������ƶ�����һ�е��±� i �� i + 1

//���ö�̬�滮���������Ͻ��б������ܹ���ȡ��Сֵ
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for (int i = 0; i < triangle[m - 1].size(); i++)
        {
            dp[m - 1][i] = triangle[m - 1][i];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};


//�½�������С��
//����һ�� n x n �� ���� �������� matrix �������ҳ�������ͨ�� matrix ���½�·�� �� ��С�� ��
//
//�½�·�� ���Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�
//����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ�У���λ�����·������ضԽ�������������ҵĵ�һ��Ԫ�أ���
//������˵��λ��(row, col) ����һ��Ԫ��Ӧ����(row + 1, col - 1)��(row + 1, col) ����(row + 1, col + 1) ��

//���ö�̬�滮�������·��
class Solution {
public:
    int getmin(int x, int y, int z)
    {
        int m = min(x, y);
        return min(m, z);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 1)
        {
            return matrix[0][0];
        }
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < m; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                }
                else if (j == m - 1)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                }
                else
                {
                    dp[i][j] = getmin(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                }
            }
        }
        for (auto i : dp[m - 1])
        {
            dp[m - 1][m - 1] = min(i, dp[m - 1][m - 1]);
        }
        return dp[m - 1][m - 1];
    }
};


//���������
//��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������


//��̬�滮��dp[i][j]��ʾΪ���½��Ƿ�Ϊһ���߳�Ϊ2�������Σ����ж�̬�滮���ۼ�
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + 1;//״̬����
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};