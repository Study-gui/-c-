 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ũ������һȺţ�����Ǳ���֯��һ��������ʽ�Ķ��С�ÿͷţ����һ����ţ�ÿֻţ���Ψһ������ŷ�Χ��[-105, 105]��
// ÿͷţ����һ��ָ�룬ָ���������һͷţ�����ǣ���һЩ��Ƥ��ţ���ܻ�ָ������ǰ���ĳһͷţ���Ӷ��γ�һ������
//���ڣ�����һ�������ͷ�ڵ� head���ж����ţ�������Ƿ��л���
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
//bool hasCycle(struct ListNode* head) {
//    //����˼·�����ÿ���ָ����б����������ǲ�ͬ������Ƕ���ÿһ����㶼�Ƕ����ģ����Բ��ܱȽϽڵ��ַ
//    if (head == NULL || head->next == NULL)
//    {
//        return false;
//    }
//    else {
//        struct ListNode* cur, * tail;
//        tail = head;
//        cur = head->next;
//        while (cur && cur->next)
//        {
//            if (cur->val == tail->val)
//            {
//                return true;
//            }
//            cur = cur->next->next;
//            tail = tail->next;
//        }
//        return false;
//    }
//}

//ũ������һȺţ��ÿͷţ����һ����ţ������һ��������ʾ��������Χ��[0, 100]��ͬʱҲ��ʾţ�����ؼ���
//ţȺ�е�ţ�õ������ʾ�����ڣ�ũ������Ҫ����ţȺ��˳��ʹ���ؽϴ��ţ��һ�ߣ����ؽ�С��ţ��һ��
//����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������С�� x �Ľڵ㶼�����ڴ��ڻ���� x �Ľڵ�
//֮ǰ����Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
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
  * @param x int����
  * @return ListNode��
  */
//#include <math.h>
//struct ListNode* cow_partition(struct ListNode* head, int x) {
//    //����˼·��������������һ����С��x��һ�����ڵ���x��������������б����Ƚϣ������д���
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    struct ListNode* max = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* min = (struct ListNode*)malloc(sizeof(struct ListNode));
//    min->next = NULL, max->next = NULL;
//    struct ListNode* tail = head;
//    struct ListNode* pmax, * pmin;
//    pmax = max, pmin = min;
//    while (tail)
//    {
//        if (tail->val < x)
//        {
//            min->next = tail;
//            min = tail;
//        }
//        else {
//            max->next = tail;
//            max = tail;
//        }
//        tail = tail->next;
//    }
//    min->next = pmax->next;//������������н�ϣ�����ͷβ�ڵ�Ĺ�ϵ
//    max->next = NULL;
//    return pmin->next;
//}
//ũ������һȺţ��ÿͷţ����һ����ţ������һ��������ʾ��������Χ��[-100, 100]��ţȺ�е�ţ�õ������ʾ��
//���ڣ�ũ������Ҫ����ţȺ��˳�򡣸���һ�������ͷ�ڵ� head ��������ÿͷţ�����ƶ� k ��λ�á�
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
//struct ListNode* rotateLeft(struct ListNode* head, int k) {
//    //����˼·���뷭תk���������ƣ��ҵ�������k���ڵ���з�ת��Ҫע�Ȿ��Ҫ����ȡ������ж��Ƿ����������
//    if (head == NULL || head->next == NULL || k == 0)
//    {
//        return head;
//    }
//    struct ListNode* cur = head;
//    int ret = 1;
//    while (cur->next)//����õ�����ĳ���
//    {
//        cur = cur->next;
//        ret++;
//    }
//    if (k > ret)
//    {
//        int count = k % ret;//����ȡ��
//        struct ListNode* tail, * prev;
//        tail = prev = head;
//        while (count--)//��ָ������k��
//        {
//            prev = prev->next;
//        }
//        while (prev->next)//���ҵ�������k���ڵ��ǰһλ
//        {
//            prev = prev->next;
//            tail = tail->next;
//        }
//        struct ListNode* next = tail->next;//��Ҫ���ص�ͷ�����б���
//        tail->next = NULL;//�Է�ת���������ͷβ����������
//        prev->next = head;
//        return next;
//    }
//    else if (k == ret)
//    {
//        return head;
//    }
//    else {//������ͬ��
//        struct ListNode* tail, * prev;
//        tail = prev = head;
//        while (k--)
//        {
//            prev = prev->next;
//        }
//        while (prev->next)
//        {
//            prev = prev->next;
//            tail = tail->next;
//        }
//        struct ListNode* next = tail->next;
//        tail->next = NULL;
//        prev->next = head;
//        return next;
//    }
//}


int main()
{
	int arr[3][3] = {0,1,2,3,4,5,6,7,8};
	int i = 2;
	int* p[1] = {&i};
	int x = *p[0];
	printf("%d\n", sizeof(arr[0]));
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr+1));
	printf("%p\n", arr[0]);
	printf("%p\n", arr);
	printf("%p\n", arr+1);
	printf("%p\n", arr[0] + 1);
	return 0;
}