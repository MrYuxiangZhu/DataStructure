// Sequence_Queue_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

//顺序队列包含两个结构体：第一个结构体含有data数据和next指针，其中data是简单的类型（int，double等等），next指针表示下一个指针，指向下一个结点，通过next指针将各个结点链接
//第二个结构体包含指向队列的队尾和对头的指针
//结点定义
typedef struct Queue_Node
{
	ElemType data;
	struct Queue_Node* next;
}Queue_Node, *Queue_Node_List;

//队列指针定义
typedef struct Queue_List
{
	Queue_Node* front;	//头指针
	Queue_Node* rear;	//尾指针
}Queue_List, *Queue_Linked_List;

//初始化结点
Queue_Node_List queue_node_init()
{
	Queue_Node* node = (Queue_Node*)malloc(sizeof(Queue_Node));
	if (NULL == node)
	{
		cout << "create queue node failed!" << endl;
		return NULL;
	}

	return node;
}

//初始化队列，前后指针都为空
Queue_Linked_List queue_linked_list_init()
{
	Queue_List* queue = (Queue_List*)malloc(sizeof(Queue_List));
	if (NULL == queue)
	{
		cout << "create queue list failed!" << endl;
		return NULL;
	}

	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

//判断队列是否为空是比较常用的操作，如果堆头指针与队尾指针相等，则队列为空；反之队列不为空
bool empty(Queue_List* queue)
{
	return queue->front == queue->rear ? true : false;
}

//入队操作时，首先判断一下队列是否为空，如果队列为空，则需要将队头指针和队尾指针都指向第一个结点
//如果队列不为空，则需要将尾结点向后移动，通过不断移动next指针指向新的结点构成新的队列即可。
void push(Queue_List* queue, ElemType data)
{
	Queue_Node* node = queue_node_init();
	node->data = data;
	node->next = NULL;
	//采用尾插法
	if (true == empty(queue))
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;//node作为当前尾节点的下一个新节点
		queue->rear = node; //新结点作为新的尾节点
	}
}

int main()
{
    
}
