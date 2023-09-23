 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//题目描述
//“饱了么“外卖系统中维护着 N 家外卖店，编号1~N。每家外卖店都有一个优先级，初始时（0时刻）优先级都为0。
//每经过1个时间单位，如果外卖店没有订单，则优先级会减少1，最低减到0；而如果外卖店有订单，则优先级不减反加
// ，每有一单优先级加2。
//如果某家外卖店某时刻优先级大于5，则会被系统加入优先缓存中；如果 优先级小于等于3，则会被清除出优先缓存。
//给定T时刻以内的 M条订单信息，请你计算T 时刻时有多少外卖店在优先缓存中？
//输入描述
//第一行包含3个整数N, M, T。
//以下 M 行每行包含两个整数ts, id，表示ts时刻编号id的外卖店收到一个订单。
//H4, 1 ≤ N, M, T≤10, 1 ≤ts < T, 1≤id < N.
//	输出描述
//	输出一个整数代表答案。


//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    int n, m, t;
//    scanf("%d %d %d", &n, &m, &t);//n表示有多少家店，m表示有多少条订单，t表示有多少时刻
//    int arr[100000];//表示每家店的优先级是多少
//    int book[100000];//判断这家店的是否有订单
//    int fit[100000];//判断这家店是否在优先级队列
//    int ts[100000], id[100000];//分别表示时刻和订单一一对应
//    for (int i = 0; i < m; i++)//输入时刻和订单
//    {
//        scanf("%d %d", &ts[i], &id[i]);
//    }
//    for (int i = 0; i <= t; i++)//对t时刻内进行遍历
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            book[j] = 0;//把判断是否有订单置空
//        }
//        for (int j = 0; j < m; j++)
//        {
//            if (ts[j] == i)//判断哪个时刻有订单
//            {
//                arr[id[j]] += 2;//有订单的加上2
//                book[id[j]] = 1;//标记这家店
//            }
//        }
//        for (int j = 0; j <= n; j++)//对没有订单的店进行减少优先级
//        {
//            if (arr[j] > 0 && book[j] == 0)//判断该店是否为零和是否有订单
//            {
//                arr[j]--;
//            }
//            if (fit[j] > 0 && book[j] == 0)//并对优先级缓存减减
//            {
//                fit[j]--;
//            }
//        }
//        for (int j = 0; j <= n; j++)
//        {
//            if (arr[j] > 5)//对优先级缓存进行更新
//            {
//                fit[j] = arr[j];
//            }
//            if (arr[j] <= 3)
//            {
//                fit[j] = 0;
//            }
//        }
//    }
//    int ret = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        if (fit[i] > 3)//对有优先缓存的店进行计数
//        {
//            ret++;
//        }
//    }
//
//    printf("%d", ret);
//    return 0;
//}

//int main()
//{
//	int x = -12;
//	int y = x % 10;
//	int i = x / 100;
//	printf("%d", i);
//	char arr='a';
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%c", arr);
//	}
//	printf("%c", arr);
//
//	return 0;
//}
//数字转换为罗马数字
//const char* value[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//const int nums[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//
//char* intToRoman(int num) {
//    //本题思路：就是通过枚举，和贪心思想来进行转换
//    char* arr = (char*)malloc(sizeof(char) * 16);
//    arr[0] = '\0';
//    for (int i = 0; i < 13; i++)
//    {
//        while (num >= nums[i])//通过减去最大值
//        {
//            num -= nums[i];
//            strcpy(arr + strlen(arr), value[i]);//利用库函数来进行拷贝
//        }
//        if (num == 0)
//        {
//            break;
//        }
//    }
//    return arr;
//
//}
//罗马数字转换为数字


//int romanToInt(char* s) {
//    //本体思路：在于利用字符串的每一位和数组相结合
//    int symbolValues[26];
//    symbolValues['I' - 'B'] = 1;
//    symbolValues['V' - 'B'] = 5;
//    symbolValues['X' - 'B'] = 10;
//    symbolValues['L' - 'B'] = 50;
//    symbolValues['C' - 'B'] = 100;
//    symbolValues['D' - 'B'] = 500;
//    symbolValues['M' - 'B'] = 1000;
//    int n = strlen(s);
//    int value = 0;
//    int sum = 0;
//    for (int i = 0; i < n; i++)//从左往右遍历数组，如果后一位比前一位大就减去
//    {
//        int value = symbolValues[s[i] - 'B'];
//        if (i < n - 1 && value < symbolValues[s[i + 1] - 'B'])
//        {
//            sum -= value;
//        }
//        else {
//            sum += value;
//        }
//    }
//    return sum;
//
//}
#include<string.h>
//int main()
//{
//	char arr[] = { "abc"};
//	char arr1[] = "abc";
//
//	int n = strlen(arr);
//	int n1 = strlen(arr);
//
//	int x = sizeof(arr) / sizeof(arr[0]);
//	int x1 = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", n);
//	printf("%d\n", n1);
//	printf("%d\n", x);
//	printf("%d\n", x1);
//	return 0;
//}
//int main()
//{
//	int x = -1;
//	int y = -x;
//	printf("%d\n", y);
//	int a = -1;
//	int b = 1;
//	int n = a ^ b;
//	printf("%d\n", n);
//	return 0;
//}

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的


