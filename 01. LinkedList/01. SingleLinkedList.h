#pragma once

#define ElemType int

//定义结点类型
typedef struct _LinkedListNode
{
	int data;						//数据类型
	struct _LinkedListNode* next;	//指向直接后继元素的指针
}LinkedListNode, *LinkedList;//List_Node表示结点的类型，LinkedList表示指向List_Node结点类型的指针类型

LinkedList LinkedListInit(); //初始化链表

LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem);//头插法建立单链表

LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem);  //尾插法建立单链表

LinkedList LinkedListInsert(LinkedList slist, ElemType elem, int pos);//插入结点

LinkedList GetLinkedList(LinkedList slist, int pos);//获取结点

LinkedList LinkedListDelete(LinkedList slist, int pos);		//删除链表结点

int GetLinkedListLength(LinkedList slist);	//获取链表长度

void DisplayLinkedList(LinkedList slist);



