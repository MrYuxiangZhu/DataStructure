// DoublyCircleLinkedList.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "DoublyCircleLinkedList.h"

using namespace std;

int main()
{
	CircleLinkedList clist1 = nullptr;
	CircleLinkedList clist2 = nullptr;

	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "��������б�" << endl;
	clist1 = CircleLinkedListCreate(clist1, array[0]);
	clist1 = CircleLinkedListCreate(clist1, array[1]);
	clist1 = CircleLinkedListCreate(clist1, array[2]);
	clist1 = CircleLinkedListCreate(clist1, array[3]);
	clist1 = CircleLinkedListCreate(clist1, array[4]);

	cout << "��1��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist1, 1)->data << endl;
	cout << "��2��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist1, 2)->data << endl;
	cout << "��3��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist1, 3)->data << endl;
	cout << "��4��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist1, 4)->data << endl;
	cout << "��5��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist1, 5)->data << endl;

	cout << "������Ϊ: " << GetCircleLinkedListLength(clist1) << endl;

	cout << "����Ԫ�غ���б�" << endl;
	clist1 = CircleLinkedListInsert(clist1, 6, 6);
	clist1 = CircleLinkedListInsert(clist1, 7, 4);

	DisplayCircleLinkedList(clist1);

	cout << "������Ϊ: " << GetCircleLinkedListLength(clist1) << endl;

	cout << "ɾ��Ԫ��" << endl;
	clist1 = CircleLinkedListDelete(clist1, 1);
	clist1 = CircleLinkedListDelete(clist1, 6);

	DisplayCircleLinkedList(clist1);

	cout << "����Ԫ�غ���б�" << endl;
	clist2 = CircleLinkedListCreate(clist2, 1);
	clist2 = CircleLinkedListInsert(clist2, 2, 2);
	clist2 = CircleLinkedListInsert(clist2, 3, 3);
	clist2 = CircleLinkedListInsert(clist2, 4, 4);
	clist2 = CircleLinkedListInsert(clist2, 5, 5);
	cout << "��5��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist2, 1)->pre->data << endl;
	cout << "��4��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist2, 1)->pre->pre->data << endl;
	cout << "��3��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->data << endl;
	cout << "��2��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->pre->data << endl;
	cout << "��1��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->pre->pre->data << endl;

	return 0;
}