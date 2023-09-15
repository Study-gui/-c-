 #define _CRT_SECURE_NO_WARNINGS
//用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能
//。 队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
///**
// * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// *
// *
// * @param node int整型
// * @return 无
// */
//#define max 1000
// //本体思路：注意栈的特性是先进后出，队列是先进先出，用两个栈即可进行这个转换
// //一定要注意，数组下标和栈里元素个数的区分
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
// * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// *
// *
// * @param 无
// * @return int整型
// */
//int pop() {
//    if (pops.top == 0)
//    {
//        while (pushs.top)
//            pops.data[pops.top++] = pushs.data[--pushs.top];//先把pushs栈的元素倒到pops中
//    }
//    return pops.data[--pops.top];//再把pops的栈顶的元素进行输出
//
//}
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 
//和 min 函数操作时，栈中一定有元素。
//此栈包含的方法有：
//push(value) :将value压入栈中
//pop() : 弹出栈顶元素
//top() : 获取栈顶元素
//min() : 获取栈中最小元素
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param value int整型
 * @return 无
 */
typedef struct stack1
{
    int data[10001];
    int top;
}stack1;
stack1 stack;
//本题关键就是理解栈的元素和下标的用法
void push(int value) {
    stack.data[stack.top++] = value;

}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param 无
 * @return 无
 */
void pop() {
    stack.top--;

}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param 无
 * @return int整型
 */
int top() {
    int i = stack.top - 1;
    return stack.data[i];

}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param 无
 * @return int整型
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