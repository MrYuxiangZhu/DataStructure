#pragma once

#define ERROR (-1)
#define ElemType int

typedef struct _CircleLinkedList
{
	ElemType data;
	struct _CircleLinkedList* next;
}CircleLinkedListNode, *CircleLinkedList;

CircleLinkedList CircleLinkedListCreate(CircleLinkedList slist, ElemType elem);
   
CircleLinkedList CircleLinkedListDelete(CircleLinkedList slist, int pos);

CircleLinkedList CircleLinkedListInsert(CircleLinkedList slist, ElemType elem, int pos);

CircleLinkedList GetCircleLinkedList(CircleLinkedList slist, int pos);

int GetCircleLinkedListLength(CircleLinkedList slist);

void DisplayCircleLinkedList(CircleLinkedList slist);