 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣


struct Node* copyRandomList(struct Node* head) {
    //����һ���ռ����ӳ�俽��
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;//�����б���
        cur->next = copy;//�Ͽ����
        cur = copy->next;
    }
    //�Կ����ռ��randomҲ���п���
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
    //��ӳ�俽���Ŀռ����ȡ��������ԭ������и�ԭ
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
