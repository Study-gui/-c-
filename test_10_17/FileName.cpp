 #define _CRT_SECURE_NO_WARNINGS

//����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

//�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false ��



//bool canJump(int* nums, int numsSize) {
//    //����˼·�������±�����Լ����߲��ӣ�һֱά�����Ĳ��ӣ��ж��ܲ������ߵ����������ܷ����һλ
//    if (numsSize == 1)
//    {
//        return true;
//    }
//    int k = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i <= k)//�ж��Ƿ�����ǰ��
//            k = fmax(i + nums[i], k);//���������߲���
//        if (k >= numsSize - 1)//�ж��Ƿ��ܵ����һλ
//        {
//            return true;
//        }
//    }
//    return false;
//}


//����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��

//ÿ��Ԫ�� nums[i] ��ʾ������ i ��ǰ��ת����󳤶ȡ����仰˵��������� nums[i] �����������ת������ 
//nums[i + j] ��:

//0 <= j <= nums[i] i + j < n���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]��
int jump(int* nums, int numsSize) {
    //����˼·��Ҳ������ά������ӣ��ҵ����ȵ����һλ�������ü���λ���м�¼
    if (numsSize == 1)
    {
        return 0;
    }
    if (numsSize == 2)
    {
        return 1;
    }
    int cur = 0;
    int next = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        next = (i + nums[i] > next ? (i + nums[i]) : next);//�ҵ����Ĳ���
        if (i == cur)//����һ���ļ��ޣ���һ�²�
        {
            count++;
            cur = next;
            if (next >= numsSize - 1)//�ж��Ƿ��ܵ����һλ
            {
                break;
            }
        }

    }
    return count;
}