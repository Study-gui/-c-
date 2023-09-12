 #define _CRT_SECURE_NO_WARNINGS
//农场里有一些牛，每头牛都有一个编号（0-9）。这些牛按照一定的顺序站立，我们可以把这个顺序看作是一个单链表，
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
  * @return bool布尔型
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
    //本题利用快慢指针找到中间结点，对中间结点后面的链表进行翻转，在进行比较
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* solw, * cur;
    solw = head, cur = head;
    while (solw && solw->next)//找到中间结点
    {
        solw = solw->next->next;
        cur = cur->next;
    }
    cur = Reverse(cur);//翻转后面链表
    while (cur)//进行比较
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