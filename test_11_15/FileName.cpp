 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

class personB
{
public:
	personB(int x)
	{
		this->age = x;
		cout << "���캯��B�ĵ���:" << this->age << endl;
	}
	~personB()
	{
		cout << "��������B�ĵ���:" << this->age << endl;
	}
	int age;
};
class personA
{
public:
	personA(int x, int y) :m_age(x), m_p(y)
	{
		/*this->m_age = x;
		this->m_p= y;*/
		cout << "���캯��A�ĵ���:" <<this->m_age<< endl;
	}
	~personA()
	{
		cout << "��������A�ĵ���:" <<this->m_age<< endl;
	}
	int m_age;
	personB m_p;
};


void test01()
{

	personA p1(1,3);
	//person p2(2);
}
void print(pair<int, int>& v)
{
	cout << v.first << "   "<<v.second << endl;
}
bool cmp(pair<int, int>& v1, pair<int, int>& v2)
{
	return v1.first > v2.first;
}
int main()
{
	//test01();
	//vector<int>v(10);
	//for (int x = 0; x < 10; x++)
	//{
	//	cin >> v[x];
	//	//v.push_back(x);
	//}
	vector<pair<int, int>>v(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	for_each(v.begin(), v.end(), print);
	
	system("pause");
	return 0;
}

////��дһ������������һ��ʮ���Ƶ�����������ʮ��������ת��Ϊʮ�����Ƶ��ַ��������ء���ʮ�������ַ����е���ĸȫ����д��
//����������
//��������һ��ʮ���Ƶ�������
//���������
//�����ʮ��������ת�����ʮ�������ַ���

//#include <iostream>
//#include <string>
//using namespace std;
//
//string toHexString(int n);
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	string hexStr = toHexString(n);
//	cout << hexStr << endl;
//
//	return 0;
//}
//
//string toHexString(int n) {
//	// write your code here......
//	//����˼·��Ҫ����˽�string����ַ�ƴ�ӣ��Ͷ�ʮ����תʮ�����Ƶ����
//	string arr = "";
//	string ret = "0123456789ABCDEF";
//	while (n != 0)
//	{
//		int k = n % 16;
//		arr = ret[k] + arr;
//		n = n / 16;
//	}
//	return arr;
//
//}


//��������
//������ʦ��һλ�Ȱ��й���ͳ�Ļ�BS��ʦ���ر�ʢ���ղظ��ָ����Ĵ���������һ��ϰ�ߣ�
// ������ÿһ�������ײ�����ע�ϴ�����ֱ
//һ�죬������ʦͻȻ������һ���Լ��Ĵ����ՏS������һ���ر�Ķ��壺�����������������ڸ����� A��
// �����������һ������B����ֱ���͸߶ȶ��ϸ���ڴ��� A ��ֱ���͸߶ȣ���ƴ���AΪ
//���ش�������
//������ʦ�� N��������ÿ����������һ��ֱ���͸߶ȡ��������������ʦ����������Ĵ����ղ����ж��ٸ�
// �����ش�������
//����ĵ�һ�а���һ������I��I�� N�� 10�㣩��
//��������N�У�ÿ�а��������������ֱ��ʾ������ֱ��d�͸߶�h��I��dh��100��
//�����ʽ
//���һ����������ʾ������ʦ�Ĵ����ղ��С����ش�������������
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int>v1, pair<int, int>v2)
{
	return v1.first > v2.first;
}
int main()
{
	//����˼·�����ö�����ص��ֱ���͸߶�����
	//����sort���������ҵ��߶ȵĹ�ϵ
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	// sort(v.begin(),v.end(),[&](pair<int,int>v1,pair<int,int>v2)
	// {
	//   return v1.first>v2.first;
	// });
	// ���ڴ��������Ĵ���
	sort(v.begin(), v.end(), cmp);
	int count = 0;
	int smax = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second >= smax)
		{
			count++;
		}
		smax = max(smax, v[i].second);
	}
	cout << count;
	return 0;
}