#pragma once

#define AVAILABLE (-1)

typedef int	 ElemType;				//��������
typedef int	 PointType;				//ָ������
typedef void StaticLinkedList;		//����void����
typedef void StaticLinkedListNode;	//����void����

typedef struct _LinkedListNode
{
	ElemType data;		//�洢������
	PointType next;		//��һ���ռ�
}LinkedListNode;

typedef struct _LinkedList
{
	int length;				//������
	int capacity;			//����
	LinkedListNode header;	//����ͷ
	LinkedListNode node[];	//������
}LinkedList;

StaticLinkedList* StaticLinkedList_Create(int capacity);

void StaticLinkedList_Destroy(StaticLinkedList* list);

void StaticLinkedList_Clear(StaticLinkedList* list);

int StaticLinkedList_Length(StaticLinkedList* list);

int StaticLinkedList_Capacity(StaticLinkedList* list);

int StaticLinkedList_Insert(StaticLinkedList* list, StaticLinkedListNode* node, int pos);

StaticLinkedListNode* StaticLinkedList_Get(StaticLinkedList* list, int pos);

StaticLinkedListNode* StaticLinkedList_Delete(StaticLinkedList* list, int pos);
