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
//    // 请在此输入您的代码
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


//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
//需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
char* removeDuplicateLetters(char* s) {
    //本题思路：利用单调栈进行存放字符
    if (s == NULL || strlen(s) == 1)
    {
        return s;
    }
    int ret[26] = { 0 };//记录每个字符的个数
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        ret[s[i] - 'a']++;//记录个数
    }
    char* stack = (char*)malloc(sizeof(char) * 27);//开辟栈空间
    int top = -1;
    int flag = 1;//标志位
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = 0; j <= top; j++)
        {
            if (s[i] == stack[j])//遍历栈是否含有要入栈的字符
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)//如果含有要入栈的元素，不必入栈，直接减少这个字符的个数
        {
            ret[s[i] - 'a']--;
        }
        else {
            while (top > -1 && stack[top] > s[i] && ret[stack[top] - 'a'] > 1)//如果栈里有元素
                //并且栈顶的字符大于要入栈的字符，并且要入栈的字符，后面还有的情况
            {
                ret[stack[top] - 'a']--;//减少栈顶字符的个数
                top--;//栈顶元素出栈
            }
            stack[++top] = s[i];
        }
    }
    stack[++top] = '\0';//进行字符终止
    return stack;
}