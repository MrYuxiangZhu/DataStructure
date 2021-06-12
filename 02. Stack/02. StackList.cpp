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

//O(n)
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
		for (int index = 0; index < list->length; clist = clist->next, ++index);
		clist->next = nlist;
		list->length++;
		return 0;
	}
}

//O(n)
StackListNode* StackListPop(StackList* stack)
{
	LinkedList* list = (LinkedList*)stack;
	if (nullptr == stack)
	{
		cout << "空栈" << endl;
		return nullptr;
	}

	assert(list->length > 0);
	
	LinkedListNode* plist = &list->header;
	LinkedListNode* clist = &list->header;
	for (int index = 0; index < list->length; plist = clist, clist = clist->next, ++index);
	plist->next = nullptr;
	list->length--;
	return clist;
}