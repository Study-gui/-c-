 #define _CRT_SECURE_NO_WARNINGS
//��������һ������prices������Ϊn������prices[i]�ǹ�Ʊ�ڵ�i��ļ۸����������۸����飬
// ����������Ʊ�ܻ�õ�������� 1.���������һ�ι�Ʊ������һ�ι�Ʊ������ÿ�춼�������������һ�Σ�
// �ܹ�ֻ�����������һ�Σ������������������ǰ���ĳһ��
//2.������ܻ�ȡ���κ������뷵��0
//3.����������������������
* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
*
*
* @param prices int����һά����
* @param pricesLen int prices���鳤��
* @return int����
*
*C������������ȫ�ֱ��������static����ֹ�ظ�����
* /
int maxProfit(int* prices, int pricesLen) {
    // write code here
    if (pricesLen <= 1)
        return 0;
    int min_buy = prices[0];//��ʼ����С����۸�
    int max_sale = 0;
    for (int i = 1; i < pricesLen; i++) {
        //��i����ۣ��ж������Ƿ���� max_sale 
        if (prices[i] - min_buy > max_sale)
            max_sale = prices[i] - min_buy;
        //��i���Ƿ�����͵�����۸����ˢ�����ֵ ֮���������ֵ
        if (prices[i] < min_buy)
            min_buy = prices[i];

    }
    //�����������
    return max_sale;
}
