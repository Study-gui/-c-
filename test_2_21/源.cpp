 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//三角形最小路径和   
//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者
////等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，
//那么下一步可以移动到下一行的下标 i 或 i + 1

//利用动态规划，从下向上进行遍历，能够求取最小值
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


//下降矩阵最小和
//给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
//
//下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
//在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
//具体来说，位置(row, col) 的下一个元素应当是(row + 1, col - 1)、(row + 1, col) 或者(row + 1, col + 1) 。

//利用动态规划，求最短路径
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


//最大正方形
//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。


//动态规划，dp[i][j]表示为右下角是否为一个边长为2的正方形，进行动态规划的累加
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
                    dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + 1;//状态方程
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};