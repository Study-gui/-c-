 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点,并返回新的头节点 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur)//对整个链表进行遍历
//    {
//        if (cur->val == val)//判断是否相等
//        {
//            if (cur == head)//在进行判断是否是首元素相等，进行头删
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//            }
//            else {//不是首元素，就进行删除
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else {//若不相等，向后走
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}


//给你单链表的头节点head ，请你反转链表，并返回反转后的链表。

//思路1： 直接在原链表里翻转
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)//对链表为空进行判断
//        return NULL;
//    struct ListNode* n1 = NULL;//设定一个为n1进行翻转赋值
//    struct ListNode* n2 = head;//设定一个n2进行反转赋值
//    struct ListNode* n3 = head->next;//设定一个n3进行充当中间变量
//    while (n2)
//    {
//        //翻转赋值过程
//        n2->next = n1;
//        //迭代过程
//        n1 = n2;
//        n2 = n3;
//        if (n3)//n3判断不能越界
//            n3 = n3->next;
//    }
//    return n1;
//}

//思路2：创建一个新链表进行赋值
//struct ListNode* reverseList(struct ListNode* head) {
//struct ListNode* newnode = NULL;//反转前一位地址变量
//struct ListNode* cur = head;//表示现在的状态
//while (cur)
//{
//    struct ListNode* next = cur->next;//创建中间变量
//    //逻辑赋值
//    cur->next = newnode;
//    //迭代过程
//    newnode = cur;
//    cur = next;
//}
//return newnode;
//}

//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//思路1：暴力解法
struct ListNode* middleNode(struct ListNode* head) {
    //思路1：暴力解法
//    int count=0;//技术链表有多少元素
//    struct ListNode* cur=head;
//    while(cur)
//    {
//        cur=cur->next;
//        count++;
//    }
//    if(count%2==0)
//    {
//        int mid=count/2;//进行遍历
//        while(mid)
//        {
//            head=head->next;
//            mid--;
//        }
//    }
//    else{
//        int mid=count/2;
//        while(mid)
//        {
//            head=head->next;
//            mid--;
//        }
//    }
//    return head;
}

//思路2：快慢指针
//struct ListNode* middleNode(struct ListNode* head) {
//truct ListNode* slow = head;//创建一个指针每次走一步
//struct ListNode* fast = head;//创建一个指针每次走两步
//while (fast && fast->next)//奇数和偶数的条件
//{
//    slow = slow->next;//当flat走完之后slow真好在链表的中间结点
//    fast = fast->next->next;
//}
//return slow;
//
//}


//输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
//如果该链表长度小于k，请返回一个长度为 0 的链表
struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    //思路1：暴力求解
    // int count=0;//计算链表的元素
    // struct ListNode* cur=pHead;
    // while(cur)
    // {
    //     cur=cur->next;
    //     count++;
    // }
    // if(k>count)//对个数进行判断
    // {
    //     return NULL;
    // }
    // else{
    //     int ret=count-k;
    //     while(ret)//进行求解
    //     {
    //         pHead=pHead->next;
    //         ret--;
    //     }
    // }
    // return pHead;
//}

    //思路2；快慢指针
    struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
    struct ListNode* slow = pHead;
    struct ListNode* fast = pHead;
    while (k--)//fast走k步
    {
        if (fast == NULL)//判断k是否大于链表的个数
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast)//再到fast走到空指针，就相当于slow在倒数的k位
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
