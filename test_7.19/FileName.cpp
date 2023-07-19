 #define _CRT_SECURE_NO_WARNINGS
//对于一个长度为 n 字符串，我们需要对它做一些变形。
//首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把这个字符串中由空格隔开
// 的单词反序，同时反转每个字符的大小写。比如"Hello World"变形后就变成了"wORLD hELLO"
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param s string字符串
 * @param n int整型
 * @return string字符串
 */
void is_nixu(char* s, int left, int right)
{
    while (left < right)
    {
        char tmp = *(s + left);
        *(s + left) = *(s + right);
        *(s + right) = tmp;
        left++;
        right--;
    }
}
char* trans(char* s, int n) {
    int left = 0;
    int right = n - 1;
    int ret = 0;
    is_nixu(s, left, right);
    while (left < n)
    {
        ret = left;
        while (*(s + ret) != ' ' && ret < n)
        {
            if (*(s + ret) <= 'z' && *(s + ret) >= 'a')
            {
                *(s + ret) -= 32;
            }
            else if (*(s + ret) >= 'A' && *(s + ret) <= 'Z')
            {
                *(s + ret) += 32;
            }
            ret++;
        }
        is_nixu(s, left, ret - 1);
        left = ret + 1;
    }
    return s;
}