 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
������������С������,�����
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int ret = (a > b ? a : b);
	while (1)
	{
		if (ret%a == 0 && ret % b == 0)
		{
			printf("%d ", ret);
			break;
		}
		ret++;
	}
	return 0;
}
���Ž�
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int i = 1;
	while ((a*i)%b)
	{
		i++;
	}
	printf("%d ", a * i);
	return 0;
}
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
1�������ַ������� 2�ٽ�ÿ����������
 #include <stdio.h>
#include <string.h>

void ReverseString(char* left, char* right)//��ת�ַ���
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
int main()
{
    char str[100] = "0";
    gets_s(str);
    int length = strlen(str);
    ���ַ������巭ת
    ReverseString(str, str + length - 1);
    char* start = str;
    ���ַ����е�ÿ�����ʷ�ת
    while (*start)
    {
        char* end = start;
        while (*end != ' ' && *end)//Ѱ�ҿո��'\0'
        {
            end++;
        }
        ReverseString(start, end - 1);
        if (*end == ' ')
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    printf("%s", str);
    return 0;
}