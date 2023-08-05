 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//数组包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O（n）时间内完成吗？
//思路1
//int missingNumber(int* nums, int numsSize) {
//    //运用相同数字异或为0的特性
//    int x = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        x ^= i;//先整体异或0到n的数
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        x ^= nums[i];//再异或数组就能得到却的那个数
//    }
//    return x;
//}

//思路2
//先将0到n所有的数相加减去数组所有的数就是得到却的数
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

//给定一个整数数组nums，将数组中的元素向右轮转k个位置，其中k是非负数
//思路1
//暴力求解：去最后一个数，数组整体向后移动一位，再将最后一个数赋值第一个数上，实现k次循环
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

//思路2
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
//    //关键要考虑到k大于等于n时候
//    if (k >= numsSize)
//    {
//        k %= numsSize;
//    }
//    //先将前n-k个数进行逆置
//    is_nixu(nums, 0, numsSize - 1 - k);
//    //再将最后k个数进行你逆置
//    is_nixu(nums, numsSize - k, numsSize - 1);
//    //最后再将整个数组进行逆置
//    is_nixu(nums, 0, numsSize - 1);
//    return nums;
//}
//牛客项目发布项目版本时会有版本号，比如1.02.11，2.14.4等等
//现在给你2个版本号version1和version2，请你比较他们的大小
//版本号是由修订号组成，修订号与修订号之间由一个"."连接。1个修订号可能有多位数字组成，
// 修订号可能包含前导0，且是合法的。例如，1.02.11，0.1，0.2都是合法的版本号
//每个版本号至少包含1个修订号。
//修订号从左到右编号，下标从0开始，最左边的修订号下标为0，下一个修订号下标为1，以此类推。
//比较规则：
//一.比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较忽略任何前导零后的整数值。
// 比如"0.1"和"0.01"的版本号是相等的
//二.如果版本号没有指定某个下标处的修订号，则该修订号视为0。例如，"1.1"的版本号小于"1.1.1"。
// 因为"1.1"的版本号相当于"1.1.0"，第3位修订号的下标为0，小于1
//三.version1 > version2 返回1，如果 version1 < version2 返回 - 1，不然返回0.
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 比较版本号
 * @param version1 string字符串
 * @param version2 string字符串
 * @return int整型
 */
//此题思路：巧妙运用了每个修订号下标转化为整数数组的每个下标进行比较
#include <stdio.h>
int is_zhuanhuang(char* version, int arr_ver[])
{
    int i = 0;
    char* p = version;
    while (*p != '\0')
    {

        if (*p == '.')
        {
            i++;//返回修订号的下标
        }
        else if (*p >= '0' && *p <= '9')
        {
            arr_ver[i] = arr_ver[i] * 10 + *p - '0';//表示对每个修订号进行转化为数组的每个元素
        }
        p++;
    }
    return i;
}
int compare(char* version1, char* version2) {
    int arr_ver1[1000];//创建两个放置转化为整数的数组，进行比较
    int arr_ver2[1000];
    int num_ver1 = 0, num_ver2 = 0;//返回修订号的下标
    int ret = 0;//记录比较判断大小的标识
    num_ver1 = is_zhuanhuang(version1, arr_ver1);//返回最大修订号转化为整数的下标
    num_ver2 = is_zhuanhuang(version2, arr_ver2);
    int i = 0;
    for (i = 0; i <= num_ver2 || i <= num_ver1; i++)
    {
        if (arr_ver1[i] > arr_ver2[i])//对每个修订号进行比较
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
    return ret;//若全部相等，则ret为0
}