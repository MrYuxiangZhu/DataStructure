// Circular_Queue_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define MAXSIZE 100	//循环队列最大容量

typedef struct
{
	int data[MAXSIZE];
	int rear;
	int front;
}Circular_Queue_List;

//对于顺序队列而言，存在一些缺陷和不足，例如当入队和出队操作均是直接进行结点的链接和删除，这必然造成使用空间向出队的那一边偏移，
//产生假溢出的现象。假溢出是指队列的元素出队后，新插入的元素不是在原内存插入数据，而是创建新的内存空间与原队列结点进行链接。
//当进行动态创建队列的时候，只不过是向后继续不断的申请内存空间，即使前面出队操作释放了前面的内存，但是指针依旧向后移动
//直到达到系统预留给程序的内存上届被强行终止，这对于极为频繁的队列操作和程序而言是致命的。
//循环队列设定队列固定的大小范围，对固定大小的队列进行插入和删除操作，以达到重复利用空间的效果。
Circular_Queue_List* circular_queue_linked_list_init()
{
	Circular_Queue_List* queue = (Circular_Queue_List*)malloc(sizeof(Circular_Queue_List));
	if (NULL == queue)
	{
		cout << "create queue failed!" << endl;
		return NULL;
	}

	queue->front = 0;
	queue->rear = 0;

	return queue;
}

//判断队列是否为空，就是front == rear，说明队列无元素
bool empty(Circular_Queue_List* queue)
{
	return queue->front == queue->rear ? true : false;
}

//入队操作时，直接将rear向后移动。如果rear达到队列的空间最大值，将要从头继续开始移动，这里使用余数法
void push_queue(Circular_Queue_List* queue, int data)
{
	if ((queue->rear + 1) % MAXSIZE == queue->front)
	{
		cout << "队列已满！" << endl;
		return;
	}
	
	cout << "入队元素为：" << data << endl;
	queue->data[queue->rear] = data;
	queue->rear = (queue->rear + 1) % MAXSIZE;
}

//出队操作直接将front进行后移一位，当队列为空的时候无法进行出队操作
void pop_queue(Circular_Queue_List* queue)
{
	if (true == empty(queue))
	{
		cout << "队列为空，无法出队" << endl;
		return;
	}

	cout << "出队元素为：" << queue->data[queue->front] << endl;
	queue->front = (queue->front + 1) % MAXSIZE;
}

//遍历队列
void display(Circular_Queue_List* queue)
{
	int count = queue->front;
	cout << "队列所有元素为：";
	while (count != queue->rear)
	{
		cout << queue->data[count] << " ";
		count = (count + 1) % MAXSIZE;
	}

	cout << endl;
}

int main()
{
	int data = 0;
	int length = 0;
	Circular_Queue_List* queue = circular_queue_linked_list_init();

	cout << "请输入队列长度" << endl;
	cin >> length;
	cout << "请输入队列元素" << endl;
	while (length--)
	{
		cin >> data;
		push_queue(queue, data);
	}

	display(queue);

	pop_queue(queue);

	display(queue);

	return 0;
}

