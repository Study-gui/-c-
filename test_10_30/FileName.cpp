 #define _CRT_SECURE_NO_WARNINGS
//
////��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
//
//���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��
//
//����ʵ��������ַ�������ָ�������任�ĺ�����
//
//string convert(string s, int numRows);
//0             0 + t                    0 + 2t                     0 + 3t
//1      t - 1    1 + t            0 + 2t - 1  1 + 2t            0 + 3t - 1   1 + 3t
//2  t - 2        2 + t  0 + 2t - 2            2 + 2t  0 + 3t - 2             2 + 3t
//3             3 + t                    3 + 2t                     3 + 3t
//kΪ4ʱ
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
    for (int i = 0; i < r; i++)//ö�پ������
    {
        for (int j = 0; j + i < n; j += t)//ö��ÿ�����ڵ���ʼ�±�
        {
            ans[pos++] = s[j + i];//��ǰ���ڵĵ�һ���ַ�
            if (i > 0 && i < r - 1 && j + t - i < n)
            {
                ans[pos++] = s[j + t - i];//��ǰ���ڵĵĶ����ַ�
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}