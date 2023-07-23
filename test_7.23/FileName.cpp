 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <xpolymorphic_allocator.h>
using namespace std;
//给定一个 n* m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，
//路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param matrix int整型二维数组 the matrix
 * @param matrixRowLen int matrix数组行数
 * @param matrixColLen int* matrix数组列数
 * @return int整型
 */
int minPathSum(int** matrix, int matrixRowLen, int* matrixColLen) {
    int i = 0;
    int j = 0;
    int row = matrixRowLen;  //行数
    int col = *matrixColLen;
    int min_x = 0;
    for (i = 0; i < row; i++) {
        matrix[i][0] = matrix[i][0] + matrix[i - 1][0];
    }
    for (j = 0; j < col; j++) {
        matrix[0][j] = matrix[0][j] + matrix[0][j - 1];
    }
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            min_x = min(matrix[i - 1][j], matrix[i][j - 1]);
            matrix[i][j] += min_x;
        }
    }
    return matrix[row - 1][col - 1];
}