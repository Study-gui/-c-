 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O��n��ʱ���������
//˼·1
//int missingNumber(int* nums, int numsSize) {
//    //������ͬ�������Ϊ0������
//    int x = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        x ^= i;//���������0��n����
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        x ^= nums[i];//�����������ܵõ�ȴ���Ǹ���
//    }
//    return x;
//}

//˼·2
//�Ƚ�0��n���е�����Ӽ�ȥ�������е������ǵõ�ȴ����
//int missingNumber(int* nums, int numsSize) {
//	int x = 0;
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x += i;
//	}
//	for (int i = 0; i < numsSize; i++)
//	{
//		x -= nums[i];
//	}
//	return x;
//}

//����һ����������nums���������е�Ԫ��������תk��λ�ã�����k�ǷǸ���
//˼·1
//������⣺ȥ���һ������������������ƶ�һλ���ٽ����һ������ֵ��һ�����ϣ�ʵ��k��ѭ��
//void rotate(int* nums, int numsSize, int k) {
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < k; i++)
//    {
//        int tmp = nums[numsSize - 1];
//        for (j = numsSize - 1; j > 0; j--)
//        {
//            nums[j] = nums[j - 1];
//        }
//        nums[0] = tmp;
//    }
//    return nums;
//}

//˼·2
////void is_nixu(int* nums,int left,int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    //�ؼ�Ҫ���ǵ�k���ڵ���nʱ��
//    if (k >= numsSize)
//    {
//        k %= numsSize;
//    }
//    //�Ƚ�ǰn-k������������
//    is_nixu(nums, 0, numsSize - 1 - k);
//    //�ٽ����k��������������
//    is_nixu(nums, numsSize - k, numsSize - 1);
//    //����ٽ����������������
//    is_nixu(nums, 0, numsSize - 1);
//    return nums;
//}
//ţ����Ŀ������Ŀ�汾ʱ���а汾�ţ�����1.02.11��2.14.4�ȵ�
//���ڸ���2���汾��version1��version2������Ƚ����ǵĴ�С
//�汾�������޶�����ɣ��޶������޶���֮����һ��"."���ӡ�1���޶��ſ����ж�λ������ɣ�
// �޶��ſ��ܰ���ǰ��0�����ǺϷ��ġ����磬1.02.11��0.1��0.2���ǺϷ��İ汾��
//ÿ���汾�����ٰ���1���޶��š�
//�޶��Ŵ����ұ�ţ��±��0��ʼ������ߵ��޶����±�Ϊ0����һ���޶����±�Ϊ1���Դ����ơ�
//�ȽϹ���
//һ.�Ƚϰ汾��ʱ���밴�����ҵ�˳�����αȽ����ǵ��޶��š��Ƚ��޶���ʱ��ֻ��ȽϺ����κ�ǰ����������ֵ��
// ����"0.1"��"0.01"�İ汾������ȵ�
//��.����汾��û��ָ��ĳ���±괦���޶��ţ�����޶�����Ϊ0�����磬"1.1"�İ汾��С��"1.1.1"��
// ��Ϊ"1.1"�İ汾���൱��"1.1.0"����3λ�޶��ŵ��±�Ϊ0��С��1
//��.version1 > version2 ����1����� version1 < version2 ���� - 1����Ȼ����0.
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 * �Ƚϰ汾��
 * @param version1 string�ַ���
 * @param version2 string�ַ���
 * @return int����
 */
//����˼·������������ÿ���޶����±�ת��Ϊ���������ÿ���±���бȽ�
#include <stdio.h>
int is_zhuanhuang(char* version, int arr_ver[])
{
    int i = 0;
    char* p = version;
    while (*p != '\0')
    {

        if (*p == '.')
        {
            i++;//�����޶��ŵ��±�
        }
        else if (*p >= '0' && *p <= '9')
        {
            arr_ver[i] = arr_ver[i] * 10 + *p - '0';//��ʾ��ÿ���޶��Ž���ת��Ϊ�����ÿ��Ԫ��
        }
        p++;
    }
    return i;
}
int compare(char* version1, char* version2) {
    int arr_ver1[1000];//������������ת��Ϊ���������飬���бȽ�
    int arr_ver2[1000];
    int num_ver1 = 0, num_ver2 = 0;//�����޶��ŵ��±�
    int ret = 0;//��¼�Ƚ��жϴ�С�ı�ʶ
    num_ver1 = is_zhuanhuang(version1, arr_ver1);//��������޶���ת��Ϊ�������±�
    num_ver2 = is_zhuanhuang(version2, arr_ver2);
    int i = 0;
    for (i = 0; i <= num_ver2 || i <= num_ver1; i++)
    {
        if (arr_ver1[i] > arr_ver2[i])//��ÿ���޶��Ž��бȽ�
        {
            ret = 1;
            break;
        }
        else if (arr_ver1[i] < arr_ver2[i])
        {
            ret = -1;
            break;
        }
    }
    return ret;//��ȫ����ȣ���retΪ0
}