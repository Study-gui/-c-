 #define _CRT_SECURE_NO_WARNINGS
//ũ������һȺţ��ÿͷţ����һ����ţ������һ��������ʾ��������Χ��[-500, 500]��ţȺ�е�ţ�õ������ʾ��
//���ڣ�ũ������Ҫ�ı�ţȺ������˳�򡣸���һ���������ͷָ�� head ���������� left �� right������ left <= right��
//���㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת���ţȺ����
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
  * @param left int����
  * @param right int����
  * @return ListNode��
  */

//struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
//    if (head == NULL || head->next == NULL || left == right)//��������������ж�
//    {
//        return head;
//    }
//    struct ListNode* phead;
//    phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = head;//����һ��ָ��ͷ�ڵ���½ڵ�
//    struct ListNode* hleft, * hright, * tail, * lcur, * rcur;
//    hleft = NULL, hright = NULL, tail = phead;
//    int m = left, n = right;
//    while (--m)
//    {
//        tail = tail->next;
//    }
//    hleft = tail;//�ҵ�leftǰһ���ڵ�
//    lcur = tail->next;//�ҵ�left���
//    tail = phead;
//    while (n--)
//    {
//        tail = tail->next;
//    }
//    hright = tail;//right���
//    rcur = tail->next;//right��һ�����
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL, n2 = lcur, n3 = n2->next;
//    while (n2 != rcur && n3)//��left��right��������з�ת
//    {
//        n3 = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//    }
//    hleft->next = n1;//������left��right֮���ǰ����
//    lcur->next = rcur;
//    if (left == 1)//�ж��ǲ��Ǵ�ͷ�����з�ת
//    {
//        return n1;
//    }
//    return head;
//
//}
//ũ��������Ⱥţ��ÿȺţ����һ��������ֵ������ֵ��һ��������ʾ��������Χ��[-100, 100]��ÿȺţ������ֵ�Ѿ�����
//�ǵ���˳�����У����洢��������
//���ڣ�����Ҫ������Ⱥţ������ֵ�ϲ�Ϊһ���µķǵ����������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
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
  * @param l1 ListNode��
  * @param l2 ListNode��
  * @return ListNode��
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