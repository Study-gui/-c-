// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
////创建一个抽象计算器类
//class AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//	int m_num1;
//	int m_num2;
//};
////加法
//class ADDCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 + m_num2;
//	}
//	int m_num3;
//	int m_num4;
//};
////减法
//class subCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
////利用多态来写一个计算器
////多态使用条件：父类指针或引用指向子类对象
//void test01()
//{
//	//利用父类的指针指向子类对象，父类的同名函数指针就被覆盖为子类同名函数的指针
//	AbstractCalculator* m = new ADDCalculator;
//	m->m_num1 = 10;
//	m->m_num2 = 10;
//	m->m_num1 = 100;
//	cout << m->m_num1 << "+" << m->m_num2 << "=" << m->getResult() << endl;
//	cout << m->m_num1 << endl;
//	
//
//}
//int main()
//{
//	test01();
//
//
//	system("pause");
//	return 0;
//}