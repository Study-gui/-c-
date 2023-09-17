 #define _CRT_SECURE_NO_WARNINGS
//求给定二叉树的最大深度，
//深度是指树的根节点到任一叶子节点路径上节点的数量。
//最大深度是所有叶子节点的深度的最大值
///**
// * struct TreeNode {
// *	int val;
// *	struct TreeNode *left;
// *	struct TreeNode *right;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param root TreeNode类
//  * @return int整型
//  */
//
//int maxDepth(struct TreeNode* root) {
//    //利用递归的做法进行左子树递归和右子树递归
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//    return left > right ? left + 1 : right + 1;
//
//}
//给定一个二叉树root和一个值 sum ，判断是否有从根节点到叶子节点的节点值之和等于 sum 的路径。
//1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
//2.叶子节点是指没有子节点的节点
//3.路径只能从父节点到子节点，不能从子节点到父节点
//4.总节点数目为n
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
  * @param sum int整型
  * @return bool布尔型
  */
//bool hasPathSum(struct TreeNode* root, int sum) {
//    //本体思路：创建一个队列进行记录树节点的路径之和。跟sum进行比较
//    if (root == NULL)
//    {
//        return false;
//    }
//    struct TreeNode* queue[10001];//创建一个队列
//    struct TreeNode* ret;
//    int head = 0;//头指针
//    int cur = 0;//尾指针
//    queue[cur++] = root;//存入跟结点
//    while (head != cur)//对数进行遍历
//    {
//        struct TreeNode* ret = queue[head];//取出结点
//        if (ret->left == NULL && ret->right == NULL && ret->val == sum)//题意进行比较
//        {
//            return true;
//        }
//        if (ret->left != NULL)//存入左节点
//        {
//            queue[cur++] = ret->left;
//            queue[cur - 1]->val = queue[cur - 1]->val + ret->val;//对结点的值进行累加，关键一步
//        }
//        if (ret->right != NULL)//存入右节点
//        {
//            queue[cur++] = ret->right;
//            queue[cur - 1]->val = queue[cur - 1]->val + ret->val;
//        }
//        head++;//头指针向后走
//    }
//    return false;
//}
////给定一个整数数组 
//i 个台阶向上爬需要支付的费用，下标从0开始。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//
//请你计算并返回达到楼梯顶部的最低花费
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param cost int整型一维数组
 * @param costLen int cost数组长度
 * @return int整型
 */
int min(int x, int y)
{
    return x > y ? y : x;
}
int minCostClimbingStairs(int* cost, int costLen) {
    //本题思路：最小花费就是i-1花费到i-1个楼梯，或者花费i-2价格到i-2的楼梯，中取最小值，再加上之前花费的价格，就是到达楼顶的最小花费
    if (costLen == 1)
    {
        return cost[0];
    }
    int dp[costLen + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= costLen; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);//关键
    }
    return dp[costLen];
}