 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��sn=a+aa+aaa+aaaa+aaaaa...ǰn��ĺ�
//*int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sn = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sn += ret;
//	}
//	printf("%d ", sn);
//	return *
//}
//��һ��1��10000֮���ˮ�ɻ���
//����153=1^3+5^3+5^3����nλ����n�η��ĺ�
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10001; i++)
//	{
//		//�ж�i�м�λ��
//		int a = 0;
//		int ret =i;
//		int sum = 0;
//		while (ret)
//		{
//			a++;
//			ret /= 10;
//		}
//		//�õ�i��ÿһλ
//		// 1234��
//		//����nλ���ĺ�
//		ret = i;
//		while (ret)
//		{
//			sum += pow((ret  % 10), a);
//			ret /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//����ˮ���⣬һƿ��ˮһԪǮ��������ƿ���Ի�һƿ��ˮ����20��Ǯ���Ժȶ�����ˮ
int is_qishui(int n)
{
	int ret = 0;
	while (n >= 2)
	{
		ret++;
		n--;
	}
	return ret;
}
int main()
{
	//nΪ��ƿ��
	int n = 20;
	int tmp = is_qishui(n);
	printf("%d", tmp + 20);
	return 0;
}