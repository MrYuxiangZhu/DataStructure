#pragma once

#define ERROR (-1)

typedef void SingleLinkedList;		//������
typedef void SingleLinkedListNode;	//������

typedef struct _LinkedListNode
{
	struct _LinkedListNode* next;	//ָ��ָ����һ�����
}LinkedListNode;

typedef struct _LinkedList
{
	LinkedListNode header;	//ͷ���
	int length;
}LinkedList;

SingleLinkedList* SingleLinkedListCreate();

int SingleLinkedListDestroy(SingleLinkedList* slist);

int SingleLinkedListClear(SingleLinkedList* slist);

int GetSingleLinkedListLength(SingleLinkedList* slist);

int SingleLinkedListInsert(SingleLinkedList* slist, SingleLinkedListNode* node, int pos);

SingleLinkedListNode* GetSingleLinkedList(SingleLinkedList* slist, int pos);

SingleLinkedListNode* SingleLinkedListDelete(SingleLinkedList* slist, int pos);


