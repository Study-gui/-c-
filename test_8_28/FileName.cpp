 #define _CRT_SECURE_NO_WARNINGS
//给出一个有序的整数数组 A 和有序的整数数组 B ，请将数组 B 合并到数组 A 中，变成一个有序的升序数组

/**
 *
 * @param A int整型一维数组
 * @param ALen int A数组长度
 * @param B int整型一维数组
 * @param BLen int B数组长度
 * @return void
 */
void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    //思路：从后往前比较，并且从后往前排序
    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] > B[j])//进行比较
        {
            A[k--] = A[i--];
        }
        else {
            A[k--] = B[j--];
        }
    }
    while (i >= 0)//A数组不为空的情况
    {
        A[k--] = A[i--];
    }
    while (j >= 0)//B数组不为空的情况
    {
        A[k--] = B[j--];
    }

}