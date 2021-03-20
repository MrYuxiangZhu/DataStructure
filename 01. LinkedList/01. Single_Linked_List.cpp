// Single_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

//定义结点类型
typedef struct List_Node
{
	ElemType data;			//数据类型
	struct List_Node* next;	//指向直接后继元素的指针
}List_Node, * LinkedList;	//List_Node表示结点的类型，LinkedList表示指向List_Node结点类型的指针类型

//初始化链表
LinkedList linked_list_init()
{
	List_Node* p = (List_Node*)malloc(sizeof(List_Node));	//创建新的空间
	if (NULL == p)
	{
		cout << "申请内存是失败" << endl;
	}
	else
	{
		p->next = NULL;
	}

	return p;
}

//头插法建立单链表
LinkedList create_linked_list_by_head()
{
	ElemType elem = 0;
	List_Node* head = (List_Node*)malloc(sizeof(List_Node));	//创建新的空间
	if (NULL == head)
	{
		cout << "申请内存是失败" << endl;
		return head;
	}

	head->next = NULL;
	while (cin >> elem)
	{
		List_Node* temp = (List_Node*)malloc(sizeof(List_Node)); //创建新的结点
		temp->data = elem;		//结点内容赋值
		temp->next = head->next;	//将结点插入表头head-->|2|-->|1|-->NULL
		head->next = temp;

		if (cin.get() == '\n')
		{
			break;
		}
	}

	return head;
}

//尾插法建立单链表
LinkedList create_linked_list_by_tail()
{
	ElemType elem = 0;
	List_Node* head = (List_Node*)malloc(sizeof(List_Node));	//创建新的空间
	List_Node* tail = NULL;
	head->next = NULL;
	tail = head;			//指向末尾结点
	while (cin >> elem)
	{
		List_Node* temp = (List_Node*)malloc(sizeof(List_Node));
		temp->data = elem;		//结点内容赋值
		tail->next = temp;		//将结点插入表头head-->|1|-->|2|-->NULL
		tail = temp;			//表尾重新赋值

		if (cin.get() == '\n')
		{
			break;
		}
	}

	tail->next = NULL;

	return head;
}

//插入操作是指在链表的第i个位置增加结点，将i位置的next指针修改为指向新创建的结点，新创建结点的next指向i+1位置的结点。
//其操作方式可以设置一个前驱结点，利用循环找到i位置，再进行插入
LinkedList linked_list_insert(LinkedList List, int i, ElemType elem)
{
	List_Node* pre = NULL;					//前驱结点
	pre = List;

	for (int cnt = 1; cnt < i; ++cnt)
	{
		pre = pre->next;			//找到第i位置的前驱结点
	}

	List_Node* p = (List_Node*)malloc(sizeof(List_Node));//插入结点p
	p->data = elem;
	p->next = pre->next;
	pre->next = p;

	return List;
}

//从单链表中删除值为x的结点
LinkedList linked_list_delete(LinkedList List, ElemType elem)
{
	List_Node* p = NULL;	//p为查找的结点
	List_Node* pre = NULL;	//pre为前驱结点
	p = List->next;
	while (p->data != elem)	//查找值为elem结点
	{
		pre = p;
		p = p->next;
	}

	if (p->data == elem)
	{ 
		pre->next = p->next;	//删除操作，将其前驱next指向其后继
		free(p);
	}
	else
	{
		cout << "未找到该元素" << endl;
	}

	return List;
}

//链表内容的修改，再链表中修改值为x的元素变为k。
LinkedList linked_list_replace(LinkedList List, ElemType x, ElemType k)
{
	List_Node* p = List->next;
	while (p)
	{
		if (p->data == x)
		{
			p->data = k;
		}
		p = p->next;
	}

	return List;
}

//输出链表，从链表的头开始，逐步向后遍历每一个元素；可以衍生出很多常用的数据操作，比如查找元素，修改元素，获取元素个数，打印整个链表数据等
void display(LinkedList list)
{
	List_Node* p = list->next;
	int count = 0;

	while (p)
	{
		cout << "第" << ++count << "个元素的值为: " << p->data << endl;
		p = p->next;
	}
}

int main()
{
	LinkedList list = NULL;
	cout << "请输入单链表数据，以回车结尾" << endl;
	list = create_linked_list_by_tail();
	display(list);

	//插入元素
	int pos = 0;
	int data = 0;
	cout << "请输入插入数据的位置" << endl;
	cin >> pos;
	cout << "请输入插入数据的值" << endl;
	cin >> data;
	linked_list_insert(list, pos, data);
	display(list);

	//修改数据
	cout << "请输入修改的数据" << endl;
	cin >> pos;
	cout << "请输入修改后数据" << endl;
	cin >> data;
	linked_list_replace(list, pos, data);
	display(list);

	//删除元素
	cout << "请输入删除的数据" << endl;
	cin >> data;
	linked_list_delete(list, data);
	display(list);

	return 0;
}
