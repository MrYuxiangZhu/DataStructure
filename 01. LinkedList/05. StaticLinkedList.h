#pragma once

#define AVAILABLE (-1)

typedef int	 ElemType;				//数据类型
typedef int	 PointType;				//指针类型
typedef void StaticLinkedList;		//定义void类型
typedef void StaticLinkedListNode;	//定义void类型

typedef struct _LinkedListNode
{
	ElemType data;		//存储的数据
	PointType next;		//下一个空间
}LinkedListNode;

typedef struct _LinkedList
{
	int length;				//链表长度
	int capacity;			//容量
	LinkedListNode header;	//链表头
	LinkedListNode node[];	//链表结点
}LinkedList;

StaticLinkedList* StaticLinkedList_Create(int capacity);

void StaticLinkedList_Destroy(StaticLinkedList* list);

void StaticLinkedList_Clear(StaticLinkedList* list);

int StaticLinkedList_Length(StaticLinkedList* list);

int StaticLinkedList_Capacity(StaticLinkedList* list);

int StaticLinkedList_Insert(StaticLinkedList* list, StaticLinkedListNode* node, int pos);

StaticLinkedListNode* StaticLinkedList_Get(StaticLinkedList* list, int pos);

StaticLinkedListNode* StaticLinkedList_Delete(StaticLinkedList* list, int pos);
