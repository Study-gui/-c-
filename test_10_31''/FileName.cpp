 #define _CRT_SECURE_NO_WARNINGS

//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
//
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

//class Solution {
//public:
//    string tmp;
//    vector<string> arr = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string>ans;
//    void dfs(int pos, string digits)
//    {
//        if (digits.size() == pos)//�м���������ʾ�м����ַ��������
//        {
//            ans.push_back(tmp);//��������ַ�
//            return;
//        }
//        int num = digits[pos] - '0';//�ҵ������İ���
//        for (int i = 0; i < arr[num].size(); i++)//�԰�����Ӧ���ַ����б���
//        {
//            tmp.push_back(arr[num][i]);//�����ַ�
//            dfs(pos + 1, digits);//�����������
//            tmp.pop_back();//���л���ɾ��������Ѿ������ĵ��ַ�
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0)//�ж��������
//        {
//            return {};
//        }
//        dfs(0, digits);//�����������
//        return ans;
//
//    }
//};



//���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� �������
//class Solution {
//public:
//    //����˼·����������dfs����ö��ÿһ�εĽ�������ж�
//    vector<string>ans;
//    void dfs(const string& str, int left, int right)
//    {
//        if (left<0 || left>right)//���������С��0���������Ŵ��������ž��񣨣���������
//        {
//            return;
//        }
//        if (left == 0 && right == 0)//��Ϊ0ʱ���ܴ���
//        {
//            ans.push_back(str);
//            return;
//        }
//        dfs(str + '(', left - 1, right);//���������Ž���ö�ٱ���
//        dfs(str + ')', left, right - 1);
//
//    }
//    vector<string> generateParenthesis(int n) {
//        dfs("", n, n);
//        return ans;
//    }
//};

//���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ���
//�ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻�  -1 ��
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
        {
            return -1;
        }
        int falg = 1;//��־λ
        int m = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            falg = 1;
            for (int j = 0, ret = i; j < needle.size() && ret < haystack.size(); j++, ret++)
            {
                if (haystack[ret] == needle[j])
                {
                }
                else {
                    falg = 0;
                    break;
                }
            }
            if (falg == 1)//�ж��Ƿ����needle�ַ�����û�в����
            {
                m = i;
                break;
            }
        }
        if (haystack.size() - m < needle.size())//�����ж��Ƿ��������λû�б�����needle��λ��
        {
            return -1;
        }
        if (falg == 1)
        {
            return m;
        }
        return -1;
    }
};