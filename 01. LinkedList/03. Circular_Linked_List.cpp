// Circular_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

typedef struct List_Node
{
	ElemType data;			//链表数据
	struct List_Node* next;	//指向下一个结点
}List_Node, * LinkedList;

//初始化结点，如同单链表的创建，需要先创建一个头结点并开辟内存空间，但与单链表不同的是
//开辟内存空间成功后将头结点的next指向head自身
LinkedList linked_list_init()
{
	List_Node* head = (List_Node*)malloc(sizeof(List_Node));
	if (NULL == head)
	{
		cout << "创建失败！" << endl;
		return NULL;
	}
	else
	{
		head->next = NULL;
		return head;
	}
}

int main()
{
     
}
