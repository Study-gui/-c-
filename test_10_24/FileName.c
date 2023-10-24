//#include<stdio.h>

/*小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X。这个炉子有一个称作转换率的属性 V，V 是一个正整数，这意味着消耗 V 个普通金

属 O 恰好可以冶炼出一个特殊金属 X，当普通金属 O 的数目不足 V 时，无法继续冶炼。
现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次投入了 A 个普通金属 O，最终冶炼出了 B 个特殊金属 X。每条记录都是独立
的，这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。

根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况*/
//int n = 0;
//long long a[10005] = { 0 };
//long long b[10005] = { 0 };
////找到转化率最小的函数
//int v_min_check(int v_min)
//{//本题思路：通过二分算法找到最小值和最大值
//	//根据本提题意，小于最小值转化的b肯定大于规定的
//	//大于最小值转化的b肯定小于规定的
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i] / v_min > b[i])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
////找到最大值的函数
//int v_max_check(int v_max)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i] / v_max < b[i])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	
//	scanf("%d", &n);
//	
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%lld %lld", &a[i], &b[i]);
//	}
//	long long left = 1;
//	long long right = 10000000000;
//	long long  mid = 0;
//	int v_min = 0;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (v_min_check(mid))
//		{
//			v_min = mid;
//			right = mid - 1;
//		}
//		else {
//			left = mid + 1;
//		}
//	}
//	
//	left = 1;
//	right = 10000000000;
//	int v_max = 0;
//
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (v_max_check(mid))
//		{
//			v_max = mid;
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//	printf("%d\n%d", v_min, v_max);
//	return 0;
//}


//N 架飞机准备降落到某个只有一条跑道的机场。其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，即它最早
//可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。降落过程需要 Li个单位时间。
//一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
//请你判断 N 架飞机是否可以全部安全降落。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int t[11], d[11], l[11];
int flag;
int used[11];//此数组为判断这架飞机是否已经降落
int n;
void dfs(int x, int time)
{
	if (flag == 1)//终止dfs
	{
		return;
	}
	if (x == n)//表示已经全部降落
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0 && time <= t[i] + d[i])//表示这架飞机没有降落并且表示现在的时刻
			//小于飞机的到达时刻加上盘旋时间
		{
			used[i] = 1;//表示飞机成功降落
			dfs(x + 1, fmax(t[i], time) + l[i]);//进入下一次dfs，time表示取这架飞机到达时刻
			//和time最大值，因为没有到达，飞机也不能降落
			if (flag == 1)
				return;
			used[i] = 0;//如果到这一步说明这架飞机在这个时刻如果降落了后面飞机肯定不能降落，
			//所以在这个时刻这架飞机不能降落
		}
	}
}
void solve()
{
	flag = 0;//重置标志位
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &t[i], &d[i], &l[i]);
		used[i] = 0;
	}
	dfs(0,0);
	if (flag == 1)
	{
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}
int main()
{//本题思路：利用dfs思想进行递归每组航班的时间
	//先让第一架飞机降落，在遍历第二架飞机能降落，就进行下一架，
	// 如果不行就返回上一架飞机不降落，看能否这家飞机降落，直到循环完成时间复杂度为O(n!)
	//但是中间如果能直接全部降落就直接终止，利用标志位flag
	int T;
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
	return 0;
}