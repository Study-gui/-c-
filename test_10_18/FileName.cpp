 #define _CRT_SECURE_NO_WARNINGS

//假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，
//它们会争夺水源，两者都会死去。

//给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
//另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。


//bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
//    //本题思路：就是利用标志位来记录上一块土地有没有种花
//    int ret = 0;
//    for (int i = 0; i < flowerbedSize; i++)
//    {
//        if (flowerbed[i] == 1)//如果这块土地有花
//        {
//            if (ret == 1)//就判断上一块是否有花
//            {
//                n++;//有就+1
//            }
//            ret = 1;//这块土地就变成上一块土地置为1
//        }
//        if (flowerbed[i] == 0)//这块土地没有花
//        {
//            if (ret == 0)//就判断上块土地没有花
//            {
//                n--;//--
//                ret = 1;//这块土地就变成上一块土地置为1
//            }
//            else {
//                ret = 0;//如果上一块土地有花，这块就不能种花
//            }
//        }
//    }
//    if (n > 0)//判断是否能种满
//    {
//        return false;
//    }
//    return true;
//
//}



//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

//只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
//设计一个算法来计算你所能获取的最大利润。

//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

// int maxProfit(int* prices, int pricesSize){
// //贪心算法：
// int min=prices[0];
// int max=0;
// for(int i=0;i<pricesSize;i++)
// {
//     if(min>prices[i])
//     {
//         min=prices[i];
//     }
//     if(prices[i]-min>max)
//     {
//         max=prices[i]-min;
//     }
// }
// return max;
// }
//int maxProfit(int* prices, int pricesSize) {
//    //动态规划
//    int dp[pricesSize][2];//dp[i][j] i表示在i天，j=0表示没有持有股票，j=1表示持有股票
//    dp[0][0] = 0;
//    dp[0][1] = -prices[0];
//    for (int i = 1; i < pricesSize; i++)
//    {
//        //第i天没有持有股票，1是前一天也没有股票，2是前一天有股票，今天卖出
//        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//        //第i天有股票，1前一天也有股票，2是前一天没有股票，今天刚买的
//        dp[i][1] = fmax(dp[i - 1][1], -prices[i]);
//    }
//    return dp[pricesSize - 1][0];
//}



//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

//在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，
//然后在 同一天 出售。

//返回 你能获得的 最大 利润 。
// int maxProfit(int* prices, int pricesSize){
// int dp[pricesSize][2];;//dp[i][j] i表示在i天，j=0表示没有持有股票，j=1表示持有股票
// dp[0][0]=0;
// dp[0][1]=-prices[0];
// for(int i=1;i<pricesSize;i++)
// {
//     //第i天没有持有股票，1是前一天也没有股票，2是前一天有股票，今天卖出
//     dp[i][0]=fmax(dp[i-1][0],dp[i-1][1]+prices[i]);
//     //第i天有股票，1前一天也有股票，2是前一天没有股票，今天刚买的
//     dp[i][1]=fmax(dp[i-1][1],dp[i-1][0]-prices[i]);
// }
// return dp[pricesSize-1][0];
// }
//
//int maxProfit(int* prices, int pricesSize) {
//    //贪心算法：多次交易大于一次交易
//    int sum = 0;
//    for (int i = 0; i < pricesSize - 1; i++)
//    {
//        if (prices[i + 1] > prices[i])
//        {
//            sum += prices[i + 1] - prices[i];
//        }
//    }
//    return sum;
//
//
//}
//
#include<stdio.h>
//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
//    int sum = 0;
//    for (int i = 0; i < gasSize; i++)
//    {
//        sum = gas[i];
//        for (int j = i + 1; sum > 0; j++)
//        {
//            if (i == (j % gasSize) && sum >= cost[(j - 1) % costSize])
//            {
//                return i;
//            }
//            sum = sum - cost[(j - 1) % costSize];
//            if (sum >= 0)
//            {
//                sum += gas[j % gasSize];
//            }
//            else {
//                break;
//            }
//            
//        }
//    }
//    return -1;
//}
//
//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
//    int sum = 0;
//    int start = 0;
//    int ret = 0;
//    for (int i = 0; i < gasSize; i++)
//    {
//        ret += gas[i] - cost[i];
//        sum += ret;
//        if (ret < 0)
//        {
//            start = i + 1;
//            ret = 0;
//        }
//    }
//    if (sum < 0)
//    {
//        return -1;
//    }
//    return start;
//
//
//}
//int main()
//{
//    int arr[6] = { 4,5,2,6,5,3 };
//    int brr[6] = { 3,2,7,3,2,9 };
//    int n=canCompleteCircuit(arr, 6, brr, 6);
//    printf("%d", n);
//
//
//
//	return 0;
//}


//在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。
//你从其中的一个加油站出发，开始时油箱为空。
//给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，
//否则返回 - 1 。如果存在解，则 保证 它是 唯一 的。

// int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    //时间复杂度太高
// int sum=0;
// for(int i=0;i<gasSize;i++)
// {
//     sum=gas[i];
//     for(int j=i+1;sum>0;j++)
//     {
//          if(i==(j%gasSize)&&sum>=cost[(j-1)%costSize])
//         {
//             return i;
//         }
//         sum=sum-cost[(j-1)%costSize];
//         if(sum>=0)
//         {
//             sum+=gas[j%gasSize];
//         }
//         else{
//             break;
//         }

//     }
// }
// return -1;
// }

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum = 0;
    int start = 0;
    int ret = 0;
    //本题思路：就是用贪心算法，把大问题转化为小问题，从第一个加油站开始遍历，不行向后遍历，把消耗的和
    //加的油唯一轮回，如果总的小于零肯定不能到
    for (int i = 0; i < gasSize; i++)
    {
        ret += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if (ret < 0)
        {
            start = i + 1;
            ret = 0;
        }
    }
    if (sum < 0)
    {
        return -1;
    }
    return start;
}
