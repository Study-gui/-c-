 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ������Ϊn������nums�������ҵ���ֵ��������������������ܰ��������ֵ������������£�
// �����κ�һ������λ�ü��ɡ�
//��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء��ϸ���ڼ������е���
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param nums int����һά����
 * @param numsLen int nums���鳤��
 * @return int����
 */
//int findPeakElement(int* nums, int numsLen) {
//    int i = 0;
//    for (i = 1; i < numsLen; i++)
//    {
//        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//        {
//            return i;
//        }
//    }
//    if (nums[0] > nums[1])
//        return 0;
//    else if (nums[numsLen - 1] > nums[numsLen - 2])
//        return numsLen - 1;
//    else
//        return -1;
//}
//��һ������Ϊ n �ķǽ������飬����[1,2,3,4,5]������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ��
//���һ����ת���飬��������[3,4,5,1,2]������[4,5,1,2,3]�����ġ����ʣ���������һ����ת���飬�������е���Сֵ
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param nums int����һά����
 * @param numsLen int nums���鳤��
 * @return int����
 */
int minNumberInRotateArray(int* nums, int numsLen) {
    int i = 0;
    for (i = 0; i < numsLen; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return nums[i + 1];//���ǰ��������i+1Ϊ��תǰ��Ԫ��
        }
    }
    return nums[0];//�޷���˵��û����ת
}