 #define _CRT_SECURE_NO_WARNINGS
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
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
  * @return int����һά����
  * @return int* returnSize ������������
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
//    //���⿼�飺��������ǰ����������ڵ��ȱ���
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 101);
//    preBtNode(root, returnSize, arr);
//    return arr;
//}

//����һ���������ĸ��ڵ�root��������������������
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
  * @return int����һά����
  * @return int* returnSize ������������
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
//    //����˼·�������������
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 1001);
//    PreOrderBTnode(root, returnSize, arr);
//    return arr;
//}

//����һ�����������������ĺ������������
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
  * @return int����һά����
  * @return int* returnSize ������������
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
//       //����˼·�����Ǻ������
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    int* arr = (int*)malloc(sizeof(int) * 1001);
//    PreOrderBTnode(root, returnSize, arr);
//    return arr;
//}

//����һ�������������ظö�������������Ľ�����������ң�һ��һ��ر�����
//���磺
//�����Ķ�������{ 3,9,20,#,#,15,7 },
//�ö�������������Ľ����
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
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param root TreeNode��
  * @return int���Ͷ�ά����
  * @return int* returnSize ������������
  * @return int** returnColumnSizes ������������
  */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // write code here
    //����˼·���ѵ����ڰ�ÿ��Ľ��������з��أ�ͨ����λ������з���
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* queue[15001];//��������Ķ���
    int** ret = (int**)malloc(sizeof(int) * 10000);//���������ж��ٲ�
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);//��������ÿ�㣬�ж�����
    int head = 0;//���е�ͷ�ڵ�
    int cur = 0;//���е�β�ڵ�
    queue[cur++] = root;//���ڵ����
    while (head != cur)
    {
        int count = cur;
        int k = 0;
        ret[*returnSize] = (int*)malloc(sizeof(int) * (count - head));//���ٵ�ǰ���Ԫ�ظ����ռ�
        while (head < count)//��ѭ���ǣ���ÿ�����������ѭ��
        {
            struct TreeNode* p = queue[head];//�����Ľڵ���г���
            ret[*returnSize][k++] = p->val;//�����Ľڵ�������
            if (p->left != NULL)//�Խ��������������ж��������
            {
                queue[cur++] = p->left;
            }
            if (p->right != NULL)//�Խ��������������ж��������
            {
                queue[cur++] = p->right;
            }
            head++;//���е�ÿ��ͷָ�������
        }
        (*returnColumnSizes)[*returnSize] = k;//��ÿ����ĸ������и�ֵ
        (*returnSize)++;//�����Ӽ�
    }
    return ret;


}