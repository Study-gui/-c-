 #define _CRT_SECURE_NO_WARNINGS
//将给出的链表中的节点每 k 个一组翻转，返回翻转后的链表
//如果链表中的节点数不是 k 的倍数，将最后剩下的节点保持原样
//你不能更改节点中的值，只能更改节点本身
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param head ListNode类
  * @param k int整型
  * @return ListNode类
  */
#include <math.h>
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 1)//对特殊情况进行讨论
    {
        return head;
    }
    //本题思路：利用递归的方法进行解决
    struct ListNode* cur, * prev, * tail;
    cur = head;
    prev = NULL, tail = NULL;
    for (int i = 1; i <= k; i++)
    {
        if (cur == NULL)
        {
            return head;//递归解决条件
        }
        cur = cur->next;
    }
    cur = head;
    for (int i = 1; i <= k; i++)//对k范围进行逆转
    {
        tail = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tail;
    }
    head->next = reverseKGroup(cur, k);//用逆置后的尾连接下一段逆置后的头节点
    return prev;//返回整个逆置头节点
}