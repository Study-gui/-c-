//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
//
////������ģ��
//template <class nametype, class agetype>
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	nametype m_name;
//	agetype m_age;
//};
////��һ�ְ���ָ�����ʹ���
////void func(person<string,int>& p)
////{
////	cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
////
////}
////�ڶ��ֲ���ģ�黯����
////template <class T1,class T2>
////void func(person <T1, T2>& p)
////{
////	cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
////}
////�����ֽ������ģ�黯
//template<class T>
//void func(T& p)
//{
//	cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
//
//}
//void test01()
//{
//	person<string ,int>p("����", 20);
//	func(p);
	//cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
//}

//template<class T>
//class base
//{
//public:
//	base(T age)
//	{
//		m_age = age;
//	}
//	T m_age;
//};
////������Ϊ��ģ�壬����Ӧ��ָ�������е�����
////class son :public base<int>
////{
////	int m_age;
////};
////����ֱ�ӽ�����Ҳ������ģ��
//template<class T1,class T2>
//class son :public base<T2>
//{
//public:
//	son()
//	{
//		/*this->m_name = name;
//		this->m_age1 = age;*/
//		cout << typeid(T1).name() << endl;
//		cout << typeid(T2).name() << endl;
//	}
//
//	T1 m_name;
//
//};
//void test02()
//{
//	/*base<int>b(20);
//	cout << b.m_age << endl;*/
//	son<string,int> s;
//	//cout << "������"<<s.m_name<<s.m_age1<< "���䣺" << s.m_age << endl;
//}
//int main()
//{
//	//test01();
//
//	test02();
//	system("pause");
//	return 0;
//}