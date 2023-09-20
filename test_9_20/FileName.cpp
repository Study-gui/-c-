 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//
//int main()
//{
//	//插入排序的另外一种，就是前面的元素逐一跟后面的元素相比较
//	int arr[] = { 5,1,4,6,1,3 ,9,8,7};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 1; i < n; i++)
//	{
//		int tmp = arr[i-1];
//		int end = i;
//		while (end < n)
//		{
//			if (tmp < arr[end])
//			{
//				arr[i - 1] = arr[end];
//				arr[end] = tmp;
//				tmp = arr[i - 1];
//				end++;
//			}
//			else {
//				end++;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树。
//在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
//平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，
//并且左右两个子树都是一棵平衡二叉树
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
  * @param pRoot TreeNode类
  * @return bool布尔型
  */
//int maxdepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int leftDepth = maxdepth(root->left);//左子树的深度
//    int rightDepth = maxdepth(root->right);//右子树的深度
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//bool IsBalanced_Solution(struct TreeNode* pRoot) {
//    // write code here
//    //本体思路：求左子树的最大深度和右子树最大深度不超过1，并且递归下面的也不超过
//    if (pRoot == NULL)
//    {
//        return true;
//    }
//    int left = maxdepth(pRoot->left);
//    int right = maxdepth(pRoot->right);
//    return abs(left - right) < 2 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//}

//小蓝正在学习一门神奇的语言，这门语言中的单词都是由小写英文母组成，有些单词很长，
//远远超过正常英文单词的长度。小蓝学了很长时间也记不住一些单词，他准备不再完全记忆这些单词，
//而是根据单词中哪个字母出现得最多来分辨单词。现在，请你帮助小蓝，给了一个单词后，
//帮助他找到出现最多的字母和这 个字母出现的次数
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    //本题思路：巧妙运用字母转换尾ascii码值存放到数组找寻最大值
//    // 请在此输入您的代码
//    char arr;
//    int ret[26] = { 0 };
//    int max = 0;
//    int j = 0;
//    while ((scanf("%c", &arr)) != EOF)
//    {
//        ret[arr - 'a']++;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (ret[i] > ret[max])
//        {
//            max = i;
//        }
//    }
//    printf("%c\n%d", max + 'a', ret[max]);
//    return 0;
//}
//小蓝有很多数字卡片，每张卡片上都是数字0到9。
//小蓝准备用这些卡片来拼一些数，他想从1开始拼出正整数，每拼一个，就保存起来，卡片就不能用来拼其它数了。
//小藍想知道自己能以1拼到多少。
//例如，当小蓝有30张卡片，其中0到9备3张，则小蓝可以拼出
//1到10，
//但是拼11 时卡片1已经只有一张了，不够拼出11。
//现在小蓝手里有0到9的卡片各2021张，共20210张，请问小蓝可以从 1拼到多少？
//提示：建议使用计算机编程解决问题
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //本题思路：1是最先用完的,只要算出用最后1一个1的数就是结果
    // 请在此输入您的代码
    int n = 2021;
    int i = 0;
    int ret = 0;
    for (int i = 1; n > 0; i++, ret++)
    {
        int j = i;
        while (i)
        {
            if (i % 10 == 1)
                n--;
            i /= 10;
        }
        i = j;
    }
    printf("%d", ret);
    return 0;
}