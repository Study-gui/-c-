 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy
//�򾭹��滻֮����ַ���ΪWe%20Are%20Happy 
//������ⷨ������ÿ��һ���ո�Ͷ���λ��ԭ����ǰ���ٺÿռ䣬�趨һ��������end2���ٺõ����һλ�Ŀռ�
//ʹ���ַ��������һλend1���ֵ�������ո�͸�ֵ%20
int main()
{
	char arr[20];
	gets_s(arr);
	int sz = strlen(arr) - 1;
	int i = 0;
	int ret = 0;//��¼�ո�����
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == ' ')
		{
			ret++;
		}
	}
	int end1 = sz;//�ַ������һλ�±�
	int end2 = sz + 2 * ret;//���ٺõĿռ�����һλ
	while (end1 != end2)
	{
		if (arr[end1] != ' ')
		{
			arr[end2--] = arr[end1--];
		}
		else {
			arr[end2--] = '0';//%20��ǰ����ֵ
			arr[end2--] = '2';
			arr[end2--] = '%';
			end1--;
		}
	}
	printf("%s\n", arr);
	return 0;
}