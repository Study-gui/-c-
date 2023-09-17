 #define _CRT_SECURE_NO_WARNINGS
//������������������ȣ�
//�����ָ���ĸ��ڵ㵽��һҶ�ӽڵ�·���Ͻڵ��������
//������������Ҷ�ӽڵ����ȵ����ֵ
///**
// * struct TreeNode {
// *	int val;
// *	struct TreeNode *left;
// *	struct TreeNode *right;
// * };
// */
// /**
//  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//  *
//  *
//  * @param root TreeNode��
//  * @return int����
//  */
//
//int maxDepth(struct TreeNode* root) {
//    //���õݹ�����������������ݹ���������ݹ�
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//    return left > right ? left + 1 : right + 1;
//
//}
//����һ��������root��һ��ֵ sum ���ж��Ƿ��дӸ��ڵ㵽Ҷ�ӽڵ�Ľڵ�ֵ֮�͵��� sum ��·����
//1.����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ�ӽ���������Ľ��
//2.Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
//3.·��ֻ�ܴӸ��ڵ㵽�ӽڵ㣬���ܴ��ӽڵ㵽���ڵ�
//4.�ܽڵ���ĿΪn
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
  * @param root TreeNode��
  * @param sum int����
  * @return bool������
  */
//bool hasPathSum(struct TreeNode* root, int sum) {
//    //����˼·������һ�����н��м�¼���ڵ��·��֮�͡���sum���бȽ�
//    if (root == NULL)
//    {
//        return false;
//    }
//    struct TreeNode* queue[10001];//����һ������
//    struct TreeNode* ret;
//    int head = 0;//ͷָ��
//    int cur = 0;//βָ��
//    queue[cur++] = root;//��������
//    while (head != cur)//�������б���
//    {
//        struct TreeNode* ret = queue[head];//ȡ�����
//        if (ret->left == NULL && ret->right == NULL && ret->val == sum)//������бȽ�
//        {
//            return true;
//        }
//        if (ret->left != NULL)//������ڵ�
//        {
//            queue[cur++] = ret->left;
//            queue[cur - 1]->val = queue[cur - 1]->val + ret->val;//�Խ���ֵ�����ۼӣ��ؼ�һ��
//        }
//        if (ret->right != NULL)//�����ҽڵ�
//        {
//            queue[cur++] = ret->right;
//            queue[cur - 1]->val = queue[cur - 1]->val + ret->val;
//        }
//        head++;//ͷָ�������
//    }
//    return false;
//}
////����һ���������� 
//i ��̨����������Ҫ֧���ķ��ã��±��0��ʼ��һ����֧���˷��ã�����ѡ��������һ����������̨�ס�
//
//�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�
//
//������㲢���شﵽ¥�ݶ�������ͻ���
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param cost int����һά����
 * @param costLen int cost���鳤��
 * @return int����
 */
int min(int x, int y)
{
    return x > y ? y : x;
}
int minCostClimbingStairs(int* cost, int costLen) {
    //����˼·����С���Ѿ���i-1���ѵ�i-1��¥�ݣ����߻���i-2�۸�i-2��¥�ݣ���ȡ��Сֵ���ټ���֮ǰ���ѵļ۸񣬾��ǵ���¥������С����
    if (costLen == 1)
    {
        return cost[0];
    }
    int dp[costLen + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= costLen; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);//�ؼ�
    }
    return dp[costLen];
}