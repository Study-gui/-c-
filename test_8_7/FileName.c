 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����һ������ ��һ��ֵ ������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�numsvalval
//��Ҫʹ�ö��������ռ䣬����벻ʹ�ö���ռ䲢ԭ���޸���������
//������⣻ͨ�������͸�ֵ�����������val��Ԫ����������󣬲����ؼ�ȥval�ĸ���������
//int cmp(void* const e1, void* const e2)
//{
//    return ((*(int*)e2) - (*(int*)e1));
//}
//
//
//int removeElement(int* nums, int numsSize, int val) {
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == val)
//        {
//            nums[i] = 0;
//            count++;
//        }
//    }
//    qsort(nums, numsSize, sizeof(int),cmp);//���ÿ��ź���
//    return numsSize - count;
//}

//˼·2�����ÿ���ָ��������
//�ռ临�Ӷ�βO��N��
//int removeElement(int* nums, int numsSize, int val) {
//    //��������������src��dst
//    int src = 0;
//    int dst = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)//���srcָ�����������val�ͽ�����ǰ��ֵ��dst
//        {
//            nums[dst] = nums[src];
//            src++;
//            dst++;//dst��ǰ��
//        }
//        else {//�������val�ͽ�������
//            src++;
//        }
//    }
//    return dst;//dst��ʾ������val�������±���ǵ�������ĸ���
//}
//˼·����Ҳ�����ÿ���ָ��
//һ����ǰ����ҵ���val������һ���Ӻ���ǰ�Ҳ�����val������������н���
//int removeElement(int* nums, int numsSize, int val) {
//    int sta = 0;//������Ԫ��
//    int end = numsSize - 1;//�������һλԪ��
//    while (sta <= end)
//    {
//        while (sta <= end && nums[sta] != val)//�ҵ�sta��Ӧ��������val
//        {
//            sta++;
//        }
//        while (sta <= end && nums[end] == val)//�ҵ�end��Ӧ����������val
//        {
//            end--;
//        }
//        if (sta < end)//��ǰ��sta��Ӧ�ĵ���val����������end��Ӧ�Ĳ�����val�������ڽ������sta���Ƕ�Ӧ����ĸ���
//        {
//            int tmp = nums[sta];
//            nums[sta] = nums[end];
//            nums[end] = tmp;
//            sta++;
//            end--;
//        }
//
//    }
//    return sta;
// 
// 
//����һ�� �������е�����nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//Ԫ�ص� ���˳��Ӧ�ñ��� һ�� ��Ȼ�󷵻� ��ΨһԪ�صĸ�����
//int removeDuplicates(int* nums, int numsSize) {
//    //����˫ָ��������
//    int sta = 0;//��Ӧ��������ȥ�ص���
//    int mid = sta + 1;//��Ӧȥ�ص���
//    if (numsSize == 0)
//        return 0;
//    while (mid < numsSize)
//    {
//        if (nums[sta] == nums[mid])
//        {
//            mid++;//�ҵ�����ȵ���
//        }
//        else {
//            sta++;
//            nums[sta] = nums[mid];//���и�ֵ
//            mid++;
//        }
//    }
//    return sta + 1;//��������ȥ�غ��Ԫ������
//}
//���������� �ǵݼ�˳�� ���е���������nums1��nums2,������������m��n���ֱ��ʾnums1��nums2�е�Ԫ����Ŀ��
//����nums2�ϲ���nums1�У�ʹ�ϲ��������ͬ�����ǵݼ�˳������
//˼·1���������
//#include<stdlib.h>
//int cmp(const void* e1, const void* e2)
//{
//    return *((int*)e1) - *((int*)e2);
//}
//
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int i = m;
//    int j = 0;
//    for (i = m; i < m + n; i++)
//    {
//        nums1[i] = nums2[j];//��nums2�е�Ԫ�ظ�ֵ��nums1��
//        j++;
//    }
//    qsort(nums1, m + n, sizeof(int), cmp);//�����ÿ��Ž�����������
//    return nums1;
//}
//˼·2������˫ָ���������
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //����˫ָ���������
    int i = m - 1;//nums1���һ�������±�
    int j = n - 1;//nums2���һ�������±�
    int end = m + n - 1;//�ϲ�������һ�������±�
    if (m = 0)//�ж�nums1Ϊ�յ����
    {
        for (int x = 0; x < nums2Size; x++)
        {
            nums1[x] = nums2[x];
        }
        return nums1;
    }
    if (n = 0)//�ж�nums2Ϊ�յ����
        return nums1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])//�Ƚ��Ǹ���������ͷ��������
        {
            nums1[end] = nums1[i];
            i--;
            end--;
        }
        else
        {
            nums1[end] = nums2[j];
            j--;
            end--;
        }//���nums1���һ��������С��ֱ�ӽ���
    }
    if (i < 0 && j >= 0)//���nums2��󼸸�������С����ô��Ҫ���м���ѭ��
    {
        while (j >= 0)
        {
            nums1[end] = nums2[j];
            j--;
            end--;
        }
    }
    return nums1;
}