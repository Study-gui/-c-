#define _CRT_SECURE_NO_WARNINGS
// ��ʵ�����ظ����ֵ���������Ķ��ֲ���
//����һ�� Ԫ������ġ����ظ����ֵ��������� nums ��һ��Ŀ��ֵ target ��дһ���������� nums �е� 
//target�����Ŀ��ֵ���ڷ����±꣨�±�� 0 ��ʼ�������򷵻� - 1
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param nums int����һά����
 * @param numsLen int nums���鳤��
 * @param target int����
 * @return int����
 */
//#include<assert.h>
//int search(int* nums, int numsLen, int target) {
//    assert(nums);
//    int left = 0;
//    int right = numsLen - 1;
//    int mid = (left + right) / 2;
//    while (left <= right)
//    {
//        if (target > nums[mid])
//        {
//            left = mid + 1;
//            mid = (left + right) / 2;
//        }
//        else if (target < nums[mid])
//        {
//            right = mid - 1;
//            mid = (left + right) / 2;
//        }
//        else {
//            return mid;
//        }
//    }
//    return -1;
//}
//����һ������Ϊ n �����飬�����дһ�����������ظ����鰴���������Ľ����
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * ��������������
 * @param arr int����һά���� �����������
 * @param arrLen int arr���鳤��
 * @return int����һά����
 * @return int* returnSize ������������
 */
#include<assert.h>
int* MySort(int* arr, int arrLen, int* returnSize) {
    int i = 0;
    assert(arr);
    int j = 0;
    *returnSize = arrLen;
    if (arrLen > 1)
    {
        for (i = 0; i < arrLen - 1; i++)
        {
            for (j = 0; j < arrLen - 1 - i; j++)
            {
                if (arr[j + 1] < arr[j])
                {
                    int tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    else {
        return arr;
    }
    return arr;
}