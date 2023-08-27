 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



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
	int end = n - 1;
	while (end >0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
//快速排序,挖坑法
void QuickSort(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//一次循环的条件
	while (begin<end)
	{
		//从右往左找小
		while (begin<end && a[end] > key)
		{
			end--;
		}
		//把左边的坑填上，右边产生新的坑
		a[pivot] = a[end];
		pivot = end;
		//从左往右找大
		while (begin<end && a[begin] < key)
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
	//采用分治,将两边再次递归、
	//左边
	QuickSort(a, left, pivot - 1);
	//右边
	QuickSort(a, pivot + 1, right);
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