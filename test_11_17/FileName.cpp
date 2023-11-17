 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
class java {
public:
	void right()
	{
		cout << "学习 资料" << endl;
	}
	void left()
	{
		cout << "课堂 参考" << endl;
	}
};

//子类继承父类，子类又称派生类，父类又称基类
class cpp :public java
{
public:
	void func()
	{
		cout << "cpp" << endl;
	}
};
//测试继承
void test01()
{
	cpp c;
	c.func();
	c.left();
	c.right();
}
class Base {
	
public:
	Base()
	{
		m_a = 100;
		m_b = 200;
		m_c = 300;
	}
	int m_a;
	int m_b;
protected:
	
private:
	int m_c;
};
//继承方式为公共，则按父类的权限来当作子类同样的权限，父类私有权限不能访问
class son1 :public Base {
public:
	void fun()
	{
		m_a = 10;
		//m_b = 20;
		//m_c = 30;
	}
};
//继承方式为保护权限，则父类全部权限被当作子类的保护权限，父类私有权限不能访问
class son2 :protected Base {
public:
	void fun()
	{
		m_a = 10;
		m_b = 20;
		//m_c = 30;
	}
};
//继承方式为私有权限，则父类的全部权限被当作子类的私有权限，父类私有权限不能访问
class son3 :private Base {
public:
	void fun()
	{
		m_a = 10;
		m_b = 20;
		//m_c = 30;
	}
};
void test02()
{
	son1 s1;
	s1.fun();
	cout << s1.m_a << endl;
	cout << s1.Base::m_b << endl;
	//son2 s2;
	/*s2.fun();
	cout << s2.m_a << endl;*/

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}