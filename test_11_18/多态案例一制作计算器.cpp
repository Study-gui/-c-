// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
////����һ�������������
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
////�ӷ�
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
////����
//class subCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
////���ö�̬��дһ��������
////��̬ʹ������������ָ�������ָ���������
//void test01()
//{
//	//���ø����ָ��ָ��������󣬸����ͬ������ָ��ͱ�����Ϊ����ͬ��������ָ��
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