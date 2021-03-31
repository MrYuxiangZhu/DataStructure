// Sequence_Queue_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

//使用数组实现顺序队列，需要先申请一块足够大的内存空间初始化顺序队列。除此之外，为了满足队列中数据从
//队尾进，队头出且先进先出的原则，因此需要定义两个指针（top和rear）分别用于指向顺序队列的队头元素和队尾元素
//由于顺序队列初始状态没有存储任何元素，因此top指针和rear指针重合，且由于顺序队列底层实现靠的是数组，因此top和rear实际上是两个变量
//它值分别是队头元素和队尾元素所在数组位置的下标
void push_queue(int *queue, int *rear, int data)
{
	if (NULL == queue) 
	{ 
		cout << "queue is NULL" << endl;
		return; 
	}
	cout << "入队元素为：" << data << endl;
	queue[*rear] = data;
	(*rear)++;
}

//出队列
void pop_queue(int* queue, int* front, int* rear)
{
	//如果*front == *rear，表示队列为空
	if (NULL == queue)
	{
		cout << "queue is NULL" << endl;
		return;
	}

	while (*front != *rear)
	{
		cout << "出队元素为：" << queue[*front] << endl;
		(*front)++;
	}
}

int main()
{
	int n = 0;
	int array[100] = { 0 };
	int data = 0;
	int front = 0;
	int rear = 0;
	//设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
	cout << "请输入队列元素个数" << endl;
	cin >> n;
	cout << "请输入一行数据" << endl;
	while (n--)
	{
		cin >> data;
		push_queue(array, &rear, data);
	}

	//出队
	pop_queue(array, &front, &rear);

	return 0;
}
