 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
//岛屿 : 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 判断岛屿数量
 * @param grid char字符型二维数组
 * @param gridRowLen int grid数组行数
 * @param gridColLen int* grid数组列数
 * @return int整型
 */
void is_count(char** grid, int gridRowLen, int* gridColLen, int i, int j)
{
    if (i < 0 || j < 0 || i == gridRowLen || j == *gridColLen || grid[i][j] == '0')
    {
        return;//如果不是1直接返回
    }
    grid[i][j] = '0';//周围有1进行置0，表示已经进行判断了
    is_count(grid, gridRowLen, gridColLen, i - 1, j);
    is_count(grid, gridRowLen, gridColLen, i + 1, j);
    is_count(grid, gridRowLen, gridColLen, i, j - 1);
    is_count(grid, gridRowLen, gridColLen, i, j + 1);
}
int solve(char** grid, int gridRowLen, int* gridColLen) {
    int i = 0;
    int j = 0;
    int ret = 0;
    for (i = 0; i < gridRowLen; i++)
    {
        for (j = 0; j < *gridColLen; j++)
        {
            if (grid[i][j] == '1')
            {
                is_count(grid, gridRowLen, gridColLen, i, j);//判断周围上下左右是否有1
                ret++;//表示进行上下左右置0后1的个数
            }
        }
    }
    return ret;
}