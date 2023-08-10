 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
//˼·�����бȽϣ���ֵ
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)//�ж�list1Ϊ��ָ��
    {
        return list2;
    }
    if (list2 == NULL)//�ж�list2Ϊ��ָ��
    {
        return list1;
    }
    struct ListNode* head = NULL, * tail = NULL;
    while (list1 && list2)//�����������ÿ��������ѭ��
    {
        if (list1->val > list2->val)//�����ж�
        {
            if (head == NULL)//Ϊ��Ԫ�ؽ���ͷ��
            {
                head = tail = list2;
            }
            else {//����ͷ�����������ֵ
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;//�������ֵ
        }
        else {
            if (head == NULL)//�ж��Ƿ�Ϊͷ��
            {
                head = tail = list1;
            }
            else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;//���������
        }
        if (list1)//�ж�list1�Ƿ����꣬δ������и�ֵ
        {
            tail->next = list1;
        }
        if (list2)//�ж�list2�Ƿ�����
        {
            tail->next = list2;
        }
    }
    return head;
}