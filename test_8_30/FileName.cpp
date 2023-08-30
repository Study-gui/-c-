 #define _CRT_SECURE_NO_WARNINGS
//给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
//例如：
//给出的链表为
//1→2→3→3→4→4→5, 返回1→2→5.
//给出的链表为
//1→1→1→2→3, 返回2→3.
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
  * @return ListNode类
  */
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//    if (head == NULL || head->next == NULL)//特殊情况
//    {
//        return head;
//    }
//    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = head;//创建空节点
//    struct ListNode* list = phead;//空结点
//    struct ListNode* cur, * slow;//慢指针和快指针
//    cur = head->next, slow = head;
//    while (cur)//遍历链表
//    {
//        if (cur->val != slow->val)//如果不相等，就将空结点的向后移
//        {
//
//            list = slow;
//            slow = cur;
//            cur = cur->next;
//        }
//        else {//如果相等，就让快指针向后走，找到与自己后一个不相等的数的结点
//            while (cur->next != NULL && cur->val == cur->next->val)
//            {
//                cur = cur->next;
//            }
//            if (cur->next == NULL)//判断特殊情况
//            {
//                list->next = NULL;//如果快指针走到尾节点，说明后面都是相等的数，直接连接空指针
//                return phead->next;
//            }
//            slow = cur->next;
//            list->next = slow;//连接新的节点
//            cur = slow->next;
//        }
//    }
//    return phead->next;
//}
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
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
  * @param val int整型
  * @return ListNode类
  */
//#include <stdlib.h>
//struct ListNode* deleteNode(struct ListNode* head, int val) {
//    // write code here
//    if (head == NULL)//特殊情况
//    {
//        return head;
//    }
//    struct ListNode* cur, * prev;
//    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = head, cur = head, prev = tail;//开辟新节点，指向head
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            tail->next = cur->next;//相同进行删除
//            tail = cur->next;
//        }
//        else {
//            tail = cur;
//        }
//        cur = cur->next;
//    }
//    return prev->next;
//}
//给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
//要求：空间复杂度O(n) ，时间复杂度O(nlogk)
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param input int整型一维数组
 * @param inputLen int input数组长度
 * @param k int整型
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void AdjustDown(int* a, int n, int root)//堆排
{
    int parent = root;
    int child = 2 * parent + 1;//左节点
    while (child < n)//对整个树进行遍历
    {
        if (a[child + 1] > a[child] && child < n - 1)//找到左右子树最大的那个
        {
            child += 1;
        }
        if (a[child] > a[parent])//跟父节点进行比较交换
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
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)//建堆
    {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end > 0)//用大堆进行排升序序列
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}