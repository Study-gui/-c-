 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//class person
//{
//public:
//	int m_s;
//	int m_h;
//	int m_l;
//};
//
//int main()
//{
//	person s1;
//	cin >> s1.m_h >> s1.m_l >> s1.m_s ;
//	cout << s1.m_h<<endl << s1.m_l<<endl << s1.m_s << endl;
//
//
//
//	system("pause");
//}


//����һ���������� arr�����㽫������ָ�Ϊ���� ��� Ϊ k ��һЩ�������������顣�ָ���ɺ�
//ÿ����������е�����ֵ�����Ϊ���������е����ֵ��
//���ؽ�����ָ��任���ܹ��õ���Ԫ�����͡��������õ��Ĳ���������ȷ������һ�� 32 λ������
//���룺arr = [1,15,7,9,2,5,10], k = 3
//�����84
//���ͣ������Ϊ[15, 15, 15, 9, 10, 10, 10]

//#define max(a, b) ((a) > (b) ? (a) : (b))
//int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
//    //����˼·����������dp��̬�滮����������зֽ��С����
//    //�������һ������ʼ����k��������Χ�ڵ����ֵ��dp[i]����ʾ�ڼ����������ֵ
//    int dp[505];
//    memset(dp, 0, sizeof(dp));
//    int max = 0;
//    for (int i = 1; i <= arrSize; i++)
//    {
//        max = arr[i - 1];
//        for (int j = i - 1; i - j <= k && j >= 0; j--)
//        {
//            dp[i] = max(dp[i], dp[j] + (i - j) * max);//���ö�̬�滮��˼��:�ӵ�һ������ʼ���Ѱ�������
//            if (j > 0)
//                max = max(max, arr[j - 1]);
//        }
//    }
//    return dp[arrSize];
//}

//����һ������ n ����������������һ������Ϊ n + 1 ������ nums ��

//nums[0] = 0
//nums[1] = 1
//�� 2 <= 2 * i <= n ʱ��nums[2 * i] = nums[i]
//�� 2 <= 2 * i + 1 <= n ʱ��nums[2 * i + 1] = nums[i] + nums[i + 1]
//������������ nums �е� ��� ֵ��


//
//int getMaximumGenerated(int n) {
//    if (n == 0)
//    {
//        return 0;
//    }
//    if (n == 1)
//    {
//        return 1;
//    }
//    int num[n + 1];
//    num[0] = 0;
//    num[1] = 1;
//    int max = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        if (i % 2 == 0)
//        {
//            num[i] = num[i / 2];
//        }
//        else {
//            num[i] = num[i / 2] + num[(i / 2) + 1];
//        }
//        if (num[i] > max)
//        {
//            max = num[i];
//        }
//    }
//    return max;
//}


//int main()
//{
//	char arr[] = { "abcdef" };
//	char brr[] = { "bcd" };
//	if (!strncmp(arr+3, brr, 3))
//	{
//		printf("����");
//	}
//	else {
//		printf("������");
//	}
//	
//
//	return 0;
//}

//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��

//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
//bool wordBreak(char* s, char** wordDict, int wordDictSize) {
//    //����˼·����������dp����¼���ַ����ıȽ�״̬
//    //dpÿ������ʾÿ���ַ��Ƿ��ܽ���ƥ���״̬
//    int n = strlen(s);
//    int dp[n + 1];
//    memset(dp, 0, sizeof(dp));
//    dp[0] = 1;
//    for (int i = 1; i <= n; i++)//�ӵ�һ���ַ���ʼ����
//    {
//        for (int j = 0; j < wordDictSize; j++)//�ӵ�һ���ַ�����ʼ�����Ƚ����
//        {
//            int len = strlen(wordDict[j]);//��ȡ�Ƚϳ��ȳ���
//            int ret = i - len;//��ȡ�Ƚ�λ��
//            if (ret < 0)//С��������
//            {
//                continue;
//            }
//            dp[i] = (dp[ret] && !strncmp(s + ret, wordDict[j], len) || dp[i]);//��֤ǰ����ַ�ƥ��ɹ�
//            //�����ڵ��ַ�ƥ��״̬���ɹ�����
//        }
//    }
//    return dp[n];
//}

//#include<bits/stdc++.h>
using namespace std;
#include<math.h>
int weishu = 23333333;

bool check(int n)
{
	int n0 = n;
	int n1 = weishu - n0;
	double zhanbi1 = n1 * 1.0 / weishu;
	double zhanbi0 = n0 * 1.0 / weishu;
	double ans = -n0 * zhanbi0 * log2(zhanbi0) - n1 * zhanbi1 *log2(zhanbi1);
	if (abs(ans - 11625907.5798) < 0.0001)
		printf("%.7f     %d\n", ans, n);
	//return true;
	//cout<<ans<<endl;
	return false;
}

int main()
{
	/*int left=0,right=23333333;
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(check(mid))right=mid;
		else left=mid+1;
	}*/
	for (int i = 0; i < 23333333; ++i)
		if (check(i))
			cout << i << endl;
	//cout<<std::log2(8);
	//check(1);
	//check(1217805);

	return 0;
}

/*
1217804
1217805
*/