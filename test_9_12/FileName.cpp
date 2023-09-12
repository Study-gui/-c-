 #define _CRT_SECURE_NO_WARNINGS
//ũ������һЩţ��ÿͷţ����һ����ţ�0-9������Щţ����һ����˳��վ�������ǿ��԰����˳������һ��������
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
  * @return bool������
  */
struct ListNode* Reverse(struct ListNode* phead)
{
    if (phead == NULL || phead->next == NULL)
    {
        return phead;
    }
    struct ListNode* n1, * n2, * n3;
    n1 = NULL, n2 = phead, n3 = phead->next;
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
bool isPalindrome(struct ListNode* head) {
    //�������ÿ���ָ���ҵ��м��㣬���м�������������з�ת���ڽ��бȽ�
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* solw, * cur;
    solw = head, cur = head;
    while (solw && solw->next)//�ҵ��м���
    {
        solw = solw->next->next;
        cur = cur->next;
    }
    cur = Reverse(cur);//��ת��������
    while (cur)//���бȽ�
    {
        if (head->val != cur->val)
        {
            return false;
        }
        cur = cur->next;
        head = head->next;
    }
    return true;

}