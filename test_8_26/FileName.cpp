 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。（注意因为传入数据是链表，
//所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pHead1 ListNode类
  * @param pHead2 ListNode类
  * @return ListNode类
  */
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL)//对特殊情况进行判断
        return NULL;
    struct ListNode* p1, * p2;
    p1 = pHead1, p2 = pHead2;
    int n = 0, m = 0;//计算链表有多少元素个数
    while (p1)
    {
        p1 = p1->next;
        n++;
    }
    while (p2)
    {
        p2 = p2->next;
        m++;
    }
    //    if(p1!=p2)
    //    {
    //     return NULL;
    //    }
    struct ListNode* plist1, * plist2;
    plist1 = pHead1, plist2 = pHead2;//假设phead1大
    if (m > n)//假设性判断
    {
        plist1 = pHead2;
        plist2 = pHead1;
    }
    int s = abs(m - n);//求出绝对值
    while (s--)//将两个链表进行对齐
    {
        plist1 = plist1->next;
    }
    while (plist1 && plist2)//对链表进行遍历
    {
        if (plist1 == plist2)//判断链表是否相等
        {
            return plist1;
        }
        plist1 = plist1->next;
        plist2 = plist2->next;

    }
    return NULL;
}