 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int cmp(const void* x1, const void* x2)
//{
//	return *(int*)x1 - *(int*)x2;
//}
//
//int main()
//{
//	int arr[] = { 9,4,6,7,3,5,2,1,8 };
//	qsort(arr, 9, sizeof(int), cmp);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//问题描述
//小蓝是一个热爱收集玩具的小伙子，他拥有n个不同的玩具。
//这天，他把 n2个玩具按照高度顺序从矮到高摆放在了窗台上，然后，他希望将这些玩具分成k个段，使得所有分段的极差之和尽可能小。
//具体来说，你需要将一个长度为n的序列分为 段，我们定义G
//为第之个分段的极差，你要最小化之」G。
//你能帮助小蓝找到最小值是多少吗？


#include <stdio.h>
#include <stdlib.h>
//typedef long long ll;
int cmp(const void* x1, const void* x2)
{
    return *(int*)x1 - *(int*)x2;
}
int main(int argc, char* argv[])
{//本题思路：就是利用把每一个玩具之间的差值都算出来，然后进行排序，因为n数个有n-1个差值
//因为差值都是两个树之间的，就相当于去掉k-1个最大差值，其他相加就是最小差值的和
  // 请在此输入您的代码
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int brr[n - 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        brr[i] = arr[i + 1] - arr[i];
    }
    qsort(brr, n - 1, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < n - k; i++)
    {
        sum += brr[i];
    }
    printf("%d", sum);
    return 0;
}