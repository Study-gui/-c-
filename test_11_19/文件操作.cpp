 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//写文件
void test01()
{
	//创建写文件流对象
	ofstream ofs;
	//指定打开方式
	ofs.open("test.txt", ios::out);
	//写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：20" << endl;
	//关闭文件
	ofs.close();
}
//读文件
void test02()
{
	//创建读文件流对象
	ifstream ifs;
	//打开方式
	ifs.open("test.txt", ios::in);
	//判断是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读文件
	//第一种方式
	/*char m[1024] = { 0 };
	while (ifs.getline((char*)&m,sizeof(m)))
	{
		cout << m << endl;
	}*/
	//第二种方式
	string m;
	while (getline(ifs, m))
	{
		cout << m << endl;
	}
	//关闭文件
	ifs.close();
}
//以二进制写文件
class person
{
public:
	string m_name;
	int m_age;
};
void test03()
{
	//创建写文件流对象
	ofstream ofs;
	//打开方式
	ofs.open("person.txt", ios::out | ios::binary);
	//写文件
	person p;
	p.m_age = 20;
	p.m_name= "张三";
	ofs.write((const char*)&p, sizeof(person));
	//关闭文件
	ofs.close();
}
//以二进制读文件
void test04()
{
	//创建二进制读文件流对象
	ifstream ifs;
	//打开方式
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读文件
	person m;
	ifs.read((char*)&m, sizeof(person));
	cout << "姓名：" << m.m_name << " 年龄：" << m.m_age << endl;
	//关闭文件
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