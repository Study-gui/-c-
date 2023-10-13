 #define _CRT_SECURE_NO_WARNINGS


//����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
//ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����

//�㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* x1, const void* x2)
{
    return (*(int*)x1) - (*(int*)x2);
}
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//    //����˼·���������ÿ��ź�����������������һ���̶�λ��˫ָ����б��������ҵ�����0����
//    *returnSize = 0;
//    if (numsSize < 3)
//    {
//        return NULL;
//    }
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * numsSize * numsSize);//���ٶ�ά����
//    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
//    int arrleft = 0;//����
//    int arrmid = 0;//ָ��
//    int arrright = 0;//�ҽڵ�
//    int sum;
//    for (arrleft = 0; arrleft < numsSize - 2; arrleft++)//�ӵ�һ���������һ�������м�ָ����б���
//    {
//        if (nums[arrleft] > 0)//��Ϊͨ���˿��ţ������ڵ㶼����0����ֱ�ӷ���
//        {
//            return ans;
//        }
//        if (arrleft > 0 && nums[arrleft] == nums[arrleft - 1])//�����ڵ㣬����һ����ڵ���ȣ���ֱ������
//            continue;
//        arrmid = arrleft + 1;
//        arrright = numsSize - 1;
//        while (arrmid < arrright)//ָ���������
//        {
//            sum = nums[arrleft] + nums[arrmid] + nums[arrright];
//            if (sum == 0)
//            {
//                (*returnColumnSizes)[*returnSize] = 3;
//                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
//                ans[*returnSize][0] = nums[arrleft];//�Է�������������д���
//                ans[*returnSize][1] = nums[arrmid];
//                ans[*returnSize][2] = nums[arrright];
//                (*returnSize)++;
//                while (arrmid < arrright && nums[arrmid] == nums[++arrmid]);//���м�ָ�����������ͬ����
//                while (arrmid < arrright && nums[arrright] == nums[--arrright]);//ͬ��
//            }
//            else if (sum > 0)
//            {
//                arrright--;
//            }
//            else {
//                arrmid++;
//            }
//        }
//    }
//    return ans;
//}


//����һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������ʹ���ǵĺ��� target 
//��ӽ����������������ĺ�

//int cmp(const void* x1, const void* x2)
//{
//    return *(int*)x1 - *(int*)x2;
//}
//int threeSumClosest(int* nums, int numsSize, int target) {
//    //����˼·�����ÿ��ţ���˫ָ����б������飬����¼��Сֵ
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ret = nums[0] + nums[1] + nums[2];
//    int left = 0;
//    int mid = 0;
//    int right = 0;
//    int sum;
//    for (left = 0; left < numsSize - 2; left++)
//    {
//        mid = left + 1;
//        right = numsSize - 1;
//        while (mid < right)
//        {
//            sum = nums[left] + nums[mid] + nums[right];
//            if (sum == target)
//            {
//                return sum;
//            }
//            if (sum < target)
//            {
//                ret = (abs(sum - target) < abs(ret - target) ? sum : ret);//���þ���ֵ�������¼��Сֵ
//                mid++;
//            }
//            else {
//                ret = (abs(sum - target) < abs(ret - target) ? sum : ret);
//                right--;
//            }
//        }
//    }
//    return ret;
//}


//����һ����������

//struct Node {
//  int val;
// Node* left;
//Node* right;
//Node* next;
//}
//�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL
//��ʼ״̬�£����� next ָ�붼������Ϊ NULL ��


struct Node* find_Node(struct Node* root)//�˺������ҵ�next��������������

{
    while (root)
    {
        if (root->left)
        {
            return root->left;
        }
        if (root->right)
        {
            return root->right;
        }
        root = root->next;
    }
    return NULL;
}
struct Node* connect(struct Node* root) {
    //����˼·������bfs���������������һ����
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left)//�������������������Ľ��
    {
        root->left->next = root->right ? root->right : find_Node(root->next);
    }
    if (root->right)
    {
        root->right->next = find_Node(root->next);//������Ҳ��ͬ�������ӷ�ʽ
    }
    connect(root->right);//�ȶ������������б�������������
    connect(root->left);
    return root;


}