#include<iostream>
using namespace std;
int sum = 1;

int cheek(long long x, long long y)
{
	while (x % y)
	{
		long long ret = x % y;
		x = y;
		y = ret;
	}
	if (x > 1)
	{
		return 1;
	}
	else {
		return 0;
	}
}


void dfs(long long** arr, int n, int m, int r, int c)
{
	if (r != n && cheek(arr[r][c], arr[r + 1][c]))
	{
		sum++;
		dfs(arr, n, m, r + 1, c);
	}
	if (r> 1 && cheek(arr[r][c], arr[r-1][c]))
	{
		sum++;
		dfs(arr, n, m, r - 1, c);
	}
	if (c != m && cheek(arr[r][c], arr[r][c + 1]))
	{
		sum++;
		dfs(arr, n, m, r, c + 1);
	}
	if (c >1 && cheek(arr[r][c], arr[r][c - 1]))
	{
		sum++;
		dfs(arr, n, m, r, c - 1);
	}
}

int main(int argc, char** argv)
{
	//	问题描述
	//　　小蓝站在一个 n 行 m 列的方格图中间，方格图的每一个方格上都标有一个正整数。
	//　　如果两个相邻方格（上下左右四个方向相邻）内的数的最大公约数大于 1 ，则可以从其中一个方格移动到另一个方格，当然也可以从另一个方格移回第一个方格。
	//　　假设小蓝开始时站在第 r 行第 c 列，请问小蓝可以移动到方格图内的多少个方格？
	//输入格式
	//　　输入的第一行包含两个整数 n, m ，用一个空格分隔，表示方格图的行数和列数。
	//　　接下来 n 行，每行包含 m 个正整数，相邻整数间用一个空格分隔，依次表示方格图中从第 1 行到第 n 行，每行从第 1 列到第 m 列中的数。
	//　　接下来一行包含两个整数 r, c，用一个空格分隔，表示小蓝所在的行号和列号。
	//输出格式
	//　　输出一行包含一个整数，表示答案。
	//样例输入
	//3 4
	//3 6 5 5
	//2 4 3 5
	//7 8 3 8
	//3 2
	//样例输出
	//5
	//	　对于50%的评测用例，1 <= n, m <= 100，方格图中的每个数不超过 10**5 （10的5次方）。
	//　　对于所有评测用例，1 <= n, m <= 1000，方格图中的每个数不超过 10**9 （10的9次方）

	int n, m;
	cin >> n >> m;
	long long arr[4][5] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int r, c;
	cin >> r >> c;
	dfs((long long**)arr, n, m, r, c);
	cout << sum << endl;
	return 0;
}