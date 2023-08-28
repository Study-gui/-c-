 #define _CRT_SECURE_NO_WARNINGS
//����һ��������������� A ��������������� B ���뽫���� B �ϲ������� A �У����һ���������������

/**
 *
 * @param A int����һά����
 * @param ALen int A���鳤��
 * @param B int����һά����
 * @param BLen int B���鳤��
 * @return void
 */
void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    //˼·���Ӻ���ǰ�Ƚϣ����ҴӺ���ǰ����
    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] > B[j])//���бȽ�
        {
            A[k--] = A[i--];
        }
        else {
            A[k--] = B[j--];
        }
    }
    while (i >= 0)//A���鲻Ϊ�յ����
    {
        A[k--] = A[i--];
    }
    while (j >= 0)//B���鲻Ϊ�յ����
    {
        A[k--] = B[j--];
    }

}