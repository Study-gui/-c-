 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//������ʥ���ڣ�ţţҪ��ӡһ��Ư����ʥ�����͸������е�Ů���ѣ����������ʵ�����롣
//���룺1
//�����
//  *
// * *
//* * *
//  *
#include <stdio.h>
int main()
{
    int h = 0;
    scanf("%d", &h);
    int i = 0, j = 0, x = 0;
    for (i = 1; i <= 3 * h; i++)
    {
        if (i % 3 == 1)//��һ���ӡ
        {
            for (j = i; j < 3 * h; j++)
            {
                printf(" ");
            }
            for (x = i; x > 0; x -= 3)
            {
                printf("*     ");
            }
            printf("\n");
        }
        if (i % 3 == 2)//�ڶ����ӡ
        {
            for (j = i; j < 3 * h; j++)
            {
                printf(" ");
            }
            for (x = i; x > 0; x -= 3)
            {
                printf("* *   ");
            }
            printf("\n");
        }
        if (i % 3 == 0)//�������ӡ
        {
            for (j = i; j < 3 * h; j++)
            {
                printf(" ");
            }
            for (x = i; x > 0; x -= 3)
            {
                printf("* * * ");
            }
            printf("\n");
        }
    }
    for (i = 0; i < h; i++)//�ײ���ӡ
    {
        for (j = 1; j < 3 * h; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}