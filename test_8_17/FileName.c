 #define _CRT_SECURE_NO_WARNINGS
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���
//ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ�
// ���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//���ʵ��Ӧ��֧�����²�����

//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�������




//��������Ķ���ʵ�֣����������±�ʵ��
typedef struct {

    int* data;
    int front;//����ͷ���±�
    int tail;//����β���±�
    int k;//����ռ��С
} MyCircularQueue;
//��������
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * (k + 1));//����k+1���ռ�
    obj->front = obj->tail = 0;//�ÿ�
    obj->k = k;//���пռ��С
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))//�������˲岻��ȥ
    {
        return false;
    }
    obj->data[obj->tail] = value;//��������
    obj->tail++;//��β���±��һ
    obj->tail %= obj->k + 1;//�������β�ٵ�����ͷ
    return true��
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//����Ϊ�գ�����ɾ��
    {
        return false;
    }
    obj->front++;//ɾ������
    obj->front %= (obj->k + 1);//�������β�ٵ���ͷ
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//����Ϊ��
    {
        return -1;
    }
    return obj->data[obj->front];//��ͷ����
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//����Ϊ��
    {
        return -1;
    }
    if (obj->tail == 0)//����β���±�������β���±�
    {
        return obj->data[obj->k];//��β�����ݾ�������ͷ�ĵ�����
    }
    else {//�������
        return obj->data[obj->tail - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail;//��ͷ�Ͷ�β���±���ȣ���Ϊ��
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % (obj->k + 1) == obj->front;//��β���±�+1�Ͷ�ͷ��������ȣ���Ϊ��
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);//���ͷſ��ٿռ��
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


//˼·2��������ķ���
//˼·�����������ͷ�ڵ��β�ڵ�

typedef struct {
    int size;//�������ݵ�����
    int capacity;   //���������
    struct ListNode* head;//�����ͷ���
    struct ListNode* tail;//�����β�ڵ�

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->size = 0;//��ʼ��
    obj->capacity = k;
    obj->head = obj->tail = NULL;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size >= obj->capacity)//��������
    {
        return false;
    }
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));//�����½ڵ�
    newnode->val = value;
    newnode->next = NULL;
    if (!obj->head)//����Ϊ��ʱ
    {
        obj->head = obj->tail = newnode;
    }
    else {//����Ϊ��
        obj->tail->next = newnode;
        obj->tail = newnode;
    }
    obj->size++;//����++
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)//����Ϊ��ʱ
    {
        return false;
    }
    obj->size--;
    struct ListNode* cur = obj->head;
    obj->head = obj->head->next;//��ͷ�ڵ�ָ����һ�����
    free(cur);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//����Ϊ��ʱ
    {
        return -1;
    }
    return obj->head->val;//����ͷ�ڵ������
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))//����Ϊ��ʱ
    {
        return -1;
    }
    return obj->tail->val;//����β��������
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;//�ж������Ƿ�Ϊ��
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;//�ж������������Ƿ����
}

void myCircularQueueFree(MyCircularQueue* obj) {
    while (obj->head)
    {
        struct ListNode* cur = obj->head->next;
        free(obj->head);//ע���ͷ�ÿһ���ڵ�
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