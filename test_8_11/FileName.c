 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        struct ListNode* lesshead, * lesstail, * grarthead, * grarttail;
//        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));//创建一个链表存放小于x的值
//        grarthead = grarttail = (struct ListNode*)malloc(sizeof(struct ListNode));//创建一个链表存放大于等于x的值
//        lesstail->next = NULL;
//        grarttail->next = NULL;
//        struct ListNode* cur = pHead;
//        while (cur)//遍历链表进行比较
//        {
//            if (cur->val < x)
//            {
//                lesstail->next = cur;//小于存放
//                lesstail = cur;
//            }
//            else {
//                grarttail->next = cur;//大于存放
//                grarttail = cur;
//            }
//            cur = cur->next;
//        }
//        lesstail->next = grarthead->next;//将两个链表进行连接
//        grarttail->next = NULL;//*对最后的结点进行连接空指针
//        struct ListNode* newhead = lesshead->next;//存放起点
//        free(lesshead);//释放空间
//        free(grarthead);
//        return newhead;
//
//
//    }
//};

//
//找出单向链表中的一个节点，该节点到尾指针的距离为K。链表的倒数第0个结点为链表的尾指针。要求时间复杂度为O(n)
//#include <stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//    int m_nKey;
//    struct ListNode* m_pNext;
//};
//void sListNode(struct ListNode** head, int x)
//{
//    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newnode->m_nKey = x;
//    newnode->m_pNext = NULL;
//    struct ListNode* cur = *head;
//    if (*head == NULL)
//    {
//        *head = newnode;
//    }
//    else {
//        while (cur->m_pNext)
//        {
//            cur = cur->m_pNext;
//        }
//        cur->m_pNext = newnode;
//    }
//}
//int  sListnode(struct ListNode** phead, int k)
//{
//    //利用快慢指针
//    struct ListNode* list, * next;
//    list = *phead, next = *phead;
//    while (k--)//先走k步
//    {
//        next = next->m_pNext;
//    }
//    while (next)//再走到空指针，慢指针正好走到倒数的k位
//    {
//        list = list->m_pNext;
//        next = next->m_pNext;
//    }
//    return list->m_nKey;
//}
//int main()
//{
//    struct ListNode* head = NULL;
//    sListNode(&head, 1);//编写插入链表的函数
//    sListNode(&head, 2);
//    sListNode(&head, 3);
//    sListNode(&head, 4);
//    sListNode(&head, 5);
//    sListNode(&head, 6);
//    sListNode(&head, 7);
//    int k = 0;
//    scanf("%d", &k);
//    int kNode = sListnode(&head, k);//编写返回倒数k为的数
//    printf("%d", kNode);
//    return 0;
//}

//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
struct ListNode* is_slist(struct ListNode* list)//将链表逆置翻转的函数
{
    struct ListNode* n1, * n2, * n3;
    n1 = NULL, n2 = list, n3 = list->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        struct ListNode* list, * tail;
        list = tail = A;
        while (tail && tail->next)//查找中间节点
        {
            tail = tail->next->next;
            list = list->next;
        }
        struct ListNode* newlist = is_slist(list);//将中间节点进行逆置
        while (newlist)
        {
            if (A->val == newlist->val)//对链表进行判断,即使是奇数比如 1 2 3 2 1，
            {                          //逆置后  1 2 1 2 3 中间的2的next也是指向3的结点同样适用
                newlist = newlist->next;
                A = A->next;
            }
            else {
                return false;//不相等直接返回
            }
        }
        return true;
    }
};