 #define _CRT_SECURE_NO_WARNINGS
//牛牛正在买书，每本书都有名字和价格，牛牛想把书按照价格升序排序。
#include <stdio.h>
#include<string.h>
typedef struct book
{
    char str[100];
    int p;
} book;
int main() {
    //本题思路：创建一个结构体类型包含书的价格和书名，之后进行排序，本题利用冒泡排序
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