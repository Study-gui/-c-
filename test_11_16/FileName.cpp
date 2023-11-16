 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class person
{
	//全局函数在成员函数内部作友元
	friend ostream& operator<<(ostream& cout, person p);
public:
	person(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
	person operator+(person& p)//重载+号
	{
		this->m_a += p.m_a;
		this->m_b += p.m_b;
		return *this;
	}
	
private:
	int m_a;
	int m_b;
};
//重载<<左移运算符的时候不能作成员函数，只能做全局函数
ostream& operator<<(ostream& cout, person p)//本质就是cout<<p
{
	cout << "p1->m_a的值："<<p.m_a << " p1->m_b的值：" << p.m_b << endl;
	return cout;
}

//测试左移运算符和加号重载
void test01()
{
	person p1(10, 10);
	person p2(20, 20);
	person p3 = p1 + p2;
	//p1 + p2;
	cout << p1 + p2 << endl;
	cout << p1 <<endl;
	cout << p3 << endl;
	p3 + p1;
	cout << p3;
}
class Myint
{
public:
	Myint()
	{
		m_a = 0;
    }

	Myint& operator++()//简化为++p,前置++
	{
		m_a++;
		return *this;
	}
	//利用int表示占位参数，区分前置++和后置++
	Myint operator++(int)//返回值，不能返回引用，应为引用为局部变量
	{
		Myint tmp = *this;
		m_a++;
		return tmp;
	}
	int m_a;

};
ostream& operator<<(ostream& cout, Myint p)//本质就是cout<<p
{
	cout << "m_a的值：" << p.m_a << endl;
	return cout;
}
//测试递增重载
void test02()
{
	Myint p;
	cout << p << endl;
	cout << ++p << endl;
	cout << p++ << endl;
	cout << p++ << endl;
	cout << p << endl;
}
//
class Person 
{
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	Person& operator=(Person&p)//当重载=号运算符是要注意深浅拷贝的问题，一定把自己堆区清理干净，
		//再用new开辟新的堆区
	{//或者直接拷贝本身堆区的值，并不该堆区的地址
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		return *this;
		/**m_age = *p.m_age;
		return *this;*/
	}

	int* m_age;
};
//重载=运算符
void test03()
{
	Person p1(10);
	Person p2(20);
	cout << *p2.m_age << endl;
	p2 = p1;
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;

}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}