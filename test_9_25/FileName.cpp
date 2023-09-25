 #define _CRT_SECURE_NO_WARNINGS
//给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。
//你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。
//以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。
//注意 返回的结果字符串 可以 含前导零。
//char* maximumOddBinaryNumber(char* s) {
//    //本体思路：就是先确定有几个一，一个一就是前面为0最后以为置一
//    //一个一以上就是从前往后找0，从后往前找1 进行交换，最后把最后一位都最后一个一进行交换
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

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
//输入: s = "abcabcbb"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//int lengthOfLongestSubstring(char* s) {
//    //本体思路:关键在于利用标志位来判定是否重复
//    //利用双指针 left right进行标识最长字符串
//    //如果重复了 left指向重复字符后面一位，重新开始计算
//    int left = 0;//左指针
//    int right = 0;//右指针
//    int max = 0;//保存最大值
//    int n = strlen(s);//字符串长度
//    int arr[127];//关键标志位：因为字母assci码值最大是127，所以数组就是127长度
//    //作用：出现一个字符，就将该字符置为1，作为标志位
//    //如果出现0时，说明有重复字符，遍历right指针之前的字符串找到重复字符
//    while (right < n)//遍历字符串
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
//        max = max > (right - left + 1) ? max : (right - left + 1);//保留最大值
//        right++;
//    }
//    return max;
//}

//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

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
    // 请在此输入您的代码
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