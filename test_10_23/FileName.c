//#include <stdio.h>
//#include <stdlib.h>
//
//int abc(int i, int j)
//{
//    int tmp = 0;
//    while (j)
//    {
//        tmp = i % j;
//        i = j;
//        j = tmp;
//    }
//    return i;
//}
//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    int sum = 0;
//    for (int i = 1; i <= 2020; i++)
//    {
//        for (int j = 1; j <= 2020; j++)
//        {
//
//            if (abc(i, j) == 1)
//            {
//                sum++;
//            }
//        }
//    }
//    printf("%d", sum);
//    return 0;
//}


//����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ�
//�豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
char* removeDuplicateLetters(char* s) {
    //����˼·�����õ���ջ���д���ַ�
    if (s == NULL || strlen(s) == 1)
    {
        return s;
    }
    int ret[26] = { 0 };//��¼ÿ���ַ��ĸ���
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        ret[s[i] - 'a']++;//��¼����
    }
    char* stack = (char*)malloc(sizeof(char) * 27);//����ջ�ռ�
    int top = -1;
    int flag = 1;//��־λ
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = 0; j <= top; j++)
        {
            if (s[i] == stack[j])//����ջ�Ƿ���Ҫ��ջ���ַ�
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)//�������Ҫ��ջ��Ԫ�أ�������ջ��ֱ�Ӽ�������ַ��ĸ���
        {
            ret[s[i] - 'a']--;
        }
        else {
            while (top > -1 && stack[top] > s[i] && ret[stack[top] - 'a'] > 1)//���ջ����Ԫ��
                //����ջ�����ַ�����Ҫ��ջ���ַ�������Ҫ��ջ���ַ������滹�е����
            {
                ret[stack[top] - 'a']--;//����ջ���ַ��ĸ���
                top--;//ջ��Ԫ�س�ջ
            }
            stack[++top] = s[i];
        }
    }
    stack[++top] = '\0';//�����ַ���ֹ
    return stack;
}