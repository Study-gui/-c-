// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
////���ý�����ģ�壬���н�������
////�ַ�����
////��������
//
//
////��������ģ��
//template<class T>
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//
//template<class T>
//void mysort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
////��ӡģ��
//template<class T>
//void print(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << "  " ;
//	}
//	cout << endl;
//}
////�����ַ����飬
//void test01()
//{
//	char charArray[] = "fcbade";
//	int num = sizeof(charArray) / sizeof(charArray[0]);
//	mysort<char>(charArray, num);
//	print(charArray, num);
//}
////��������
//void test02()
//{
//	int arr[] = { 1,6,9,7,4,3 };
//	int num = sizeof(arr) / sizeof(int);
//	mysort(arr, num);
//	print(arr, num);
//}
//int main()
//{
//	//test01();
//	//test02();
//	string s;
//	cout << typeid(s).name() << endl;
//	system("pause");
//	return 0;
//}
