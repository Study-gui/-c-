//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
//
////创建类模板
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
////第一种按照指定类型传入
////void func(person<string,int>& p)
////{
////	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
////
////}
////第二种参数模块化传入
////template <class T1,class T2>
////void func(person <T1, T2>& p)
////{
////	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
////}
////第三种将类进行模块化
//template<class T>
//void func(T& p)
//{
//	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
//
//}
//void test01()
//{
//	person<string ,int>p("张三", 20);
//	func(p);
	//cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
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
////父类作为类模板，子类应该指定父类中的类型
////class son :public base<int>
////{
////	int m_age;
////};
////或者直接将子类也进行类模板
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
//	//cout << "姓名："<<s.m_name<<s.m_age1<< "年龄：" << s.m_age << endl;
//}
//int main()
//{
//	//test01();
//
//	test02();
//	system("pause");
//	return 0;
//}