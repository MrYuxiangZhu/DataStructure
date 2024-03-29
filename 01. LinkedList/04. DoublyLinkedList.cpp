﻿#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

//O(1)
LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem)
{
	LinkedListNode* header = nullptr;

	if (nullptr == slist)
	{
		header = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == header)
		{
			cout << "创建链表头失败" << endl;
			return nullptr;
		}
		else
		{
			header->data = elem;
			header->pre = nullptr;
			header->next = nullptr;
			return header;
		}
	}
	else
	{
		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			LinkedListNode* clist = slist;

			node->data = elem;
			node->next = clist;
			clist->pre = node;
			header = node;
			return header;
		}
	}
}

//O(n)
LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		LinkedListNode* header = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == header)
		{
			cout << "创建链表头失败" << endl;
			return nullptr;
		}
		else
		{
			header->data = elem;
			header->pre = nullptr;
			header->next = nullptr;
			return header;
		}
	}
	else
	{
		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			LinkedListNode* header = slist;
			LinkedListNode* clist = slist;

			for (clist = slist; clist->next != nullptr; clist = clist->next);//寻找尾结点

			node->data = elem;
			node->pre = clist;
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
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}	
	else
	{
		LinkedListNode* nlist = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
		}
		else
		{
			if (1 == pos)
			{
				nlist->data = elem;
				nlist->pre = nullptr;
				nlist->next = slist;	//指向下一个结点
				slist->pre = nlist;
				slist = nlist;//插入的结点作为新的头结点
			}
			else
			{
				int index = 1;
				LinkedListNode* clist = slist;
				for (clist = slist; index < pos && clist->next != nullptr; clist = clist->next, ++index);
				if (index == pos)
				{
					nlist->data = elem;
					nlist->next = clist;		//指向下一个结点
					nlist->pre = clist->pre;
					clist->pre->next = nlist;	//指向插入结点
					clist->pre = nlist;
				}
				else
				{
					cout << "插入位置 " << pos << " 超出链表长度" << index << " ，默认插入到尾结点"<< endl;
					nlist->data = elem;
					nlist->next = nullptr;
					nlist->pre = clist;
					clist->next = nlist;
				}
			}
		}

		return slist;
	}
}

//O(n)
LinkedList GetLinkedList(LinkedList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}	
	else
	{
		int index = 1;
		LinkedListNode* clist = slist;
		for (clist = slist; index < pos && clist->next != nullptr; clist = clist->next, ++index);
		
		if (index < pos)
		{
			cout << "寻找位置 " << pos << " 超出链表长度" << index << " ，默认输出尾结点" << endl;
		}

		return clist;
	}
}

//O(n)
LinkedList LinkedListDelete(LinkedList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}
	else
	{
		LinkedListNode* nlist = nullptr;
		if (1 == pos) //删除头结点
		{
			nlist = slist;
			slist = slist->next;
			free(nlist);
		}
		else
		{
			int index = 1;	//头结点位置
			LinkedListNode* clist = slist;//当前结点
			for (clist = slist; index < pos && clist->next != nullptr; clist = clist->next, ++index);
			if (index == pos)
			{
				nlist = clist;
				clist->next != nullptr ? clist->pre->next = clist->next : clist->pre->next = nullptr;
				clist->next != nullptr ? clist->next->pre = clist->pre : nullptr;
				free(nlist);
			}
			else
			{
				cout << "删除位置 " << pos << " 超出链表最大长度 " << index << endl;
			}

			return slist;
		}

		return slist;
	}
}

//O(n)
int GetLinkedListLength(LinkedList slist)
{
	if (nullptr == slist)
	{
		cout << "空链表" << endl;
		return 0;
	}
	else
	{
		int index = 1;
		LinkedListNode* clist = slist;
		for (clist = slist; clist->next != nullptr; clist = clist->next, ++index);

		return index;
	}
}

//O(n)
void DisplayLinkedList(LinkedList slist)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return;
	}

	LinkedListNode* p = slist;
	int count = 0;
	while (p)
	{
		cout << "第" << ++count << "个元素的值为: " << p->data << endl;
		p = p->next;
	}
}