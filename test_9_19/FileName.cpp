 #define _CRT_SECURE_NO_WARNINGS
//��֪���Ŷ������������Ǻϲ���һ�Ŷ��������ϲ������ǣ������ڵĽ�㣬�ͽ����ֵ������������յ�λ�þ�����һ�����Ľ��������
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
  * @param t1 TreeNode��
  * @param t2 TreeNode��
  * @return TreeNode��
  */
//#include <math.h>
//struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
//    //����˼·���������õݹ��ԭ���Ȱ�����������г�������
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

//���������Ķ�����������任ΪԴ�������ľ���
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
  * @return TreeNode��
  */
//struct TreeNode* Mirror(struct TreeNode* pRoot) {
//    //����˼·��Ҳ��ͨ���ݹ飬��㽻����������
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

//����һ�����������ڵ㣬�����ж�������ǲ��Ƕ�����������
//��������������ÿ���ڵ���������ϵ����нڵ��С�ڵ�ǰ�ڵ����������ϵ����нڵ�����ڵ�ǰ�ڵ㡣
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
    //����˼·��������������������������飬���Ƿ�����
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


