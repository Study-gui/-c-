 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//给你一个数组 和一个值 ，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。numsvalval
//不要使用额外的数组空间，你必须不使用额外空间并原地修改输入数组
//暴力求解；通过计数和赋值和排序把数组val的元素排序在最后，并返回减去val的个数的数组
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
//    qsort(nums, numsSize, sizeof(int),cmp);//利用快排函数
//    return numsSize - count;
//}

//思路2：利用快慢指针解决问题
//空间复杂度尾O（N）
//int removeElement(int* nums, int numsSize, int val) {
//    //创建两个变量，src，dst
//    int src = 0;
//    int dst = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)//如果src指向的数不等于val就进行向前赋值给dst
//        {
//            nums[dst] = nums[src];
//            src++;
//            dst++;//dst向前走
//        }
//        else {//如果等于val就进行跳过
//            src++;
//        }
//    }
//    return dst;//dst表示不等于val的数的下标就是等于数组的个数
//}
//思路三：也是利用快慢指针
//一个从前向后找等于val的数，一个从后向前找不等于val的数，对其进行交换
//int removeElement(int* nums, int numsSize, int val) {
//    int sta = 0;//数组首元素
//    int end = numsSize - 1;//数组最后一位元素
//    while (sta <= end)
//    {
//        while (sta <= end && nums[sta] != val)//找到sta对应的数等于val
//        {
//            sta++;
//        }
//        while (sta <= end && nums[end] == val)//找到end对应的数不等于val
//        {
//            end--;
//        }
//        if (sta < end)//对前面sta对应的等于val的数跟后面end对应的不等于val交换，在进行输出sta就是对应数组的个数
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
//给你一个 升序排列的数组nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//元素的 相对顺序应该保持 一致 。然后返回 中唯一元素的个数。
//int removeDuplicates(int* nums, int numsSize) {
//    //利用双指针进行求解
//    int sta = 0;//对应的是数组去重的数
//    int mid = sta + 1;//对应去重的数
//    if (numsSize == 0)
//        return 0;
//    while (mid < numsSize)
//    {
//        if (nums[sta] == nums[mid])
//        {
//            mid++;//找到不相等的数
//        }
//        else {
//            sta++;
//            nums[sta] = nums[mid];//进行赋值
//            mid++;
//        }
//    }
//    return sta + 1;//返回数组去重后的元数个数
//}
//给你两个按 非递减顺序 排列的整数数组nums1和nums2,另有两个整数m和n，分别表示nums1和nums2中的元素数目。
//请你nums2合并到nums1中，使合并后的数组同样按非递减顺序排列
//思路1；暴力求解
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
//        nums1[i] = nums2[j];//把nums2中的元素赋值给nums1中
//        j++;
//    }
//    qsort(nums1, m + n, sizeof(int), cmp);//再利用快排进行升序排序
//    return nums1;
//}
//思路2；利用双指针逆向放置
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //利用双指针逆向放置
    int i = m - 1;//nums1最后一个数的下标
    int j = n - 1;//nums2最后一个数的下标
    int end = m + n - 1;//合并后的最后一个数的下标
    if (m = 0)//判断nums1为空的情况
    {
        for (int x = 0; x < nums2Size; x++)
        {
            nums1[x] = nums2[x];
        }
        return nums1;
    }
    if (n = 0)//判断nums2为空的情况
        return nums1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])//比较那个数组数大就放在最后面
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
        }//如果nums1最后一个数是最小就直接结束
    }
    if (i < 0 && j >= 0)//如果nums2最后几个数是最小，那么还要进行几次循环
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