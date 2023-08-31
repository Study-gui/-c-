 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//就是把tmp前面的元素跟tmp比较
			{
				a[end+1] = a[end];//将大的元素进行排序
				end--;//下标向后走
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;//如果tmp是最小就付给end+1下标的值
		//如果不是,循环就会终止，
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	//时间复杂度位O（N*log2为底N）
	//希尔排序就是在选择排序的基础上，进行预排序，是gap逐渐减小到一就是选择排序，但是可以减小运行时间
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//每次减小
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)//就是把tmp前面的元素跟tmp比较
				{
					a[end + gap] = a[end];//将大的元素进行排序
					end-=gap;//下标向后走
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;//如果tmp是最小就付给end+1下标的值
			//如果不是,循环就会终止，
		}
	}
}
//交换函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//堆排
void AdjustDwon(int* a, int n, int root)
{
	//前提条件是左右子树都是小堆，才行
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右子树最小的那个
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
//建堆
void HeapSort(int* a, int n)
{//建堆，时间复杂度为O（N）
	//从最下面往上面进行堆排,但是防止越界就从，倒数第二层开始
	for(int i = (n - 1 - 1) / 2; i>=0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//堆排序
	//升序，采用建大堆，时间复杂度为O（N*logN）
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
//取中函数
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
//快速排序,挖坑法,时间复杂度O（N*logN）
//快速排序弊端，如果是有序的话时间复杂度就是O（N^2），所以要进行取中，进行赋值给left
//并且可以进行小区间优化，就是递归到后面，可以进行插入排序，代替节省时间复杂度
void QuickSort(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	int pivot = begin;
	int key = a[begin];
	//一次循环的条件
	while (begin<end)
	{
		//从右往左找小
		while (begin<end && a[end] >= key)
		{
			end--;
		}
		//把左边的坑填上，右边产生新的坑
		a[pivot] = a[end];
		pivot = end;
		//从左往右找大
		while (begin<end && a[begin] <= key)
		{
			begin++;
		}
		//把右边的坑填上，左边产生新的坑
		a[pivot] = a[begin];
		pivot = begin;
	}
	//把最后的坑，用记录的key，填上
	pivot = begin;
	a[pivot] = key;
	//[left,pivot-1] pivot [pivot+1,right]
	//小区间优化
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
	//采用分治,将两边再次递归、
	//左边
	//QuickSort(a, left, pivot - 1);
	//右边
	//QuickSort(a, pivot + 1, right);
}
//快速排序，交换的形式
void QuickSort1(int* a, int left, int right)
{
	//递归终止条件
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	//int pivot = begin;
	int key = a[begin];
	while (begin < end)//就是找到右边大的数，和左边小的数进行交换，不同与挖坑法，这个是直接进行交换
	{
		while (begin < end && a[end] >= key)//找右边小于key的数
		{
			end--;
		}
		while (begin < end && a[begin] <= key)//找左边大于key的数
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);//把右边大的数，和左边小的数进行交换
	}
	Swap(&a[begin], &key);//把begin跟key进行交换
	//进行小区间优化
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
//快速排序，快慢指针法
void QuickSort2(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}
	int mid = GetMid(a, left, right);
	//int begin = left, end = right;
	Swap(&a[left], &a[mid]);
	//int pivot = begin;
	int key = a[left];
	int cur = left;//慢指针
	int prev = left + 1;//快指针
	while (prev <= right)//遍历整个数组，进行交换
	{
		while (a[prev] < key&& ++cur!=prev)//小于key就进行交换
		{
			Swap(&a[cur], &a[prev]);
		}
		prev++;
	}
	Swap(&key, &a[cur]);//把最后（cur的位置一定小于key）和key进行交换
	//小区间优化
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
//归并子函数
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
//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);

}
//选择插入，时间复杂度为O（N^2）
void SelectSort(int* a, int n)
{
	int left = 0, right = n-1;
	while (left < right)//对数组进行遍历
	{
		if (a[left] > a[right])//如果左边小于右边，就进行交换
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