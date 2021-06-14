#pragma once

#define ERROR (-1)

typedef void StackList;
typedef void StackListNode;

typedef struct _LinkedListNode
{
	struct _LinkedListNode* next;
}LinkedListNode;

typedef struct _List
{
	LinkedListNode header;	//头结点
	int length;	//链表长度
}LinkedList;

StackList* StackListCreate();

int StackListPush(StackList* stack, StackListNode* node);

StackListNode* StackListPop(StackList* stack);

