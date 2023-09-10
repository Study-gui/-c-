 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//农场里有一群牛，它们被组织成一个链表形式的队列。每头牛都有一个编号（每只牛编号唯一），编号范围是[-105, 105]。
// 每头牛都有一个指针，指向它后面的一头牛。但是，有一些顽皮的牛可能会指向它们前面的某一头牛，从而形成一个环。
//现在，给你一个链表的头节点 head，判断这个牛队列中是否有环。
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
  * @return bool布尔型
  */
//bool hasCycle(struct ListNode* head) {
//    //本题思路：利用快慢指针进行遍历链表，但是不同链表的是队列每一个结点都是独立的，所以不能比较节点地址
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

//农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[0, 100]，同时也表示牛的体重级别。
//牛群中的牛用单链表表示。现在，农场主想要调整牛群的顺序，使体重较大的牛在一边，体重较小的牛在一边
//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点
//之前。你应当保留两个分区中每个节点的初始相对位置。
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
  * @param x int整型
  * @return ListNode类
  */
//#include <math.h>
//struct ListNode* cow_partition(struct ListNode* head, int x) {
//    //本题思路：创建两个链表，一个人小于x，一个大于等于x的链表，对链表进行遍历比较，并进行存入
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
//    min->next = pmax->next;//把两个链表进行结合，处理头尾节点的关系
//    max->next = NULL;
//    return pmin->next;
//}
//农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[-100, 100]。牛群中的牛用单链表表示。
//现在，农场主想要调整牛群的顺序。给你一个链表的头节点 head ，将链表每头牛向右移动 k 个位置。
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
  * @param k int整型
  * @return ListNode类
  */
//struct ListNode* rotateLeft(struct ListNode* head, int k) {
//    //本题思路：与翻转k个链表相似，找到倒数第k个节点进行翻转，要注意本题要进行取余或者判断是否大于链表本身
//    if (head == NULL || head->next == NULL || k == 0)
//    {
//        return head;
//    }
//    struct ListNode* cur = head;
//    int ret = 1;
//    while (cur->next)//计算得到链表的长度
//    {
//        cur = cur->next;
//        ret++;
//    }
//    if (k > ret)
//    {
//        int count = k % ret;//进行取余
//        struct ListNode* tail, * prev;
//        tail = prev = head;
//        while (count--)//快指针先走k步
//        {
//            prev = prev->next;
//        }
//        while (prev->next)//再找到倒数第k个节点的前一位
//        {
//            prev = prev->next;
//            tail = tail->next;
//        }
//        struct ListNode* next = tail->next;//对要返回的头结点进行保存
//        tail->next = NULL;//对翻转的链表进行头尾结点进行连接
//        prev->next = head;
//        return next;
//    }
//    else if (k == ret)
//    {
//        return head;
//    }
//    else {//与上面同理
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