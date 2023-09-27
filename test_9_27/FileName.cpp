 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
//using namespace std;
//
//class student
//{
//public:
//	int age;
//	string name;
//	void print()
//	{
//		cout << "年龄：" << age << endl;
//		cout << "姓名：" << name << endl;
//	}
//};
//
//
//
//int main()
//{
//
//	student n1,n2;
//	n1.age = 20;
//	n1.name= "zhangsan";
//	n2.age = 22;
//	n2.name = "lisi";
//
//	n1.print();
//	n2.print();
//	//cout << "学生信息："<< n1.print() << endl;
//	system("pause");
//	return 0;
//}


//给定一个长度为N的数组A=A1,A2,AN］，数组中有可能有重复出现的整数。
//现在小明要按以下方法将其修改为没有重复整数的数组。小明会依次修改A2, A3，•，AN。
//当修改 A；时，小明会检查A；是否在4」~Ai—1中出现过。如果出现过，则小明会给A；加上1；如果新的A；
// 仍在之前出现过，小明会持续给 A；加1，直到A；没有在A1~4i - 1中出现过。
//当 AN 也经过上述修改之后，显然4 数組中就沒有重复的整数了。
//现在给定初始的4数组，请你计算出最终的A数组


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //本体思路:就是通过一个标志位的数组，来记录前面是否出现过此数字
    //关键在于，优化计数 如果前面加自己出现的数字加加减一即可，不用从重复加加
    // 请在此输入您的代码
    int n;
    scanf("%d", &n);
    int arr[100005];
    int brr[1000005] = { 0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        while (brr[arr[i]] != 0)
        {
            brr[arr[i]]++;//对有的数进行加加等于加上自己一共出现了多少个这个数
            arr[i] += brr[arr[i]] - 1;  //关键一步
        }
        if (brr[arr[i]] == 0)
        {
            brr[arr[i]] = 1;
        }
        printf("%d ", arr[i]);
    }
    return 0;
}