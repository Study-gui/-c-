 #define _CRT_SECURE_NO_WARNINGS
//ţţ�������飬ÿ���鶼�����ֺͼ۸�ţţ����鰴�ռ۸���������
#include <stdio.h>
#include<string.h>
typedef struct book
{
    char str[100];
    int p;
} book;
int main() {
    //����˼·������һ���ṹ�����Ͱ�����ļ۸��������֮��������򣬱�������ð������
    book book[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%*C%d", &(book[i].str), &(book[i].p));
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (book[j].p > book[j + 1].p)
            {
                int ret = book[j].p;
                book[j].p = book[j + 1].p;
                book[j + 1].p = ret;
                char a[100] = "\0";
                strcpy(a, book[j].str);
                strcpy(book[j].str, book[j + 1].str);
                strcpy(book[j + 1].str, a);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", book[i].str);
    }


    return 0;
}