 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//��Ŀ����
//������ô������ϵͳ��ά���� N �������꣬���1~N��ÿ�������궼��һ�����ȼ�����ʼʱ��0ʱ�̣����ȼ���Ϊ0��
//ÿ����1��ʱ�䵥λ�����������û�ж����������ȼ������1����ͼ���0��������������ж����������ȼ���������
// ��ÿ��һ�����ȼ���2��
//���ĳ��������ĳʱ�����ȼ�����5����ᱻϵͳ�������Ȼ����У���� ���ȼ�С�ڵ���3����ᱻ��������Ȼ��档
//����Tʱ�����ڵ� M��������Ϣ���������T ʱ��ʱ�ж��������������Ȼ����У�
//��������
//��һ�а���3������N, M, T��
//���� M ��ÿ�а�����������ts, id����ʾtsʱ�̱��id���������յ�һ��������
//H4, 1 �� N, M, T��10, 1 ��ts < T, 1��id < N.
//	�������
//	���һ����������𰸡�


//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    int n, m, t;
//    scanf("%d %d %d", &n, &m, &t);//n��ʾ�ж��ټҵ꣬m��ʾ�ж�����������t��ʾ�ж���ʱ��
//    int arr[100000];//��ʾÿ�ҵ�����ȼ��Ƕ���
//    int book[100000];//�ж���ҵ���Ƿ��ж���
//    int fit[100000];//�ж���ҵ��Ƿ������ȼ�����
//    int ts[100000], id[100000];//�ֱ��ʾʱ�̺Ͷ���һһ��Ӧ
//    for (int i = 0; i < m; i++)//����ʱ�̺Ͷ���
//    {
//        scanf("%d %d", &ts[i], &id[i]);
//    }
//    for (int i = 0; i <= t; i++)//��tʱ���ڽ��б���
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            book[j] = 0;//���ж��Ƿ��ж����ÿ�
//        }
//        for (int j = 0; j < m; j++)
//        {
//            if (ts[j] == i)//�ж��ĸ�ʱ���ж���
//            {
//                arr[id[j]] += 2;//�ж����ļ���2
//                book[id[j]] = 1;//�����ҵ�
//            }
//        }
//        for (int j = 0; j <= n; j++)//��û�ж����ĵ���м������ȼ�
//        {
//            if (arr[j] > 0 && book[j] == 0)//�жϸõ��Ƿ�Ϊ����Ƿ��ж���
//            {
//                arr[j]--;
//            }
//            if (fit[j] > 0 && book[j] == 0)//�������ȼ��������
//            {
//                fit[j]--;
//            }
//        }
//        for (int j = 0; j <= n; j++)
//        {
//            if (arr[j] > 5)//�����ȼ�������и���
//            {
//                fit[j] = arr[j];
//            }
//            if (arr[j] <= 3)
//            {
//                fit[j] = 0;
//            }
//        }
//    }
//    int ret = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        if (fit[i] > 3)//�������Ȼ���ĵ���м���
//        {
//            ret++;
//        }
//    }
//
//    printf("%d", ret);
//    return 0;
//}

//int main()
//{
//	int x = -12;
//	int y = x % 10;
//	int i = x / 100;
//	printf("%d", i);
//	char arr='a';
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%c", arr);
//	}
//	printf("%c", arr);
//
//	return 0;
//}
//����ת��Ϊ��������
//const char* value[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//const int nums[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//
//char* intToRoman(int num) {
//    //����˼·������ͨ��ö�٣���̰��˼��������ת��
//    char* arr = (char*)malloc(sizeof(char) * 16);
//    arr[0] = '\0';
//    for (int i = 0; i < 13; i++)
//    {
//        while (num >= nums[i])//ͨ����ȥ���ֵ
//        {
//            num -= nums[i];
//            strcpy(arr + strlen(arr), value[i]);//���ÿ⺯�������п���
//        }
//        if (num == 0)
//        {
//            break;
//        }
//    }
//    return arr;
//
//}
//��������ת��Ϊ����


//int romanToInt(char* s) {
//    //����˼·�����������ַ�����ÿһλ����������
//    int symbolValues[26];
//    symbolValues['I' - 'B'] = 1;
//    symbolValues['V' - 'B'] = 5;
//    symbolValues['X' - 'B'] = 10;
//    symbolValues['L' - 'B'] = 50;
//    symbolValues['C' - 'B'] = 100;
//    symbolValues['D' - 'B'] = 500;
//    symbolValues['M' - 'B'] = 1000;
//    int n = strlen(s);
//    int value = 0;
//    int sum = 0;
//    for (int i = 0; i < n; i++)//�������ұ������飬�����һλ��ǰһλ��ͼ�ȥ
//    {
//        int value = symbolValues[s[i] - 'B'];
//        if (i < n - 1 && value < symbolValues[s[i + 1] - 'B'])
//        {
//            sum -= value;
//        }
//        else {
//            sum += value;
//        }
//    }
//    return sum;
//
//}
#include<string.h>
//int main()
//{
//	char arr[] = { "abc"};
//	char arr1[] = "abc";
//
//	int n = strlen(arr);
//	int n1 = strlen(arr);
//
//	int x = sizeof(arr) / sizeof(arr[0]);
//	int x1 = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", n);
//	printf("%d\n", n1);
//	printf("%d\n", x);
//	printf("%d\n", x1);
//	return 0;
//}
//int main()
//{
//	int x = -1;
//	int y = -x;
//	printf("%d\n", y);
//	int a = -1;
//	int b = 1;
//	int n = a ^ b;
//	printf("%d\n", n);
//	return 0;
//}

