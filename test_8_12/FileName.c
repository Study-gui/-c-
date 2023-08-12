 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给你两个单链表的头节点 headA 和 headB，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点返回null
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* tailA, * tailB;//创建变量，找到最后的结点，判断是否相等,相等为有环
//    tailA = headA, tailB = headB;
//    int lenA = 1;//计算链表的个数
//    int lenB = 1;
//    while (tailA->next)
//    {
//        tailA = tailA->next;
//        lenA++;
//    }
//    while (tailB->next)
//    {
//        tailB = tailB->next;
//        lenB++;
//    }
//    if (tailA != tailB)//如果尾结点不相等，说明链表不相交
//    {
//        return NULL;
//    }
//    else {
//        int gap = abs(lenA - lenB);//运算出两个链表的个数绝对值
//        struct ListNode* longhead = headA;
//        struct ListNode* shorthead = headB;
//        if (lenA < lenB)//假设A链表大
//        {
//            longhead = headB;
//            shorthead = headA;
//        }
//        while (gap--)//将链表进行对齐
//        {
//            longhead = longhead->next;
//        }
//        while (longhead != shorthead)//判断找到相交的节点
//        {
//            longhead = longhead->next;
//            shorthead = shorthead->next;
//        }
//        return longhead;//输出相交的结点
//    }
//}

//给你一个链表的头节点 head ，判断链表中是否有环。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//bool hasCycle(struct ListNode* head) {
//    if (head == NULL || head->next == NULL)//至少链表有两个元素，才能成环
//    {
//        return false;
//    }
//    else {//利用快慢指针，
//        struct ListNode* headA, * headB;
//        headA = headB = head;
//        while (headB && headB->next)//快指针是慢指针的两倍，如果有环就能追上
//        {
//            headA = headA->next;
//            headB = headB->next->next;
//            if (headA == headB)
//            {
//                return true;
//            }
//        }
//        //没有追上则为空
//        return false;
//    }
//}
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //利用公式法，解题，首元素与环内相交点的相交点尾环的第一个结点
    struct ListNode* headA, * headB;
    headA = headB = head;
    while (headB && headB->next)
    {
        headA = headA->next;
        headB = headB->next->next;
        if (headA == headB)//找到环内相交的点
        {
            while (head != headA)//找到入环的第一结点
            {
                head = head->next;
                headA = headA->next;
            }
            return head;//有环返回相交点
        }
    }
    return NULL;//无环返回空指针
}