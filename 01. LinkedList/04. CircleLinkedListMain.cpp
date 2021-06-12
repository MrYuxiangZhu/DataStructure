// CircleLinkedList.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "CircleLinkedList.h"

using namespace std;

int main()
{
	CircleLinkedList clist = nullptr;
	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "��������б�" << endl;
	clist = CircleLinkedListCreate(clist, array[0]);
	clist = CircleLinkedListCreate(clist, array[1]);
	clist = CircleLinkedListCreate(clist, array[2]);
	clist = CircleLinkedListCreate(clist, array[3]);
	clist = CircleLinkedListCreate(clist, array[4]);

	cout << "��1��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist, 1)->data << endl;
	cout << "��2��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist, 2)->data << endl;
	cout << "��3��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist, 3)->data << endl;
	cout << "��4��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist, 4)->data << endl;
	cout << "��5��Ԫ�ص�ֵΪ: " << GetCircleLinkedList(clist, 5)->data << endl;

	cout << "������Ϊ: " << GetCircleLinkedListLength(clist) << endl;

	cout << "����Ԫ�غ���б�" << endl;
	clist = CircleLinkedListInsert(clist, 6, 6);
	clist = CircleLinkedListInsert(clist, 7, 4);

	DisplayCircleLinkedList(clist);

	cout << "������Ϊ: " << GetCircleLinkedListLength(clist) << endl;

	cout << "ɾ��Ԫ��" << endl;
	clist = CircleLinkedListDelete(clist, 1);
	clist = CircleLinkedListDelete(clist, 6);

	DisplayCircleLinkedList(clist);

	return 0;
}