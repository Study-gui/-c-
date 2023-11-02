 #define _CRT_SECURE_NO_WARNINGS

//�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�
//ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ�

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
//        int left = max(0, oneSideMax(root->left));//����ڵ����ڵ��ֵ
//        int right = max(0, oneSideMax(root->right));//����ڵ���ҽڵ��ֵ
//        // ����λ��
//        res = max(res, left + right + root->val);//�������ÿһ���ڵ�����·����
//        return max(left, right) + root->val;
//    }
//    int maxPathSum(TreeNode* root) {
//        //����˼·���������ú���������а�·���ͽ����ۼӣ�
//        oneSideMax(root);
//        return res;
//    }
//};

//���������������� preorder �� inorder ������ preorder �Ƕ����������������
//inorder ��ͬһ����������������빹�����������������ڵ㡣


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
        if (prestart > preend)//�������ڵ�ǰ���Ѿ�û�����������߽��б������
        {
            return NULL;
        }
        int rootval = preorder[prestart];//�ѽڵ�ֵͨ��ǰ��������У���ֵ
        int indix = 0;
        for (int i = instart; i <= inend; i++)//�ҵ��˽ڵ�����������±�
        {
            if (inorder[i] == rootval)
            {
                indix = i;
                break;
            }
        }
        int leftsize = indix - instart;//����˽ڵ���������ĸ���
        TreeNode* root = new TreeNode(rootval);//�����˽ڵ�
        //�����������Ľڵ�-��ǰ��ͷָ����ǰ��һ����βָ��Ϊǰ���������Ľڵ����//����ͷָ�벻�䣬βָ��Ϊ�������ĸ���
        root->left = bulid(preorder, prestart + 1, prestart + leftsize, inorder, instart, indix - 1);
        //�����������Ľڵ�-��ǰ��ͷָ�������������Ľڵ㣬βָ�벻��//����ͷָ��Ϊ�˽ڵ���ǰ���൱�ڵ��˽ڵ���ҽڵ㣬βָ�벻��
        root->right = bulid(preorder, prestart + leftsize + 1, preend, inorder, indix + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //����˼·����������ǰ����������������˳��ͬ�����л�ԭ������
        TreeNode* root = bulid(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
};

