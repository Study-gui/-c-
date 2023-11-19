 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//д�ļ�
void test01()
{
	//����д�ļ�������
	ofstream ofs;
	//ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);
	//д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺20" << endl;
	//�ر��ļ�
	ofs.close();
}
//���ļ�
void test02()
{
	//�������ļ�������
	ifstream ifs;
	//�򿪷�ʽ
	ifs.open("test.txt", ios::in);
	//�ж��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ļ�
	//��һ�ַ�ʽ
	/*char m[1024] = { 0 };
	while (ifs.getline((char*)&m,sizeof(m)))
	{
		cout << m << endl;
	}*/
	//�ڶ��ַ�ʽ
	string m;
	while (getline(ifs, m))
	{
		cout << m << endl;
	}
	//�ر��ļ�
	ifs.close();
}
//�Զ�����д�ļ�
class person
{
public:
	string m_name;
	int m_age;
};
void test03()
{
	//����д�ļ�������
	ofstream ofs;
	//�򿪷�ʽ
	ofs.open("person.txt", ios::out | ios::binary);
	//д�ļ�
	person p;
	p.m_age = 20;
	p.m_name= "����";
	ofs.write((const char*)&p, sizeof(person));
	//�ر��ļ�
	ofs.close();
}
//�Զ����ƶ��ļ�
void test04()
{
	//���������ƶ��ļ�������
	ifstream ifs;
	//�򿪷�ʽ
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ļ�
	person m;
	ifs.read((char*)&m, sizeof(person));
	cout << "������" << m.m_name << " ���䣺" << m.m_age << endl;
	//�ر��ļ�
	ifs.close();
}
int main()
{
	
	//test01();
	//test02();
	test03();
	test04();


	system("pause");
	return 0;
}