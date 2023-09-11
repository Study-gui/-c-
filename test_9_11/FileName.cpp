 #define _CRT_SECURE_NO_WARNINGS
//农场里有一些牛，每头牛都有一个编号（0 - 9）。这些牛按照一定的顺序站立，我们可以把这个顺序看作是一个单链表，
//牛的编号就是链表的节点。现在农场主想知道，这些牛的编号顺序是否是回文的。如果是，返回 true ；否则，返回 false
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