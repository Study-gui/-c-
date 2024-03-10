 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

class Myint
{
	friend ostream& operator<<(ostream& cout, Myint p);
public:
	Myint(int a)
	{
		m_a = a;
	}
	//Ç°ÖÃ¼õ¼õ
	Myint& operator--()
	{
		m_a--;
		return *this;
	}
	//ºóÖÃ¼õ¼õ
	 Myint operator--(int)
	{
		Myint tmp = *this;
		m_a--;
		return tmp;
	}
	int m_a;
};
ostream& operator<<(ostream& cout, Myint p)
{
	cout << p.m_a;
	return cout;
}
//ostream& operator<<(ostream& cout,const Myint& p)
//{
//	cout << p.m_a;
//	return cout;
//}
void test01()
{
	Myint p(10);
	cout << --p << endl; ;
	cout << p << endl;
}

void test02()
{
	Myint p1(10);
	cout << p1 --<< endl;;
	cout << p1 << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}



