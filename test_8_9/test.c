 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ�,�������µ�ͷ�ڵ� 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur)//������������б���
//    {
//        if (cur->val == val)//�ж��Ƿ����
//        {
//            if (cur == head)//�ڽ����ж��Ƿ�����Ԫ����ȣ�����ͷɾ
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//            }
//            else {//������Ԫ�أ��ͽ���ɾ��
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else {//������ȣ������
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}


//���㵥�����ͷ�ڵ�head �����㷴ת���������ط�ת�������

//˼·1�� ֱ����ԭ�����﷭ת
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)//������Ϊ�ս����ж�
//        return NULL;
//    struct ListNode* n1 = NULL;//�趨һ��Ϊn1���з�ת��ֵ
//    struct ListNode* n2 = head;//�趨һ��n2���з�ת��ֵ
//    struct ListNode* n3 = head->next;//�趨һ��n3���г䵱�м����
//    while (n2)
//    {
//        //��ת��ֵ����
//        n2->next = n1;
//        //��������
//        n1 = n2;
//        n2 = n3;
//        if (n3)//n3�жϲ���Խ��
//            n3 = n3->next;
//    }
//    return n1;
//}

//˼·2������һ����������и�ֵ
//struct ListNode* reverseList(struct ListNode* head) {
//struct ListNode* newnode = NULL;//��תǰһλ��ַ����
//struct ListNode* cur = head;//��ʾ���ڵ�״̬
//while (cur)
//{
//    struct ListNode* next = cur->next;//�����м����
//    //�߼���ֵ
//    cur->next = newnode;
//    //��������
//    newnode = cur;
//    cur = next;
//}
//return newnode;
//}

//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//˼·1�������ⷨ
struct ListNode* middleNode(struct ListNode* head) {
    //˼·1�������ⷨ
//    int count=0;//���������ж���Ԫ��
//    struct ListNode* cur=head;
//    while(cur)
//    {
//        cur=cur->next;
//        count++;
//    }
//    if(count%2==0)
//    {
//        int mid=count/2;//���б���
//        while(mid)
//        {
//            head=head->next;
//            mid--;
//        }
//    }
//    else{
//        int mid=count/2;
//        while(mid)
//        {
//            head=head->next;
//            mid--;
//        }
//    }
//    return head;
}

//˼·2������ָ��
//struct ListNode* middleNode(struct ListNode* head) {
//truct ListNode* slow = head;//����һ��ָ��ÿ����һ��
//struct ListNode* fast = head;//����һ��ָ��ÿ��������
//while (fast && fast->next)//������ż��������
//{
//    slow = slow->next;//��flat����֮��slow�����������м���
//    fast = fast->next->next;
//}
//return slow;
//
//}


//����һ������Ϊ n �������������е�Ԫ�ص�ֵΪ ai �����ظ������е�����k���ڵ㡣
//�����������С��k���뷵��һ������Ϊ 0 ������
struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    //˼·1���������
    // int count=0;//���������Ԫ��
    // struct ListNode* cur=pHead;
    // while(cur)
    // {
    //     cur=cur->next;
    //     count++;
    // }
    // if(k>count)//�Ը��������ж�
    // {
    //     return NULL;
    // }
    // else{
    //     int ret=count-k;
    //     while(ret)//�������
    //     {
    //         pHead=pHead->next;
    //         ret--;
    //     }
    // }
    // return pHead;
//}

    //˼·2������ָ��
    struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    struct ListNode* slow = pHead;
    struct ListNode* fast = pHead;
    while (k--)//fast��k��
    {
        if (fast == NULL)//�ж�k�Ƿ��������ĸ���
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast)//�ٵ�fast�ߵ���ָ�룬���൱��slow�ڵ�����kλ
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
