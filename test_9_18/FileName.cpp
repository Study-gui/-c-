 #define _CRT_SECURE_NO_WARNINGS
//����һ�ö��������������ö���������ת����һ�������˫����������ͼ��ʾ
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

 /**
  *
  * @param pRootOfTree TreeNode��
  * @return TreeNode��
  */
//void OrderBTNode(struct TreeNode* root, struct TreeNode* queue[1001], int* cur)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    OrderBTNode(root->left, queue, cur);//��������ĺ���
//    queue[(*cur)++] = root;//��������
//    OrderBTNode(root->right, queue, cur);
//}
//struct TreeNode* Convert(struct TreeNode* pRootOfTree) {
//    //����˼·���������ö����������������Ȼ�󴴽�һ�����н��д洢��㣬Ȼ��ȡ���ѽڵ��Ϊ˫�����������ӷ�ʽ
//    //����ؼ������������������������������ͨ��������������������
//    if (pRootOfTree == NULL)
//    {
//        return NULL;
//    }
//    struct TreeNode* queue[1001];//��������
//    int head = 0;//ͷָ��
//    int cur = 0;//βָ��
//    OrderBTNode(pRootOfTree, queue, &cur);
//    queue[cur] = NULL;//��Ϊ���һ���ڵ�ҲҪ��NULL����,���Զഴ��һ����㣬��������
//
//    struct TreeNode* pre = NULL;//����˫������ͷ�ڵ�
//    struct TreeNode* tail = queue[head++];//ȡ����Сֵ���
//    struct TreeNode* next = queue[head];//ȡ������õ���һ���ڵ�
//    struct TreeNode* ret = tail;//����ͷ�ڵ�
//    while (head <= cur)//�Զ��н��б���
//    {
//        tail->left = pre;//��������
//        tail->right = next;
//        pre = tail;
//        tail = next;
//        head++;
//        next = queue[head];
//    }
//
//    return ret;
//}
//����һ�ö��������ж����Ƿ�������ľ��񣨼����Ƿ�Գƣ�
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
#include <stdbool.h>
bool _bool(struct TreeNode* lchild, struct TreeNode* rchild)
{
    if (lchild == NULL)//ͨ�������������ֹ�ݹ�
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
    //˼·������������󲿷�Ӧ���ǵݹ��������Ƕ������ĶԳƣ����϶��£��Ӹ��ڵ���������Һ�������ͬ�ġ�Ȼ���ٴ����Һ����������ڵ���������ӵ����ӽڵ�����Һ��ӵ��Һ��ӽڵ㣬���ӵ��Һ��ӽڵ�����Һ��ӵ����ӽ�
    if (pRoot == NULL)
    {
        return true;
    }
    return _bool(pRoot->left, pRoot->right);
}