 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

class personB
{
public:
	personB(int x)
	{
		this->age = x;
		cout << "构造函数B的调用:" << this->age << endl;
	}
	~personB()
	{
		cout << "析构函数B的调用:" << this->age << endl;
	}
	int age;
};
class personA
{
public:
	personA(int x, int y) :m_age(x), m_p(y)
	{
		/*this->m_age = x;
		this->m_p= y;*/
		cout << "构造函数A的调用:" <<this->m_age<< endl;
	}
	~personA()
	{
		cout << "析构函数A的调用:" <<this->m_age<< endl;
	}
	int m_age;
	personB m_p;
};


void test01()
{

	personA p1(1,3);
	//person p2(2);
}
void print(pair<int, int>& v)
{
	cout << v.first << "   "<<v.second << endl;
}
bool cmp(pair<int, int>& v1, pair<int, int>& v2)
{
	return v1.first > v2.first;
}
int main()
{
	//test01();
	//vector<int>v(10);
	//for (int x = 0; x < 10; x++)
	//{
	//	cin >> v[x];
	//	//v.push_back(x);
	//}
	vector<pair<int, int>>v(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	for_each(v.begin(), v.end(), print);
	
	system("pause");
	return 0;
}

////编写一个函数，传入一个十进制的正整数，将十进制整数转换为十六进制的字符串并返回。（十六进制字符串中的字母全部大写）
//输入描述：
//键盘输入一个十进制的正整数
//输出描述：
//输出该十进制整数转换后的十六进制字符串

//#include <iostream>
//#include <string>
//using namespace std;
//
//string toHexString(int n);
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	string hexStr = toHexString(n);
//	cout << hexStr << endl;
//
//	return 0;
//}
//
//string toHexString(int n) {
//	// write your code here......
//	//本题思路：要充分了解string类的字符拼接，和对十进制转十六进制的理解
//	string arr = "";
//	string ret = "0123456789ABCDEF";
//	while (n != 0)
//	{
//		int k = n % 16;
//		arr = ret[k] + arr;
//		n = n / 16;
//	}
//	return arr;
//
//}


//问题描述
//网坤老师是一位热爱中国传统文化BS老师，特别盛欢收藏各种各样的瓷器。他有一个习惯，
// 就是在每一个瓷器底部都标注上瓷器的直
//一天，阿坤老师突然想整理一下自己的瓷器收廠。他有一个特别的定义：独特资器”，即对于个资器 A，
// 如果不存在另一个资器B，其直径和高度都严格大于瓷器 A 的直径和高度，则称瓷器A为
//独特瓷器”。
//阿坤老师有 N个瓷器，每个瓷器都有一个直径和高度。请你帮助阿坤老师，计算出他的瓷器收藏中有多少个
// “独特瓷器”。
//输入的第一行包含一个整数I（I≤ N≤ 10°）。
//接下来的N行，每行包含两个整数，分别表示瓷器的直径d和高度h（I≤dh≤100。
//输出格式
//输出一个整数，表示阿坤老师的瓷器收藏中“独特瓷器”的数量。
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int>v1, pair<int, int>v2)
{
	return v1.first > v2.first;
}
int main()
{
	//本题思路：利用队组的特点把直径和高度相结合
	//利用sort进行排序，找到高度的关系
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	// sort(v.begin(),v.end(),[&](pair<int,int>v1,pair<int,int>v2)
	// {
	//   return v1.first>v2.first;
	// });
	// 请在此输入您的代码
	sort(v.begin(), v.end(), cmp);
	int count = 0;
	int smax = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second >= smax)
		{
			count++;
		}
		smax = max(smax, v[i].second);
	}
	cout << count;
	return 0;
}