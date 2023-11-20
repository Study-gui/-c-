 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

template<class T1,class T2>
class base
{
public:
	base(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	T1 m_name;
	T2 m_age;
};

template<class T1,class T2>
class son :public base<T1, T2>
{
public:
	void fun()
	{
		cout << typeid(T1).name() << endl;
	}
};


void test01()
{
	base<string, int>b("уехЩ", 20);
	cout << b.m_name << endl;
	cout << b.m_age << endl;
	son<string, int>s;
	s.fun();
}

int main()
{


	test01();
	system("pause");
	return 0;
}