 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;



class Student
{
public:
	Student()
	{

	}
	Student(string name, string gender, int id)
	{
		this->m_name = name;
		this->m_gender = gender;
		this->m_id = id;
	}

	string m_name;
	string m_gender;
	int m_id;
};

int main()
{
	vector<Student> person;
	string nameseed="ABCDEFGHJK";

	for (int i = 0; i < 10; i++)
	{
		string name = "ѧ��";
		Student p(name + nameseed[i], "��", i);
		person.push_back(p);
	}
	
	for (vector<Student>::iterator it = person.begin(); it != person.end(); it++)
	{
		
		ofstream ofs("student.txt", ios::out | ios::app);
		cout << "ѧ��������" << it->m_name << "ѧ���Ա�" << it->m_gender << "ѧ��ѧ�ţ�" << it->m_id << endl;
		if (!ofs.is_open())
		{
			ofs << it->m_name << it->m_gender << it->m_id << endl;
		}
		ofs.close();
	}
	
	


	return 0;
}