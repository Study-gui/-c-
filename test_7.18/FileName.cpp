 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��ʵ�����ظ����ֵ���������Ķ��ֲ���
//����һ�� Ԫ������ġ����ظ����ֵ��������� nums ��һ��Ŀ��ֵ target ��
//дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣨�±�� 0 ��ʼ�������򷵻� - 1
//int my_shuzu(int nums[], int target, int sz)
//{
//    int left = 0;
//    int right =sz - 1;
//    int b = (left + right) / 2;
//    while (left <= right)
//    {
//        if (target > nums[b])
//        {
//            left = b + 1;
//        }
//        else if (target < nums[b])
//        {
//            right = b - 1;
//        }
//        else
//        {
//            return b;
//        }
//        b = (left + right) / 2;
//    }
//    return -1;
//}
//int main()
//{
//    int nums[6] = { 0 };
//    int target = 0;
//    int sz = sizeof(nums) / sizeof(nums[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        scanf("%d", nums + i);
//    }
//    scanf("%d", &target);
//    int ret = my_shuzu(nums, target, sz);
//    printf("%d ", ret);
//    return 0;
//}
//��һ����ά����array�У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
//�ж��������Ƿ��и�����,���򷵻�1��û���򷵻�0
// /**
//  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//  *
//  * 
//  * @param target int���� 
//  * @param array int���Ͷ�ά���� 
//  * @param arrayRowLen int array��������
//  * @param arrayColLen int* array��������
//  * @return bool������
//  */
// bool Find(int target, int** array, int arrayRowLen, int* arrayColLen ) {
//     // write code here
// }
bool Find(int target, int** array, int arrayRowLen, int* arrayColLen)
{
    int i = 0, j = 0;
    for (i = 0; i < arrayRowLen; i++)
    {
        for (j = 0; j < (*arrayColLen); j++)
        {
            if (target == array[i][j])
            {
                return true;
            }
        }
    }
    return false;
}