 #define _CRT_SECURE_NO_WARNINGS
//����������ÿһ���ڵ��ֵ���� 0 - 9 ֮�䣬��ô��������Ϳ��Դ���һ��������
//���������������������ɴ��������������ֵ�Ľ������
//���磺���� 1 Ϊ 9->3->7������ 2 Ϊ 6->3����������µĽ������Ϊ 1->0->0->0��
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
  * @param head1 ListNode��
  * @param head2 ListNode��
  * @return ListNode��
  */
  //��д��ת����ĺ���
struct ListNode* reverse(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* n1, * n2, * n3;
    n1 = NULL, n2 = head, n3 = head->next;
    while (n2 != NULL)
    {
        //��������������������з�ת
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
    //     struct ListNode* newnode;
    //     newnode=reverse(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //    return newnode;
}
//��д���������ȵĺ���
int get_len(struct ListNode* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2) {
    if (head1 == NULL)//��д�������
        return head2;
    if (head2 == NULL)
        return head1;
    int len1 = get_len(head1);//���������ĳ���
    int len2 = get_len(head2);
    struct ListNode* phead1 = reverse(head1);//��������з�ת
    struct ListNode* phead2 = reverse(head2);
    struct ListNode* plist1 = phead1;//����phead1��һЩ
    struct ListNode* plist2 = phead2;
    struct ListNode* phead = NULL;

    if (len1 < len2)
    {
        plist1 = phead2;
        plist2 = phead1;
    }
    phead = plist1;//��phead��¼û�з�תǰ��ͷ���
    int arr_j = 0;//Ϊ��������ӵĽ�λ
    int arr_b = 0;//Ϊÿһλ��������ӵ��ܺ�

    while (plist2 != NULL)//�Զ̵�������б���
    {
        plist1->val = plist1->val + arr_j;//��ǰһλ�Ľ�λ���ӵ���λ����
        arr_b = plist1->val + plist2->val;//�õ��ܺ�
        arr_j = arr_b / 10;//�õ���λ
        plist1->val = arr_b % 10;//�õ���λ�����
        plist1 = plist1->next;
        plist2 = plist2->next;
    }
    //if(arr_j==1)
    //{
    while (plist1 != NULL)//��û�б������������б���
    {
        arr_b = plist1->val + arr_j;
        arr_j = arr_b / 10;
        plist1->val = arr_b % 10;
        plist1 = plist1->next;
    }
    //}
    struct ListNode* ret = reverse(phead);//����Ӻ��������з�ת
    if (arr_j == 1)//���������ˣ���λΪ1���Ļ������Ƿ�ת���������λ��1
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = 1;//���ٿռ���и�ֵ
        newnode->next = ret;
        ret = newnode;
    }
    return ret;//����ͷ�ڵ�



}