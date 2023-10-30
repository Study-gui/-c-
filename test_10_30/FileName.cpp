 #define _CRT_SECURE_NO_WARNINGS
//
////将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//0             0 + t                    0 + 2t                     0 + 3t
//1      t - 1    1 + t            0 + 2t - 1  1 + 2t            0 + 3t - 1   1 + 3t
//2  t - 2        2 + t  0 + 2t - 2            2 + 2t  0 + 3t - 2             2 + 3t
//3             3 + t                    3 + 2t                     3 + 3t
//k为4时
char* convert(char* s, int numRows) {
    int n = strlen(s);
    int r = numRows;
    if (r == 1 || r >= n)
    {
        return s;
    }
    int t = r * 2 - 2;
    char* ans = (char*)malloc(sizeof(char) * (n + 1));
    int pos = 0;
    for (int i = 0; i < r; i++)//枚举矩阵的行
    {
        for (int j = 0; j + i < n; j += t)//枚举每个周期的起始下标
        {
            ans[pos++] = s[j + i];//当前周期的第一个字符
            if (i > 0 && i < r - 1 && j + t - i < n)
            {
                ans[pos++] = s[j + t - i];//当前周期的的二个字符
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}