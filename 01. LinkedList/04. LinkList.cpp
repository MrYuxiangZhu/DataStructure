#include "LinkList.h"

using namespace std;

//O(1)
LinkList* LinkList_Create()
{
	TLinkList* tlist = (TLinkList*)malloc(sizeof(TLinkList));
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
void List_Destroy(LinkList* list)
{
	if (nullptr == list)
	{
		return;
	}

	free(list);
}

//O(1)
void LinkList_Clear(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (nullptr == tlist)
	{
		return;
	}

	tlist->length = 0;
	tlist->header.next = nullptr;
}

//O(1)
int LinkList_Length(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (nullptr == tlist)
	{
		return -1;
	}

	return tlist->length;
}

//从头结点之后插入
//O(n)
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	if (nullptr == list || nullptr == node || pos < 0)
	{
		return -1;
	}

	TLinkList* tlist = (TLinkList*)list;	//原链表
	LinkListNode* clist = &tlist->header; //当前结点

	for (int i = 0; (i < pos) && (nullptr != clist); ++i)
	{
		clist = clist->next;
	}

	node->next = clist->next;//1
	clist->next = node; //2
	tlist->length++;

	return 0;
}

//O(n)
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	if (nullptr == list || pos < 0)
	{
		return nullptr;
	}

	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* clist = &tlist->header;

	for (int i = 0; i < pos; ++i)
	{
		clist = clist->next;
	}

	return clist->next;
}

//O(n)
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* tlist = (TLinkList*)list;

	if (nullptr == list || pos < 0 || tlist->length < 0)
	{
		return nullptr;
	}
	
	LinkListNode* clist = &tlist->header;
	LinkListNode* temp = nullptr;
	for (int i = 0; i < pos; ++i)
	{
		clist = clist->next;
	}
	temp = clist->next;
	clist->next = clist->next->next;
	tlist->length--;

	return temp;//返回要删除的结点
}
