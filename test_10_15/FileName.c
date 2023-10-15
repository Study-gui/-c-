 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


//
//int main()
//{
//	char b[5];
//	//scanf("%c", &b);
//	//puts(b);
//	/*for (int i = 0; i < 4; i++)
//	{
//		scanf("%c", &b[i]);
//	}*/
//	scanf("%s", &b);
//	/*for (int i = 0; i < 4; i++)
//	{
//		printf("%c", b[i]);
//	}*/
//	printf("%s", b);
//	printf("\n%d", strlen(b));
//
//	
//	return 0;
//}

/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int t;
  scanf("%d",&t);
  getchar();
  char ret[4];
  int arr[100];
  while(t--)
  {
    for(int i=0;i<100;i++)
    {
      arr[i]=0;
    }
    for(int i=0;i<4;i++)
    {
    scanf("%c",&ret[i]);
    }
    for(int i=0;i<4;i++)
    {
      arr[ret[i]-'0']++;
    }
    int count=0;
    for(int j=0;j<100;j++)
    {
      if(arr[j]==3)
      {
       count=1;
      }
    }
    if(count==1)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0*/;
//}

//问题描述
//蓝桥小学要进行3单弹单球游戏，二年级班总共有n个同学，要求分成 个队伍，由于弹弹球游戏要求队员
// 的身高差不能人大，小蓝是班长，他对这个事情正在发愁，他想问你，如何最小化每个组之间的身高极差。
//具体的，假设分成了k个组，第i组最高的人身高是Hzi，最矮的是 Hni，你被要求最小化表达式：
//巴（Ha一Hn.）。直白
//来说，你需要将n个元素分出 组，使得最大的极差尽可能小。你需要输出这个最小化后的值。


#include <stdio.h>
#include <stdlib.h>
//#include<bool.h>
  int cmp(const void* x1, const void* x2)
  {
      return *(int*)x1 - *(int*)x2;
  }
  int  check(int num[], int k, int mid, int n)
  {
      int cur = num[0];
      //int n=sizeof(num)/sizeof(num[0]);
      for (int i = 0; i < n; i++)
      {
          if (num[i] - cur > mid)
          {
              k--;
              cur = num[i];
          }
      }
      if (k > 0)
      {
          return 1;
      }
      return 0;
  }

  int main(int argc, char* argv[])
  {//本题思路：利用了贪心和二分查找，进行运算
  //先排序，找到最大的身高差，再用二分查找，看是否符合分组k，对数组进行遍历差值大于mid的k--，k如果小于等于0说明mid大了
  //利用二分重新遍历数组，找到最佳身高差即可
    // 请在此输入您的代码
      int n, k;
      scanf("%d %d", &n, &k);
      int num[n];
      for (int i = 0; i < n; i++)
      {
          scanf("%d", &num[i]);
      }
      qsort(num, n, sizeof(int), cmp);
      int left = 0;
      int right = num[n - 1] - num[0];
      while (left < right)
      {
          int mid = left + (right - left) / 2;
          if (check(num, k, mid, n))
          {
              right = mid;
          }
          else {
              left = mid + 1;
          }
      }
      printf("%d", left);
      return 0;
  }