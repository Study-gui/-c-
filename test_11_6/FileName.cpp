 #define _CRT_SECURE_NO_WARNINGS


//给你一个字符串数组 words ，找出并返回 length(words[i])* length(words[j]) 的最大值，
//并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        //巧妙运用位运算进行解题
//        //把每一位字符串中的字符想象于一个二进制数中的一位，如果两个字符串相于等于0，说明没有重复字符
//        //在求出最大的相乘长度
//        int sum = 0;
//        int n = words.size();
//        int arr[n];
//        memset(arr, 0, sizeof(arr));
//        for (int i = 0; i < n; i++)
//        {
//            for (char& c : words[i])
//            {
//                arr[i] |= 1 << (c - 'a');//把每一位字符转化位二进制数位
//            }
//            for (int j = 0; j < i; j++)
//            {
//                if ((arr[i] & arr[j]) == 0)//判断是否有重复
//                {
//                    sum = max(sum, (int)(words[i].size() * words[j].size()));//求出最大值
//                }
//            }
//        }
//        return sum;
//    }
//};

//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//     //水平扫描法
//     if(strs.size()==0)//判断特殊情况
//     {
//         return "";
//     }
//     string ret=strs[0];//假设第一个字符串为前缀
//     for(int i=1;i<strs.size();i++)//从第二个字符串开始进行比对
//     {

//         while(strs[i].find(ret)!=0)//不匹配进来
//         {
//             ret.pop_back();//不匹配进行尾删
//             if(ret.empty())//判断是否为空
//             {
//                 return "";
//             }
//         }
//     }
//     return ret;//返回最长前缀
//     }
// };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //垂直扫描法
        string ret;
        for (int i = 0; i < strs[0].size(); i++)//从第一个字符串的第一个字符进行比对
        {
            char b = strs[0][i];
            for (int j = 1; j < strs.size(); j++)//从第二个字符串开始比对
            {
                if (i > strs[j].size() || b != strs[j][i])//判断不相等
                {
                    ret = strs[0].substr(0, i);//这放回第一个字符串到i下标位置的就是最大前缀
                    return ret;
                }
            }
        }
        return strs[0];//全部匹配
    }
};