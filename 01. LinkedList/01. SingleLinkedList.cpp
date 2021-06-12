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

		for (clist = slist; clist->next != nullptr; clist = clist->next);//寻找尾结点

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
				nlist->next = slist;//指向下一个结点
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
			cout << "插入位置 " << pos << " 超出链表长度" << index << " ，默认输出尾结点" << endl;
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
			LinkedListNode* plist = slist;//上一个结点
			LinkedListNode* clist = slist;//当前结点
			for (plist = slist, clist = slist; index < pos && clist->next != nullptr; plist = clist, clist = clist->next, ++index);
			if (index == pos)
			{
				nlist = clist;
				plist->next = clist->next;
				free(nlist);
			}
			else
			{
				cout << "查找位置 " << pos << " 超出链表最大长度 " << index << endl;
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
void display(LinkedList slist)
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