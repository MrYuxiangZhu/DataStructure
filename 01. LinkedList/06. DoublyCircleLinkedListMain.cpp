// DoublyCircleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DoublyCircleLinkedList.h"

using namespace std;

int main()
{
	CircleLinkedList clist1 = nullptr;
	CircleLinkedList clist2 = nullptr;

	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "创建后的列表" << endl;
	clist1 = CircleLinkedListCreate(clist1, array[0]);
	clist1 = CircleLinkedListCreate(clist1, array[1]);
	clist1 = CircleLinkedListCreate(clist1, array[2]);
	clist1 = CircleLinkedListCreate(clist1, array[3]);
	clist1 = CircleLinkedListCreate(clist1, array[4]);

	cout << "第1个元素的值为: " << GetCircleLinkedList(clist1, 1)->data << endl;
	cout << "第2个元素的值为: " << GetCircleLinkedList(clist1, 2)->data << endl;
	cout << "第3个元素的值为: " << GetCircleLinkedList(clist1, 3)->data << endl;
	cout << "第4个元素的值为: " << GetCircleLinkedList(clist1, 4)->data << endl;
	cout << "第5个元素的值为: " << GetCircleLinkedList(clist1, 5)->data << endl;

	cout << "链表长度为: " << GetCircleLinkedListLength(clist1) << endl;

	cout << "插入元素后的列表" << endl;
	clist1 = CircleLinkedListInsert(clist1, 6, 6);
	clist1 = CircleLinkedListInsert(clist1, 7, 4);

	DisplayCircleLinkedList(clist1);

	cout << "链表长度为: " << GetCircleLinkedListLength(clist1) << endl;

	cout << "删除元素" << endl;
	clist1 = CircleLinkedListDelete(clist1, 1);
	clist1 = CircleLinkedListDelete(clist1, 6);

	DisplayCircleLinkedList(clist1);

	cout << "插入元素后的列表" << endl;
	clist2 = CircleLinkedListCreate(clist2, 1);
	clist2 = CircleLinkedListInsert(clist2, 2, 2);
	clist2 = CircleLinkedListInsert(clist2, 3, 3);
	clist2 = CircleLinkedListInsert(clist2, 4, 4);
	clist2 = CircleLinkedListInsert(clist2, 5, 5);
	cout << "第5个元素的值为: " << GetCircleLinkedList(clist2, 1)->pre->data << endl;
	cout << "第4个元素的值为: " << GetCircleLinkedList(clist2, 1)->pre->pre->data << endl;
	cout << "第3个元素的值为: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->data << endl;
	cout << "第2个元素的值为: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->pre->data << endl;
	cout << "第1个元素的值为: " << GetCircleLinkedList(clist2, 1)->pre->pre->pre->pre->pre->data << endl;

	return 0;
}