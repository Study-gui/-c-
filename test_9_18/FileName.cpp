 #define _CRT_SECURE_NO_WARNINGS
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。如下图所示
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

 /**
  *
  * @param pRootOfTree TreeNode类
  * @return TreeNode类
  */
//void OrderBTNode(struct TreeNode* root, struct TreeNode* queue[1001], int* cur)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    OrderBTNode(root->left, queue, cur);//中序遍历的函数
//    queue[(*cur)++] = root;//结点入队列
//    OrderBTNode(root->right, queue, cur);
//}
//struct TreeNode* Convert(struct TreeNode* pRootOfTree) {
//    //本体思路：就是利用二叉树的中序遍历，然后创建一个队列进行存储结点，然后取出把节点改为双向链表结点连接方式
//    //本题关键就是搜索二叉树就是排序二叉树，通过中序遍历就是能排序好
//    if (pRootOfTree == NULL)
//    {
//        return NULL;
//    }
//    struct TreeNode* queue[1001];//创建队列
//    int head = 0;//头指针
//    int cur = 0;//尾指针
//    OrderBTNode(pRootOfTree, queue, &cur);
//    queue[cur] = NULL;//因为最后一个节点也要与NULL连接,所以多创造一个结点，进行连接
//
//    struct TreeNode* pre = NULL;//连接双向链表头节点
//    struct TreeNode* tail = queue[head++];//取出最小值结点
//    struct TreeNode* next = queue[head];//取出排序好的下一个节点
//    struct TreeNode* ret = tail;//返回头节点
//    while (head <= cur)//对队列进行遍历
//    {
//        tail->left = pre;//进行连接
//        tail->right = next;
//        pre = tail;
//        tail = next;
//        head++;
//        next = queue[head];
//    }
//
//    return ret;
//}
//给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param pRoot TreeNode类
  * @return bool布尔型
  */
#include <stdbool.h>
bool _bool(struct TreeNode* lchild, struct TreeNode* rchild)
{
    if (lchild == NULL)//通过特殊情况，终止递归
    {
        if (rchild == NULL)
        {
            return true;
        }
        else {
            return false;
        }
    } if (rchild == NULL)
    {
        if (lchild == NULL)
        {
            return true;
        }
        else {
            return false;
        }
    }
    if (lchild->val != rchild->val)
    {
        return false;
    }
    else {
        if (_bool(lchild->left, rchild->right) && _bool(lchild->right, rchild->left))
            return true;
        else {
            return false;
        }
    }
}
bool isSymmetrical(struct TreeNode* pRoot) {
    //思路：二叉树问题大部分应该是递归解决，考虑二叉树的对称，自上而下，从根节点除法，左右孩子是相同的。然后再从左右孩子这两个节点除法，左孩子的左孩子节点等于右孩子的右孩子节点，左孩子的右孩子节点等于右孩子的左孩子节
    if (pRoot == NULL)
    {
        return true;
    }
    return _bool(pRoot->left, pRoot->right);
}