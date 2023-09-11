 #define _CRT_SECURE_NO_WARNINGS
//ũ������һЩţ��ÿͷţ����һ����ţ�0 - 9������Щţ����һ����˳��վ�������ǿ��԰����˳������һ��������
//ţ�ı�ž�������Ľڵ㡣����ũ������֪������Щţ�ı��˳���Ƿ��ǻ��ĵġ�����ǣ����� true �����򣬷��� false
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
  * @return ListNode��
  */
struct ListNode* sortCowsIV(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* max = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* min = (struct ListNode*)malloc(sizeof(struct ListNode));
    max->next = NULL, min->next = NULL;
    struct ListNode* tail, * prev;
    tail = max, prev = min;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == 0)
        {
            min->next = cur;
            min = cur;
        }
        else if (cur->val == 1)
        {
            max->next = cur;
            max = cur;
        }
        cur = cur->next;
    }
    min->next = tail->next;
    max->next = NULL;
    return prev->next;
}