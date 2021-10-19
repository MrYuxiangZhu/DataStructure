#include <iostream>
#include "CircleLinkedList.h"

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
			return slist->next; //返回尾结点
		}
	}
	else
	{
		CircleLinkedListNode* rlist = (CircleLinkedListNode*)malloc(sizeof(CircleLinkedListNode));
		if (nullptr == rlist)
		{
			cout << "创建结点失败" << endl;
		}
		else
		{
			rlist->data = elem;
			rlist->next = slist->next;
			slist->next = rlist;
		}

		return rlist; //返回尾结点
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
		CircleLinkedListNode* clist = slist;
		CircleLinkedListNode* rlist = slist;//存放尾指针
		CircleLinkedListNode* nlist = nullptr;

		int index = 1;	//头结点位置
		for (clist = slist; index < pos && clist->next != slist; clist = clist->next, ++index);//寻找当前结点
		if (index == pos)
		{
			clist->next == slist ? rlist = clist : //最后一个结点作为新的尾结点
								   rlist = slist;  //尾结点不变

			nlist = clist->next;	//暂存要删除的结点结点
			clist->next = clist->next->next;	//指向当前结点的下一个结点
			free(nlist);
		}
		else
		{
			cout << "删除位置 " << pos << " 超出链表最大长度 " << index << endl;
		}

		return rlist;
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
		CircleLinkedListNode* nlist = (CircleLinkedListNode*)malloc(sizeof(CircleLinkedListNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
			return slist;
		}
		else
		{
			int index = 1;	//头结点位置
			CircleLinkedListNode* clist = slist;
			for (clist = slist; index < pos && clist->next != slist; clist = clist->next, ++index);//寻找当前结点
			if (index == pos)	//在指定位置插入
			{
				nlist->data = elem;
				nlist->next = clist->next;	//插入结点下一个结点指向当前位置结点
				clist->next = nlist;	//上一个结点的下一个结点指向新结点
			}
			else
			{
				cout << "查找位置 " << pos << " 超出链表最大长度 " << index << "，默认插入到尾结点" << endl;
				nlist->data = elem;
				nlist->next = slist->next;	//插入结点下一个结点指向当前位置结点
				slist->next = nlist;		//尾结点指针域指向新结点
				slist = nlist;				//新结点作为新的尾结点
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

		return clist->next;
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
		cout << "第" << ++count << "个元素的值为: " << p->next->data << endl;
		p = p->next;
	}

	cout << "第" << ++count << "个元素的值为: " << p->next->data << endl;
}