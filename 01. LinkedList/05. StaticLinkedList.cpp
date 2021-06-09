#include <iostream>
#include "StaticLinkedList.h"

using namespace std;

//O(n)
StaticLinkedList* StaticLinkedList_Create(int capacity)
{
	//���������ڴ�����н���ڴ�
	LinkedList* tlist = (LinkedList*)malloc(sizeof(LinkedList) + sizeof(LinkedListNode) * (capacity + 1));
	if (nullptr == tlist)
	{
		cout << "��������ͷʧ��" << endl;
		return nullptr;
	}

	tlist->capacity = capacity;
	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = 0;
	tlist->node[0] = tlist->header;
	for (int i = 0; i < capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}

	return tlist;
}

//O(1)
void StaticLinkedList_Destroy(StaticLinkedList* list)
{
	if (nullptr == list)
	{
		cout << "�����������" << endl;
		return;
	}

	free(list);
}

//O(n)
void StaticLinkedList_Clear(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		cout << "�����������" << endl;
		return;
	}

	tlist->length = 0;
	tlist->header.data = 0;
	tlist->header.next = AVAILABLE;
	for (int i = 0; i <= tlist->capacity; ++i)
	{
		tlist->node[i].data = AVAILABLE;
		tlist->node[i].next = AVAILABLE;
	}
}

//O(1)
int StaticLinkedList_Length(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		return -1;
	}

	return tlist->length;
}

//O(1)
int StaticLinkedList_Capacity(StaticLinkedList* list)
{
	LinkedList* tlist = (LinkedList*)list;
	if (nullptr == tlist)
	{
		return -1;
	}

	return tlist->capacity;
}

//��ͷ���֮�����1...n
//O(n)
int StaticLinkedList_Insert(StaticLinkedList* list, StaticLinkedListNode* node, int pos)
{
	int current = 0;
	int index = 0;
	LinkedList* tlist = (LinkedList*)list;	//ԭ����

	if (nullptr == tlist || nullptr == node || pos <= 0 || tlist->length >= tlist->capacity)
	{
		cout << "�����������" << endl;
		return -1;
	}

	//node[0]��ͷ���
	for (int i = 0; i <= tlist->capacity; ++i)
	{
		if (tlist->node[i].next == AVAILABLE)
		{
			index = i + 1;
			break;
		}
	}

	tlist->node[index].data = *(ElemType*)node;
	
	for (int i = 1; i < pos; ++i)
	{
		current = tlist->node[current].next;
	}

	tlist->node[index].next = tlist->node[current].next;
	tlist->node[current].next = index;
	tlist->header = tlist->node[0];
	tlist->length++;

	return 0;
}

//O(n)
StaticLinkedListNode* StaticLinkedList_Get(StaticLinkedList* list, int pos)
{
	int current = 1;
	LinkedList* tlist = (LinkedList*)list;

	if (nullptr == list || pos < 0 || pos > tlist->length)
	{
		cout << "�����������" << endl;
		return nullptr;
	}

	//�߼����Ǵ�λ��1��n����
	for (int i = 1; (i < pos) && (tlist->node[current].next != 0); ++i)
	{
		current = tlist->node[current].next;
	}

	return &tlist->node[current].data;
}

//O(n)
StaticLinkedListNode* StaticLinkedList_Delete(StaticLinkedList* list, int pos)
{
	int current = 0;
	int index = 0;
	LinkedList* tlist = (LinkedList*)list;

	if (nullptr == list || pos <= 0 || tlist->length < 0)
	{
		cout << "�����������" << endl;
		return nullptr;
	}
	
	for (int i = 1; i < pos; ++i)
	{
		current = tlist->node[current].next;
	}

	index = tlist->node[current].next;
	tlist->node[current].next = tlist->node[index].next;
	tlist->node[index].next = AVAILABLE;
	tlist->length--;

	return &tlist->node[index].data;//����Ҫɾ���Ľ��
}
