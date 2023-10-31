 #define _CRT_SECURE_NO_WARNINGS

//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

//class Solution {
//public:
//    string tmp;
//    vector<string> arr = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string>ans;
//    void dfs(int pos, string digits)
//    {
//        if (digits.size() == pos)//有几个按键表示有几个字符进行组合
//        {
//            ans.push_back(tmp);//放入组成字符
//            return;
//        }
//        int num = digits[pos] - '0';//找到遍历的按键
//        for (int i = 0; i < arr[num].size(); i++)//对按键对应的字符进行遍历
//        {
//            tmp.push_back(arr[num][i]);//放入字符
//            dfs(pos + 1, digits);//进行深度搜索
//            tmp.pop_back();//进行回溯删除掉这层已经遍历的的字符
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0)//判断特殊情况
//        {
//            return {};
//        }
//        dfs(0, digits);//进行深度搜索
//        return ans;
//
//    }
//};



//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合
//class Solution {
//public:
//    //本题思路：就是利用dfs进行枚举每一次的结果进行判断
//    vector<string>ans;
//    void dfs(const string& str, int left, int right)
//    {
//        if (left<0 || left>right)//如果左括号小于0或者左括号大于右括号就像（（）））（
//        {
//            return;
//        }
//        if (left == 0 && right == 0)//都为0时才能存入
//        {
//            ans.push_back(str);
//            return;
//        }
//        dfs(str + '(', left - 1, right);//对左右括号进行枚举遍历
//        dfs(str + ')', left, right - 1);
//
//    }
//    vector<string> generateParenthesis(int n) {
//        dfs("", n, n);
//        return ans;
//    }
//};

//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串
//的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
        {
            return -1;
        }
        int falg = 1;//标志位
        int m = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            falg = 1;
            for (int j = 0, ret = i; j < needle.size() && ret < haystack.size(); j++, ret++)
            {
                if (haystack[ret] == needle[j])
                {
                }
                else {
                    falg = 0;
                    break;
                }
            }
            if (falg == 1)//判断是否遍历needle字符并且没有不相等
            {
                m = i;
                break;
            }
        }
        if (haystack.size() - m < needle.size())//进行判断是否是在最后几位没有遍历完needle的位置
        {
            return -1;
        }
        if (falg == 1)
        {
            return m;
        }
        return -1;
    }
};