 #define _CRT_SECURE_NO_WARNINGS
//假设你有一个数组prices，长度为n，其中prices[i]是股票在第i天的价格，请根据这个价格数组，
// 返回买卖股票能获得的最大收益 1.你可以买入一次股票和卖出一次股票，并非每天都可以买入或卖出一次，
// 总共只能买入和卖出一次，且买入必须在卖出的前面的某一天
//2.如果不能获取到任何利润，请返回0
//3.假设买入卖出均无手续费
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param prices int整型一维数组
* @param pricesLen int prices数组长度
* @return int整型
*
*C语言声明定义全局变量请加上static，防止重复定义
* /
int maxProfit(int* prices, int pricesLen) {
    // write code here
    if (pricesLen <= 1)
        return 0;
    int min_buy = prices[0];//初始化最小买入价格
    int max_sale = 0;
    for (int i = 1; i < pricesLen; i++) {
        //第i天出售：判断利润是否大于 max_sale 
        if (prices[i] - min_buy > max_sale)
            max_sale = prices[i] - min_buy;
        //第i天是否是最低的买入价格，如果刷新最低值 之后沿用这个值
        if (prices[i] < min_buy)
            min_buy = prices[i];

    }
    //返回最大利润
    return max_sale;
}
