 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



//��������
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
{//���ѣ�ʱ�临�Ӷ�ΪO��N��
	//����������������ж���,���Ƿ�ֹԽ��ʹӣ������ڶ��㿪ʼ
	for(int i = (n - 1 - 1) / 2; i>=0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//������
	//���򣬲��ý���ѣ�ʱ�临�Ӷ�ΪO��N*logN��
	int end = n - 1;
	while (end >0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
//��������,�ڿӷ�
void QuickSort(int* a, int left, int right)
{
	//�ݹ��������
	if (left >= right)
	{
		return;
	}
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//һ��ѭ��������
	while (begin<end)
	{
		//����������С
		while (begin<end && a[end] > key)
		{
			end--;
		}
		//����ߵĿ����ϣ��ұ߲����µĿ�
		a[pivot] = a[end];
		pivot = end;
		//���������Ҵ�
		while (begin<end && a[begin] < key)
		{
			begin++;
		}
		//���ұߵĿ����ϣ���߲����µĿ�
		a[pivot] = a[begin];
		pivot = begin;
	}
	//�����Ŀӣ��ü�¼��key������
	pivot = begin;
	a[pivot] = key;
	//���÷���,�������ٴεݹ顢
	//���
	QuickSort(a, left, pivot - 1);
	//�ұ�
	QuickSort(a, pivot + 1, right);
}
//ѡ����룬ʱ�临�Ӷ�ΪO��N^2��
void SelectSort(int* a, int n)
{
	int left = 0, right = n-1;
	while (left < right)//��������б���
	{
		if (a[left] > a[right])//������С���ұߣ��ͽ��н���
		{
			Swap(&a[left], &a[right]);
		}
		left++;
		right--;
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
	//HeapSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	SelectSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}