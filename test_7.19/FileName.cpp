 #define _CRT_SECURE_NO_WARNINGS
//����һ������Ϊ n �ַ�����������Ҫ������һЩ���Ρ�
//��������ַ����а�����һЩ�ո񣬾���"Hello World"һ����Ȼ������Ҫ�����ǰ�����ַ������ɿո����
// �ĵ��ʷ���ͬʱ��תÿ���ַ��Ĵ�Сд������"Hello World"���κ�ͱ����"wORLD hELLO"
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param s string�ַ���
 * @param n int����
 * @return string�ַ���
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