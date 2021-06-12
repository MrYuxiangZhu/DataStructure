#include <iostream>
#include "StaticLinkedList.h"

using namespace std;

StaticLinkedList* StaticLinkedListCreate(int capacity)
{
	if (capacity < 0)
	{
		cout << "capacity error" << endl;
		return nullptr;
	}

	TLinkedList* tlist = (TLinkedList*)malloc(sizeof(TLinkedList) + sizeof(TLinkedListNode) * (capacity + 1));
	if (nullptr == tlist)
	{
		cout << "创建链表失败" << endl;
		return nullptr;
	}

	tlist->capacity = capacity;
	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = 0;

	for (int i = 0; i < capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}

	tlist->header = tlist->node[0];

	return tlist;
}

int StaticLinkedListClear(StaticLinkedList* slist)
{
	if (nullptr == slist)
	{
		cout << "链表为空" << endl;
		return -1;
	}

	TLinkedList* tlist = (TLinkedList*)slist;
	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = 0;

	for (int i = 0; i < tlist->capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}

	tlist->header = tlist->node[0];

	return 0;
}

int StaticLinkedListInsert(StaticLinkedList* slist, StaticLinkedListNode* node, int pos)
{
	TLinkedList* tlist = (TLinkedList*)slist;
	
	if (nullptr == tlist || nullptr == node || pos <= 0 || pos > tlist->capacity)
	{
		cout << "输入参数错误" << endl;
		return -1;
	}

	int current = 0;//头结点
	int index = 0;	//下一个节点

	for (int i = 0; i < tlist->capacity; ++i)
	{
		if (AVAILABLE == tlist->node[i].next)
		{
			index = i + 1;
			break;
		}
	}

	tlist->node[index].data = *(ElemType*)node;

	for (int i = 1; (i < pos) && (tlist->node[current].next != 0); ++i)
	{
		current = tlist->node[current].next;
	}

	tlist->node[index].next = tlist->node[current].next;
	tlist->node[current].next = index;
	tlist->header = tlist->node[0];
	tlist->length++;

	return 0;
}

int GetStaticLinkedListLength(StaticLinkedList* slist)
{
	if (nullptr == slist)
	{
		cout << "链表为空" << endl;
		return -1;
	}

	TLinkedList* tlist = (TLinkedList*)slist;
	
	return tlist->length;
}

int GetStaticLinkedListCapacity(StaticLinkedList* slist)
{
	if (nullptr == slist)
	{
		cout << "链表为空" << endl;
		return -1;
	}

	TLinkedList* tlist = (TLinkedList*)slist;

	return tlist->capacity;
}

StaticLinkedListNode* GetStaticLinkedListNode(StaticLinkedList* slist, int pos)
{
	TLinkedList* tlist = (TLinkedList*)slist;

	if (nullptr == slist || pos <= 0 || pos > tlist->length)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}

	int current = 0; //头结点
	int index = 0;

	for (int i = 1; (i < pos) && (tlist->node[current].next != 0); ++i)
	{
		current = tlist->node[current].next;	//向后移动
	}

	index = tlist->node[current].next;

	return &tlist->node[index].data;
}

StaticLinkedListNode* StaticLinkedListDelete(StaticLinkedList* slist, int pos)
{
	TLinkedList* tlist = (TLinkedList*)slist;

	if (nullptr == slist || pos <= 0 || pos > tlist->length)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}

	int current = 0; //头结点
	int index = 0;	 //下一个节点

	for (int i = 1; (i < pos) && (tlist->node[current].next != 0); ++i)
	{
		current = tlist->node[current].next;
	}

	index = tlist->node[current].next;
	tlist->node[current].next = tlist->node[index].next;
	tlist->node[index].next = AVAILABLE;
	tlist->length--;

	return &tlist->node[index].data;
}