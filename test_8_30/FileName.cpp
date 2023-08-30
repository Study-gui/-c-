 #define _CRT_SECURE_NO_WARNINGS
//����һ���������������ɾ�������е������ظ����ֵ�Ԫ�أ�ֻ����ԭ������ֻ����һ�ε�Ԫ�ء�
//���磺
//����������Ϊ
//1��2��3��3��4��4��5, ����1��2��5.
//����������Ϊ
//1��1��1��2��3, ����2��3.
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
//    if (head == NULL || head->next == NULL)//�������
//    {
//        return head;
//    }
//    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = head;//�����սڵ�
//    struct ListNode* list = phead;//�ս��
//    struct ListNode* cur, * slow;//��ָ��Ϳ�ָ��
//    cur = head->next, slow = head;
//    while (cur)//��������
//    {
//        if (cur->val != slow->val)//�������ȣ��ͽ��ս��������
//        {
//
//            list = slow;
//            slow = cur;
//            cur = cur->next;
//        }
//        else {//�����ȣ����ÿ�ָ������ߣ��ҵ����Լ���һ������ȵ����Ľ��
//            while (cur->next != NULL && cur->val == cur->next->val)
//            {
//                cur = cur->next;
//            }
//            if (cur->next == NULL)//�ж��������
//            {
//                list->next = NULL;//�����ָ���ߵ�β�ڵ㣬˵�����涼����ȵ�����ֱ�����ӿ�ָ��
//                return phead->next;
//            }
//            slow = cur->next;
//            list->next = slow;//�����µĽڵ�
//            cur = slow->next;
//        }
//    }
//    return phead->next;
//}
//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣����ɾ����������ͷ�ڵ㡣
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
  * @param val int����
  * @return ListNode��
  */
//#include <stdlib.h>
//struct ListNode* deleteNode(struct ListNode* head, int val) {
//    // write code here
//    if (head == NULL)//�������
//    {
//        return head;
//    }
//    struct ListNode* cur, * prev;
//    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = head, cur = head, prev = tail;//�����½ڵ㣬ָ��head
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            tail->next = cur->next;//��ͬ����ɾ��
//            tail = cur->next;
//        }
//        else {
//            tail = cur;
//        }
//        cur = cur->next;
//    }
//    return prev->next;
//}
//����һ������Ϊ n �Ŀ������ظ�ֵ�����飬�ҳ����в�ȥ�ص���С�� k ��������������Ԫ����4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4(����˳��Կ�)��
//Ҫ�󣺿ռ临�Ӷ�O(n) ��ʱ�临�Ӷ�O(nlogk)
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param input int����һά����
 * @param inputLen int input���鳤��
 * @param k int����
 * @return int����һά����
 * @return int* returnSize ������������
 */
void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void AdjustDown(int* a, int n, int root)//����
{
    int parent = root;
    int child = 2 * parent + 1;//��ڵ�
    while (child < n)//�����������б���
    {
        if (a[child + 1] > a[child] && child < n - 1)//�ҵ��������������Ǹ�
        {
            child += 1;
        }
        if (a[child] > a[parent])//�����ڵ���бȽϽ���
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else {
            break;
        }
    }
}
void HeapSort(int* a, int n)
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)//����
    {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)//�ô�ѽ�������������
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}