 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//С��������ڿ���ѧϰ����������������������Լ������С����������������Ȼ������������������
//���Լ������С������֮��������������������⡣
//1,�������,ͨ�����Լ������С������������������
//int main()
//{
//	long n = 0, m = 0;
//	scanf("%ld %ld", &n, &m);
//	long min = n < m ? n : m;
//	long max = n > m ? n : m;
//	int i = min;
//	int j = max;
//	while (1)
//	{
//		if (n % min == 0 && m % min==0)
//		{
//			break;
//		}
//		min--;
//	}
//	while (1)
//	{
//		if (max % n == 0 && max % m == 0)
//		{
//			break;
//		}
//		max++;
//	}
//	printf("%ld\n", min + max);
//	return 0;
//}
//����շת�����
int main()
{
	long n = 0, m = 0;
	scanf("%ld %ld", &n, &m);
	long i = n, j = m;
	long r = 0;
	while (r = i % j)
	{
		i = j;
		j = r;
	}
	//��С����������������˳������Լ��
	long min = (n * m) / j;
	printf("%ld\n", min + j);
	return 0;
}