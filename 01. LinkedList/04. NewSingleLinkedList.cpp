#include <iostream>
#include "NewSingleLinkedList.h"

using namespace std;

//O(1)
SingleLinkedList* SingleLinkedListCreate()
{
	LinkedList* tlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (nullptr == tlist)
	{
		cout << "��������ʧ��" << endl;
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
		cout << "������" << endl;
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
		cout << "������" << endl;
		return ERROR;
	}

	return tlist->length;
}

//O(n)
int SingleLinkedListInsert(SingleLinkedList* slist, SingleLinkedListNode* node, int pos)
{
	if (nullptr == slist || nullptr == node || pos <= 0)
	{
		cout << "�����������" << endl;
		return ERROR;
	}

	LinkedList* tlist = (LinkedList*)slist;
	LinkedListNode* plist = (LinkedListNode*)node;
	LinkedListNode* clist = &tlist->header;//ͷ���
	
	for (int i = 1; (i < pos) && (nullptr != clist); ++i)
	{
		clist = clist->next;//����һ������ƶ�
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
		cout << "�����������" << endl;
		return nullptr;
	}
	
	LinkedListNode* clist = &tlist->header;

	for (int i = 1; (i < pos) && (nullptr != clist); ++i)
	{
		clist = clist->next;//����һ������ƶ�
	}

	return clist->next;
}

//O(n)
SingleLinkedListNode* SingleLinkedListDelete(SingleLinkedList* slist, int pos)
{
	LinkedList* tlist = (LinkedList*)slist;

	if (nullptr == tlist || pos <= 0 || pos > tlist->length)
	{
		cout << "�����������" << endl;
		return nullptr;
	}

	LinkedListNode* clist = &tlist->header;//ָ��ͷ���
	LinkedListNode* plist = nullptr;
	for (int i = 1; i < pos; ++i)
	{
		clist = clist->next;	//����һ������ƶ�
	}

	plist = clist->next;		//��Ҫɾ���Ľ��
	clist->next = plist->next;	//��Ҫɾ���Ľ��ָ�����һ�����
	tlist->length--;			//�����ȼ�һ

	return plist;
}