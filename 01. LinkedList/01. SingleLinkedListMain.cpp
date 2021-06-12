// SingleLinkedList.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
	LinkedList slist1 = nullptr;
	LinkedList slist2 = nullptr;
	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "ͷ�" << endl;
	slist1 = LinkedListCreateByHeader(slist1, array[0]);
	slist1 = LinkedListCreateByHeader(slist1, array[1]);
	slist1 = LinkedListCreateByHeader(slist1, array[2]);
	slist1 = LinkedListCreateByHeader(slist1, array[3]);
	slist1 = LinkedListCreateByHeader(slist1, array[4]);
	display(slist1);

	cout << "ͷ���������: " << GetLinkedListLength(slist1) << endl;

	cout << "ɾ��Ԫ��" << endl;
	slist1 = LinkedListDelete(slist1, array[2]);
	slist1 = LinkedListDelete(slist1, array[3]);

	slist1 = LinkedListCreateByHeader(slist1, array[2]);
	slist1 = LinkedListCreateByHeader(slist1, array[3]);
	display(slist1);

	cout << "β�巨" << endl;
	slist2 = LinkedListCreateByTail(slist2, array[0]);
	slist2 = LinkedListCreateByTail(slist2, array[1]);
	slist2 = LinkedListCreateByTail(slist2, array[2]);
	slist2 = LinkedListCreateByTail(slist2, array[3]);
	slist2 = LinkedListCreateByTail(slist2, array[4]);

	display(slist2);

	cout << "β�巨��������: " << GetLinkedListLength(slist2) << endl;

	cout << "ɾ��Ԫ��" << endl;
	slist2 = LinkedListDelete(slist2, 2);
	slist2 = LinkedListDelete(slist2, 3);

	display(slist2);

	cout << "����Ԫ��" << endl;

	slist2 = LinkedListInsert(slist2, array[2], 1);
	slist2 = LinkedListInsert(slist2, array[2], 4);
	slist2 = LinkedListInsert(slist2, array[3], 6);

	display(slist2);

	cout << "�� 5 ��Ԫ��Ϊ��" << GetLinkedList(slist2, 5)->data << endl;
	cout << "�� 6 ��Ԫ��Ϊ��" << GetLinkedList(slist2, 6)->data << endl;
	cout << "�� 7 ��Ԫ��Ϊ��" << GetLinkedList(slist2, 7)->data << endl;

	return 0;
}
