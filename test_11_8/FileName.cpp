 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;

//int n;
//int ti[11], di[11], li[11];
//int falg;
//int used[11];
//N 架飞机准备降落到某个只有一条跑道的机场。其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，即它最早
//可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。降落过程需要 Li个单位时间。
//一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
//请你判断 N 架飞机是否可以全部安全降落。
//输入格式
//输入包含多组数据。
//第一行包含一个整数 T，代表测试数据的组数。
//对于每组数据，第一行包含一个整数 N。
//以下 N 行，每行包含三个整数：Ti，Di 和 Li。
//void dfs(int x,int time)
//{
//	if (falg == 1)
//	{
//		return;
//	}
//	if (x == n)
//	{
//		falg = 1;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (used[i] == 0 && time <= ti[i]+di[i])
//		{
//			used[i] = 1;
//			dfs(x + 1, max(time, ti[i]) + li[i]);
//			if (falg == 1)
//			{
//				return;
//			}
//			used[i] = 0;
//		}
//		
//	}
//}
//void sovle()
//{
//	falg = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ti[i] >> di[i] >> li[i];
//		used[i] = 0;
//	}
//	dfs(0,0);
//	if (falg == 1)
//	{
//		cout << "YES" << endl;
//	}
//	else {
//		cout << "NO" << endl;
//	}
//}
//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		sovle();
//
//	}
//
//	system("pause");
//	return 0;
//}


//小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X。这个炉子有一个称作转换率的属性 V，V 是一个正整数，这意味着消耗 V 个普通金
//
//属 O 恰好可以冶炼出一个特殊金属 X，当普通金属 O 的数目不足 V 时，无法继续冶炼。
//现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次投入了 A 个普通金属 O，最终冶炼出了 B 个特殊金属 X。每条记录都是独立
//的，这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。
//
//根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况。

//第一行一个整数 N，表示冶炼记录的数目。
//接下来输入 N 行，每行两个整数 A、B，含义如题目所述。
int a[10005], b[10005];
int n;
int cheekvmin(int mid)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] / mid > b[i])
		{
			return 0;
		}
	}
	return 1;
}

int cheekvmax(int mid)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] / mid < b[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	int left = 1, right = 1e9;
	int mid = 0;
	int vmin;
	while (left <=right)
	{
		 mid = left + (right - left) / 2;
		if (!cheekvmin(mid))
		{
			
			left = mid +1;
		}
		else {
			vmin = mid;
			right = mid-1 ;
		}
	}
	
	left = 1, right = 1e9;
	int vmax ;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (!cheekvmax(mid))
		{
			
			right = mid-1 ;
		}
		else {
			vmax = mid;
			left = mid + 1;
		}
	}
	
	cout << vmin << " "<<vmax << endl;

	system("pause");
	return 0;
}