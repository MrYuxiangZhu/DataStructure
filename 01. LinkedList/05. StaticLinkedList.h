#pragma once
#define AVAILABLE	(-1)

typedef unsigned int  ElemType;
typedef void StaticLinkedList;
typedef void StaticLinkedListNode;

typedef struct _TLinkedListNode
{
	ElemType data;
	int next;
}TLinkedListNode;

typedef struct _TLinkedList
{
	int length;
	int capacity;
	TLinkedListNode header;
	TLinkedListNode node[];
}TLinkedList;

StaticLinkedList* StaticLinkedListCreate(int capacity);

int StaticLinkedListClear(StaticLinkedList* slist);

int StaticLinkedListInsert(StaticLinkedList* slist, StaticLinkedListNode* node, int pos);

int GetStaticLinkedListLength(StaticLinkedList* slist);

int GetStaticLinkedListCapacity(StaticLinkedList* slist);

StaticLinkedListNode* GetStaticLinkedListNode(StaticLinkedList* slist, int pos);

StaticLinkedListNode* StaticLinkedListDelete(StaticLinkedList* slist, int pos);
