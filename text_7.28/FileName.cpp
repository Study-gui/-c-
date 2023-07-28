 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//今天是圣诞节，牛牛要打印一个漂亮的圣诞树送给想象中的女朋友，请你帮助他实现梦想。
//输入：1
//输出：
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
        if (i % 3 == 1)//第一层打印
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
        if (i % 3 == 2)//第二层打印
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
        if (i % 3 == 0)//第三层打印
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
    for (i = 0; i < h; i++)//底部打印
    {
        for (j = 1; j < 3 * h; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}