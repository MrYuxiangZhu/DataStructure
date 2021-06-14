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
	LinkedListNode header;	//ͷ���
	int length;	//������
}LinkedList;

StackList* StackListCreate();

int StackListPush(StackList* stack, StackListNode* node);

StackListNode* StackListPop(StackList* stack);

