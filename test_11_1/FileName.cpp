 #define _CRT_SECURE_NO_WARNINGS

//����һ������Ϊ n ���ַ��������дһ�������жϸ��ַ����Ƿ���ġ�����ǻ����뷵��true��
// ���򷵻�false��
//
//�ַ�������ָ���ַ������������������ַ�һ��

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ��� ���жϵ��ַ���
     * @return bool������
     */
//    bool judge(string str) {
//        // write code here
//        //����˼·����������˫ָ����б�������
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


    //һȺ��������Ϸ���������������Ϸ�÷������ǹ���Ҫ�����£�

    //1. ÿ�����Ӳ��ܵ÷ֶ��٣�����ֵ�һ���ǹ���
    //    2. �����������ڵĺ���֮�䣬�÷ֽ϶�ĺ��ӱ����ö�һЩ�ǹ���(����ͬ���޴�����)

    //    ����һ������
    //    ?
    //    ?
    //    ?
    //    arr ����÷����飬�뷵��������Ҫ�����ǹ���

//#include <vector>
//    class Solution {
//    public:
//        /**
//         * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//         *
//         * pick candy
//         * @param arr int����vector the array
//         * @return int����
//         */
//        int candy(vector<int>& arr) {
//            // write code here
//            //����˼·�������α�����1�������ұ���������2����������������
//            //�����������ֵ
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


    //����һ�����䣬��ϲ������ص������䡣
    //    �뱣֤�ϲ�������䰴��������������С�


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
         * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
         *
         *
         * @param intervals Interval��vector
         * @return Interval��vector
         */
        vector<Interval> merge(vector<Interval>& intervals) {
            // write code here
            //����˼·����ͨ����������������������
            //�ڽ�����β������бȽϣ��ٽ�������
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
                if (ans.empty() || ans.back().end < intervals[i].start)//���ansΪ�ջ���endС��start
                    //˵��û�н���
                {
                    ans.push_back(intervals[i]);
                }
                if (ans.back().end < intervals[i].end)//���end����startС��end�����end
                {
                    ans.back().end = intervals[i].end;
                }
            }
            return ans;

        }
    };