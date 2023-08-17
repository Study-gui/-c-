 #define _CRT_SECURE_NO_WARNINGS
//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）
//原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，
// 我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//你的实现应该支持如下操作：

//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。




//利用数组的队列实现，利用两个下标实现
typedef struct {

    int* data;
    int front;//代表头的下标
    int tail;//代表尾的下标
    int k;//数组空间大小
} MyCircularQueue;
//函数声明
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * (k + 1));//开辟k+1个空间
    obj->front = obj->tail = 0;//置空
    obj->k = k;//队列空间大小
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))//队列满了插不进去
    {
        return false;
    }
    obj->data[obj->tail] = value;//插入数据
    obj->tail++;//对尾的下标加一
    obj->tail %= obj->k + 1;//到数组队尾再到，队头
    return true；
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//队列为空，不能删除
    {
        return false;
    }
    obj->front++;//删除数据
    obj->front %= (obj->k + 1);//到数组队尾再到队头
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//队列为空
    {
        return -1;
    }
    return obj->data[obj->front];//对头数据
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//队列为空
    {
        return -1;
    }
    if (obj->tail == 0)//当队尾的下标是数组尾的下标
    {
        return obj->data[obj->k];//队尾的数据就是数组头的的数据
    }
    else {//正常情况
        return obj->data[obj->tail - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail;//队头和队尾的下标相等，即为空
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % (obj->k + 1) == obj->front;//队尾的下标+1和队头的数据相等，即为满
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);//先释放开辟空间的
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/


//思路2：用链表的方法
//思路：利用链表的头节点和尾节点

typedef struct {
    int size;//链表数据的数量
    int capacity;   //链表的容量
    struct ListNode* head;//链表的头结点
    struct ListNode* tail;//链表的尾节点

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size = 0;//初始化
    obj->capacity = k;
    obj->head = obj->tail = NULL;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size >= obj->capacity)//链表满了
    {
        return false;
    }
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));//开辟新节点
    newnode->val = value;
    newnode->next = NULL;
    if (!obj->head)//链表为空时
    {
        obj->head = obj->tail = newnode;
    }
    else {//链表不为空
        obj->tail->next = newnode;
        obj->tail = newnode;
    }
    obj->size++;//容量++
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)//链表为空时
    {
        return false;
    }
    obj->size--;
    struct ListNode* cur = obj->head;
    obj->head = obj->head->next;//让头节点指向下一个结点
    free(cur);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//链表为空时
    {
        return -1;
    }
    return obj->head->val;//返回头节点的数据
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//链表为空时
    {
        return -1;
    }
    return obj->tail->val;//返回尾结点的数据
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;//判断数量是否为空
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;//判断数量和容量是否相等
}

void myCircularQueueFree(MyCircularQueue* obj) {
    while (obj->head)
    {
        struct ListNode* cur = obj->head->next;
        free(obj->head);//注意释放每一个节点
        obj->head = cur;
    }
    obj->tail = NULL;
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/