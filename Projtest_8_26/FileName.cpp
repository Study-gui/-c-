 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


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
	/*int end = n - 1;
	while (end >0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}*/
	//int j = 0;
	//for (j = 0; j < n; j++)
	//{
	//	AdjustDwon(a, n, j);
	//}
}
//ȡ�к���
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[mid] > a[left])
	{
		if (a[left] > a[right])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return mid;
		}
		else {
			return right;
		}
	}
	else {//a[mid]<a[left]
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[mid] > a[right])
		{
			return mid;
		}
		else {
			return right;
		}
	}
}
//��������,�ڿӷ�,ʱ�临�Ӷ�O��N*logN��
//��������׶ˣ����������Ļ�ʱ�临�ӶȾ���O��N^2��������Ҫ����ȡ�У����и�ֵ��left
//���ҿ��Խ���С�����Ż������ǵݹ鵽���棬���Խ��в������򣬴����ʡʱ�临�Ӷ�
void QuickSort(int* a, int left, int right)
{
	//�ݹ��������
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	int pivot = begin;
	int key = a[begin];
	//һ��ѭ��������
	while (begin<end)
	{
		//����������С
		while (begin<end && a[end] >= key)
		{
			end--;
		}
		//����ߵĿ����ϣ��ұ߲����µĿ�
		a[pivot] = a[end];
		pivot = end;
		//���������Ҵ�
		while (begin<end && a[begin] <= key)
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
	//[left,pivot-1] pivot [pivot+1,right]
	//С�����Ż�
	if (pivot - 1 - left < 10)
	{
		InsertSort(a + left, pivot - 1 - left + 1);
	}
	else {
		
		QuickSort(a, left, pivot - 1);
	}
	if (right - (pivot + 1) < 10)
	{
		InsertSort(a + pivot + 1, right - (pivot + 1) + 1);
	}
	else {
		QuickSort(a, pivot + 1, right);
	}
	//���÷���,�������ٴεݹ顢
	//���
	//QuickSort(a, left, pivot - 1);
	//�ұ�
	//QuickSort(a, pivot + 1, right);
}
//�������򣬽�������ʽ
void QuickSort1(int* a, int left, int right)
{
	//�ݹ���ֹ����
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	//int pivot = begin;
	int key = a[begin];
	while (begin < end)//�����ҵ��ұߴ�����������С�������н�������ͬ���ڿӷ��������ֱ�ӽ��н���
	{
		while (begin < end && a[end] >= key)//���ұ�С��key����
		{
			end--;
		}
		while (begin < end && a[begin] <= key)//����ߴ���key����
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);//���ұߴ�����������С�������н���
	}
	Swap(&a[begin], &key);//��begin��key���н���
	//����С�����Ż�
	if (begin - 1 - left < 10)
	{
		InsertSort(a + left, begin - 1 - left + 1);
	}
	else {

		QuickSort(a, left, begin - 1);
	}
	if (right - (begin + 1) < 10)
	{
		InsertSort(a + begin + 1, right - (begin + 1) + 1);
	}
	else {
		QuickSort(a, begin + 1, right);
	}



}
//�������򣬿���ָ�뷨
void QuickSort2(int* a, int left, int right)
{
	//�ݹ��������
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	//int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	//int pivot = begin;
	int key = a[left];
	int cur = left;//��ָ��
	int prev = left + 1;//��ָ��
	while (prev <= right)//�����������飬���н���
	{
		while (a[prev] < key&& ++cur!=prev)//С��key�ͽ��н���
		{
			Swap(&a[cur], &a[prev]);
		}
		prev++;
	}
	Swap(&key, &a[cur]);//�����cur��λ��һ��С��key����key���н���
	//С�����Ż�
	if (cur - 1 - left < 10)
	{
		InsertSort(a + left, cur - 1 - left + 1);
	}
	else {

		QuickSort(a, left, cur - 1);
	}
	if (right - (cur + 1) < 10)
	{
		InsertSort(a + cur + 1, right - (cur + 1) + 1);
	}
	else {
		QuickSort(a, cur + 1, right);
	}
}
//�鲢�Ӻ���
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1,right,tmp);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1; 
	int end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else {
			tmp[index++] = a[begin2++];
		}
	}

	for (int i = 0; i < right ;i++)
	{
		a[i] = tmp[i];
	}
}
//�鲢����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);

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
	int arr[] = {3,5,2,7,8,6,1,9,4,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	////InsertSort(arr, n);
	//ShellSort(arr, n);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	HeapSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//SelectSort(arr, n);
	//QuickSort1(arr, 0, n - 1);
	//QuickSort2(arr, 0, n - 1);
	//MergeSort(arr,n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}