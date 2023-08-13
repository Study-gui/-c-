 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。


struct Node* copyRandomList(struct Node* head) {
    //创建一个空间进行映射拷贝
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;//结点进行保存
        cur->next = copy;//断开结点
        cur = copy->next;
    }
    //对拷贝空间的random也进行拷贝
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    //对映射拷贝的空间进行取出，并对原链表进行复原
    cur = head;
    struct Node* tailhead = NULL, * listhead = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (tailhead == NULL)
        {
            tailhead = listhead = copy;
        }
        else {
            tailhead->next = copy;
        }
        tailhead = copy;
        cur->next = copy->next;
        cur = copy->next;
    }
    return listhead;
}
