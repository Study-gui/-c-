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

//��������
//����СѧҪ����3����������Ϸ�����꼶���ܹ���n��ͬѧ��Ҫ��ֳ� �����飬���ڵ�������ϷҪ���Ա
// ����߲���˴�С���ǰ೤����������������ڷ���������㣬�����С��ÿ����֮�����߼��
//����ģ�����ֳ���k���飬��i����ߵ��������Hzi������� Hni���㱻Ҫ����С�����ʽ��
//�ͣ�HaһHn.����ֱ��
//��˵������Ҫ��n��Ԫ�طֳ� �飬ʹ�����ļ������С������Ҫ��������С�����ֵ��


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
  {//����˼·��������̰�ĺͶ��ֲ��ң���������
  //�������ҵ�������߲���ö��ֲ��ң����Ƿ���Ϸ���k����������б�����ֵ����mid��k--��k���С�ڵ���0˵��mid����
  //���ö������±������飬�ҵ������߲��
    // ���ڴ��������Ĵ���
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