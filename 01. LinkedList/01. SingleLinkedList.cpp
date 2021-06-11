﻿#include <iostream>
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

//O(n)
LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem)
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
			header->next = nullptr;
			return header;
		}
	}
	else
	{
		LinkedListNode* header = slist;
		LinkedListNode* clist = slist;
		while (nullptr != clist->next)//寻找空结点
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

//O(1)
LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem)
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
			header->next = nullptr;
			return header;
		}
	}
	else
	{
		LinkedListNode* clist = slist;

		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (nullptr == node)
		{
			cout << "创建结点失败" << endl;
			return nullptr;
		}
		else
		{
			node->data = elem;
			node->next = clist;
			header = node;
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
				nlist->next = slist->next;	//指向下一个结点
				slist = nlist;//插入的结点作为新的头结点
			}
			else
			{
				int index = 1;
				LinkedListNode* plist = slist;
				LinkedListNode* clist = slist;
				for (plist = slist, clist = slist; index < pos && clist->next != nullptr; plist = clist, clist = clist->next, ++index);
				if (index == pos)
				{
					nlist->data = elem;
					nlist->next = clist; //指向下一个结点
					plist->next = nlist;
				}
				else
				{
					cout << "插入位置 " << pos << " 超出链表长度" << index << " ，默认插入到尾结点"<< endl;
					nlist->data = elem;
					nlist->next = nullptr;
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
	else
	{
		int index = 1;
		LinkedListNode* clist = slist;
		for (clist = slist; index < pos && clist->next != nullptr; clist = clist->next, ++index);
		
		if (index < pos)
		{
			cout << "插入位置 " << pos << " 超出链表长度" << index << " ，默认输出尾结点" << endl;
		}

		return clist;
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
		LinkedListNode* plist = slist;//上一个结点
		LinkedListNode* clist = slist;//当前结点
		LinkedListNode* tlist = nullptr;
		while (nullptr != clist)
		{
			if (elem == clist->data)
			{
				FindFlag = true;
				break;
			}
			else
			{
				plist = clist;
				clist = clist->next;
			}
		}

		if (FindFlag)
		{
			if (clist == slist)
			{
				tlist = slist;
				slist = slist->next;
			}
			else
			{
				tlist = clist;
				plist->next = clist->next;
			}

			cout << "元素 " << elem << " 删除成功" << endl;
			free(tlist);
		}
		else
		{
			cout << "未找到该元素" << endl;
		}

		return slist;
	}
}

//O(n)
int GetLinkedListLength(LinkedList slist)
{
	LinkedListNode* p = slist;
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
	while (p)
	{
		cout << "第" << ++count << "个元素的值为: " << p->data << endl;
		p = p->next;
	}
}