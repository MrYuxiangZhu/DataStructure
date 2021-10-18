#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

//O(1)
LinkedList LinkedListInit()
{
	LinkedListNode* header = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	if (nullptr == header)
	{
		cout << "创建链表头失败" << endl;
		return nullptr;
	}

	header->data = 0;
	header->next = nullptr;

	return header;
}

//O(1)
LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		cout << "链表未初始化" << endl;
		return nullptr;
	}
	else
	{
		LinkedListNode* header = slist;

		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			node->data = elem;
			node->next = header->next;
			header->next = node;
			return header;
		}
	}
}

//O(1)
LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		cout << "链表未初始化" << endl;
		return nullptr;
	}
	else
	{
		LinkedListNode* header = slist;
		LinkedListNode* clist = slist;
		while (nullptr != clist->next)
		{
			clist = clist->next;
		}

		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			node->data = elem;
			node->next = nullptr;
			clist->next = node;
			return header;
		}
	}
}

//O(n)
LinkedList LinkedListInsert(LinkedList slist, ElemType elem, int pos)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else
	{
		LinkedListNode* header = slist;//头结点
		LinkedListNode* clist = slist;//当前结点
		for (int i = 1; i < pos && nullptr != clist->next; ++i)
		{
			clist = clist->next;
		}
		
		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			node->data = elem;
			node->next = clist->next;
			clist->next = node;
			return header;
		}
	}
}

//O(n)
LinkedList LinkedListDelete(LinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else
	{
		bool FindFlag = false;
		LinkedListNode* header = slist;//头结点
		LinkedListNode* clist = slist;//当前结点
		LinkedListNode* tlist = nullptr;
		while (nullptr != clist->next)
		{
			if (elem == clist->next->data)
			{
				tlist = clist->next;
				clist->next = clist->next->next;
				free(tlist);
				tlist = nullptr;
				FindFlag = true;
				break;
			}
			else
			{
				clist = clist->next;
			}
		}
		
		if (!FindFlag)
		{
			cout << "未找到该元素: " << elem << endl;
		}

		return header;
	}
}

LinkedListNode* GetLinkedListNode(LinkedList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return nullptr;
	}
	else
	{
		LinkedListNode* clist = slist;//当前结点
		for (int i = 0; i < pos && clist->next != nullptr; ++i)
		{
			clist = clist->next;
		}

		return clist;
	}
}

LinkedListNode* LocateLinkedListNode(LinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else
	{
		LinkedListNode* clist = slist->next;//当前结点
		while (clist && elem != clist->data)
		{
			clist = clist->next;
		}

		return clist; //查找成功返回值为elem的结点地址, 查找失败p为NULL
	}
}

//O(n)
int GetLinkedListLength(LinkedList slist)
{
	LinkedListNode* p = slist->next;
	int length = 0;
	while (p)
	{
		++length;
		p = p->next;
	}

	return length;
}

//O(n)
void display(LinkedList slist)
{
	LinkedListNode* p = slist;
	int count = 0;
	p = p->next;//跳过头结点
	while (p)
	{
		cout << "第" << ++count << "个元素的值为: " << p->data << endl;
		p = p->next;
	}
}