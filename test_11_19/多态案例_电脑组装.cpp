// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
////cpu��
//class Cpu
//{
//public:
//	virtual void calculate() = 0;
//};
////�Կ���
//class VideoCard
//{
//public:
//	virtual void Display() = 0;
//};
////�ڴ�����
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
////������
//class Computer
//{
//public:
//	Computer(Cpu* cpu,VideoCard* vid,Memory* mem)
//	{
//		m_cpu = cpu;
//		m_vid = vid;
//		m_mem = mem;
//	}
//	~Computer()
//	{
//		//�ͷ�cpu
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		//�ͷ��Կ�
//		if (m_vid != NULL)
//		{
//			delete m_vid;
//			m_vid = NULL;
//		}
//		//�ͷ��ڴ���
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//	void Work()
//	{
//		m_cpu->calculate();
//		m_vid->Display();
//		m_mem->storage();
//	}
//	
//private:
//	Cpu* m_cpu;
//	VideoCard* m_vid;
//	Memory* m_mem;
//};
////Inter������
//class Intercpu :public Cpu
//{
//public:
//	void calculate()
//	{
//		cout << "Inter��cpu��ʼ������" << endl;
//	}
//};
//class InterVideoCard :public VideoCard
//{
//public:
//	void Display()
//	{
//		cout << "Inter���Կ���ʼ������" << endl;
//	}
//};
//class InterMemory :public Memory
//{
//public:
//	void storage()
//	{
//		cout << "Inter���ڴ濪ʼ�洢��" << endl;
//	}
//};
////Lenove������
//class Levenocpu :public Cpu
//{
//public:
//	void calculate()
//	{
//		cout << "Leveno��cpu��ʼ������" << endl;
//	}
//};
//class LevenoVideoCard :public VideoCard
//{
//public:
//	void Display()
//	{
//		cout << "Leveno���Կ���ʼ������" << endl;
//	}
//};
//class LevenoMemory :public Memory
//{
//public:
//	void storage()
//	{
//		cout << "Leveno���ڴ濪ʼ�洢��" << endl;
//	}
//};
//void test01()
//{
//	//���ø���ָ��ָ���������
//	Cpu* InterCpu = new Intercpu;
//	VideoCard* Intervid = new InterVideoCard;
//	Memory* Intermem = new InterMemory;
//	cout << "��һ̨����" << endl;
//	Computer* com1 = new Computer(InterCpu,Intervid,Intermem);
//	com1->Work();
//	delete com1;
//	com1 = NULL;
//	cout << "------------------------------" << endl;
//	cout << "�ڶ�̨����" << endl;
//	Computer* com2 = new Computer(new Levenocpu,new LevenoVideoCard, new LevenoMemory);
//	com2->Work();
//	delete com2;
//    com2 = NULL;
//	cout << "------------------------------" << endl;
//	cout << "����̨����" << endl;
//	Computer* com3 = new Computer(new Levenocpu, new InterVideoCard, new LevenoMemory);
//	com3->Work();
//	delete com3;
//	com3 = NULL;
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}