#pragma once

#define ElemType int

//����������
typedef struct _LinkedListNode
{
	int data;						//��������
	struct _LinkedListNode* pre;	//ָ��ֱ��ǰ��Ԫ�ص�ָ��
	struct _LinkedListNode* next;	//ָ��ֱ�Ӻ��Ԫ�ص�ָ��
}LinkedListNode, *LinkedList;//List_Node��ʾ�������ͣ�LinkedList��ʾָ��List_Node������͵�ָ������

LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem);//ͷ�巨����˫������

LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem);  //β�巨����˫������

LinkedList LinkedListInsert(LinkedList slist, ElemType elem, int pos);//������

LinkedList GetLinkedList(LinkedList slist, int pos);//��ȡ���

LinkedList LinkedListDelete(LinkedList slist, int pos);		//ɾ��������

int GetLinkedListLength(LinkedList slist);	//��ȡ������

void DisplayLinkedList(LinkedList slist);



