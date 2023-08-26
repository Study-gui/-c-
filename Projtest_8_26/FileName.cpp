 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



//ѡ������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//���ǰ�tmpǰ���Ԫ�ظ�tmp�Ƚ�
			{
				a[end+1] = a[end];//�����Ԫ�ؽ�������
				end--;//�±������
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;//���tmp����С�͸���end+1�±��ֵ
		//�������,ѭ���ͻ���ֹ��
	}
}

//ϣ������
void ShellSort(int* a, int n)
{
	//ʱ�临�Ӷ�λO��N*log2Ϊ��N��
	//ϣ�����������ѡ������Ļ����ϣ�����Ԥ������gap�𽥼�С��һ����ѡ�����򣬵��ǿ��Լ�С����ʱ��
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//ÿ�μ�С
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)//���ǰ�tmpǰ���Ԫ�ظ�tmp�Ƚ�
				{
					a[end + gap] = a[end];//�����Ԫ�ؽ�������
					end-=gap;//�±������
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;//���tmp����С�͸���end+1�±��ֵ
			//�������,ѭ���ͻ���ֹ��
		}
	}
}
//��������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//����
void AdjustDwon(int* a, int n, int root)
{
	//ǰ��������������������С�ѣ�����
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ������������С���Ǹ�
		if (child+1<n && a[child + 1] > a[child])
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
//����
void HeapSort(int* a, int n)
{
	//����������������ж���,���Ƿ�ֹԽ��ʹӣ������ڶ��㿪ʼ
	for(int i = (n - 1 - 1) / 2; i>=0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//������
	int end = n - 1;
	while (end >0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	////InsertSort(arr, n);
	//ShellSort(arr, n);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	HeapSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}