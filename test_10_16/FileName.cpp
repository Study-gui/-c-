 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//#include<stdio.h>
//#include<math.h>
////long long N=1e5+100;
//int  dp[10005][10005];
//
//int main()
//{
//    int n, v;
//    scanf("%d %d", &n, &v);
//    int vi[10005];
//    int wi[10005];
//    int a, b, c;
//    int ret = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d %d %d", &a, &b, &c);
//        for (int j = 1; j <= c; j++)
//        {
//            vi[ret] = a;
//            wi[ret] = b;
//            ret++;
//        }
//    }
//    for (int i = 1; i < ret; i++)
//    {
//        for (int j = 1; j <= v; j++)
//        {
//            if (j < vi[i])
//            {
//                dp[i][j] = dp[i - 1][j];
//            }
//            else {
//                dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - vi[i]]+ wi[i]);
//            }
//        }
//    }
//    printf("%d", dp[n][v]);
//    return 0;
//}


//有 N种物品和一个容量是 V的背包。第 i种物品最多有 si件，每件体积是 vi，价值是 wi
//求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
//输出最大价值

//#include<stdio.h>
//#include<math.h>
//int dp[10005];
//
//int main()
//{
//    //本题思路：就是利用dp思想，跟背包01问题一样，只是把，每个物品单独放进数组中，在进行遍历
//    int n, v;
//    scanf("%d %d", &n, &v);
//    int ret = 1;
//    int vi[10005];
//    int wi[10005];
//    int a, b, c;
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d %d %d", &a, &b, &c);
//        for (int j = 1; j <= c; j++)
//        {
//            vi[ret] = a;
//            wi[ret] = b;
//            ret++;
//        }
//    }
//    for (int i = 1; i < ret; i++)
//    {
//        for (int j = v; j >= vi[i]; j--)//从前往后，进行遍历，从最大进行统计
//        {
//            dp[j] = fmax(dp[j], dp[j - vi[i]] + wi[i]);//把放当前价值和，放不放当前价值比较
//        }
//    }
//    printf("%d", dp[v]);
//    return 0;
//}



//#include<stdio.h>
//#include<math.h>
//int dp[105][105];
////不选第 i ii 组的物品：对应 d p [ i − 1 ] [ j ] dp[i-1][j]dp[i−1][j]。
////选第 i ii 组的第 1 11 个物品：对应 d p [ i − 1 ] [ j − w [ i ] [ 1 ] ] + v [ i ] [ 1 ] dp[i-1][j-w[i][1]]+v[i][1]dp[i−1][j−w[i][1]]+v[i][1]。
////选第 i ii 组的第 2 22 个物品：对应 d p [ i − 1 ] [ j − w [ i ] [ 2 ] ] + v [ i ] [ 2 ] dp[i-1][j-w[i][2]]+v[i][2]dp[i−1][j−w[i][2]]+v[i][2]。
////选第 i ii 组的第 s [ i ] s[i]s[i] 个物品：对应 d p [ i − 1 ] [ j − w [ i ] [ s [ i ] ] ] + v [ i ] [ s [ i ] ] dp[i-1][j-w[i][s[i]]]+v[i][s[i]]dp[i−1][j−w[i][s[i]]]+v[i][s[i]]。
//int main()
//{
//    int n, v;
//    scanf("%d %d", &n, &v);
//    int si[105];
//    int wi[105][105];
//    int vi[105][105];
//    for (int i = 1; i < n; i++)
//    {
//        scanf("%d", &si[i]);
//        for (int j = 0; j < si[i]; j++)
//        {
//            scanf("%d %d", &vi[i][j], &wi[i][j]);
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= v; j++)
//        {
//            for (int k = 0; k < si[i]; k++)
//            {
//                if (j < vi[i][k])
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//                else {
//                    dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - vi[i][k]] + wi[i][k]);
//                }
//            }
//        }
//    }
//    printf("%d", dp[n][v]);
//    return 0;
//}

//有 N组物品和一个容量是 V的背包。每组物品有若干个，同一组内的物品最多只能选一个。每件物品的体积是 vij
//，价值是 wij，其中 i是组号，j是组内编号。
//求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
//输出最大价值。


#include<stdio.h>

/*int dp[110][110];
int main()
{//本题思路：就是利用dp动态规划的思想来进行做
//因为每组只能选一个，所以要不不选这一组，要么就是选这一组的，第一个，第二个，第三个。。。。到si[i]个取最大值
    int n,v;
    scanf("%d %d",&n,&v);
    int si[110];
    int wi[110][110];
    int vi[110][110];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&si[i]);
        for(int j=1;j<=si[i];j++)
        {
            scanf("%d %d",&vi[i][j],&wi[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v;j++)
        {
             dp[i][j]=dp[i-1][j];//要么不选，
            for(int k=1;k<=si[i];k++)
            {
            if(j>=vi[i][k]){
                    dp[i][j]=fmax(dp[i][j],dp[i-1][j-vi[i][k]]+wi[i][k]);//要么取最大值
                }
            }
        }
    }
    printf("%d",dp[n][v]);
    return 0;
}*/
int dp[105];

int main()
{//一维做法：就是从后向前遍历；取最大值
    int n, v;
    scanf("%d %d", &n, &v);
    int si[110];
    int wi[110][110];
    int vi[110][110];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &si[i]);
        for (int j = 1; j <= si[i]; j++)
        {
            scanf("%d %d", &vi[i][j], &wi[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            for (int k = 1; k <= si[i]; k++)
            {
                if (j >= vi[i][k]) {
                    dp[j] = fmax(dp[j], dp[j - vi[i][k]] + wi[i][k]);
                }
            }
        }
    }
    printf("%d", dp[v]);
    return 0;
}