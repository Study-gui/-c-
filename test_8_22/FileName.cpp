 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(N),空间复杂度O(1)
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param head ListNode类
  * @param m int整型
  * @param n int整型
  * @return ListNode类
  */
//#include <stddef.h>
//struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
//    if (!head || !head->next)//两种极端情况
//        return head;
//    if (m == n)
//        return head;
//    struct ListNode* vhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    vhead->next = head;//创建一个指向head的节点
//    struct ListNode* phead = vhead;
//    struct ListNode* p1m, * pm, * p1n, * pn;
//    p1m = NULL, pm = NULL, p1n = NULL, pn = NULL;
//    for (int i = 1; i < m; i++)
//    {
//        phead = phead->next;
//    }
//    p1m = phead;//找到m前一个节点
//    pm = phead->next;//找到m结点
//    phead = vhead;
//    for (int i = 1; i < n; i++)
//    {
//        phead = phead->next;
//    }
//    pn = phead->next;//找到n结点
//    p1n = pn->next;//找到n后一个结点
//    struct ListNode* ps = NULL;
//    while (ps != pn)//对m到n的区间进行翻转
//    {
//        struct ListNode* plist = pm->next;
//        pm->next = ps;
//        ps = pm;
//        pm = plist;
//    }
//    p1m->next->next = p1n;//再把m前一个结点连接到n的节点
//    p1m->next = pn;//m节点连接到n后的一个节点
//    //free(vhead);
//    return vhead->next;//返回头节点
//}

//给定一个链表，删除链表的倒数第 n 个节点并返回链表的头指针
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param head ListNode类
  * @param n int整型
  * @return ListNode类
  */
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//    if (head == NULL || head->next == NULL)//判断个别情况
//    {
//        return NULL;
//    }
//    struct ListNode* phead1, * phead2;
//    phead1 = phead2 = head;
//    while (n--)//先让phead2走n个节点
//    {
//        phead2 = phead2->next;
//    }
//    if (phead2 == NULL)//判断是否为空指针，为空指针说明删除的是首元素
//    {
//        return head->next;
//    }
//
//    while (phead2->next)//不空指针，找到第n个的前一个结点
//    {
//        phead1 = phead1->next;
//        phead2 = phead2->next;
//    }
//    phead1->next = phead1->next->next;//把n前一个结点连接n后一个节点
//    return head;
//}
//给你一个整数数组,其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素。你可以按任意顺序 返回答案


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    //利用相同数异或为零的原理
    int i = 0;
    int ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];//将全部数进行异或，就是相当于两个不同的数进行异或
    }
    int pos = 0;
    while (((ret >> pos) & 1) != 1)//找到两个不同的数最低位的不同位
    {
        pos++;
    }
    int tmp = 0;
    for (i = 0; i < numsSize; i++)//将不同位的一样的数进行异或就是其中一个一个数
    {
        if ((nums[i] >> pos) & 1)
        {
            tmp ^= nums[i];
        }
    }
    int* arr = (int*)malloc(sizeof(int) * 2);//
    arr[0] = tmp;//返回其中一个数
    arr[1] = tmp ^ ret;//其中一个数异或两个不同的数，就会得到另外一个数
    *returnSize = 2;
    return arr;
}