//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    //本体思路：利用双指针将两个数组合并成一个新的数组，然后求中位数
//    double arr[nums1Size + nums2Size];//创建新数组
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < nums1Size && j < nums2Size)//通过下标遍历数组
//    {
//        if (nums1[i] < nums2[j])
//        {
//            arr[k] = nums1[i];
//            i++;
//        }
//        else {
//            arr[k] = nums2[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < nums1Size)//看那个数组没有遍历完成
//    {
//        arr[k] = nums1[i];
//        i++;
//        k++;
//    }
//    while (j < nums2Size)
//    {
//        arr[k] = nums2[j];
//        j++;
//        k++;
//    }
//    double x = 0;
//    if (k % 2 == 0)//求得中位数
//    {
//        x = (arr[k / 2] + arr[k / 2 - 1]) / 2;
//    }
//    else {
//        x = arr[k / 2];
//    }
//    return x;
//}
//int* fun(int x)
//{
//	x = 100;
//	return &x;
//}
//int main()
//{
//	int x = 10;
//	int* p = fun(x);
//	int y = 10;
//	printf("%d\n", *p);
//	printf("%d\n", y);
//	printf("%d\n", *p);
//
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    int n;
//    scanf("%d", &n);
//    long long arr[3][3];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%lld", &arr[i][j]);
//        }
//    }
//    int k = 0;
//    long long max[3] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        int j = 0;
//        int ret = i;
//        int x = n;
//        while (x--)
//        {
//            max[k] += arr[j % n][i % n];
//            j++;
//            i++;
//        }
//        k++;
//        i = ret;
//    }
//    long long m = max[0];
//    for (int i = 0; i < n; i++)
//    {
//        if (m < max[i])
//        {
//            m = max[i];
//        }
//    }
//    printf("%lld", m);
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    long long n;
//    scanf("%lld", &n);
//    long long d[5] = {3,5,2,3,6};
//    long long h[5] = { 4,6,5,7,5 };
//  /*  for (long long i = 0; i < n; i++)
//    {
//        scanf("%lld %lld", &d[i], &h[i]);
//    }*/
//    long long ret = n;
//    for (long long i = 0; i < n; i++)
//    {
//        int falg = 0;
//        for (long long j = 0; j < n; j++)
//        {
//            if (d[i] < d[j])
//            {
//                if (h[i] < h[j])
//                {
//                    ret--;
//                    falg = 1;
//                }
//            }
//            if (falg == 1)
//            {
//                break;
//            }
//        }
//    }
//    printf("%lld", ret);
//    return 0;
//}

//输出描述
//输出一个整数代表答案。问题描述
//阿坤老师是学校的数学老师，他特别喜欢让学生挑战一些有趣的数学问题。今天，他给学生带来了一个巨大的魔方
// 。这个魔方的每个面都是一个 N× N 的方阵，每个小格子上都填有一个整数。
//阿坤老师允许学生按行或者按列，将魔方的一个面上的所有行或者所有列，循环移动若干个位置。
// 他希望学生通过移动行或列，使得主对角线（左上角到右下角）上的数字之和最大。
//请问，应该如何移动，才能得到最大的主对角线数字之和？
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{//本体思路：直接算出各个对角线的值然后最大的那个，就是魔方的最大值
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    long long arr[n][n];//创建魔方
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    int k = 0;
    long long max[n];//把每个对角线的值存入数组
    for (int i = 0; i < n; i++)
    {
        int j = 0;//保持行坐标不动
        int ret = i;//设置中间变量
        int x = n;//设置求对角线的次数
        max[k] = 0;//数组初始化
        while (x--)
        {
            max[k] += arr[j % n][i % n];
            j++;
            i++;
        }
        k++;
        i = ret;
    }
    long long m = max[0];
    for (int i = 0; i < n; i++)
    {
        if (m < max[i])
        {
            m = max[i];
        }
    }
    printf("%lld", m);
    return 0;
}