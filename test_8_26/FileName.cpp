 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���������޻��ĵ��������ҳ����ǵĵ�һ��������㣬���û�й����ڵ��򷵻ؿա���ע����Ϊ��������������
//���Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pHead1 ListNode��
  * @param pHead2 ListNode��
  * @return ListNode��
  */
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL)//��������������ж�
        return NULL;
    struct ListNode* p1, * p2;
    p1 = pHead1, p2 = pHead2;
    int n = 0, m = 0;//���������ж���Ԫ�ظ���
    while (p1)
    {
        p1 = p1->next;
        n++;
    }
    while (p2)
    {
        p2 = p2->next;
        m++;
    }
    //    if(p1!=p2)
    //    {
    //     return NULL;
    //    }
    struct ListNode* plist1, * plist2;
    plist1 = pHead1, plist2 = pHead2;//����phead1��
    if (m > n)//�������ж�
    {
        plist1 = pHead2;
        plist2 = pHead1;
    }
    int s = abs(m - n);//�������ֵ
    while (s--)//������������ж���
    {
        plist1 = plist1->next;
    }
    while (plist1 && plist2)//��������б���
    {
        if (plist1 == plist2)//�ж������Ƿ����
        {
            return plist1;
        }
        plist1 = plist1->next;
        plist2 = plist2->next;

    }
    return NULL;
}