 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//������Ʒ����
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//������Ʒ
	void Makedrinking()
	{
		Boil();
		Brew();
		PourCup();
		PutSomething();
	}
};
//��������
class coffee :public AbstractDrinking
{
public:
	//��ˮ
	 void Boil()
	{
		cout << "�󴿾�ˮ" << endl;
	}
	//����
	 void Brew()
	 {
		 cout << "���뿧��" << endl;
	 }
	//���뱭��
	 void PourCup()
	 {
		 cout << "���뱭��" << endl;
	 }
	//���븨��
	 void PutSomething()
	 {
		 cout << "�����Ǻ�ţ��" << endl;
	 }

};
//��������
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	//����
	void Brew()
	{
		cout << "�����Ҷ" << endl;
	}
	//���뱭��
	void PourCup()
	{
		cout << "���뱭��" << endl;
	}
	//���븨��
	void PutSomething()
	{
		cout << "��������" << endl;
	}
};
//������Ʒ
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