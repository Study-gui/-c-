 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//KiKi��һ����������֪������k���б任���б任��õ��ľ������̰������
//��tΪ�ַ�'r'ʱ��������б任����tΪ�ַ�'c'ʱ��������б任��a��bΪ��Ҫ�������л��С�
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d%d", &n, &m);
//    int arr[5][5] = {0};
//    int i = 0, j = 0;
//    int k = 0, a = 0, b = 0;
//    char t = 0;
//    int ret = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    scanf("%d", &k);
//    while (k)
//    {
//        scanf(" %c %d %d", &t, &a, &b);
//        if (t == 'r')
//        {
//            for (j = 0; j < m; j++)
//            {
//                //�����б任
//                ret = arr[a - 1][j];
//                arr[a - 1][j] = arr[b - 1][j];
//                arr[b - 1][j] = ret;
//            }
//        }
//        else if (t == 'c')
//        {
//            //�����б任
//            for (i = 0; i < n; i++)
//            {
//                ret = arr[i][a - 1];
//                arr[i][a - 1] = arr[i][b - 1];
//                arr[i][b - 1] = ret;
//            }
//        }
//        k--;
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//����ף���ĸ��70����֮�ʣ���ʦ��С���ֳ���һ�����⡣��Ҷ�֪��China��Ӣ����д��CHN����ô����һ���ַ���s��
// ����Ҫ������ͳ��s�������С�CHN���ĸ����������еĶ��壺���������±�a < b < c����ô��s[a]s[b]s[c]��
// //�͹���s��һ�������С��硰ABC�����������С�A������B������C������AB������AC������BC������ABC����
//���һ��������Ϊ�ַ���s�������С�CHN��������
//int main()
//{
//	//˼·Ϊ��¼C�ĸ�����H��ϵĸ���������N��ϵĸ��������ܵ��ַ�����CHN�ĸ���
//	char s[8001] = { 0 };
//	long fristC = 0, twoCH = 0, threeCHN = 0;
//	scanf("%s", &s);
//	int ret = sizeof(s) / sizeof(s[0]);
//	for (int i = 0; i < ret; i++)
//	{
//		if (s[i] == 'C')
//		{
//			//��¼C�ĸ���
//			fristC++;
//		}
//		if (s[i] == 'H')
//		{
//			//��¼CH���ܸ����ĸ���
//			twoCH += fristC;
//		}
//		if (s[i] == 'N')
//		{
//			//��¼CH��N��ϵ��ܸ���
//			threeCHN += twoCH;
//		}
//	}
//	printf("%ld\n", threeCHN);
//
//	return 0;
//}
//����һ���������У�KiKi������е��ظ�������ȥ��������ȥ�غ�����д�С�������������
//����˼·����Ͱ�ŷ���
//ÿ��������һ��Ͱ��Ͱ����ž��Ƕ�ӦͰ��ֵ��
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int arr[1000] = { 0 };
    int max = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ret);
        arr[ret] = ret;//��Ӧ��ÿһ��Ͱ
        if (ret > max)
        {
            max = ret;//ɸѡ����������Ͱ��
        }
    }
    for (i = 0; i <= max; i++)
    {
        if (arr[i])//����0�Ĳ���ӡ
        {
            printf("%d ", arr[i]);//�õ�����ɸѡ�����صĴ�С�������������
        }
    }
    return 0;
}