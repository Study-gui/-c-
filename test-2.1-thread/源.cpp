// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<string>
//using namespace std;
//
//
//void printHello()
//{
//
//	cout << "hello world" << endl;
//}
//void add(int& a)
//{
//	a++;
//}
//void test()
//{
//	int a = 1;
//	thread thread2(add, ref(a));
//	//thread2.join();
//}
//static Log* loog = NULL;
//once_flag once;
//class Log
//{
//public:
//	Log() {};
//	~Log() {};
//	static Log& getinstance()
//	{
//		//static log Log;
//		//if(!log) log = new Log;
//		call_once(once, &init);
//		return *loog;
//	}
//	 static void init()
//	{
//		if (!loog) loog = new Log;
//		//static Log Log;
//	}
//	void print()
//	{
//		cout << "hello world" << endl;
//	}
//};
//void print()
//{
//	Log::getinstance().print();
//
//}
//int main()
//{
//	/*thread thread1(printhello);
//	thread1.join();*/
//	/*test();
//	t.join();*/
//	thread t1(print);
//	thread t2(print);
//	t1.join();
//	t2.join();
//	system("pause");
//	return 0;
//}