 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class person
{
	//ȫ�ֺ����ڳ�Ա�����ڲ�����Ԫ
	friend ostream& operator<<(ostream& cout, person p);
public:
	person(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
	person operator+(person& p)//����+��
	{
		this->m_a += p.m_a;
		this->m_b += p.m_b;
		return *this;
	}
	
private:
	int m_a;
	int m_b;
};
//����<<�����������ʱ��������Ա������ֻ����ȫ�ֺ���
ostream& operator<<(ostream& cout, person p)//���ʾ���cout<<p
{
	cout << "p1->m_a��ֵ��"<<p.m_a << " p1->m_b��ֵ��" << p.m_b << endl;
	return cout;
}

//��������������ͼӺ�����
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

	Myint& operator++()//��Ϊ++p,ǰ��++
	{
		m_a++;
		return *this;
	}
	//����int��ʾռλ����������ǰ��++�ͺ���++
	Myint operator++(int)//����ֵ�����ܷ������ã�ӦΪ����Ϊ�ֲ�����
	{
		Myint tmp = *this;
		m_a++;
		return tmp;
	}
	int m_a;

};
ostream& operator<<(ostream& cout, Myint p)//���ʾ���cout<<p
{
	cout << "m_a��ֵ��" << p.m_a << endl;
	return cout;
}
//���Ե�������
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
	Person& operator=(Person&p)//������=���������Ҫע����ǳ���������⣬һ�����Լ���������ɾ���
		//����new�����µĶ���
	{//����ֱ�ӿ������������ֵ�������ö����ĵ�ַ
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
//����=�����
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