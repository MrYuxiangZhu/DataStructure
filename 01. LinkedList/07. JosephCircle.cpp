#include <iostream>
#include "JosephCircle.h"

using namespace std;

//O(n)
JosephCircleList JosephCircleListCreate(JosephCircleList slist, ElemType elem)
{
	if (nullptr == slist)
	{
		slist = (JosephCircleNode*)malloc(sizeof(JosephCircleNode));
		if (nullptr == slist)
		{
			cout << "创建链表头失败" << endl;
			return nullptr;
		}
		else
		{
			slist->person = elem;
			slist->next = slist;
			slist->pre = slist;
			return slist;
		}
	}
	else
	{
		JosephCircleNode* nlist = (JosephCircleNode*)malloc(sizeof(JosephCircleNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
		}
		else
		{
			JosephCircleNode* clist = slist;
			for (clist = slist; clist->next != slist; clist = clist->next);
			nlist->person = elem;
			nlist->pre = clist;			//指向当前结点
			nlist->next = clist->next;	//指向头结点
			clist->next->pre = nlist;	//头结点上个结点指向插入节点
			clist->next = nlist;		//当前结点下个结点指向插入节点
		}

		return slist;
	}
}

//O(n)
JosephCircleList JosephCircleListDelete(JosephCircleList slist, int pos)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}
	else
	{
		JosephCircleNode* nlist = nullptr;
		JosephCircleNode* clist = slist;

		int index = 1;	//头结点位置
		for (clist = slist; index < pos; clist = clist->next, ++index);//寻找当前结点

		nlist = clist;	//暂存当前结点
		clist->pre->next = clist->next;	//上一个结点指向当前结点的下一个结点
		clist->next->pre = clist->pre;	//下一个结点指向当前结点的上一个结点
		clist != clist->next ? slist = clist->next : slist = nullptr;
		cout << "出局人的编号为: " << nlist->person << endl;
		free(nlist);
		return slist;
	}
}

//O(n)
JosephCircleList JosephCircleListInsert(JosephCircleList slist, ElemType elem, int pos)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return nullptr;
	}
	else if (pos <= 0)
	{
		cout << "输入位置错误" << endl;
		return slist;
	}
	else
	{
		JosephCircleNode* clist = slist;
		JosephCircleNode* nlist = (JosephCircleNode*)malloc(sizeof(JosephCircleNode));
		if (nullptr == nlist)
		{
			cout << "创建结点失败" << endl;
			return slist;
		}
		else if (1 == pos)
		{
			for (clist = slist; clist->next != slist; clist = clist->next);//找到尾结点
			nlist->person = elem;
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
				nlist->person = elem;
				nlist->pre = clist->pre;	//插入结点上一个结点指向当前结点的上一个结点
				nlist->next = clist;		//插入结点下一个结点指向当前位置结点
				clist->pre->next = nlist;	//上一个结点的下一个结点指向新结点
				clist->pre = nlist;			//当前结点的上一个结点指向新结点
			}
			else
			{
				cout << "查找位置 " << pos << " 超出链表最大长度 " << index << "，默认插入到尾结点"<< endl;
				nlist->person = elem;
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
JosephCircleList GetJosephCircleListHeader(JosephCircleList slist, ElemType hperson)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return nullptr;
	}
	else
	{
		JosephCircleNode* clist = slist;

		for (clist = slist; clist->person != hperson && clist->next != slist; clist = clist->next);//找到头结点

		return clist;
	}
}

//O(n)
int GetJosephCircleListLength(JosephCircleList slist)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return 0;
	}
	else
	{
		int index = 1;
		JosephCircleNode* clist = slist;
		for (clist = slist; clist->next != slist; clist = clist->next, ++index);//找到尾结点
		return index;
	}
}

//O(n)
void JosephCircleKickOut(JosephCircleList slist, ElemType hperson, int key)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return;
	}
	else
	{
		slist = GetJosephCircleListHeader(slist, hperson);
		while (nullptr != slist)
		{
			slist = JosephCircleListDelete(slist, key);
		}
	}
}

//O(n)
void DisplayJosephCircleList(JosephCircleList slist)
{
	if (nullptr == slist)
	{
		cout << "输入空约瑟夫环" << endl;
		return;
	}

	JosephCircleNode* p = slist;
	int count = 0;
	while (p->next != slist)
	{
		cout << "第" << ++count << "个人的编号为: " << p->person << endl;
		p = p->next;
	}

	cout << "第" << ++count << "个人的编号为: " << p->person << endl;
}