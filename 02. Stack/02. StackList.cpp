#include <iostream>
#include <assert.h>
#include "StackList.h"

using namespace std;

//O(1)
StackList* StackListCreate()
{
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (nullptr == list)
	{
		cout << "创建栈失败" << endl;
		return nullptr;
	}
	else
	{
		list->length = 0;
		list->header.next = nullptr;
		return list;
	}
}

//O(1)
int StackListPush(StackList* stack, StackListNode* node)
{
	if (nullptr == stack)
	{
		cout << "栈未初始化" << endl;
		return ERROR;
	}
	else
	{
		LinkedList* list = (LinkedList*)stack;
		LinkedListNode* nlist = (LinkedListNode*)node;
		LinkedListNode* clist = &list->header;
		nlist->next = clist->next;
		clist->next = nlist;
		list->length++;
		return 0;
	}
}

//O(1)
StackListNode* StackListPop(StackList* stack)
{
	LinkedList* list = (LinkedList*)stack;
	if (nullptr == list->header.next)
	{
		cout << "空栈" << endl;
		return nullptr;
	}

	assert(list->length > 0);
	LinkedListNode* nlist = nullptr;
	LinkedListNode* clist = &list->header;
	nlist = clist->next;
	clist->next = clist->next->next;
	list->length--;
	return nlist;
}

