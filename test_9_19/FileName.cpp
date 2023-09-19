 #define _CRT_SECURE_NO_WARNINGS
//已知两颗二叉树，将它们合并成一颗二叉树。合并规则是：都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替
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
  * @param t1 TreeNode类
  * @param t2 TreeNode类
  * @return TreeNode类
  */
//#include <math.h>
//struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
//    //本体思路：就是利用递归的原理，先把特殊的条件列出，就行
//    // write code here
//    if (t1 == NULL && t2 != NULL)
//    {
//        return t2;
//    }
//    if (t1 != NULL && t2 == NULL)
//    {
//        return t1;
//    }
//    if (t1 == NULL && t2 == NULL)
//    {
//        return t1;
//    }
//    t1->val += t2->val;
//    t1->left = mergeTrees(t1->left, t2->left);
//    t1->right = mergeTrees(t1->right, t2->right);
//    return t1;
//}

//操作给定的二叉树，将其变换为源二叉树的镜像。
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
  * @return TreeNode类
  */
//struct TreeNode* Mirror(struct TreeNode* pRoot) {
//    //本体思路：也是通过递归，逐层交换左右子树
//    // write code here
//    if (pRoot == NULL)
//    {
//        return NULL;
//    }
//    // if(pRoot->left==NULL&&pRoot->right!=NULL)
//    // {
//    //    pRoot->left=pRoot->right;
//    //     pRoot->right=NULL;
//    // }
//    // if(pRoot->left!=NULL&&pRoot->right==NULL)
//    // {
//    //     pRoot->right=pRoot->left;
//    //     pRoot->left=NULL;
//    // }
//    struct TreeNode* ret = pRoot->left;
//    pRoot->left = pRoot->right;
//    pRoot->right = ret;
//    pRoot->left = Mirror(pRoot->left);
//    pRoot->right = Mirror(pRoot->right);
//    return pRoot;
//}

//给定一个二叉树根节点，请你判断这棵树是不是二叉搜索树。
//二叉搜索树满足每个节点的左子树上的所有节点均小于当前节点且右子树上的所有节点均大于当前节点。
#include <stdbool.h>
void OrderBT(struct TreeNode* root, int* arr, int* i)
{
    if (root == NULL)
    {
        return;
    }
    OrderBT(root->left, arr, i);
    arr[(*i)++] = root->val;
    OrderBT(root->right, arr, i);
}
bool isValidBST(struct TreeNode* root) {
    //本体思路：就是中序遍历二叉树放入数组，看是否升序
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int arr[10001];
    int i = 0;
    OrderBT(root, &arr, &i);
    for (int j = 0; j < i - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            return false;
        }
    }
    return true;
}


