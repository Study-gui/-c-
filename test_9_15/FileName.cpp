 #define _CRT_SECURE_NO_WARNINGS
//������ջ��ʵ��һ�����У�ʹ��n��Ԫ������� n ���ڶ���β����������(push)��n���ڶ���ͷ��ɾ������(pop)�Ĺ���
//�� �����е�Ԫ��Ϊint���͡���֤�����Ϸ�������֤pop����ʱ����������Ԫ�ء�
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param node int����
// * @return ��
// */
//#define max 1000
// //����˼·��ע��ջ���������Ƚ�������������Ƚ��ȳ���������ջ���ɽ������ת��
// //һ��Ҫע�⣬�����±��ջ��Ԫ�ظ���������
//typedef struct Stack
//{
//    int data[max + 1];
//    int top;
//} sta;
//sta pushs, pops;
//void push(int node) {
//    pushs.data[pushs.top++] = node;
//
//}
//
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param ��
// * @return int����
// */
//int pop() {
//    if (pops.top == 0)
//    {
//        while (pushs.top)
//            pops.data[pops.top++] = pushs.data[--pushs.top];//�Ȱ�pushsջ��Ԫ�ص���pops��
//    }
//    return pops.data[--pops.top];//�ٰ�pops��ջ����Ԫ�ؽ������
//
//}
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص� min �������������ʱ��֤ pop��top 
//�� min ��������ʱ��ջ��һ����Ԫ�ء�
//��ջ�����ķ����У�
//push(value) :��valueѹ��ջ��
//pop() : ����ջ��Ԫ��
//top() : ��ȡջ��Ԫ��
//min() : ��ȡջ����СԪ��
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param value int����
 * @return ��
 */
typedef struct stack1
{
    int data[10001];
    int top;
}stack1;
stack1 stack;
//����ؼ��������ջ��Ԫ�غ��±���÷�
void push(int value) {
    stack.data[stack.top++] = value;

}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return ��
 */
void pop() {
    stack.top--;

}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return int����
 */
int top() {
    int i = stack.top - 1;
    return stack.data[i];

}

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param ��
 * @return int����
 */
int min() {
    int min = stack.data[0];
    for (int i = 0; i < stack.top; i++)
    {
        if (min > stack.data[i])
        {
            min = stack.data[i];
        }
    }
    return min;
}