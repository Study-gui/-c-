 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//思路：进行比较，赋值
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)//判断list1为空指针
    {
        return list2;
    }
    if (list2 == NULL)//判断list2为空指针
    {
        return list1;
    }
    struct ListNode* head = NULL, * tail = NULL;
    while (list1 && list2)//对两个链表的每个数进行循环
    {
        if (list1->val > list2->val)//进行判断
        {
            if (head == NULL)//为首元素进行头插
            {
                head = tail = list2;
            }
            else {//不是头插进行正常赋值
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;//进行向后赋值
        }
        else {
            if (head == NULL)//判断是否为头插
            {
                head = tail = list1;
            }
            else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;//进行向后走
        }
        if (list1)//判断list1是否走完，未走完进行赋值
        {
            tail->next = list1;
        }
        if (list2)//判断list2是否走完
        {
            tail->next = list2;
        }
    }
    return head;
}