 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    long n;
//    scanf("%ld", &n);
//    long arr[7];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%ld", &arr[i]);
//    }
//    long ret = 0;
//    long brr[7];
//    while (ret < n)
//    {
//        int i = 0;
//        for (int j = ret; i < (2 ^ i) && i < n; i++)
//        {
//            brr[i] += arr[j];
//        }
//        ret = 2 ^ i;
//        i++;
//    }
//    long max = brr[0];
//    long k = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (max < brr[i])
//        {
//            max = brr[i];
//            k = i;
//        }
//    }
//    printf("%ld", k + 1);
//    return 0;
//
//}


//#include<string.h>
//int main()
//{
//	char arr[50];
//	scanf("%s", &arr);
//	int n = strlen(arr);
//	//printf("%d", n);
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] -= 32;
//		printf("%c", arr[i]);
//	}
//		
//
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//int main(int argc, char* argv[])
//{
//	// ���ڴ��������Ĵ���
//	int t;
//	scanf("%d", &t);
//	char arr[50];
//	while (t--)
//	{
//		scanf("%s", &arr);
//		int n = strlen(arr);
//		for (int i = 0; i < n; i++)
//		{
//			if ((arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') && (arr[i] >= 'a' && arr[i] <= 'z'))
//			{
//				arr[i] -= 32;
//			}
//			else {
//				if (arr[i] != 'A' && arr[i] != 'E' && arr[i] != 'I' && arr[i] != 'O' && arr[i] != 'U')
//				{
//					arr[i] += 32;
//				}
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			printf("%c", arr[i]);
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    // ���ڴ��������Ĵ���
//    int arr[4] = { 0 };
//    for (int i = 0; i < 4; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 0; i < 4 - 1; i++)
//    {
//        for (int j = 0; j < 4 - i - 1; j++)
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j] = tmp;
//            }
//    }
//    int k = arr[2] * arr[3];
//    printf("%d", k);
//    return 0;
//}
//�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ��
//�洢 һλ ���֡�
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int len(struct ListNode* l1)
{
    int x = 0;
    while (l1)
    {
        l1 = l1->next;
        x++;
    }
    return x;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //    if(l1->val==0)
    //    {
    //        return l2;
    //    }
    //    if(l2->val==0)
    //    {
    //        return l1;
    //    }
    //����˼·������������ӣ�����Ҫע���λ�����һλ�Ľ�λ
    int len1 = len(l1);//�ж���������˭����˭�����������
    int len2 = len(l2);
    struct ListNode* phead1, * phead2;
    phead1 = l1, phead2 = l2;
    if (len1 < len2)
    {
        phead1 = l2;
        phead2 = l1;
    }
    struct ListNode* head = phead1;//���Ʒ���ͷ�ڵ�ͷ�ڵ�
    int j = 0;
    int ret = 0;
    struct ListNode* list;//�ؼ����ڣ��ҵ�������֮ǰ��һ���ڵ�
    while (phead2)//�Զ�������б���
    {
        phead1->val = phead1->val + j;
        ret = phead1->val + phead2->val;
        j = ret / 10;
        phead1->val = ret % 10;
        list = phead1;
        phead1 = phead1->next;
        phead2 = phead2->next;
    }
    while (phead1)//�жϳ������Ƿ�Ϊ�գ������б���
    {
        phead1->val = phead1->val + j;
        ret = phead1->val;
        j = ret / 10;
        phead1->val = ret % 10;
        list = phead1;
        phead1 = phead1->next;
    }
    if (j == 1)//�ж����һλ�Ƿ��н�λ
    {//�еĻ���Ҫ������һ������������
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = 1;
        cur->next = NULL;
        list->next = cur;
    }
    return head;


}