 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ����
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int Treesize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : Treesize(root->left) + Treesize(root->right) + 1;
//}
//void _preoeder(struct TreeNode* root, int* a, int* pi)
//{//����ǰ�����
//    if (root == NULL)
//    {
//        return;
//    }
//    a[*pi] = root->val;
//    ++(*pi);
//    _preoeder(root->left, a, pi);
//    _preoeder(root->right, a, pi);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    int size = Treesize(root);//���Ľڵ�����
//    int* a = (int*)malloc(size * sizeof(int));//ͨ��malloc�Ŀռ䣬����һ������
//    int i = 0;
//    _preoeder(root, a, &i);//�����Ľڵ�ŵ�������
//    *returnSize = size;//��������ĸ���
//    return a;
//}

//����һ�������� root �������������ȡ�
//�������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int leftDepth = maxDepth(root->left);//�����������
//    int rightDepth = maxDepth(root->right);//�����������
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//��������������������
//}

//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

//�����У�һ�ø߶�ƽ�����������Ϊ��

//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int leftDepth = maxDepth(root->left);//�����������
//    int rightDepth = maxDepth(root->right);//�����������
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//��������������������
//}
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//    int leftDepth = maxDepth(root->left);//�����������
//    int rightDepth = maxDepth(root->right);//�����������
//    return abs(leftDepth - rightDepth) < 2 &&//��ȸ߶Ȳ�ܳ���1
//        isBalanced(root->left) && isBalanced(root->right);//���µݹ�������������������Ƚ��бȽ�

//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ�
//�ٶԶ������������������������������
#include <stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TNode;//����һ���������ṹ��
//��������������
TNode* creatTree(char str[], int* pi)
{
    if (str[*pi] == '#')//�������⣬Ϊ�ո�
    {
        (*pi)++;
        return NULL;
    }
    TNode* root = (TNode*)malloc(sizeof(TNode));//����malloc�����ܹ�����
    if (root == NULL)
    {
        printf("creatTree");
    }
    root->val = str[*pi];//������ֵ
    (*pi)++;
    root->left = creatTree(str, pi);//ͨ�������㷨���ݹ����������
    root->right = creatTree(str, pi);//ͨ�������㷨���ݹ��������ڵ�
    return root;//���ظ��ڵ�
}
void inTree(TNode* root)//���������
{
    if (root == NULL)
    {
        return;
    }
    inTree(root->left);
    printf("%c ", root->val);
    inTree(root->right);
}

int main() {
    char str[100];//������������
    scanf("%s", str);
    int i = 0;
    TNode* root = creatTree(str, &i);//����������
    inTree(root);//ͨ��������������ر������
    return 0;
}