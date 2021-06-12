#include <iostream>
#include "NewSingleLinkedList.h"

using namespace std;

//O(1)
SingleLinkedList* SingleLinkedListCreate()
{
	LinkedList* tlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (nullptr == tlist)
	{
		cout << "创建链表失败" << endl;
		return nullptr;
	}

	tlist->length = 0;
	tlist->header.next = nullptr;
	
	return tlist;
}

//O(1)
int SingleLinkedListDestroy(SingleLinkedList* slist)
{
	free(slist);

	return 0;
}

//O(1)
int SingleLinkedListClear(SingleLinkedList* slist)
{
	LinkedList* tlist = (LinkedList*)slist;

	if (nullptr == tlist)
	{
		cout << "空链表" << endl;
		return ERROR;
	}

	tlist->length = 0;
	tlist->header.next = nullptr;

	return 0;
}

//O(1)
int GetSingleLinkedListLength(SingleLinkedList* slist)
{
	LinkedList* tlist = (LinkedList*)slist;

	if (nullptr == tlist)
	{
		cout << "空链表" << endl;
		return ERROR;
	}

	return tlist->length;
}

//O(n)
int SingleLinkedListInsert(SingleLinkedList* slist, SingleLinkedListNode* node, int pos)
{
	if (nullptr == slist || nullptr == node || pos <= 0)
	{
		cout << "输入参数错误" << endl;
		return ERROR;
	}

	LinkedList* tlist = (LinkedList*)slist;
	LinkedListNode* plist = (LinkedListNode*)node;
	LinkedListNode* clist = &tlist->header;//头结点
	
	for (int i = 1; (i < pos) && (nullptr != clist); ++i)
	{
		clist = clist->next;//向下一个结点移动
	}

	plist->next = clist->next;
	clist->next = plist;
	tlist->length++;

	return 0;
}

//O(n)
SingleLinkedListNode* GetSingleLinkedList(SingleLinkedList* slist, int pos)
{
	LinkedList* tlist = (LinkedList*)slist;

	if (nullptr == tlist || pos <= 0 || pos > tlist->length)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}
	
	LinkedListNode* clist = &tlist->header;

	for (int i = 1; (i < pos) && (nullptr != clist); ++i)
	{
		clist = clist->next;//向下一个结点移动
	}

	return clist->next;
}

//O(n)
SingleLinkedListNode* SingleLinkedListDelete(SingleLinkedList* slist, int pos)
{
	LinkedList* tlist = (LinkedList*)slist;

	if (nullptr == tlist || pos <= 0 || pos > tlist->length)
	{
		cout << "输入参数错误" << endl;
		return nullptr;
	}

	LinkedListNode* clist = &tlist->header;//指向头结点
	LinkedListNode* plist = nullptr;
	for (int i = 1; i < pos; ++i)
	{
		clist = clist->next;	//向下一个结点移动
	}

	plist = clist->next;		//需要删除的结点
	clist->next = plist->next;	//需要删除的结点指向的下一个结点
	tlist->length--;			//链表长度减一

	return plist;
}