 #define _CRT_SECURE_NO_WARNINGS

//������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ���������ֲ�����ڵĵؿ��ϣ�
//���ǻ�����ˮԴ�����߶�����ȥ��

//����һ���������� flowerbed ��ʾ��̳�������� 0 �� 1 ��ɣ����� 0 ��ʾû��ֲ����1 ��ʾ��ֲ�˻���
//����һ���� n ���ܷ��ڲ�������ֲ�������������� n �仨�����򷵻� true �������򷵻� false ��


//bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
//    //����˼·���������ñ�־λ����¼��һ��������û���ֻ�
//    int ret = 0;
//    for (int i = 0; i < flowerbedSize; i++)
//    {
//        if (flowerbed[i] == 1)//�����������л�
//        {
//            if (ret == 1)//���ж���һ���Ƿ��л�
//            {
//                n++;//�о�+1
//            }
//            ret = 1;//������ؾͱ����һ��������Ϊ1
//        }
//        if (flowerbed[i] == 0)//�������û�л�
//        {
//            if (ret == 0)//���ж��Ͽ�����û�л�
//            {
//                n--;//--
//                ret = 1;//������ؾͱ����һ��������Ϊ1
//            }
//            else {
//                ret = 0;//�����һ�������л������Ͳ����ֻ�
//            }
//        }
//    }
//    if (n > 0)//�ж��Ƿ�������
//    {
//        return false;
//    }
//    return true;
//
//}



//����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�

//ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ��
//���һ���㷨�����������ܻ�ȡ���������

//��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��

// int maxProfit(int* prices, int pricesSize){
// //̰���㷨��
// int min=prices[0];
// int max=0;
// for(int i=0;i<pricesSize;i++)
// {
//     if(min>prices[i])
//     {
//         min=prices[i];
//     }
//     if(prices[i]-min>max)
//     {
//         max=prices[i]-min;
//     }
// }
// return max;
// }
//int maxProfit(int* prices, int pricesSize) {
//    //��̬�滮
//    int dp[pricesSize][2];//dp[i][j] i��ʾ��i�죬j=0��ʾû�г��й�Ʊ��j=1��ʾ���й�Ʊ
//    dp[0][0] = 0;
//    dp[0][1] = -prices[0];
//    for (int i = 1; i < pricesSize; i++)
//    {
//        //��i��û�г��й�Ʊ��1��ǰһ��Ҳû�й�Ʊ��2��ǰһ���й�Ʊ����������
//        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//        //��i���й�Ʊ��1ǰһ��Ҳ�й�Ʊ��2��ǰһ��û�й�Ʊ����������
//        dp[i][1] = fmax(dp[i - 1][1], -prices[i]);
//    }
//    return dp[pricesSize - 1][0];
//}



//����һ���������� prices ������ prices[i] ��ʾĳ֧��Ʊ�� i ��ļ۸�

//��ÿһ�죬����Ծ����Ƿ���� / ����۹�Ʊ�������κ�ʱ�� ��� ֻ�ܳ��� һ�� ��Ʊ����Ҳ�����ȹ���
//Ȼ���� ͬһ�� ���ۡ�

//���� ���ܻ�õ� ��� ���� ��
// int maxProfit(int* prices, int pricesSize){
// int dp[pricesSize][2];;//dp[i][j] i��ʾ��i�죬j=0��ʾû�г��й�Ʊ��j=1��ʾ���й�Ʊ
// dp[0][0]=0;
// dp[0][1]=-prices[0];
// for(int i=1;i<pricesSize;i++)
// {
//     //��i��û�г��й�Ʊ��1��ǰһ��Ҳû�й�Ʊ��2��ǰһ���й�Ʊ����������
//     dp[i][0]=fmax(dp[i-1][0],dp[i-1][1]+prices[i]);
//     //��i���й�Ʊ��1ǰһ��Ҳ�й�Ʊ��2��ǰһ��û�й�Ʊ����������
//     dp[i][1]=fmax(dp[i-1][1],dp[i-1][0]-prices[i]);
// }
// return dp[pricesSize-1][0];
// }
//
//int maxProfit(int* prices, int pricesSize) {
//    //̰���㷨����ν��״���һ�ν���
//    int sum = 0;
//    for (int i = 0; i < pricesSize - 1; i++)
//    {
//        if (prices[i + 1] > prices[i])
//        {
//            sum += prices[i + 1] - prices[i];
//        }
//    }
//    return sum;
//
//
//}
//
#include<stdio.h>
//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
//    int sum = 0;
//    for (int i = 0; i < gasSize; i++)
//    {
//        sum = gas[i];
//        for (int j = i + 1; sum > 0; j++)
//        {
//            if (i == (j % gasSize) && sum >= cost[(j - 1) % costSize])
//            {
//                return i;
//            }
//            sum = sum - cost[(j - 1) % costSize];
//            if (sum >= 0)
//            {
//                sum += gas[j % gasSize];
//            }
//            else {
//                break;
//            }
//            
//        }
//    }
//    return -1;
//}
//
//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
//    int sum = 0;
//    int start = 0;
//    int ret = 0;
//    for (int i = 0; i < gasSize; i++)
//    {
//        ret += gas[i] - cost[i];
//        sum += ret;
//        if (ret < 0)
//        {
//            start = i + 1;
//            ret = 0;
//        }
//    }
//    if (sum < 0)
//    {
//        return -1;
//    }
//    return start;
//
//
//}
//int main()
//{
//    int arr[6] = { 4,5,2,6,5,3 };
//    int brr[6] = { 3,2,7,3,2,9 };
//    int n=canCompleteCircuit(arr, 6, brr, 6);
//    printf("%d", n);
//
//
//
//	return 0;
//}


//��һ����·���� n ������վ�����е� i ������վ������ gas[i] ����
//����һ�������������޵ĵ��������ӵ� i ������վ������ i + 1 ������վ��Ҫ�������� cost[i] ����
//������е�һ������վ��������ʼʱ����Ϊ�ա�
//���������������� gas �� cost ���������԰�˳���ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ�
//���򷵻� - 1 ��������ڽ⣬�� ��֤ ���� Ψһ �ġ�

// int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    //ʱ�临�Ӷ�̫��
// int sum=0;
// for(int i=0;i<gasSize;i++)
// {
//     sum=gas[i];
//     for(int j=i+1;sum>0;j++)
//     {
//          if(i==(j%gasSize)&&sum>=cost[(j-1)%costSize])
//         {
//             return i;
//         }
//         sum=sum-cost[(j-1)%costSize];
//         if(sum>=0)
//         {
//             sum+=gas[j%gasSize];
//         }
//         else{
//             break;
//         }

//     }
// }
// return -1;
// }

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum = 0;
    int start = 0;
    int ret = 0;
    //����˼·��������̰���㷨���Ѵ�����ת��ΪС���⣬�ӵ�һ������վ��ʼ�����������������������ĵĺ�
    //�ӵ���Ψһ�ֻأ�����ܵ�С����϶����ܵ�
    for (int i = 0; i < gasSize; i++)
    {
        ret += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if (ret < 0)
        {
            start = i + 1;
            ret = 0;
        }
    }
    if (sum < 0)
    {
        return -1;
    }
    return start;
}
