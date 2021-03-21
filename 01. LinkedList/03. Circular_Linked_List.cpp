// Circular_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

typedef struct List_Node
{
	ElemType data;			//链表数据
	struct List_Node* next;	//指向下一个结点
}List_Node, *LinkedList;

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

//链表创建是通过逐步插入操作，创建一个新的结点，将原有链表尾结点的next指针指向新的结点，
//新的结点的next指针重新指向头结点
LinkedList linked_list_create(List_Node* head)
{
	ElemType elem = 0;	//插入的数据类型
	int length = 0;	//链表长度
	int pos = 1;	//链表位置
	cout << "请输入创建结点的长度" << endl;
	cin >> length;
	if (length < 1) { return NULL; }
	head = (List_Node*)malloc(sizeof(List_Node));
	head->next = NULL;
	cout << "请输入第" << pos++ << "个数据" << endl;
	cin >> elem;
	head->data = elem;
	List_Node* List = head;
	while (pos <= length)
	{
		List_Node* body = (List_Node*)malloc(sizeof(List_Node));
		body->next = NULL;
		cout << "请输入第" << pos++ << "个数据" << endl;
		cin >> elem;
		body->data = elem;
		List->next = body;
		List = List->next;
	}

	List->next = head;

	return head;
}


//当前结点为头结点时结束
void display(List_Node* head)
{
	List_Node* List = head;
	int pos = 1;
	while (List->next != head)
	{
		cout << "第" << pos++ << "个数据是: " << List->data << endl;
		List = List->next;
	}

	cout << "第" << pos++ << "个数据是: " << List->data << endl;
}

int main()
{
	List_Node* list = NULL;
	list = linked_list_create(list);
	display(list);
	return 0;
}
