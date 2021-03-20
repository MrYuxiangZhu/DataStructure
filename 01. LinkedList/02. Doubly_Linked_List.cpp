﻿// Doubly_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

typedef struct List_Node
{
	ElemType data;			//链表数据
	struct List_Node* pre;	//结点前驱
	struct List_Node* next;	//后继
}List_Node, *LinkedList;

//创建双向链表，需要先创建头结点再逐步添加，然而与单链表不同，双向链表的头结点是有数据元素的
//对于逐步添加数据，需要开辟一段新的内存空间作为新的结点，为这个结点的data进行赋值；然后将已成链表
//上一个结点的next指针指向自身，自身的pre指针指向上一个结点
LinkedList linked_list_create(List_Node* head)
{
	int length = 0;		//链表长度
	int pos = 1;
	ElemType elem = 0;	//输入数据
	cout << "请输入创建结点的长度" << endl;
	cin >> length;
	if (length < 1) { return NULL; }
	head = (List_Node*)malloc(sizeof(List_Node));
	head->pre = NULL;
	head->next = NULL;
	cout << "请输入第" << pos++ << "个数据" << endl;
	cin >> elem;
	head->data = elem;
	List_Node* List = head;
	while (pos <= length)
	{
		List_Node*  body = (List_Node*)malloc(sizeof(List_Node));
		body->pre = NULL;
		body->next = NULL;
		cout << "请输入第" << pos++ << "个数据" << endl;
		cin >> elem;
		body->data = elem;
		List->next = body;
		body->pre = List;
		List = List->next;
	}

	return head;
}

//对于每一次的双向链表的插入操作，首先需要创建一个独立的结点，并通过malloc开辟相应的空间
//其次选中新创建的独立结点，将其的pre指针指向所需插入位置的前一个结点
//同时其所需插入位置的前一个结点next指针指向新创建的独立结点
//新创建独立结点的next指针指向插入位置的下一个结点
//插入位置的下一个结点的pre指针指向新创建的独立结点
LinkedList linked_list_insert(List_Node* head, ElemType elem, int pos)
{
	//三个参数分别为：原链表，插入的数据，插入的位置
	List_Node* List = (List_Node*)malloc(sizeof(List_Node));
	List->pre = NULL;
	List->next = NULL;
	List->data = elem;

	//插入到链表头
	if (1 == pos)
	{
		List->next = head;
		head->pre = List;
		head = List;
	}
	else
	{
		List_Node* body = head;
		for (int cnt = 1; cnt < pos - 1; cnt++)
		{
			body = body->next;
		}

		if (NULL == body->next) //插入位置为链表尾
		{
			body->next = List;
			List->pre = body;
		}
		else
		{
			body->next->pre = List;
			List->next = body->next;
			body->next = List;
			List->pre = body;
		}
	}

	return head;
}

//选择需要删除的结点，选中该结点的前一个结点，将前一个结点的next指针指向该结点的下一个结点
//该结点的下一个结点的pre指针指向该结点的上一个结点
//释放该结点的内存空间
LinkedList linked_list_delete(List_Node* head, ElemType elem)
{
	List_Node* List = head;
	while (List)
	{
		//判断结点数据是否与此元素相等
		//将该结点的上一个结点next指针指向该结点下一个结点
		//将该结点的下一个结点pre指针指向该结点的上一个结点
		if (elem == List->data)
		{
			if (NULL == List->next)
			{
				List->pre->next = List->next;
			}
			else
			{ 
				List->pre->next = List->next;
				List->next->pre = List->pre;
			}

			free(List);
			cout << "删除成功!" << endl;
			return head;
		}

		List = List->next;
	}

	cout << "没有找到该元素，删除失败!" << endl;

	return head;
}

//如同单链表的遍历一样，利用next指针逐步向后进行索引即可，注意判断这里，我们既可以用while(list)的操作直接判断是否链表为空，也可以使用while(list->next)的操作判断该链表是否为空，
//其下一节点为空和本结点是否为空的判断条件是一样的效果。
void display(List_Node* head)
{
	List_Node* List = head;
	int pos = 1;
	while (List)
	{
		cout << "第" << pos++ << "个数据是: " << List->data << endl;
		List = List->next;
	}
}

int main()
{
	List_Node* list = NULL;
	list = linked_list_create(list);
	display(list);

	ElemType input = 0;
	int pos = 0;
	cout << "请输入插入的位置" << endl;
	cin >> pos;
	cout << "请输入第" << pos << "个数据" << endl;
	cin >> input;
	list = linked_list_insert(list, input, pos);
	display(list);

	cout << "请输入需要删除的数据" << endl;
	cin >> input;
	list = linked_list_delete(list, input);
	display(list);

	return 0;
}