 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��дһ���꣬ʵ��һ�������Ķ�����ż��λ������λ���н���
//#define swap_int(n)  (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))
//int main()
//{
//	//�涨���λ�±�λ0
//	//ʵ�ֽ�����Ҫ���еõ�ż��λ������λ,�ٰ�ż��λ������λ�������
//	//�õ�ż��λ����һ��ż��λΪ1����λΪ0�������뼰�ܵõ�����0x55555555
//	//�õ�����λ����һ��ż��λΪ0����λΪ1�������뼰�ܵõ�����0xaaaaaaaa
//	int n = 0;
//	scanf("%d", &n);
//	//swap_int(n);
//	printf("%d", swap_int(n));
//	return 0;
//}
//��һ����nÿ��ֻ��n-1����n+1����Ҫ�������ٲ����쳲�������
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
//����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1��
//���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci��
#include<math.h>
//��Ҫ���ú���abs�����ֵ����ȷ����Χ��Ƚ�����
int main()
{
	int n = 0;
	int a = 0;
	int b = 1;
	int c = a + b;
	scanf("%d", &n);
	while (1)
	{
		if (n == b)
		{
			printf("0\n");
			break;
		}
		else if (n < b)
		{
			if (abs(b - n) < abs(a - n))
			{
				printf("%d\n", abs(b - n));
				break;
			}
			else {
				printf("%d\n", abs(a - n));
				break;
			}
		}
		else {
			a = b;
			b = c;
			c = a + b;
		}
	}

	return 0;
}