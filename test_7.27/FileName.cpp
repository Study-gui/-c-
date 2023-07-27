 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//KiKi有一个矩阵，他想知道经过k次行变换或列变换后得到的矩阵。请编程帮他解答
//当t为字符'r'时代表进行行变换，当t为字符'c'时代表进行列变换，a和b为需要互换的行或列。
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d%d", &n, &m);
//    int arr[5][5] = {0};
//    int i = 0, j = 0;
//    int k = 0, a = 0, b = 0;
//    char t = 0;
//    int ret = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    scanf("%d", &k);
//    while (k)
//    {
//        scanf(" %c %d %d", &t, &a, &b);
//        if (t == 'r')
//        {
//            for (j = 0; j < m; j++)
//            {
//                //进行行变换
//                ret = arr[a - 1][j];
//                arr[a - 1][j] = arr[b - 1][j];
//                arr[b - 1][j] = ret;
//            }
//        }
//        else if (t == 'c')
//        {
//            //进行列变换
//            for (i = 0; i < n; i++)
//            {
//                ret = arr[i][a - 1];
//                arr[i][a - 1] = arr[i][b - 1];
//                arr[i][b - 1] = ret;
//            }
//        }
//        k--;
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//在庆祝祖国母亲70华诞之际，老师给小乐乐出了一个问题。大家都知道China的英文缩写是CHN，那么给你一个字符串s，
// 你需要做的是统计s中子序列“CHN”的个数。子序列的定义：存在任意下标a < b < c，那么“s[a]s[b]s[c]”
// //就构成s的一个子序列。如“ABC”的子序列有“A”、“B”、“C”、“AB”、“AC”、“BC”、“ABC”。
//输出一个整数，为字符串s中子序列“CHN”的数量
//int main()
//{
//	//思路为记录C的个数与H结合的个数，在与N结合的个数就是总的字符串中CHN的个数
//	char s[8001] = { 0 };
//	long fristC = 0, twoCH = 0, threeCHN = 0;
//	scanf("%s", &s);
//	int ret = sizeof(s) / sizeof(s[0]);
//	for (int i = 0; i < ret; i++)
//	{
//		if (s[i] == 'C')
//		{
//			//记录C的个数
//			fristC++;
//		}
//		if (s[i] == 'H')
//		{
//			//记录CH的总个数的个数
//			twoCH += fristC;
//		}
//		if (s[i] == 'N')
//		{
//			//记录CH与N结合的总个数
//			threeCHN += twoCH;
//		}
//	}
//	printf("%ld\n", threeCHN);
//
//	return 0;
//}
//给定一个整数序列，KiKi想把其中的重复的整数去掉，并将去重后的序列从小到大排序输出。
//本体思路利用桶排方法
//每个数都是一个桶，桶的序号就是对应桶的值，
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int arr[1000] = { 0 };
    int max = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ret);
        arr[ret] = ret;//对应的每一个桶
        if (ret > max)
        {
            max = ret;//筛选出输入最大的桶号
        }
    }
    for (i = 0; i <= max; i++)
    {
        if (arr[i])//对是0的不打印
        {
            printf("%d ", arr[i]);//得到就是筛选出查重的从小到大排序的数组
        }
    }
    return 0;
}