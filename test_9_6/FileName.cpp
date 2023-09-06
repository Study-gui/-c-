 #define _CRT_SECURE_NO_WARNINGS
//�������������еĽڵ�ÿ k ��һ�鷭ת�����ط�ת�������
//��������еĽڵ������� k �ı����������ʣ�µĽڵ㱣��ԭ��
//�㲻�ܸ��Ľڵ��е�ֵ��ֻ�ܸ��Ľڵ㱾��
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
  * @param k int����
  * @return ListNode��
  */
#include <math.h>
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 1)//�����������������
    {
        return head;
    }
    //����˼·�����õݹ�ķ������н��
    struct ListNode* cur, * prev, * tail;
    cur = head;
    prev = NULL, tail = NULL;
    for (int i = 1; i <= k; i++)
    {
        if (cur == NULL)
        {
            return head;//�ݹ�������
        }
        cur = cur->next;
    }
    cur = head;
    for (int i = 1; i <= k; i++)//��k��Χ������ת
    {
        tail = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tail;
    }
    head->next = reverseKGroup(cur, k);//�����ú��β������һ�����ú��ͷ�ڵ�
    return prev;//������������ͷ�ڵ�
}