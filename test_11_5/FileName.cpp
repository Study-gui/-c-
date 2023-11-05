 #define _CRT_SECURE_NO_WARNINGS

//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int n = s.size();
//        int m = p.size();
//        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//
//        dp[0][0] = true;//表示在s中第0个字符，在p中第0个字符，是相匹配的
//
//        for (int j = 1; j <= m; j++) {//初始化第一行
//            if (p[j - 1] == '*') {
//                dp[0][j] = dp[0][j - 2];//
//            }
//        }
//
//        for (int i = 1; i <= n; i++) {//初始化第一列，没有于s相匹配
//            dp[i][0] = false;
//        }
//
//        for (int i = 1; i <= n; i++) {//从第一个字符开始
//            for (int j = 1; j <= m; j++) {
//
//                if (p[j - 1] != '*') {//表示第前面的状态和这个状态都要为1
//                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
//                }
//
//                if (p[j - 1] == '*') {//如果现在的状态为*，要么前面就相匹配或者前一个字符的状态为1和现在状态相等
//                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//                }
//
//            }
//        }
//
//        return dp[n][m];
//    }
//};


//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
//        while (n--)//快指针先走n步
//        {
//            tail = tail->next;
//        }
//        if (tail == NULL)//判断是否为删掉头节点
//        {
//            return head->next;
//        }
//        while (tail)//找到倒数第n个点
//        {
//            tail = tail->next;
//            pre = cur;
//            cur = cur->next;
//        }
//        pre->next = cur->next;//进行前后指针连接
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