 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
class java {
public:
	void right()
	{
		cout << "ѧϰ ����" << endl;
	}
	void left()
	{
		cout << "���� �ο�" << endl;
	}
};

//����̳и��࣬�����ֳ������࣬�����ֳƻ���
class cpp :public java
{
public:
	void func()
	{
		cout << "cpp" << endl;
	}
};
//���Լ̳�
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
//�̳з�ʽΪ�������򰴸����Ȩ������������ͬ����Ȩ�ޣ�����˽��Ȩ�޲��ܷ���
class son1 :public Base {
public:
	void fun()
	{
		m_a = 10;
		//m_b = 20;
		//m_c = 30;
	}
};
//�̳з�ʽΪ����Ȩ�ޣ�����ȫ��Ȩ�ޱ���������ı���Ȩ�ޣ�����˽��Ȩ�޲��ܷ���
class son2 :protected Base {
public:
	void fun()
	{
		m_a = 10;
		m_b = 20;
		//m_c = 30;
	}
};
//�̳з�ʽΪ˽��Ȩ�ޣ������ȫ��Ȩ�ޱ����������˽��Ȩ�ޣ�����˽��Ȩ�޲��ܷ���
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