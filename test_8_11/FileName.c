 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ��
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
//        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));//����һ��������С��x��ֵ
//        grarthead = grarttail = (struct ListNode*)malloc(sizeof(struct ListNode));//����һ�������Ŵ��ڵ���x��ֵ
//        lesstail->next = NULL;
//        grarttail->next = NULL;
//        struct ListNode* cur = pHead;
//        while (cur)//����������бȽ�
//        {
//            if (cur->val < x)
//            {
//                lesstail->next = cur;//С�ڴ��
//                lesstail = cur;
//            }
//            else {
//                grarttail->next = cur;//���ڴ��
//                grarttail = cur;
//            }
//            cur = cur->next;
//        }
//        lesstail->next = grarthead->next;//�����������������
//        grarttail->next = NULL;//*�����Ľ��������ӿ�ָ��
//        struct ListNode* newhead = lesshead->next;//������
//        free(lesshead);//�ͷſռ�
//        free(grarthead);
//        return newhead;
//
//
//    }
//};

//
//�ҳ����������е�һ���ڵ㣬�ýڵ㵽βָ��ľ���ΪK������ĵ�����0�����Ϊ�����βָ�롣Ҫ��ʱ�临�Ӷ�ΪO(n)
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
//    //���ÿ���ָ��
//    struct ListNode* list, * next;
//    list = *phead, next = *phead;
//    while (k--)//����k��
//    {
//        next = next->m_pNext;
//    }
//    while (next)//���ߵ���ָ�룬��ָ�������ߵ�������kλ
//    {
//        list = list->m_pNext;
//        next = next->m_pNext;
//    }
//    return list->m_nKey;
//}
//int main()
//{
//    struct ListNode* head = NULL;
//    sListNode(&head, 1);//��д��������ĺ���
//    sListNode(&head, 2);
//    sListNode(&head, 3);
//    sListNode(&head, 4);
//    sListNode(&head, 5);
//    sListNode(&head, 6);
//    sListNode(&head, 7);
//    int k = 0;
//    scanf("%d", &k);
//    int kNode = sListnode(&head, k);//��д���ص���kΪ����
//    printf("%d", kNode);
//    return 0;
//}

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
struct ListNode* is_slist(struct ListNode* list)//���������÷�ת�ĺ���
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
        while (tail && tail->next)//�����м�ڵ�
        {
            tail = tail->next->next;
            list = list->next;
        }
        struct ListNode* newlist = is_slist(list);//���м�ڵ��������
        while (newlist)
        {
            if (A->val == newlist->val)//����������ж�,��ʹ���������� 1 2 3 2 1��
            {                          //���ú�  1 2 1 2 3 �м��2��nextҲ��ָ��3�Ľ��ͬ������
                newlist = newlist->next;
                A = A->next;
            }
            else {
                return false;//�����ֱ�ӷ���
            }
        }
        return true;
    }
};