 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <xpolymorphic_allocator.h>
using namespace std;
//����һ�� n* m �ľ��� a�������Ͻǿ�ʼÿ��ֻ�����һ��������ߣ���󵽴����½ǵ�λ�ã�
//·�������е������ۼ���������·���ͣ�������е�·������С��·���͡�
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param matrix int���Ͷ�ά���� the matrix
 * @param matrixRowLen int matrix��������
 * @param matrixColLen int* matrix��������
 * @return int����
 */
int minPathSum(int** matrix, int matrixRowLen, int* matrixColLen) {
    int i = 0;
    int j = 0;
    int row = matrixRowLen;  //����
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