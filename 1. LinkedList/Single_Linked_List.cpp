// Single_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//定义结点类型
typedef struct List_Node
{
	int data;	//数据类型
	struct List_Node* next;	//指向直接后继元素的指针
}List_Node, *LinkedList;//List_Node表示结点的类型，LinkedList表示指向List_Node结点类型的指针类型

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

//链表内容的修改，再链表中修改值为x的元素变为为k。
LinkedList linked_list_replace(LinkedList List, int x, int k) 
{
    Node *p = List->next;
    int i = 0;
    while(p)
	{
        if (p->data == x)
		{
            p->data = k;
        }
        p = p->next;
    }
	
    return List;
}

//插入操作是指在链表的第i个位置增加结点，将i位置的next指针修改为指向新创建的结点，新创建结点的next指向i+1位置的结点。
//其操作方式可以设置一个前驱结点，利用循环找到i位置，再进行插入
LinkedList linked_list_insert(LinkedList List, int i, int elem)
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

//初始化链表
LinkedList init_list()
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
	int elem = 0;
	List_Node* head = (List_Node*)malloc(sizeof(List_Node));	//创建新的空间
	if (NULL == head)
	{
		cout << "申请内存是失败" << endl;
		return head;
	}

	head->next = NULL;
	while (scanf("%d", &elem) != EOF)
	{
		List_Node* temp = (List_Node*)malloc(sizeof(List_Node)); //创建新的结点
		temp->data = elem;		//结点内容赋值
		temp->next = head->next;	//将结点插入表头head-->|2|-->|1|-->NULL
		head->next = temp;
	}

	return head;
}

//尾插法建立单链表
LinkedList create_linked_list_by_tail()
{
	int elem = 0;
	List_Node* head = (List_Node*)malloc(sizeof(List_Node));	//创建新的空间
	List_Node* tail = NULL;
	head->next = NULL;
	tail = head;			//指向末尾结点
	while (scanf("%d", &elem) != EOF)
	{
		List_Node* temp = (List_Node*)malloc(sizeof(List_Node));
		temp->data = elem;		//结点内容赋值
		tail->next = temp;		//将结点插入表头head-->|1|-->|2|-->NULL
		tail = temp;			//表尾重新赋值
	}

	tail->next = NULL;

	return head;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

