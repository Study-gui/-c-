 #define _CRT_SECURE_NO_WARNINGS


//��Ŀ����
//�����ӽ���������������Ҫ�Ĳ�����֪�� N ��������1��N������i������Ӳ��ֵ������ʱ��Ϊ����
//����֮���������Խ����ӽ����ӽ�ʱ��ȡ������ʱ��ϳ���һ���������� A ��ֲʱ��Ϊ5�죬����B��ֲʱ��Ϊ7�죬
//��AB �ӽ����ѵ�ʱ��Ϊ7�졣�����ӽ�������̶�������²�����������Ȼ���� N�������е�һ�֡�
//��ʼʱ��ӵ������ M ����������ӣ��������ޣ�����֧�ֶ���ӽ�����ͬʱ���Խ��ж���ӽ����̡�
//���ʶ��ڸ�����Ŀ�����ӣ�������Ҫ�������ܹ��õ���
//�����4������ABCD�����Եĳ���ʱ��Ϊ5�졢7�졢3�졢8�졣��ʼӵ�� AB ������������ӣ�
//Ŀ������ΪD����֪�ӽ����ΪAxB C, A��C D������̵��ӽ�����Ϊ��
//��1�쵽��7�죨����B��ʱ�䣩��AxB C��
//��8�쵽��12�죨����A��ʱ�䣩��AxCһD������12 ��õ�����D������

//#include <stdio.h>
//#include <stdlib.h>
//#include<math.h>
//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    int n, m, k, t;
//    scanf("%d %d %d %d", &n, &m, &k, &t);
//    int arr[2001];//��ʾ���ӵ���ֲʱ��
//    int bool_[2001];//��ʾ��������Ƿ����
//    int get[k][3];//ÿһ�б�ʾ���ӵ��ӽ�����
//    int min[2001];//��ȡ���ӵ���Сʱ��
//    for (int i = 0; i < 2002; i++)
//    {
//        min[i] = 999999;//ȫ����Ϊ��󣬴���û���������
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", &arr[i]);//���������ӽ�ʱ�䣬ע���±�Ҫ��һ��ʼ��
//    }
//    int tmp = 0;
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &tmp);
//        bool_[tmp] = 1;//��ʾ���������
//        min[tmp] = 0;//��������ӣ���ʾ��ȡʱ��Ϊ0��
//    }
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            scanf("%d", &get[i][j]);//��ȡ������
//        }
//    }
//    int get_min = 0;
//    while (1)
//    {
//        get_min = min[t];//�ҵ�Ŀ������
//        for (int i = 0; i < k; i++)
//        {
//            if (bool_[get[i][0]] && bool_[get[i][0]])//������������Ӷ���
//            {
//                int min_hq = fmax(min[get[i][1]], min[get[i][0]]);//��ʾ��ȡ�����ӵ��������ӵĻ�ȡʱ��
//                int min_zj = fmax(arr[get[i][1]], arr[get[i][0]]);//��ʾ�������ӵ��ӽ�ʱ��
//                int sum = min_hq + min_zj;//���ǻ�ȡ�÷���Ŀ�����ӵ���ʱ��
//                bool_[get[i][2]] = 1;//�ѻ�ȡ�����ӣ����Ϊ1
//                if (min[get[i][2]] > sum)//����ʱ�丳ֵ
//                {
//                    min[get[i][2]] = sum;
//                }
//            }
//        }
//        if (get_min == min[t] && min[t] != 999999)//�ж��Ƿ���Ŀ�����ӣ���ֹѭ��
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
//    // ���ڴ��������Ĵ���
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

//n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�
//
//����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
//
//ÿ���������ٷ��䵽 1 ���ǹ���
//���������������ָ��ߵĺ��ӻ��ø�����ǹ���
//�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��



// int candy(int* ratings, int ratingsSize){
//     //����˼·������̰�Ľ������α������飬ȡ���ֵ
//     //��Ϊ������ҳ��������ǹ�����
//     //�ұ����ҳ��ݼ����ǹ�����������ȡ���ֵ����ÿ���˵��ǹ�����
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
//    //���α���
//    int sum = 1;//�ǹ��ܺ�
//    int de = 1;//����������ʼ��Ϊ1
//    int dj = 0;//�ݼ�
//    int ret = 1;//��һ���˵��ǹ�����Ϊ1
//    for (int i = 1; i < ratingsSize; i++)
//    {
//        if (ratings[i] >= ratings[i - 1])//�����ж�
//        {
//            dj = 0;//���õݼ�
//            ret = (ratings[i] == ratings[i - 1]) ? 1 : ret + 1;
//            sum += ret;
//            de = ret;//�������͵���ret��
//        }
//        else {
//            dj++;//�ݼ�++
//            if (dj == de)//����ݼ��͵�����Ⱦ�Ҫ�ݼ�+1����Ϊ���һ��������0��Ĭ��Ϊ1�����Եݼ���1
//            {
//                dj++;
//            }
//            sum += dj;//Ĭ�ϵݼ���Ϊ1�����ݵݼ���������
//            ret = 1;//���ǹ���Ϊ1
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