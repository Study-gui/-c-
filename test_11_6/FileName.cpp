 #define _CRT_SECURE_NO_WARNINGS


//����һ���ַ������� words ���ҳ������� length(words[i])* length(words[j]) �����ֵ��
//�������������ʲ����й�����ĸ������������������������ʣ����� 0 ��

//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        //��������λ������н���
//        //��ÿһλ�ַ����е��ַ�������һ�����������е�һλ����������ַ������ڵ���0��˵��û���ظ��ַ�
//        //�����������˳���
//        int sum = 0;
//        int n = words.size();
//        int arr[n];
//        memset(arr, 0, sizeof(arr));
//        for (int i = 0; i < n; i++)
//        {
//            for (char& c : words[i])
//            {
//                arr[i] |= 1 << (c - 'a');//��ÿһλ�ַ�ת��λ��������λ
//            }
//            for (int j = 0; j < i; j++)
//            {
//                if ((arr[i] & arr[j]) == 0)//�ж��Ƿ����ظ�
//                {
//                    sum = max(sum, (int)(words[i].size() * words[j].size()));//������ֵ
//                }
//            }
//        }
//        return sum;
//    }
//};

//��дһ�������������ַ��������е������ǰ׺��
//
//��������ڹ���ǰ׺�����ؿ��ַ��� ""��

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//     //ˮƽɨ�跨
//     if(strs.size()==0)//�ж��������
//     {
//         return "";
//     }
//     string ret=strs[0];//�����һ���ַ���Ϊǰ׺
//     for(int i=1;i<strs.size();i++)//�ӵڶ����ַ�����ʼ���бȶ�
//     {

//         while(strs[i].find(ret)!=0)//��ƥ�����
//         {
//             ret.pop_back();//��ƥ�����βɾ
//             if(ret.empty())//�ж��Ƿ�Ϊ��
//             {
//                 return "";
//             }
//         }
//     }
//     return ret;//�����ǰ׺
//     }
// };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //��ֱɨ�跨
        string ret;
        for (int i = 0; i < strs[0].size(); i++)//�ӵ�һ���ַ����ĵ�һ���ַ����бȶ�
        {
            char b = strs[0][i];
            for (int j = 1; j < strs.size(); j++)//�ӵڶ����ַ�����ʼ�ȶ�
            {
                if (i > strs[j].size() || b != strs[j][i])//�жϲ����
                {
                    ret = strs[0].substr(0, i);//��Żص�һ���ַ�����i�±�λ�õľ������ǰ׺
                    return ret;
                }
            }
        }
        return strs[0];//ȫ��ƥ��
    }
};