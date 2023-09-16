 #define _CRT_SECURE_NO_WARNINGS
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
  * @param root TreeNode类
  * @return int整型一维数组
  * @return int* returnSize 返回数组行数
  */
//void preBtNode(struct TreeNode* root, int* ret, int* arr)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    arr[(*ret)++] = root->val;
//    preBtNode(root->left, ret, arr);
//    preBtNode(root->right, ret, arr);
//
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    //本题考查：二叉树的前序遍历，根节点先遍历
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 101);
//    preBtNode(root, returnSize, arr);
//    return arr;
//}

//给定一个二叉树的根节点root，返回它的中序遍历结果
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
  * @param root TreeNode类
  * @return int整型一维数组
  * @return int* returnSize 返回数组行数
  */
//void PreOrderBTnode(struct TreeNode* root, int* ret, int* arr)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    PreOrderBTnode(root->left, ret, arr);
//    if (root->val != '#')
//    {
//        arr[(*ret)++] = root->val;
//    }
//    PreOrderBTnode(root->right, ret, arr);
//}
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    //本体思路：就是中序遍历
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 1001);
//    PreOrderBTnode(root, returnSize, arr);
//    return arr;
//}

//给定一个二叉树，返回他的后序遍历的序列
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
  * @param root TreeNode类
  * @return int整型一维数组
  * @return int* returnSize 返回数组行数
  */
//void PreOrderBTnode(struct TreeNode* root, int* ret, int* arr)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    PreOrderBTnode(root->left, ret, arr);
//    PreOrderBTnode(root->right, ret, arr);
//    if (root->val != '#')
//    {
//        arr[(*ret)++] = root->val;
//    }
//}
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    // write code here
//       //本体思路：就是后序遍历
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 1001);
//    PreOrderBTnode(root, returnSize, arr);
//    return arr;
//}

//给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）
//例如：
//给定的二叉树是{ 3,9,20,#,#,15,7 },
//该二叉树层序遍历的结果是
//[
	/*[3],
	[9, 20],
	[15, 7]*/

//]
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
  * @param root TreeNode类
  * @return int整型二维数组
  * @return int* returnSize 返回数组行数
  * @return int** returnColumnSizes 返回数组列数
  */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // write code here
    //本体思路：难点在于把每层的结点个数进行返回，通过二位数组进行返回
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* queue[15001];//存放树结点的队列
    int** ret = (int**)malloc(sizeof(int) * 10000);//开辟数组有多少层
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);//开辟数组每层，有多少列
    int head = 0;//队列的头节点
    int cur = 0;//队列的尾节点
    queue[cur++] = root;//根节点入队
    while (head != cur)
    {
        int count = cur;
        int k = 0;
        ret[*returnSize] = (int*)malloc(sizeof(int) * (count - head));//开辟当前层的元素个数空间
        while (head < count)//此循环是，对每层结点个数进行循环
        {
            struct TreeNode* p = queue[head];//对树的节点进行出队
            ret[*returnSize][k++] = p->val;//把树的节点入数组
            if (p->left != NULL)//对结点的左子树进行判定，入队列
            {
                queue[cur++] = p->left;
            }
            if (p->right != NULL)//对结点的右子树进行判定，入队列
            {
                queue[cur++] = p->right;
            }
            head++;//队列的每层头指针向后走
        }
        (*returnColumnSizes)[*returnSize] = k;//把每层结点的个数进行赋值
        (*returnSize)++;//层数加加
    }
    return ret;


}