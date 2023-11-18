 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//制作饮品父类
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品
	void Makedrinking()
	{
		Boil();
		Brew();
		PourCup();
		PutSomething();
	}
};
//制作咖啡
class coffee :public AbstractDrinking
{
public:
	//煮水
	 void Boil()
	{
		cout << "煮纯净水" << endl;
	}
	//冲泡
	 void Brew()
	 {
		 cout << "加入咖啡" << endl;
	 }
	//倒入杯中
	 void PourCup()
	 {
		 cout << "倒入杯中" << endl;
	 }
	//加入辅料
	 void PutSomething()
	 {
		 cout << "加入糖和牛奶" << endl;
	 }

};
//制作茶类
class Tea :public AbstractDrinking
{
public:
	//煮水
	void Boil()
	{
		cout << "煮矿泉水" << endl;
	}
	//冲泡
	void Brew()
	{
		cout << "加入茶叶" << endl;
	}
	//倒入杯中
	void PourCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};
//制作饮品
void doDrinking(AbstractDrinking* m)
{
	m->Makedrinking();
	delete m;
}
void test01()
{
	doDrinking(new coffee);
	cout << "--------------------" << endl;
	doDrinking(new Tea);

}
int main()
{

	test01();

	system("pause");
	return 0;
}