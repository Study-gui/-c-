 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���������������ͷ�ڵ� headA �� headB�������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㷵��null
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* tailA, * tailB;//�����������ҵ����Ľ�㣬�ж��Ƿ����,���Ϊ�л�
//    tailA = headA, tailB = headB;
//    int lenA = 1;//��������ĸ���
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
//    if (tailA != tailB)//���β��㲻��ȣ�˵�������ཻ
//    {
//        return NULL;
//    }
//    else {
//        int gap = abs(lenA - lenB);//�������������ĸ�������ֵ
//        struct ListNode* longhead = headA;
//        struct ListNode* shorthead = headB;
//        if (lenA < lenB)//����A�����
//        {
//            longhead = headB;
//            shorthead = headA;
//        }
//        while (gap--)//��������ж���
//        {
//            longhead = longhead->next;
//        }
//        while (longhead != shorthead)//�ж��ҵ��ཻ�Ľڵ�
//        {
//            longhead = longhead->next;
//            shorthead = shorthead->next;
//        }
//        return longhead;//����ཻ�Ľ��
//    }
//}

//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//bool hasCycle(struct ListNode* head) {
//    if (head == NULL || head->next == NULL)//��������������Ԫ�أ����ܳɻ�
//    {
//        return false;
//    }
//    else {//���ÿ���ָ�룬
//        struct ListNode* headA, * headB;
//        headA = headB = head;
//        while (headB && headB->next)//��ָ������ָ�������������л�����׷��
//        {
//            headA = headA->next;
//            headB = headB->next->next;
//            if (headA == headB)
//            {
//                return true;
//            }
//        }
//        //û��׷����Ϊ��
//        return false;
//    }
//}
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //���ù�ʽ�������⣬��Ԫ���뻷���ཻ����ཻ��β���ĵ�һ�����
    struct ListNode* headA, * headB;
    headA = headB = head;
    while (headB && headB->next)
    {
        headA = headA->next;
        headB = headB->next->next;
        if (headA == headB)//�ҵ������ཻ�ĵ�
        {
            while (head != headA)//�ҵ��뻷�ĵ�һ���
            {
                head = head->next;
                headA = headA->next;
            }
            return head;//�л������ཻ��
        }
    }
    return NULL;//�޻����ؿ�ָ��
}