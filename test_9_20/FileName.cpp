 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//
//int main()
//{
//	//�������������һ�֣�����ǰ���Ԫ����һ�������Ԫ����Ƚ�
//	int arr[] = { 5,1,4,6,1,3 ,9,8,7};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 1; i < n; i++)
//	{
//		int tmp = arr[i-1];
//		int end = i;
//		while (end < n)
//		{
//			if (tmp < arr[end])
//			{
//				arr[i - 1] = arr[end];
//				arr[end] = tmp;
//				tmp = arr[i - 1];
//				end++;
//			}
//			else {
//				end++;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//����һ�ýڵ���Ϊ n ���������жϸö������Ƿ���ƽ���������
//���������ֻ��Ҫ������ƽ���ԣ�����Ҫ�������ǲ������������
//ƽ���������Balanced Binary Tree���������������ʣ�����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1��
//��������������������һ��ƽ�������
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param pRoot TreeNode��
  * @return bool������
  */
//int maxdepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int leftDepth = maxdepth(root->left);//�����������
//    int rightDepth = maxdepth(root->right);//�����������
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//bool IsBalanced_Solution(struct TreeNode* pRoot) {
//    // write code here
//    //����˼·�����������������Ⱥ������������Ȳ�����1�����ҵݹ������Ҳ������
//    if (pRoot == NULL)
//    {
//        return true;
//    }
//    int left = maxdepth(pRoot->left);
//    int right = maxdepth(pRoot->right);
//    return abs(left - right) < 2 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//}

//С������ѧϰһ����������ԣ����������еĵ��ʶ�����СдӢ��ĸ��ɣ���Щ���ʺܳ���
//ԶԶ��������Ӣ�ĵ��ʵĳ��ȡ�С��ѧ�˺ܳ�ʱ��Ҳ�ǲ�סһЩ���ʣ���׼��������ȫ������Щ���ʣ�
//���Ǹ��ݵ������ĸ���ĸ���ֵ�������ֱ浥�ʡ����ڣ��������С��������һ�����ʺ�
//�������ҵ�����������ĸ���� ����ĸ���ֵĴ���
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    //����˼·������������ĸת��βascii��ֵ��ŵ�������Ѱ���ֵ
//    // ���ڴ��������Ĵ���
//    char arr;
//    int ret[26] = { 0 };
//    int max = 0;
//    int j = 0;
//    while ((scanf("%c", &arr)) != EOF)
//    {
//        ret[arr - 'a']++;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (ret[i] > ret[max])
//        {
//            max = i;
//        }
//    }
//    printf("%c\n%d", max + 'a', ret[max]);
//    return 0;
//}
//С���кܶ����ֿ�Ƭ��ÿ�ſ�Ƭ�϶�������0��9��
//С��׼������Щ��Ƭ��ƴһЩ���������1��ʼƴ����������ÿƴһ�����ͱ�����������Ƭ�Ͳ�������ƴ�������ˡ�
//С�{��֪���Լ�����1ƴ�����١�
//���磬��С����30�ſ�Ƭ������0��9��3�ţ���С������ƴ��
//1��10��
//����ƴ11 ʱ��Ƭ1�Ѿ�ֻ��һ���ˣ�����ƴ��11��
//����С��������0��9�Ŀ�Ƭ��2021�ţ���20210�ţ�����С�����Դ� 1ƴ�����٣�
//��ʾ������ʹ�ü������̽������
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //����˼·��1�����������,ֻҪ��������1һ��1�������ǽ��
    // ���ڴ��������Ĵ���
    int n = 2021;
    int i = 0;
    int ret = 0;
    for (int i = 1; n > 0; i++, ret++)
    {
        int j = i;
        while (i)
        {
            if (i % 10 == 1)
                n--;
            i /= 10;
        }
        i = j;
    }
    printf("%d", ret);
    return 0;
}