 #define _CRT_SECURE_NO_WARNINGS


//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

//你返回所有和为 0 且不重复的三元组。
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
//    //本体思路：就是利用快排函数进行排序，再利用一个固定位和双指针进行遍历数组找到等于0的数
//    *returnSize = 0;
//    if (numsSize < 3)
//    {
//        return NULL;
//    }
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * numsSize * numsSize);//开辟二维数组
//    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
//    int arrleft = 0;//左结点
//    int arrmid = 0;//指针
//    int arrright = 0;//右节点
//    int sum;
//    for (arrleft = 0; arrleft < numsSize - 2; arrleft++)//从第一个数到最后一个数，中间指针进行遍历
//    {
//        if (nums[arrleft] > 0)//因为通过了快排，如果左节点都大于0，则直接返回
//        {
//            return ans;
//        }
//        if (arrleft > 0 && nums[arrleft] == nums[arrleft - 1])//如果左节点，与上一次左节点相等，则直接跳过
//            continue;
//        arrmid = arrleft + 1;
//        arrright = numsSize - 1;
//        while (arrmid < arrright)//指针遍历数组
//        {
//            sum = nums[arrleft] + nums[arrmid] + nums[arrright];
//            if (sum == 0)
//            {
//                (*returnColumnSizes)[*returnSize] = 3;
//                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
//                ans[*returnSize][0] = nums[arrleft];//对符合数组的数进行存入
//                ans[*returnSize][1] = nums[arrmid];
//                ans[*returnSize][2] = nums[arrright];
//                (*returnSize)++;
//                while (arrmid < arrright && nums[arrmid] == nums[++arrmid]);//让中间指针进行跳过形同的数
//                while (arrmid < arrright && nums[arrright] == nums[--arrright]);//同理
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


//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 
//最接近。返回这三个数的和

//int cmp(const void* x1, const void* x2)
//{
//    return *(int*)x1 - *(int*)x2;
//}
//int threeSumClosest(int* nums, int numsSize, int target) {
//    //本题思路：利用快排，和双指针进行遍历数组，来记录最小值
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
//                ret = (abs(sum - target) < abs(ret - target) ? sum : ret);//利用绝对值函数里记录最小值
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


//给定一个二叉树：

//struct Node {
//  int val;
// Node* left;
//Node* right;
//Node* next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL
//初始状态下，所有 next 指针都被设置为 NULL 。


struct Node* find_Node(struct Node* root)//此函数是找到next子树的最左子树

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
    //本题思路：利用bfs广度优先搜索，逐一遍历
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left)//连接左子树，相隔最近的结点
    {
        root->left->next = root->right ? root->right : find_Node(root->next);
    }
    if (root->right)
    {
        root->right->next = find_Node(root->next);//右子树也是同样的连接方式
    }
    connect(root->right);//先对最左子树进行遍历，进行连接
    connect(root->left);
    return root;


}