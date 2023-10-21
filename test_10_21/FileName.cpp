 #define _CRT_SECURE_NO_WARNINGS



//问题描述
//给定n 个整数a1， a2， ••，an，求它们两两相乘再相加的和，即：
//s = al - a + a1 - a3 + . + a - an + 02・03 + .. + 01 - 2・0n
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    long long n;
//    int arr[200000];
//    long long sum=0;
//    long long k=0;
//    scanf("%lld", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        k += arr[i];
//        sum += arr[i + 1] * k;
//    }
//    printf("%lld", sum);
//    return 0;
//}




//给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

//你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

//返回获得利润的最大值。

//注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。


// int maxProfit(int* prices, int pricesSize, int fee){
    //动态规划
// int dp[50005][2];//dp[i][j] i表示第i天，j表示是否持有股票
// dp[0][0]=0;
// dp[0][1]=-prices[0];
// for(int i=1;i<pricesSize;i++)
// {
//     //表示前一天没有股票，或者前一天有今天卖出
//     dp[i][0]=fmax(dp[i-1][1]+prices[i]-fee,dp[i-1][0]);
//     //表示前一天没有股票今天买入，或者前一天有
//     dp[i][1]=fmax(dp[i-1][1],dp[i-1][0]-prices[i]);
// }
// return dp[pricesSize-1][0];
// }
//int maxProfit(int* prices, int pricesSize, int fee) {
//    //贪心算法
//    //本题思路：就是如果今天的价格加上手续费比buy的价格低就直接更新buy
//    //如果今天的价格大于buy的价格，就直接卖出，但是不能保证一定赚，因为明天还可能涨，我们就假设明天是涨
//    //把buy更新为今天的价格，明天涨的话，就直接卖出就相当于昨天没有买，是以今天更高的价格卖出
//    //如果到明天跌的比加上买入的手续费还赚钱就直接买入
//    int buy = prices[0] + fee;
//    int sum = 0;
//    for (int i = 1; i < pricesSize; i++)
//    {
//        if (prices[i] + fee < buy)
//        {
//            buy = prices[i] + fee;
//        }
//        if (prices[i] > buy)
//        {
//            sum += prices[i] - buy;
//            buy = prices[i];//假设明天会涨
//        }
//    }
//    return sum;
//}


//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，
//都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
//你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

int cmp(const void* x1, const void* x2)
{
    return *(int*)x1 - *(int*)x2;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    //本题思路：利用排序，贪心，和双指针进行遍历数组，找到最大人数
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    // if(s[0]>g[gSize-1])
    // {
    //     return gSize;
    // }
    // if(s[sSize-1]<g[0])
    // {
    //     return 0;
    // }
    int i = 0, j = 0;
    int child = 0;
    while (i < gSize && j < sSize)
    {
        if (s[j] >= g[i])
        {
            child++;
            i++;
            j++;
        }
        else {
            j++;
        }

    }
    return child;
}