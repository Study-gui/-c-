 #define _CRT_SECURE_NO_WARNINGS
//假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
//给定两个这种链表，请生成代表两个整数相加值的结果链表。
//例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。
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
  * @param head1 ListNode类
  * @param head2 ListNode类
  * @return ListNode类
  */
  //编写翻转链表的函数
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
        //利用三个变量堆链表进行翻转
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
//编写计算链表长度的函数
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
    if (head1 == NULL)//编写极端情况
        return head2;
    if (head2 == NULL)
        return head1;
    int len1 = get_len(head1);//计算出链表的长度
    int len2 = get_len(head2);
    struct ListNode* phead1 = reverse(head1);//对链表进行翻转
    struct ListNode* phead2 = reverse(head2);
    struct ListNode* plist1 = phead1;//假设phead1长一些
    struct ListNode* plist2 = phead2;
    struct ListNode* phead = NULL;

    if (len1 < len2)
    {
        plist1 = phead2;
        plist2 = phead1;
    }
    phead = plist1;//用phead记录没有翻转前的头结点
    int arr_j = 0;//为两个数相加的进位
    int arr_b = 0;//为每一位两个数相加的总和

    while (plist2 != NULL)//对短的链表进行遍历
    {
        plist1->val = plist1->val + arr_j;//把前一位的进位，加到这位数上
        arr_b = plist1->val + plist2->val;//得到总和
        arr_j = arr_b / 10;//得到进位
        plist1->val = arr_b % 10;//得到进位后的数
        plist1 = plist1->next;
        plist2 = plist2->next;
    }
    //if(arr_j==1)
    //{
    while (plist1 != NULL)//对没有遍历完的链表进行遍历
    {
        arr_b = plist1->val + arr_j;
        arr_j = arr_b / 10;
        plist1->val = arr_b % 10;
        plist1 = plist1->next;
    }
    //}
    struct ListNode* ret = reverse(phead);//对相加后的链表进行翻转
    if (arr_j == 1)//如果相加完了，进位为1，的话，就是翻转后的链表首位的1
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = 1;//开辟空间进行赋值
        newnode->next = ret;
        ret = newnode;
    }
    return ret;//返回头节点



}