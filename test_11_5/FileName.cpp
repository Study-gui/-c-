 #define _CRT_SECURE_NO_WARNINGS

//����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ�䡣
//
//'.' ƥ�����ⵥ���ַ�
//'*' ƥ���������ǰ�����һ��Ԫ��
//��νƥ�䣬��Ҫ���� ���� �ַ��� s�ģ������ǲ����ַ�����
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int n = s.size();
//        int m = p.size();
//        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//
//        dp[0][0] = true;//��ʾ��s�е�0���ַ�����p�е�0���ַ�������ƥ���
//
//        for (int j = 1; j <= m; j++) {//��ʼ����һ��
//            if (p[j - 1] == '*') {
//                dp[0][j] = dp[0][j - 2];//
//            }
//        }
//
//        for (int i = 1; i <= n; i++) {//��ʼ����һ�У�û����s��ƥ��
//            dp[i][0] = false;
//        }
//
//        for (int i = 1; i <= n; i++) {//�ӵ�һ���ַ���ʼ
//            for (int j = 1; j <= m; j++) {
//
//                if (p[j - 1] != '*') {//��ʾ��ǰ���״̬�����״̬��ҪΪ1
//                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
//                }
//
//                if (p[j - 1] == '*') {//������ڵ�״̬Ϊ*��Ҫôǰ�����ƥ�����ǰһ���ַ���״̬Ϊ1������״̬���
//                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//                }
//
//            }
//        }
//
//        return dp[n][m];
//    }
//};


//����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (head == NULL)
//        {
//            return head;
//        }
//        if (head->next == NULL && n == 1)
//        {
//            return NULL;
//        }
//        ListNode* tail = head;
//        ListNode* cur = head;
//        ListNode* pre = NULL;
//        while (n--)//��ָ������n��
//        {
//            tail = tail->next;
//        }
//        if (tail == NULL)//�ж��Ƿ�Ϊɾ��ͷ�ڵ�
//        {
//            return head->next;
//        }
//        while (tail)//�ҵ�������n����
//        {
//            tail = tail->next;
//            pre = cur;
//            cur = cur->next;
//        }
//        pre->next = cur->next;//����ǰ��ָ������
//        return head;
//    }
//};


#include <iostream>   
#include <string>     
using namespace std;

int main()
{
    string pi = "pi is " + std::to_string(3.1415926);
    string perfect = to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
    cout << pi << '\n';
    cout << perfect << '\n';
    system("pause");
    return 0;
}