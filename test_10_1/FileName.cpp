 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//class person
//{
//public:
//	int m_s;
//	int m_h;
//	int m_l;
//};
//
//int main()
//{
//	person s1;
//	cin >> s1.m_h >> s1.m_l >> s1.m_s ;
//	cout << s1.m_h<<endl << s1.m_l<<endl << s1.m_s << endl;
//
//
//
//	system("pause");
//}


//给你一个整数数组 arr，请你将该数组分隔为长度 最多 为 k 的一些（连续）子数组。分隔完成后，
//每个子数组的中的所有值都会变为该子数组中的最大值。
//返回将数组分隔变换后能够得到的元素最大和。本题所用到的测试用例会确保答案是一个 32 位整数。
//输入：arr = [1,15,7,9,2,5,10], k = 3
//输出：84
//解释：数组变为[15, 15, 15, 9, 10, 10, 10]

//#define max(a, b) ((a) > (b) ? (a) : (b))
//int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
//    //本体思路：就是利用dp动态规划来把问题进行分解成小问题
//    //从数组第一个数开始找在k个子数范围内的最大值，dp[i]来表示第几个数的最大值
//    int dp[505];
//    memset(dp, 0, sizeof(dp));
//    int max = 0;
//    for (int i = 1; i <= arrSize; i++)
//    {
//        max = arr[i - 1];
//        for (int j = i - 1; i - j <= k && j >= 0; j--)
//        {
//            dp[i] = max(dp[i], dp[j] + (i - j) * max);//利用动态规划的思想:从第一个数开始向后寻找最大数
//            if (j > 0)
//                max = max(max, arr[j - 1]);
//        }
//    }
//    return dp[arrSize];
//}

//给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：

//nums[0] = 0
//nums[1] = 1
//当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
//当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
//返回生成数组 nums 中的 最大 值。


//
//int getMaximumGenerated(int n) {
//    if (n == 0)
//    {
//        return 0;
//    }
//    if (n == 1)
//    {
//        return 1;
//    }
//    int num[n + 1];
//    num[0] = 0;
//    num[1] = 1;
//    int max = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        if (i % 2 == 0)
//        {
//            num[i] = num[i / 2];
//        }
//        else {
//            num[i] = num[i / 2] + num[(i / 2) + 1];
//        }
//        if (num[i] > max)
//        {
//            max = num[i];
//        }
//    }
//    return max;
//}


//int main()
//{
//	char arr[] = { "abcdef" };
//	char brr[] = { "bcd" };
//	if (!strncmp(arr+3, brr, 3))
//	{
//		printf("包含");
//	}
//	else {
//		printf("不包含");
//	}
//	
//
//	return 0;
//}

//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//bool wordBreak(char* s, char** wordDict, int wordDictSize) {
//    //本体思路：就是利用dp来记录对字符串的比较状态
//    //dp每个数表示每个字符是否能进行匹配的状态
//    int n = strlen(s);
//    int dp[n + 1];
//    memset(dp, 0, sizeof(dp));
//    dp[0] = 1;
//    for (int i = 1; i <= n; i++)//从第一个字符开始遍历
//    {
//        for (int j = 0; j < wordDictSize; j++)//从第一个字符串开始遍历比较相等
//        {
//            int len = strlen(wordDict[j]);//获取比较长度长度
//            int ret = i - len;//获取比较位置
//            if (ret < 0)//小于则跳过
//            {
//                continue;
//            }
//            dp[i] = (dp[ret] && !strncmp(s + ret, wordDict[j], len) || dp[i]);//保证前面的字符匹配成功
//            //和现在的字符匹配状态都成功才行
//        }
//    }
//    return dp[n];
//}

//#include<bits/stdc++.h>
using namespace std;
#include<math.h>
int weishu = 23333333;

bool check(int n)
{
	int n0 = n;
	int n1 = weishu - n0;
	double zhanbi1 = n1 * 1.0 / weishu;
	double zhanbi0 = n0 * 1.0 / weishu;
	double ans = -n0 * zhanbi0 * log2(zhanbi0) - n1 * zhanbi1 *log2(zhanbi1);
	if (abs(ans - 11625907.5798) < 0.0001)
		printf("%.7f     %d\n", ans, n);
	//return true;
	//cout<<ans<<endl;
	return false;
}

int main()
{
	/*int left=0,right=23333333;
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(check(mid))right=mid;
		else left=mid+1;
	}*/
	for (int i = 0; i < 23333333; ++i)
		if (check(i))
			cout << i << endl;
	//cout<<std::log2(8);
	//check(1);
	//check(1217805);

	return 0;
}

/*
1217804
1217805
*/