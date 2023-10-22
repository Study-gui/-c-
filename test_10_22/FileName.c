 #define _CRT_SECURE_NO_WARNINGS


//题目描述
//作物杂交是作物栽培中重要的步。已知有 N 种作物（编号1至N），第i种作物从播种到成熟的时间为工。
//作物之间两两可以进行杂交，杂交时间取两种中时间较长的一方。如作物 A 种植时间为5天，作物B种植时间为7天，
//则AB 杂交花费的时间为7天。作物杂交会产生固定的作物，新产生的作物仍然属于 N种作物中的一种。
//初始时，拥有其中 M 种作物的种子（数量无限，可以支持多次杂交）。同时可以进行多个杂交过程。
//求问对于给定的目标种子，最少需要多少天能够得到。
//如存任4种作物ABCD，各自的成熟时间为5天、7天、3天、8天。初始拥有 AB 两种作物的种子，
//目标种子为D，已知杂交情况为AxB C, A×C D。则最短的杂交过程为：
//第1天到第7天（作物B的时间），AxB C。
//第8天到第12天（作物A的时间），AxC一D。花费12 天得到作物D的种子

//#include <stdio.h>
//#include <stdlib.h>
//#include<math.h>
//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    int n, m, k, t;
//    scanf("%d %d %d %d", &n, &m, &k, &t);
//    int arr[2001];//表示种子的种植时间
//    int bool_[2001];//表示这个种子是否存在
//    int get[k][3];//每一行表示种子的杂交方案
//    int min[2001];//获取种子的最小时间
//    for (int i = 0; i < 2002; i++)
//    {
//        min[i] = 999999;//全部置为最大，代表没有这个种子
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", &arr[i]);//输入种子杂交时间，注意下标要从一开始，
//    }
//    int tmp = 0;
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &tmp);
//        bool_[tmp] = 1;//表示有这个种子
//        min[tmp] = 0;//有这个种子，表示获取时间为0，
//    }
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            scanf("%d", &get[i][j]);//获取方案数
//        }
//    }
//    int get_min = 0;
//    while (1)
//    {
//        get_min = min[t];//找到目标种子
//        for (int i = 0; i < k; i++)
//        {
//            if (bool_[get[i][0]] && bool_[get[i][0]])//如果这两个种子都有
//            {
//                int min_hq = fmax(min[get[i][1]], min[get[i][0]]);//表示获取该种子的两个种子的获取时间
//                int min_zj = fmax(arr[get[i][1]], arr[get[i][0]]);//表示两个种子的杂交时间
//                int sum = min_hq + min_zj;//就是获取该方案目标种子的总时间
//                bool_[get[i][2]] = 1;//已获取该种子，标记为1
//                if (min[get[i][2]] > sum)//把总时间赋值
//                {
//                    min[get[i][2]] = sum;
//                }
//            }
//        }
//        if (get_min == min[t] && min[t] != 999999)//判断是否是目标种子，终止循环
//            break;
//    }
//    printf("%d", get_min);
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//// int dfs(int **arr,int i,int j,int* ret)
//// {
////   for(int x=i-1;x<=i+1;x++)
////   {
////     for(int y=j-1;y<=j+1;y++)
////     {
////       if(arr[x][y]==1||arr[x][y]==9)
////       {
////         (*ret)++;
////       }
////     }
////   }
////  return *ret;
//// }
//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int arr[102][102] = { 0 };
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            int ret = 0;
//            if (arr[i][j] == 1)
//            {
//                arr[i][j] = 9;
//            }
//            else {
//                for (int x = i - 1; x <= i + 1; x++)
//                {
//                    for (int y = j - 1; y <= j + 1; y++)
//                    {
//                        if (arr[x][y] == 1 || arr[x][y] == 9)
//                        {
//                            ret++;
//                        }
//                    }
//                }
//                arr[i][j] = ret;
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//
//你需要按照以下要求，给这些孩子分发糖果：
//
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。



// int candy(int* ratings, int ratingsSize){
//     //本题思路：利用贪心进行两次遍历数组，取最大值
//     //因为左边能找出递增的糖果数量
//     //右边能找出递减的糖果数量，两者取最大值就是每个人的糖果数量
// int left[ratingsSize];
// for(int i=0;i<ratingsSize;i++)
// {
//     if(i>0&&ratings[i]>=ratings[i-1])
//     {
//        left[i]=ratings[i]==ratings[i-1]?1:left[i-1]+1;
//     }
//     else{
//         left[i]=1;
//     }
// }
// int right=0;
// int sum=0;
// for(int i=ratingsSize-1;i>=0;i--)
// {
//    if(i<ratingsSize-1&&ratings[i]>ratings[i+1])
//    {
//      right++;
//    }
//    else{
//        right=1;
//    }
//    sum+=fmax(left[i],right);
// }
// return sum;
// }
//int candy(int* ratings, int ratingsSize) {
//    //单次遍历
//    int sum = 1;//糖果总和
//    int de = 1;//递增数，初始就为1
//    int dj = 0;//递减
//    int ret = 1;//第一个人的糖果假设为1
//    for (int i = 1; i < ratingsSize; i++)
//    {
//        if (ratings[i] >= ratings[i - 1])//进行判断
//        {
//            dj = 0;//重置递减
//            ret = (ratings[i] == ratings[i - 1]) ? 1 : ret + 1;
//            sum += ret;
//            de = ret;//递增数就等于ret数
//        }
//        else {
//            dj++;//递减++
//            if (dj == de)//如果递减和递增相等就要递减+1，因为最后一个数会变成0，默认为1，所以递减加1
//            {
//                dj++;
//            }
//            sum += dj;//默认递减都为1，根据递减数量叠加
//            ret = 1;//把糖果置为1
//        }
//    }
//    return sum;
//}


#include<stdio.h>

int main()
{
	int x = 123456789;
	char* p = (char*)malloc(sizeof(char) * 10);
	char* p1 = p;
	sprintf(p, "%d", x);
	printf("%s", p1);

	return 0;
}