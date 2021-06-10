#pragma once

#define ERROR (-1)

typedef void SingleLinkedList;		//单链表
typedef void SingleLinkedListNode;	//链表结点

typedef struct _LinkedListNode
{
	struct _LinkedListNode* next;	//指向指向下一个结点
}LinkedListNode;

typedef struct _LinkedList
{
	LinkedListNode header;	//头结点
	int length;
}LinkedList;

SingleLinkedList* SingleLinkedListCreate();

int SingleLinkedListDestroy(SingleLinkedList* slist);

int SingleLinkedListClear(SingleLinkedList* slist);

int GetSingleLinkedListLength(SingleLinkedList* slist);

int SingleLinkedListInsert(SingleLinkedList* slist, SingleLinkedListNode* node, int pos);

SingleLinkedListNode* GetSingleLinkedList(SingleLinkedList* slist, int pos);

SingleLinkedListNode* SingleLinkedListDelete(SingleLinkedList* slist, int pos);


