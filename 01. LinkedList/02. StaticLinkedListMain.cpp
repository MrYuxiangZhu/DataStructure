// StaticLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StaticLinkedList.h"

using namespace std;

int main()
{
	StaticLinkedList* LinkedList = nullptr;
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkedList = StaticLinkedListCreate(10);
	StaticLinkedListInsert(LinkedList, &array[0], 1);
	StaticLinkedListInsert(LinkedList, &array[1], 2);
	StaticLinkedListInsert(LinkedList, &array[2], 3);
	StaticLinkedListInsert(LinkedList, &array[3], 4);
	StaticLinkedListInsert(LinkedList, &array[4], 5);
	cout << "链表长度：" << GetStaticLinkedListLength(LinkedList) << endl;
	cout << "插入后链表" << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 1) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 2) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 3) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 4) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 5) << endl;
	cout << "删除后链表" << endl;
	*(int*)StaticLinkedListDelete(LinkedList, 1) = AVAILABLE;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 1) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 2) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 3) << endl;
	cout << *(int*)GetStaticLinkedListNode(LinkedList, 4) << endl;
	cout << "链表长度：" << GetStaticLinkedListLength(LinkedList) << endl;
	cout << "清空链表" << endl;
	StaticLinkedListClear(LinkedList);
	cout << "链表长度：" << GetStaticLinkedListLength(LinkedList) << endl;
	return 0;
}
