 #define _CRT_SECURE_NO_WARNINGS
//����һ�� ������ �ַ��� s ���������ٰ���һ�� '1' ��
//����밴ĳ�ַ�ʽ �������� �ַ����е�λ��ʹ�õ��Ķ����������ǿ����ɸ�������ɵ� ������������ ��
//���ַ�����ʽ����ʾ�����ؿ����ɸ���������ɵ���������������
//ע�� ���صĽ���ַ��� ���� ��ǰ���㡣
//char* maximumOddBinaryNumber(char* s) {
//    //����˼·��������ȷ���м���һ��һ��һ����ǰ��Ϊ0�����Ϊ��һ
//    //һ��һ���Ͼ��Ǵ�ǰ������0���Ӻ���ǰ��1 ���н������������һλ�����һ��һ���н���
//    int ret = strlen(s);
//    int count = 0;
//    for (int i = 0; i < ret; i++)
//    {
//        if (s[i] == '1')
//        {
//            count++;
//        }
//    }
//    if (count == 1)
//    {
//        for (int i = 0; i < ret; i++)
//        {
//            if (i == ret - 1)
//            {
//                s[i] = '1';
//            }
//            else
//            {
//                s[i] = '0';
//            }
//        }
//    }
//    else
//    {
//        int i = 0;
//        int j = ret - 1;
//        while (i < j)
//        {
//            while (s[i] == '1' && i < j)
//            {
//                i++;
//            }
//            while (s[j] == '0' && i < j)
//            {
//                j--;
//            }
//            char tmp = s[i];
//            s[i] = s[j];
//            s[j] = tmp;
//        }
//        int tmp = s[i - 1];
//        s[i - 1] = s[ret - 1];
//        s[ret - 1] = tmp;
//    }
//    return s;
//}

//����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ���
//����: s = "abcabcbb"
//��� : 3
//���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
//int lengthOfLongestSubstring(char* s) {
//    //����˼·:�ؼ��������ñ�־λ���ж��Ƿ��ظ�
//    //����˫ָ�� left right���б�ʶ��ַ���
//    //����ظ��� leftָ���ظ��ַ�����һλ�����¿�ʼ����
//    int left = 0;//��ָ��
//    int right = 0;//��ָ��
//    int max = 0;//�������ֵ
//    int n = strlen(s);//�ַ�������
//    int arr[127];//�ؼ���־λ����Ϊ��ĸassci��ֵ�����127�������������127����
//    //���ã�����һ���ַ����ͽ����ַ���Ϊ1����Ϊ��־λ
//    //�������0ʱ��˵�����ظ��ַ�������rightָ��֮ǰ���ַ����ҵ��ظ��ַ�
//    while (right < n)//�����ַ���
//    {
//        if (arr[s[right]] == 0)
//        {
//            arr[s[right]] = 1;
//        }
//        else {
//            for (int i = left; i < right; i++)
//            {
//                if (s[i] == s[right])
//                {
//                    left = i + 1;
//                    break;
//                }
//            }
//
//        }
//        max = max > (right - left + 1) ? max : (right - left + 1);//�������ֵ
//        right++;
//    }
//    return max;
//}

//����һ������������ nums �� ��������������� 1 �ĸ�����

//
//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//    int max = 0;
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)
//        {
//            ret++;
//        }
//        else {
//            ret = 0;
//        }
//        if (max < ret)
//        {
//            max = ret;
//        }
//    }
//    return max;
//}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // ���ڴ��������Ĵ���
    int n;
    int arr[100005] = { 0 };
    int brr[1000005] = { 0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        while (brr[arr[i]] != 0)
        {
            brr[arr[i]]++;
            arr[i] += (brr[arr[i]] - 1);
        }
        brr[arr[i]]++;
        printf("%d ", arr[i]);
    }
    return 0;
}