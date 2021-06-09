// 静态链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StaticLinkedList.h"

using namespace std;

#define LISTMAX	10

int main()
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	StaticLinkedList* LinkedList = StaticLinkedList_Create(LISTMAX);
	StaticLinkedList_Insert(LinkedList, &array[0], 1);
	StaticLinkedList_Insert(LinkedList, &array[1], 2);
	StaticLinkedList_Insert(LinkedList, &array[2], 3);
	StaticLinkedList_Insert(LinkedList, &array[3], 4);
	StaticLinkedList_Insert(LinkedList, &array[4], 5);
	StaticLinkedList_Insert(LinkedList, &array[5], 6);
	cout << "链表插入后" << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 1) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 2) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 3) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 4) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 5) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 6) << endl;
	cout << "链表删除后" << endl;
	*(int*)StaticLinkedList_Delete(LinkedList, 3) = 0;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 1) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 2) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 3) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 4) << endl;
	cout << *(int*)StaticLinkedList_Get(LinkedList, 5) << endl;
	return 0;
}
