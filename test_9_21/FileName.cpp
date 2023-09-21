 #define _CRT_SECURE_NO_WARNINGS
//给定一个节点数为n的无序单链表，对其按升序排序。
#include <time.h>
void _mergesort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    _mergesort(a, left, mid, tmp);
    _mergesort(a, mid + 1, right, tmp);
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= right)
    {
        tmp[k++] = a[j++];
    }
    for (int i = left; i <= right; i++)
    {
        a[i] = tmp[i];
    }
}

void mergesort(int* arr, int left, int right)
{
    int* tmp = (int*)malloc(sizeof(int) * right);
    _mergesort(arr, left, right - 1, tmp);
    free(tmp);
}
struct ListNode* sortInList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int* arr = (int*)malloc(sizeof(int) * 10000);
    struct ListNode* p = head;
    int i = 0;
    while (p)
    {
        *(arr + i) = p->val;
        p = p->next;
    }
    p = head;
    mergesort(arr, 0, i);
    i = 0;
    while (p)
    {
        p->val = *(arr + (i++));
        p = p->next;
    }
    free(arr);
    return head;


}


