#pragma once

#define ElemType int

//����������
typedef struct _LinkedListNode
{
	int data;						//��������
	struct _LinkedListNode* next;	//ָ��ֱ�Ӻ��Ԫ�ص�ָ��
}LinkedListNode, *LinkedList;//List_Node��ʾ�������ͣ�LinkedList��ʾָ��List_Node������͵�ָ������

LinkedList LinkedListInit(); //��ʼ������

LinkedList LinkedListCreateByHeader(LinkedList slist, ElemType elem);//ͷ�巨����������

LinkedList LinkedListCreateByTail(LinkedList slist, ElemType elem);  //β�巨����������

LinkedList LinkedListDelete(LinkedList slist, ElemType elem);		//ɾ���������

int GetLinkedListLength(LinkedList slist);	//��ȡ��������

void display(LinkedList slist);