//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ����������������������


//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    //����˼·������˫ָ�뽫��������ϲ���һ���µ����飬Ȼ������λ��
//    double arr[nums1Size + nums2Size];//����������
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < nums1Size && j < nums2Size)//ͨ���±��������
//    {
//        if (nums1[i] < nums2[j])
//        {
//            arr[k] = nums1[i];
//            i++;
//        }
//        else {
//            arr[k] = nums2[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < nums1Size)//���Ǹ�����û�б������
//    {
//        arr[k] = nums1[i];
//        i++;
//        k++;
//    }
//    while (j < nums2Size)
//    {
//        arr[k] = nums2[j];
//        j++;
//        k++;
//    }
//    double x = 0;
//    if (k % 2 == 0)//�����λ��
//    {
//        x = (arr[k / 2] + arr[k / 2 - 1]) / 2;
//    }
//    else {
//        x = arr[k / 2];
//    }
//    return x;
//}
//int* fun(int x)
//{
//	x = 100;
//	return &x;
//}
//int main()
//{
//	int x = 10;
//	int* p = fun(x);
//	int y = 10;
//	printf("%d\n", *p);
//	printf("%d\n", y);
//	printf("%d\n", *p);
//
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    int n;
//    scanf("%d", &n);
//    long long arr[3][3];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%lld", &arr[i][j]);
//        }
//    }
//    int k = 0;
//    long long max[3] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        int j = 0;
//        int ret = i;
//        int x = n;
//        while (x--)
//        {
//            max[k] += arr[j % n][i % n];
//            j++;
//            i++;
//        }
//        k++;
//        i = ret;
//    }
//    long long m = max[0];
//    for (int i = 0; i < n; i++)
//    {
//        if (m < max[i])
//        {
//            m = max[i];
//        }
//    }
//    printf("%lld", m);
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    long long n;
//    scanf("%lld", &n);
//    long long d[5] = {3,5,2,3,6};
//    long long h[5] = { 4,6,5,7,5 };
//  /*  for (long long i = 0; i < n; i++)
//    {
//        scanf("%lld %lld", &d[i], &h[i]);
//    }*/
//    long long ret = n;
//    for (long long i = 0; i < n; i++)
//    {
//        int falg = 0;
//        for (long long j = 0; j < n; j++)
//        {
//            if (d[i] < d[j])
//            {
//                if (h[i] < h[j])
//                {
//                    ret--;
//                    falg = 1;
//                }
//            }
//            if (falg == 1)
//            {
//                break;
//            }
//        }
//    }
//    printf("%lld", ret);
//    return 0;
//}

//�������
//���һ����������𰸡���������
//������ʦ��ѧУ����ѧ��ʦ�����ر�ϲ����ѧ����սһЩ��Ȥ����ѧ���⡣���죬����ѧ��������һ���޴��ħ��
// �����ħ����ÿ���涼��һ�� N�� N �ķ���ÿ��С�����϶�����һ��������
//������ʦ����ѧ�����л��߰��У���ħ����һ�����ϵ������л��������У�ѭ���ƶ����ɸ�λ�á�
// ��ϣ��ѧ��ͨ���ƶ��л��У�ʹ�����Խ��ߣ����Ͻǵ����½ǣ��ϵ�����֮�����
//���ʣ�Ӧ������ƶ������ܵõ��������Խ�������֮�ͣ�
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{//����˼·��ֱ����������Խ��ߵ�ֵȻ�������Ǹ�������ħ�������ֵ
    // ���ڴ��������Ĵ���
    int n;
    scanf("%d", &n);
    long long arr[n][n];//����ħ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    int k = 0;
    long long max[n];//��ÿ���Խ��ߵ�ֵ��������
    for (int i = 0; i < n; i++)
    {
        int j = 0;//���������겻��
        int ret = i;//�����м����
        int x = n;//������Խ��ߵĴ���
        max[k] = 0;//�����ʼ��
        while (x--)
        {
            max[k] += arr[j % n][i % n];
            j++;
            i++;
        }
        k++;
        i = ret;
    }
    long long m = max[0];
    for (int i = 0; i < n; i++)
    {
        if (m < max[i])
        {
            m = max[i];
        }
    }
    printf("%lld", m);
    return 0;
}