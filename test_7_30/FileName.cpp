 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ���ȥ��һ����߷ֺ�һ����ͷ�
// ���ÿ���ƽ���ɼ�����ע�������ж�������
int main()
{
    int n = 0, a = 0;
    int arr[7] = { 0 };
    float mid = 0.0f;
    int max = 0, min = 100;
    while (scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2],
        &arr[3], &arr[4], &arr[5], &arr[6]) == 7)
    {
        float mid = 0.0f;
        int max = 0, min = 100;
        for (n = 0; n < 7; n++)
        {
            if (arr[n] > max)
            {
                max = arr[n];
            }
            if (arr[n] < min)
            {
                min = arr[n];
            }
            mid += arr[n];
        }
        mid = (mid - max - min)/5.0;
        printf("%.2f\n", mid);
    }
    return 0;

}