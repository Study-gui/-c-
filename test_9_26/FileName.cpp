 #define _CRT_SECURE_NO_WARNINGS

//����һ���������� nums ��һ������ k �����㷵��������������Ԫ�صĳ˻��ϸ�С�� k ���������������Ŀ��
//���룺nums = [10,5,2,6], k = 100
//�����8
//���ͣ�8 ���˻�С�� 100 ��������ֱ�Ϊ��[10]��[5]��[2], ��[6]��[10, 5]��[5, 2]��[2, 6]��[5, 2, 6]��
//��Ҫע�����[10, 5, 2] �����ǳ˻�С�� 100 ��������

//�ⷨһ����
//int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
//    //����˼·��ͨ�����α������黬�����ڣ������м���
//    int left = 0;
//    int right = 0;
//    int count = 0;
//    for (int left = 0; left < numsSize; left++)
//    {
//        int sum = nums[left];
//        right = left + 1;
//        if (sum < k)
//        {
//            count++;
//            while (right < numsSize)
//            {
//                sum *= nums[right];
//                if (sum < k)
//                {
//                    count++;
//                }
//                else {
//                    break;
//                }
//                right++;
//            }
//        }
//    }
//    return count;
//}

//�ⷨ����
// int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
     //����˼·�������ⷨ��ͬ���ǲ��ö�̬�������ڣ�ʱ�临�Ӷ�ΪO��N��
//if (k <= 1)
//{
//    return 0;
//}
//int left = 0;
//int right = 0;
//int count = 0;
//int sum = 1;
//for (right = 0; right < numsSize; right++)
//{
//    sum *= nums[right];
//    while (sum >= k && left <= right)//���û������ڣ�left��ǰ���ҵ������
//    {
//        sum /= nums[left];
//        left++;
//    }
//    count += right - left + 1;//left��rightλ�õ��������
//}
//return count;
// }
