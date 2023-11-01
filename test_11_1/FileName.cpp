 #define _CRT_SECURE_NO_WARNINGS

//给定一个长度为 n 的字符串，请编写一个函数判断该字符串是否回文。如果是回文请返回true，
// 否则返回false。
//
//字符串回文指该字符串正序与其逆序逐字符一致

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
//    bool judge(string str) {
//        // write code here
//        //本题思路：就是利用双指针进行遍历数组
//        if (str.size() == 1)
//        {
//            return true;
//        }
//        for (int i = 0, j = str.size() - 1; i < str.size() && j >= 0; i++, j--)
//        {
//            if (str[i] != str[j])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};


    //一群孩子做游戏，现在请你根据游戏得分来发糖果，要求如下：

    //1. 每个孩子不管得分多少，起码分到一个糖果。
    //    2. 任意两个相邻的孩子之间，得分较多的孩子必须拿多一些糖果。(若相同则无此限制)

    //    给定一个数组
    //    ?
    //    ?
    //    ?
    //    arr 代表得分数组，请返回最少需要多少糖果。

//#include <vector>
//    class Solution {
//    public:
//        /**
//         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//         *
//         * pick candy
//         * @param arr int整型vector the array
//         * @return int整型
//         */
//        int candy(vector<int>& arr) {
//            // write code here
//            //本题思路：分两次遍历，1从左往右遍历找升序，2，从右往左找升序
//            //再求两者最大值
//            vector<int> dp(arr.size());
//            dp[0] = 1;
//            int left = 1;
//            for (int i = 1; i < arr.size(); i++)
//            {
//                if (arr[i] > arr[i - 1])
//                {
//                    dp[i] += dp[i - 1] + 1;
//                }
//                else {
//                    dp[i] = 1;
//                }
//            }
//            int right = 1;
//            int sum = 0;
//            for (int i = arr.size() - 1; i >= 0; i--)
//            {
//                if (arr[i] > arr[i + 1] && i < arr.size() - 1)
//                {
//                    right++;;
//                }
//                else {
//                    right = 1;
//                }
//                sum += right > dp[i] ? right : dp[i];
//            }
//            return sum;
//        }
//    };


    //给出一组区间，请合并所有重叠的区间。
    //    请保证合并后的区间按区间起点升序排列。


    /**
 * struct Interval {
 *	int start;
 *	int end;
 *	Interval(int s, int e) : start(start), end(e) {}
 * };
 */
#include <vector>
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param intervals Interval类vector
         * @return Interval类vector
         */
        vector<Interval> merge(vector<Interval>& intervals) {
            // write code here
            //本题思路：先通过排序把区间进行升序排列
            //在进行首尾区间进行比较，再进行排列
            sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
                if (a.start == b.start)
                {
                    return a.end > b.end;
                }
                else {
                    return a.start < b.start;
                }
                });
            vector<Interval>ans;
            for (int i = 0; i < intervals.size(); i++)
            {
                if (ans.empty() || ans.back().end < intervals[i].start)//如果ans为空或者end小于start
                    //说明没有交集
                {
                    ans.push_back(intervals[i]);
                }
                if (ans.back().end < intervals[i].end)//如果end大于start小于end则更新end
                {
                    ans.back().end = intervals[i].end;
                }
            }
            return ans;

        }
    };