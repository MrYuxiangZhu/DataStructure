// CircleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CircleLinkedList.h"

using namespace std;

int main()
{
	CircleLinkedList clist = nullptr;
	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "创建后的列表" << endl;
	clist = CircleLinkedListCreate(clist, array[0]);
	clist = CircleLinkedListCreate(clist, array[1]);
	clist = CircleLinkedListCreate(clist, array[2]);
	clist = CircleLinkedListCreate(clist, array[3]);
	clist = CircleLinkedListCreate(clist, array[4]);

	cout << "第1个元素的值为: " << GetCircleLinkedList(clist, 1)->data << endl;
	cout << "第2个元素的值为: " << GetCircleLinkedList(clist, 2)->data << endl;
	cout << "第3个元素的值为: " << GetCircleLinkedList(clist, 3)->data << endl;
	cout << "第4个元素的值为: " << GetCircleLinkedList(clist, 4)->data << endl;
	cout << "第5个元素的值为: " << GetCircleLinkedList(clist, 5)->data << endl;

	cout << "链表长度为: " << GetCircleLinkedListLength(clist) << endl;

	cout << "插入元素后的列表" << endl;
	clist = CircleLinkedListInsert(clist, 6, 6);
	clist = CircleLinkedListInsert(clist, 7, 4);

	DisplayCircleLinkedList(clist);

	cout << "链表长度为: " << GetCircleLinkedListLength(clist) << endl;

	cout << "删除元素" << endl;
	clist = CircleLinkedListDelete(clist, 1);
	clist = CircleLinkedListDelete(clist, 6);

	DisplayCircleLinkedList(clist);

	return 0;
}