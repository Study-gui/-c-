// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//
////cpu类
//class Cpu
//{
//public:
//	virtual void calculate() = 0;
//};
////显卡类
//class VideoCard
//{
//public:
//	virtual void Display() = 0;
//};
////内存条类
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
////电脑类
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
//		//释放cpu
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		//释放显卡
//		if (m_vid != NULL)
//		{
//			delete m_vid;
//			m_vid = NULL;
//		}
//		//释放内存条
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
////Inter厂商类
//class Intercpu :public Cpu
//{
//public:
//	void calculate()
//	{
//		cout << "Inter的cpu开始工作了" << endl;
//	}
//};
//class InterVideoCard :public VideoCard
//{
//public:
//	void Display()
//	{
//		cout << "Inter的显卡开始工作了" << endl;
//	}
//};
//class InterMemory :public Memory
//{
//public:
//	void storage()
//	{
//		cout << "Inter的内存开始存储了" << endl;
//	}
//};
////Lenove厂商类
//class Levenocpu :public Cpu
//{
//public:
//	void calculate()
//	{
//		cout << "Leveno的cpu开始工作了" << endl;
//	}
//};
//class LevenoVideoCard :public VideoCard
//{
//public:
//	void Display()
//	{
//		cout << "Leveno的显卡开始工作了" << endl;
//	}
//};
//class LevenoMemory :public Memory
//{
//public:
//	void storage()
//	{
//		cout << "Leveno的内存开始存储了" << endl;
//	}
//};
//void test01()
//{
//	//利用父类指针指向子类对象
//	Cpu* InterCpu = new Intercpu;
//	VideoCard* Intervid = new InterVideoCard;
//	Memory* Intermem = new InterMemory;
//	cout << "第一台电脑" << endl;
//	Computer* com1 = new Computer(InterCpu,Intervid,Intermem);
//	com1->Work();
//	delete com1;
//	com1 = NULL;
//	cout << "------------------------------" << endl;
//	cout << "第二台电脑" << endl;
//	Computer* com2 = new Computer(new Levenocpu,new LevenoVideoCard, new LevenoMemory);
//	com2->Work();
//	delete com2;
//    com2 = NULL;
//	cout << "------------------------------" << endl;
//	cout << "第三台电脑" << endl;
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