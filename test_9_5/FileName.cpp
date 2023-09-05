 #define _CRT_SECURE_NO_WARNINGS
//农场里有一群牛，牛群的成员分布在山坡上，形成了一个二叉树结构。每头牛都有一个高度值，表示它在山坡上的高度。
//请你编写一个程序，找出牛群中的最高牛。
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param root TreeNode类
  * @return int整型
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
//    //思路利用二叉树的前序遍历进行寻找最大值
//    if (root == NULL)
//        return 0;
//    int max = root->val;
//    PrevTree(root, &max);
//    return max;
//
//
//}
//农场里有一群牛，每头牛都有一个独特的编号，编号由一个整数表示，整数范围是[0, 200]。牛群中的牛用单链表表示，
//链表已经按照非降序排列。
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
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    //利用快慢指针去解决问题
//    struct ListNode* cur, * slow;
//    cur = head->next, slow = head;
//    while (cur)//遍历整个链表
//    {
//        if (cur->val == slow->val)
//        {
//            slow->next = cur->next;//如果相等进行假设性跳过
//            cur = cur->next;
//        }
//        else {
//            slow = slow->next;//不相等就继续遍历
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//农场主人有一群牛，他给每只牛都打了一个编号，编号由整数表示。这些牛按照编号的大小形成了一个链表。
// 现在农场主人想删除链表中比前后结点值都大的牛的编号，你能帮他设计一个算法来实现这个功能吗？注意，只考虑删除前，
//首尾的牛的编号不删除。
///**
//* struct ListNode {
//    *int val;
//    *struct ListNode* next;
//    *
//};
//*/
///**
// * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// *
// *
// * @param head ListNode类
// * @return ListNode类
// */
//    struct ListNode* deleteNodes(struct ListNode* head) {
//    if (head == NULL || head->next == NULL || head->next->next == NULL)
//    {
//        return head;
//    }
//    //思路：就是利用快慢指针对链表进行遍历
//    struct ListNode* prev, * cur;
//    prev = head, cur = head->next;
//    while (cur->next)
//    {
//        if (cur->val > prev->val && cur->val > cur->next->val)//满足条件就进行跳过结点
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
//农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[0, 100]。牛群中的牛用单链表表示。
//现在，农场主想要调整牛群的顺序。给你一个链表，将链表中的倒数第 n 个结点移到链表的末尾，并且返回调整后的
//链表的头结点
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
struct ListNode* moveNthToEnd(struct ListNode* head, int n) {
    if (head == NULL || n == 0 || head->next == NULL || n == 1)//堆特殊情况进行判断
    {
        return head;
    }
    struct ListNode* phead1, * phead2;
    struct ListNode* list;
    phead1 = head;
    phead2 = head;
    while (n - 1)//先走n-1步
    {
        phead2 = phead2->next;
        n--;
    }
    while (phead2->next)//再走到尾结点，phead1指向的就是倒数第n个节点
    {
        list = phead1;//找到n结点之前的节点
        phead1 = phead1->next;
        phead2 = phead2->next;
    }
    if (list == head)//对结点进行判断，看是不是头节点
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