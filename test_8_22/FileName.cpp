 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��һ���ڵ���Ϊ size ���� m λ�õ� n λ��֮������䷴ת��Ҫ��ʱ�临�Ӷ� O(N),�ռ临�Ӷ�O(1)
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param head ListNode��
  * @param m int����
  * @param n int����
  * @return ListNode��
  */
//#include <stddef.h>
//struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
//    if (!head || !head->next)//���ּ������
//        return head;
//    if (m == n)
//        return head;
//    struct ListNode* vhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    vhead->next = head;//����һ��ָ��head�Ľڵ�
//    struct ListNode* phead = vhead;
//    struct ListNode* p1m, * pm, * p1n, * pn;
//    p1m = NULL, pm = NULL, p1n = NULL, pn = NULL;
//    for (int i = 1; i < m; i++)
//    {
//        phead = phead->next;
//    }
//    p1m = phead;//�ҵ�mǰһ���ڵ�
//    pm = phead->next;//�ҵ�m���
//    phead = vhead;
//    for (int i = 1; i < n; i++)
//    {
//        phead = phead->next;
//    }
//    pn = phead->next;//�ҵ�n���
//    p1n = pn->next;//�ҵ�n��һ�����
//    struct ListNode* ps = NULL;
//    while (ps != pn)//��m��n��������з�ת
//    {
//        struct ListNode* plist = pm->next;
//        pm->next = ps;
//        ps = pm;
//        pm = plist;
//    }
//    p1m->next->next = p1n;//�ٰ�mǰһ��������ӵ�n�Ľڵ�
//    p1m->next = pn;//m�ڵ����ӵ�n���һ���ڵ�
//    //free(vhead);
//    return vhead->next;//����ͷ�ڵ�
//}

//����һ������ɾ������ĵ����� n ���ڵ㲢���������ͷָ��
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param head ListNode��
  * @param n int����
  * @return ListNode��
  */
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//    if (head == NULL || head->next == NULL)//�жϸ������
//    {
//        return NULL;
//    }
//    struct ListNode* phead1, * phead2;
//    phead1 = phead2 = head;
//    while (n--)//����phead2��n���ڵ�
//    {
//        phead2 = phead2->next;
//    }
//    if (phead2 == NULL)//�ж��Ƿ�Ϊ��ָ�룬Ϊ��ָ��˵��ɾ��������Ԫ��
//    {
//        return head->next;
//    }
//
//    while (phead2->next)//����ָ�룬�ҵ���n����ǰһ�����
//    {
//        phead1 = phead1->next;
//        phead2 = phead2->next;
//    }
//    phead1->next = phead1->next->next;//��nǰһ���������n��һ���ڵ�
//    return head;
//}
//����һ����������,����ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ��ҳ�ֻ����һ�ε�������Ԫ�ء�����԰�����˳�� ���ش�


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    //������ͬ�����Ϊ���ԭ��
    int i = 0;
    int ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];//��ȫ����������򣬾����൱��������ͬ�����������
    }
    int pos = 0;
    while (((ret >> pos) & 1) != 1)//�ҵ�������ͬ�������λ�Ĳ�ͬλ
    {
        pos++;
    }
    int tmp = 0;
    for (i = 0; i < numsSize; i++)//����ͬλ��һ��������������������һ��һ����
    {
        if ((nums[i] >> pos) & 1)
        {
            tmp ^= nums[i];
        }
    }
    int* arr = (int*)malloc(sizeof(int) * 2);//
    arr[0] = tmp;//��������һ����
    arr[1] = tmp ^ ret;//����һ�������������ͬ�������ͻ�õ�����һ����
    *returnSize = 2;
    return arr;
}