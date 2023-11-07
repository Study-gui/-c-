 #define _CRT_SECURE_NO_WARNINGS

//����һ���±�� 0 ��ʼ���ַ������� words ������������left �� right ��
//
//����ַ�����Ԫ����ĸ��ͷ����Ԫ����ĸ��β����ô���ַ�������һ�� Ԫ���ַ��� ������Ԫ����ĸ�� 'a'��'e'��'i'��'o'��'u' ��
//
//���� words[i] ��Ԫ���ַ�������Ŀ������ i �ڱ�����[left, right] �ڡ�

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


//�������� nums ���������У������е�ֵ ������ͬ ��
//
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ �����������磬[0, 1, 2, 4, 5, 6, 7] ���±� 3 ������ת����ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2] ��
//
//	���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� - 1 ��
//
//	��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        //����˼·�����ö����㷨���ҳ���ת��mid�Ĺ�ϵ
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])//���mid��û�з�ת��������
            {
                if (target >= nums[left] && target < nums[mid])//���target��mid��left֮��
                {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {//targe��mid��right֮��
                if (target <= nums[right] && target > nums[mid])//����ǰ������
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