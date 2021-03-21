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

//插入新结点时，首先创建新结点并分配内存空间，新结点的next指针指向插入位置的下一个结点
//插入位置的上一个结点next指针指向新结点
LinkedList linked_list_insert(List_Node* head, ElemType elem, int pos)
{
	if (NULL == head) { return NULL; }
	List_Node* List = head;
	for (int cnt = 1; cnt < pos - 1; ++cnt)
	{
		List = List->next;
	}

	List_Node* body = (List_Node*)malloc(sizeof(List_Node));
	body->data = elem;
	body->next = List->next;
	List->next = body;

	return head;
}

//找到与elem元素相等的结点，该位置的上一个结点的next指针指向该结点的下一个结点
//释放该位置结点内存
LinkedList linked_list_delete(List_Node* head, ElemType elem)
{
	if (NULL == head) { return NULL; }
	List_Node* Pre = head;
	List_Node* List = head->next;
	while (List != head)
	{
		if (List->data == elem)
		{
			Pre->next = List->next;
			free(List);
			cout << "删除结点成功！" << endl;
			break;
		}

		Pre = Pre->next;
		List = List->next;
	}

	//判断头结点
	if (List == head)
	{
		if (List->data == elem)
		{
			head = List->next;
			Pre->next = head;
			free(List);
			cout << "删除结点成功！" << endl;
		}
		else
		{
			cout << "删除结点失败，未找到元素！" << endl;
		}
	}

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
	ElemType elem = 0;	//插入的数据类型
	int pos = 0;	//链表长度
	List_Node* list = NULL;
	list = linked_list_create(list);
	display(list);
	cout << "请输入需要插入的位置" << endl;
	cin >> pos;
	cout << "请输入需要插入的元素" << endl;
	cin >> elem;
	list = linked_list_insert(list, elem, pos);
	display(list);
	cout << "请输入需要删除的元素" << endl;
	cin >> elem;
	list = linked_list_delete(list, elem);
	display(list);
	return 0;
}
