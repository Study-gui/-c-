 #define _CRT_SECURE_NO_WARNINGS
//ũ������һȺţ��ţȺ�ĳ�Ա�ֲ���ɽ���ϣ��γ���һ���������ṹ��ÿͷţ����һ���߶�ֵ����ʾ����ɽ���ϵĸ߶ȡ�
//�����дһ�������ҳ�ţȺ�е����ţ��
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param root TreeNode��
  * @return int����
  */

//void PrevTree(struct TreeNode* head, int* max)
//{
//    if (head == NULL)
//    {
//        return;
//    }
//    if (head->val > *max)
//    {
//        *max = head->val;
//    }
//    PrevTree(head->left, max);
//    PrevTree(head->right, max);
//}
//int findMaxHeight(struct TreeNode* root) {
//    //˼·���ö�������ǰ���������Ѱ�����ֵ
//    if (root == NULL)
//        return 0;
//    int max = root->val;
//    PrevTree(root, &max);
//    return max;
//
//
//}
//ũ������һȺţ��ÿͷţ����һ�����صı�ţ������һ��������ʾ��������Χ��[0, 200]��ţȺ�е�ţ�õ������ʾ��
//�����Ѿ����շǽ������С�
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
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    //���ÿ���ָ��ȥ�������
//    struct ListNode* cur, * slow;
//    cur = head->next, slow = head;
//    while (cur)//������������
//    {
//        if (cur->val == slow->val)
//        {
//            slow->next = cur->next;//�����Ƚ��м���������
//            cur = cur->next;
//        }
//        else {
//            slow = slow->next;//����Ⱦͼ�������
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//ũ��������һȺţ������ÿֻţ������һ����ţ������������ʾ����Щţ���ձ�ŵĴ�С�γ���һ������
// ����ũ��������ɾ�������б�ǰ����ֵ�����ţ�ı�ţ����ܰ������һ���㷨��ʵ�����������ע�⣬ֻ����ɾ��ǰ��
//��β��ţ�ı�Ų�ɾ����
///**
//* struct ListNode {
//    *int val;
//    *struct ListNode* next;
//    *
//};
//*/
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param head ListNode��
// * @return ListNode��
// */
//    struct ListNode* deleteNodes(struct ListNode* head) {
//    if (head == NULL || head->next == NULL || head->next->next == NULL)
//    {
//        return head;
//    }
//    //˼·���������ÿ���ָ���������б���
//    struct ListNode* prev, * cur;
//    prev = head, cur = head->next;
//    while (cur->next)
//    {
//        if (cur->val > prev->val && cur->val > cur->next->val)//���������ͽ����������
//        {
//            prev->next = cur->next;
//            prev = cur;
//            cur = cur->next;
//        }
//        else {
//            prev = cur;
//            cur = cur->next;
//
//        }
//    }
//    return head;
//}
//ũ������һȺţ��ÿͷţ����һ����ţ������һ��������ʾ��������Χ��[0, 100]��ţȺ�е�ţ�õ������ʾ��
//���ڣ�ũ������Ҫ����ţȺ��˳�򡣸���һ�������������еĵ����� n ������Ƶ������ĩβ�����ҷ��ص������
//�����ͷ���
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
struct ListNode* moveNthToEnd(struct ListNode* head, int n) {
    if (head == NULL || n == 0 || head->next == NULL || n == 1)//��������������ж�
    {
        return head;
    }
    struct ListNode* phead1, * phead2;
    struct ListNode* list;
    phead1 = head;
    phead2 = head;
    while (n - 1)//����n-1��
    {
        phead2 = phead2->next;
        n--;
    }
    while (phead2->next)//���ߵ�β��㣬phead1ָ��ľ��ǵ�����n���ڵ�
    {
        list = phead1;//�ҵ�n���֮ǰ�Ľڵ�
        phead1 = phead1->next;
        phead2 = phead2->next;
    }
    if (list == head)//�Խ������жϣ����ǲ���ͷ�ڵ�
    {
        head = list->next;
        phead2->next = phead1;
        phead1->next = NULL;
    }
    else {
        list->next = phead1->next;
        phead2->next = phead1;
        phead1->next = NULL;
    }
    return head;
}