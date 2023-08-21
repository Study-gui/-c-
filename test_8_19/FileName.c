 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历
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
//{//利用前序遍历
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
//    int size = Treesize(root);//树的节点总数
//    int* a = (int*)malloc(size * sizeof(int));//通过malloc的空间，创建一个数组
//    int i = 0;
//    _preoeder(root, a, &i);//把树的节点放到数组中
//    *returnSize = size;//输出函数的个数
//    return a;
//}

//给定一个二叉树 root ，返回其最大深度。
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
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
//    int leftDepth = maxDepth(root->left);//左子树的深度
//    int rightDepth = maxDepth(root->right);//右子树的深度
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//返回两边最大子树的深度
//}

//给定一个二叉树，判断它是否是高度平衡的二叉树。

//本题中，一棵高度平衡二叉树定义为：

//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
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
//    int leftDepth = maxDepth(root->left);//左子树的深度
//    int rightDepth = maxDepth(root->right);//右子树的深度
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//返回两边最大子树的深度
//}
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//    int leftDepth = maxDepth(root->left);//左子树的深度
//    int rightDepth = maxDepth(root->right);//右子树的深度
//    return abs(leftDepth - rightDepth) < 2 &&//深度高度差不能超过1
//        isBalanced(root->left) && isBalanced(root->right);//向下递归左子树和右子树的深度进行比较

//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，
//再对二叉树进行中序遍历，输出遍历结果。
#include <stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TNode;//创建一个二叉树结构体
//构建二叉树函数
TNode* creatTree(char str[], int* pi)
{
    if (str[*pi] == '#')//根据题意，为空格
    {
        (*pi)++;
        return NULL;
    }
    TNode* root = (TNode*)malloc(sizeof(TNode));//创建malloc变量能够返回
    if (root == NULL)
    {
        printf("creatTree");
    }
    root->val = str[*pi];//存入结点值
    (*pi)++;
    root->left = creatTree(str, pi);//通过分治算法，递归左子树结点
    root->right = creatTree(str, pi);//通过分治算法，递归右子树节点
    return root;//返回根节点
}
void inTree(TNode* root)//中序遍历，
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
    char str[100];//创建输入数组
    scanf("%s", str);
    int i = 0;
    TNode* root = creatTree(str, &i);//构建二叉树
    inTree(root);//通过中序遍历，返回遍历结果
    return 0;
}