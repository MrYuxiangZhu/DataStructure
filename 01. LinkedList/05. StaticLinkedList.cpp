#include <iostream>
#include "StaticLinkedList.h"

using namespace std;

//O(n)
StaticLinkedList* StaticLinkedList_Create(int capacity)
{
	//创建链表内存和所有结点内存
	LinkedList* tlist = (LinkedList*)malloc(sizeof(LinkedList) + sizeof(LinkedListNode) * (capacity + 1));
	if (nullptr == tlist)
	{
		cout << "创建链表头失败" << endl;
		return nullptr;
	}

	tlist->capacity = capacity;
	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = 0;
	tlist->node[0] = tlist->header;
	for (int i = 0; i < capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}

	return tlist;
}

//O(1)
void StaticLinkedList_Destroy(StaticLinkedList* list)
{
	if (nullptr == list)
	{
		cout << "输入参数错误" << endl;
		return;
	}

	free(list);
}

//O(n)
void StaticLinkedList_Clear(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		cout << "输入参数错误" << endl;
		return;
	}

	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = AVAILABLE;
	for (int i = 0; i <= tlist->capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}
}

//O(1)
int StaticLinkedList_Length(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		return -1;
	}

	return tlist->length;
}

//O(1)
int StaticLinkedList_Capacity(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		return -1;
	}

	return tlist->capacity;
}

//从头结点之后插入1...n
//O(n)
int StaticLinkedList_Insert(StaticLinkedList* list, StaticLinkedListNode* node, int pos)
{
	int current = 0;
	int index = 0;
	LinkedList* tlist = (LinkedList*)list;	//原链表

	if (nullptr == tlist || nullptr == node || pos <= 0 || tlist->length >= tlist->capacity)
	{
		cout << "输入参数错误" << endl;
		return -1;
	}

	//node[0]是头结点
	for (int i = 0; i <= tlist->capacity; ++i)
	{
		if (tlist->node[i].next == AVAILABLE)
		{
			index = i + 1;
			break;
		}
	}

	tlist->node[index].data = *(ElemType*)node;
	
	for (int i = 1; i < pos; ++i)
	{
		current = tlist->node[current].next;
	}

	tlist->node[index].next = tlist->node[current].next;
	tlist->node[current].next = index;
	tlist->header = tlist->node[0];
	tlist->length++;

	return 0;
}

//O(n)
StaticLinkedListNode* StaticLinkedList_Get(StaticLinkedList* list, int pos)
{
	int current = 1;
	LinkedList* tlist = (LinkedList*)list;

	if (nullptr == list || pos < 0 || pos > tlist->length)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}

	//逻辑上是从位置1向n查找
	for (int i = 1; (i < pos) && (tlist->node[current].next != 0); ++i)
	{
		current = tlist->node[current].next;
	}

	return &tlist->node[current].data;
}

//O(n)
StaticLinkedListNode* StaticLinkedList_Delete(StaticLinkedList* list, int pos)
{
	int current = 0;
	int index = 0;
	LinkedList* tlist = (LinkedList*)list;

	if (nullptr == list || pos <= 0 || tlist->length < 0)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}
	
	for (int i = 1; i < pos; ++i)
	{
		current = tlist->node[current].next;
	}

	index = tlist->node[current].next;
	tlist->node[current].next = tlist->node[index].next;
	tlist->node[index].next = AVAILABLE;
	tlist->length--;

	return &tlist->node[index].data;//返回要删除的结点
}
