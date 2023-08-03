 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��һ��01����1������½�أ�0������ �������1���ڣ���ô������1����ͬһ����������ֻ������������Ϊ���ڡ�
//���� : ����½�ؿ������һ�����죨����:�������ң� �жϵ��������
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * �жϵ�������
 * @param grid char�ַ��Ͷ�ά����
 * @param gridRowLen int grid��������
 * @param gridColLen int* grid��������
 * @return int����
 */
void is_count(char** grid, int gridRowLen, int* gridColLen, int i, int j)
{
    if (i < 0 || j < 0 || i == gridRowLen || j == *gridColLen || grid[i][j] == '0')
    {
        return;//�������1ֱ�ӷ���
    }
    grid[i][j] = '0';//��Χ��1������0����ʾ�Ѿ������ж���
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
                is_count(grid, gridRowLen, gridColLen, i, j);//�ж���Χ���������Ƿ���1
                ret++;//��ʾ��������������0��1�ĸ���
            }
        }
    }
    return ret;
}