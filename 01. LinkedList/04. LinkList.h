#pragma once
#include <iostream>

typedef void LinkList;	//定义void类型

typedef struct _LinkListNode
{
	struct _LinkListNode* next;
}LinkListNode;

typedef struct _TLinkList
{
	LinkListNode header;
	int	 length;
}TLinkList;

LinkList* LinkList_Create();

void List_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);
