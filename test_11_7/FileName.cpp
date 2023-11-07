 #define _CRT_SECURE_NO_WARNINGS

//给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。
//
//如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。
//
//返回 words[i] 是元音字符串的数目，其中 i 在闭区间[left, right] 内。

// class Solution {
// public:
//     int vowelStrings(vector<string>& words, int left, int right) {
//         int sum=0;
//         for(int i=left;i<=right;i++)
//         {
//             int falg=0;
//             if(words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')
//             {
//                 falg=1;
//             }
//             if(falg==1&&(words[i][words[i].size()-1]=='a'||words[i][words[i].size()-1]=='e'||words[i][words[i].size()-1]=='i'||words[i][words[i].size()-1]=='o'||words[i][words[i].size()-1]=='u'))
//             {
//                 sum++;
//             }
//         }
//       return sum;
//     }
// };

//class Solution {
//public:
//    int vowelStrings(vector<string>& words, int left, int right) {
//        int sum = 0;
//        for (int i = left; i <= right; i++) {
//            string s = words[i];
//            if (s.find_first_of("aeiou") == 0 && s.find_last_of("aeiou") == s.length() - 1)
//                sum++;
//        }
//        return sum;
//    }
//};


//整数数组 nums 按升序排列，数组中的值 互不相同 。
//
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。例如，[0, 1, 2, 4, 5, 6, 7] 在下标 3 处经旋转后可能变为[4, 5, 6, 7, 0, 1, 2] 。
//
//	给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 - 1 。
//
//	你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        //本题思路：利用二分算法，找出翻转于mid的关系
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])//如果mid再没有翻转的区间里
            {
                if (target >= nums[left] && target < nums[mid])//如果target在mid和left之间
                {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {//targe在mid和right之间
                if (target <= nums[right] && target > nums[mid])//更新前后区间
                {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};