 #define _CRT_SECURE_NO_WARNINGS
//农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[-500, 500]。牛群中的牛用单链表表示。
//现在，农场主想要改变牛群的排列顺序。给定一个单链表的头指针 head 和两个整数 left 和 right，其中 left <= right。
//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的牛群链表。
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
  * @param left int整型
  * @param right int整型
  * @return ListNode类
  */

//struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
//    if (head == NULL || head->next == NULL || left == right)//对特殊情况进行判定
//    {
//        return head;
//    }
//    struct ListNode* phead;
//    phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = head;//开辟一个指向头节点的新节点
//    struct ListNode* hleft, * hright, * tail, * lcur, * rcur;
//    hleft = NULL, hright = NULL, tail = phead;
//    int m = left, n = right;
//    while (--m)
//    {
//        tail = tail->next;
//    }
//    hleft = tail;//找到left前一个节点
//    lcur = tail->next;//找到left结点
//    tail = phead;
//    while (n--)
//    {
//        tail = tail->next;
//    }
//    hright = tail;//right结点
//    rcur = tail->next;//right后一个结点
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL, n2 = lcur, n3 = n2->next;
//    while (n2 != rcur && n3)//对left到right的区域进行翻转
//    {
//        n3 = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//    }
//    hleft->next = n1;//再连接left到right之间的前后结点
//    lcur->next = rcur;
//    if (left == 1)//判断是不是从头结点进行翻转
//    {
//        return n1;
//    }
//    return head;
//
//}
//农场里有两群牛，每群牛都有一定的能量值。能量值由一个整数表示，整数范围是[-100, 100]。每群牛的能量值已经按照
//非递增顺序排列，并存储在链表中
//现在，你需要将这两群牛的能量值合并为一个新的非递增链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
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
  * @param l1 ListNode类
  * @param l2 ListNode类
  * @return ListNode类
  */
#include <string.h>
struct ListNode* mergeEnergyValues(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode* phead = NULL;
    struct ListNode* head = NULL;

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            if (phead == NULL)
            {
                head = phead = l1;
            }
            else {
                head->next = l1;
                head = l1;
            }
            l1 = l1->next;
        }
        else {
            if (phead == NULL)
            {
                head = phead = l2;
            }
            else {
                head->next = l2;
                head = l2;
            }
            l2 = l2->next;
        }
    }
    if (l1)
    {
        head->next = l1;
    }
    if (l2)
    {
        head->next = l2;
    }
    return phead;
}