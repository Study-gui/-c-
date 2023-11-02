 #define _CRT_SECURE_NO_WARNINGS

//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
//同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//
//    int res = INT_MIN;
//    int oneSideMax(TreeNode* root) {
//        if (root == nullptr) return 0;
//        int left = max(0, oneSideMax(root->left));//这个节点的左节点的值
//        int right = max(0, oneSideMax(root->right));//这个节点的右节点的值
//        // 后序位置
//        res = max(res, left + right + root->val);//更新这个每一个节点的最大路径和
//        return max(left, right) + root->val;
//    }
//    int maxPathSum(TreeNode* root) {
//        //本题思路：就是利用后序遍历进行把路径和进行累加，
//        oneSideMax(root);
//        return res;
//    }
//};

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
//inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bulid(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend)
    {
        if (prestart > preend)//如果这个节点前面已经没有左子树或者进行遍历完成
        {
            return NULL;
        }
        int rootval = preorder[prestart];//把节点值通过前序遍历进行，存值
        int indix = 0;
        for (int i = instart; i <= inend; i++)//找到此节点的左子树的下标
        {
            if (inorder[i] == rootval)
            {
                indix = i;
                break;
            }
        }
        int leftsize = indix - instart;//算出此节点的左子树的个数
        TreeNode* root = new TreeNode(rootval);//创建此节点
        //连接左子树的节点-》前序头指针向前走一步，尾指针为前面左子树的节点个数//中序头指针不变，尾指针为左子树的个数
        root->left = bulid(preorder, prestart + 1, prestart + leftsize, inorder, instart, indix - 1);
        //连接右子树的节点-》前序头指针跳过左子树的节点，尾指针不变//中序头指针为此节点向前走相当于到此节点的右节点，尾指针不变
        root->right = bulid(preorder, prestart + leftsize + 1, preend, inorder, indix + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //本题思路：就是利用前序遍历和中序遍历的顺序不同来进行荒原二叉树
        TreeNode* root = bulid(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
};

