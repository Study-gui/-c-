 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;

//int n;
//int ti[11], di[11], li[11];
//int falg;
//int used[11];
//N �ܷɻ�׼�����䵽ĳ��ֻ��һ���ܵ��Ļ��������е� i �ܷɻ��� Ti ʱ�̵�������Ͽգ�����ʱ����ʣ�����ϻ����Լ������� Di ����λʱ�䣬��������
//������ Ti ʱ�̿�ʼ���䣬��������� Ti + Di ʱ�̿�ʼ���䡣���������Ҫ Li����λʱ�䡣
//һ�ܷɻ��������ʱ����һ�ܷɻ�����������ͬһʱ�̿�ʼ���䣬���ǲ�����ǰһ�ܷɻ���ɽ���ǰ��ʼ���䡣
//�����ж� N �ܷɻ��Ƿ����ȫ����ȫ���䡣
//�����ʽ
//��������������ݡ�
//��һ�а���һ������ T������������ݵ�������
//����ÿ�����ݣ���һ�а���һ������ N��
//���� N �У�ÿ�а�������������Ti��Di �� Li��
//void dfs(int x,int time)
//{
//	if (falg == 1)
//	{
//		return;
//	}
//	if (x == n)
//	{
//		falg = 1;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (used[i] == 0 && time <= ti[i]+di[i])
//		{
//			used[i] = 1;
//			dfs(x + 1, max(time, ti[i]) + li[i]);
//			if (falg == 1)
//			{
//				return;
//			}
//			used[i] = 0;
//		}
//		
//	}
//}
//void sovle()
//{
//	falg = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ti[i] >> di[i] >> li[i];
//		used[i] = 0;
//	}
//	dfs(0,0);
//	if (falg == 1)
//	{
//		cout << "YES" << endl;
//	}
//	else {
//		cout << "NO" << endl;
//	}
//}
//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		sovle();
//
//	}
//
//	system("pause");
//	return 0;
//}


//С����һ�������¯�����ڽ���ͨ���� O ұ����Ϊһ��������� X�����¯����һ������ת���ʵ����� V��V ��һ��������������ζ������ V ����ͨ��
//
//�� O ǡ�ÿ���ұ����һ��������� X������ͨ���� O ����Ŀ���� V ʱ���޷�����ұ����
//���ڸ����� N ��ұ����¼��ÿ����¼�а����������� A �� B�����ʾ����Ͷ���� A ����ͨ���� O������ұ������ B ��������� X��ÿ����¼���Ƕ���
//�ģ�����ζ����һ��û���������ͨ���� O �����ۼӵ���һ�ε�ұ�����С�
//
//������ N ��ұ����¼�������Ʋ��ת���� V ����Сֵ�����ֵ�ֱ�����Ƕ��٣���Ŀ��֤�������ݲ������޽�������

//��һ��һ������ N����ʾұ����¼����Ŀ��
//���������� N �У�ÿ���������� A��B����������Ŀ������
int a[10005], b[10005];
int n;
int cheekvmin(int mid)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] / mid > b[i])
		{
			return 0;
		}
	}
	return 1;
}

int cheekvmax(int mid)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] / mid < b[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	int left = 1, right = 1e9;
	int mid = 0;
	int vmin;
	while (left <=right)
	{
		 mid = left + (right - left) / 2;
		if (!cheekvmin(mid))
		{
			
			left = mid +1;
		}
		else {
			vmin = mid;
			right = mid-1 ;
		}
	}
	
	left = 1, right = 1e9;
	int vmax ;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (!cheekvmax(mid))
		{
			
			right = mid-1 ;
		}
		else {
			vmax = mid;
			left = mid + 1;
		}
	}
	
	cout << vmin << " "<<vmax << endl;

	system("pause");
	return 0;
}