 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy
//则经过替换之后的字符串为We%20Are%20Happy 
//巧妙求解法：利用每多一个空格就多两位的原理，提前开辟好空间，设定一个变量，end2开辟好的最后一位的空间
//使得字符串的最后一位end1向后赋值，遇到空格就赋值%20
int main()
{
	char arr[20];
	gets_s(arr);
	int sz = strlen(arr) - 1;
	int i = 0;
	int ret = 0;//记录空格数量
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == ' ')
		{
			ret++;
		}
	}
	int end1 = sz;//字符串最后一位下标
	int end2 = sz + 2 * ret;//开辟好的空间的最后一位
	while (end1 != end2)
	{
		if (arr[end1] != ' ')
		{
			arr[end2--] = arr[end1--];
		}
		else {
			arr[end2--] = '0';//%20从前往后赋值
			arr[end2--] = '2';
			arr[end2--] = '%';
			end1--;
		}
	}
	printf("%s\n", arr);
	return 0;
}