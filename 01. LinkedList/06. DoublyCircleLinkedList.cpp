#include <iostream>
#include "DoublyCircleLinkedList.h"

using namespace std;

//O(n)
CircleLinkedList CircleLinkedListCreate(CircleLinkedList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		slist = (CircleLinkedListNode*)malloc(sizeof(CircleLinkedListNode));
		if (nullptr == slist)
		{
			cout << "创建链表头失败" << endl;
			return nullptr;
		}
		else
		{
			slist->data = elem;
			slist->next = slist;
			slist->pre = slist;
			return slist;
		}
	}
	else
	{
		CircleLinkedListNode* nlist = (CircleLinkedListNode*)malloc(sizeof(CircleLinkedListNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
		}
		else
		{
			CircleLinkedListNode* clist = slist;
			for (clist = slist; clist->next != slist; clist = clist->next);
			nlist->data = elem;
			nlist->pre = clist;			//指向当前结点
			nlist->next = clist->next;	//指向头结点
			clist->next = nlist;		//当前结点下个结点指向插入节点
			clist->next->pre = nlist;	//头结点上个结点指向插入节点
		}

		return slist;
	}
}

//O(n)
CircleLinkedList CircleLinkedListDelete(CircleLinkedList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}
	else
	{
		CircleLinkedListNode* nlist = nullptr;
		CircleLinkedListNode* clist = slist;
		if (1 == pos)
		{
			for (clist = slist; clist->next != slist; clist = clist->next);//找到尾结点
			nlist = slist;				//暂存头结点
			clist->next = slist->next;	//尾结点的下一个结点指向头结点的下一个结点
			slist->next->pre = clist;	//头结点的下一个结点指向当前结点
			slist = slist->next;		//头结点的下一个结点作为新的头结点
			free(nlist);
		}
		else
		{
			int index = 1;	//头结点位置
			for (clist = slist; index < pos && clist->next != slist; clist = clist->next, ++index);//寻找当前结点
			if (index == pos)
			{
				nlist = clist;	//暂存当前结点
				clist->pre->next = clist->next;	//上一个结点指向当前结点的下一个结点
				clist->next->pre = clist->pre;	//下一个结点指向当前结点的上一个结点
				free(nlist);
			}
			else
			{
				cout << "查找位置 " << pos << " 超出链表最大长度 " << index << endl;
			}
		}

		return slist;
	}
}

//O(n)
CircleLinkedList CircleLinkedListInsert(CircleLinkedList slist, ElemType elem, int pos)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}
	else
	{
		CircleLinkedListNode* clist = slist;
		CircleLinkedListNode* nlist = (CircleLinkedListNode*)malloc(sizeof(CircleLinkedListNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
			return slist;
		}
		else if (1 == pos)
		{
			for (clist = slist; clist->next != slist; clist = clist->next);//找到尾结点
			nlist->data = elem;
			nlist->pre = clist;		//新结点上一个结点指向当前结点
			nlist->next = slist;	//插入结点下一个结点指向头结点
			clist->next = nlist;	//尾结点下一个结点指向新结点
			slist->pre = nlist;		//头结点上一个结点指向新结点
			slist = nlist;			//插入结点作为新的头结点
			return slist;
		}
		else
		{
			int index = 1;	//头结点位置
			for (clist = slist; index < pos && clist->next != slist; clist = clist->next, ++index);//寻找当前结点
			if (index == pos)	//在指定位置插入
			{
				nlist->data = elem;
				nlist->pre = clist->pre;	//插入结点上一个结点指向当前结点的上一个结点
				nlist->next = clist;		//插入结点下一个结点指向当前位置结点
				clist->pre = nlist;			//当前结点的上一个结点指向新结点
				clist->pre->next = nlist;	//上一个结点的下一个结点指向新结点
			}
			else
			{
				cout << "查找位置 " << pos << " 超出链表最大长度 " << index << "，默认插入到尾结点"<< endl;
				nlist->data = elem;
				nlist->pre = clist;			//插入结点上一个结点指向当前结点
				nlist->next = clist->next;	//插入结点的下一个结点指向头结点
				clist->next->pre = nlist;	//当前结点的下一个结点的上一个结点指向新结点
				clist->next = nlist;		//当前结点的下一个结点指向新结点
			}

			return slist;
		}
	}
}

//O(n)
CircleLinkedList GetCircleLinkedList(CircleLinkedList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误，默认输出头结点" << endl;
		return slist;
	}
	else
	{
		int index = 1;
		CircleLinkedListNode* clist = slist;
		for (clist = slist; index < pos && clist->next != slist; clist = clist->next, ++index);//找到尾结点
		
		if (index < pos)
		{
			cout << "查找位置 " << pos << " 超出链表最大长度 " << index << "，默认输出尾结点" << endl;
		}

		return clist;
	}
}

//O(n)
int GetCircleLinkedListLength(CircleLinkedList slist)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return 0;
	}
	else
	{
		int index = 1;
		CircleLinkedListNode* clist = slist;
		for (clist = slist; clist->next != slist; clist = clist->next, ++index);//找到尾结点
		return index;
	}
}

//O(n)
void DisplayCircleLinkedList(CircleLinkedList slist)
{
	if (nullptr == slist)
	{
		cout << "输入空链表" << endl;
		return;
	}

	CircleLinkedListNode* p = slist;
	int count = 0;
	while (p->next != slist)
	{
		cout << "第" << ++count << "个元素的值为: " << p->data << endl;
		p = p->next;
	}

	cout << "第" << ++count << "个元素的值为: " << p->data << endl;
}