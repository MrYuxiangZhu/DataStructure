// SingleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
	LinkedList slist1 = nullptr;
	LinkedList slist2 = nullptr;
	int array[5] = { 1, 2, 3, 4, 5 };

	cout << "头差法" << endl;
	slist1 = LinkedListCreateByHeader(slist1, array[0]);
	slist1 = LinkedListCreateByHeader(slist1, array[1]);
	slist1 = LinkedListCreateByHeader(slist1, array[2]);
	slist1 = LinkedListCreateByHeader(slist1, array[3]);
	slist1 = LinkedListCreateByHeader(slist1, array[4]);
	display(slist1);

	cout << "头差法后链表长度: " << GetLinkedListLength(slist1) << endl;

	cout << "删除元素" << endl;
	slist1 = LinkedListDelete(slist1, array[2]);
	slist1 = LinkedListDelete(slist1, array[3]);

	slist1 = LinkedListCreateByHeader(slist1, array[2]);
	slist1 = LinkedListCreateByHeader(slist1, array[3]);
	display(slist1);

	cout << "尾插法" << endl;
	slist2 = LinkedListCreateByTail(slist2, array[0]);
	slist2 = LinkedListCreateByTail(slist2, array[1]);
	slist2 = LinkedListCreateByTail(slist2, array[2]);
	slist2 = LinkedListCreateByTail(slist2, array[3]);
	slist2 = LinkedListCreateByTail(slist2, array[4]);

	display(slist2);

	cout << "尾插法后链表长度: " << GetLinkedListLength(slist2) << endl;

	cout << "删除元素" << endl;
	slist2 = LinkedListDelete(slist2, 2);
	slist2 = LinkedListDelete(slist2, 3);

	display(slist2);

	cout << "插入元素" << endl;

	slist2 = LinkedListInsert(slist2, array[2], 1);
	slist2 = LinkedListInsert(slist2, array[2], 4);
	slist2 = LinkedListInsert(slist2, array[3], 6);

	display(slist2);

	cout << "第 5 个元素为：" << GetLinkedList(slist2, 5)->data << endl;
	cout << "第 6 个元素为：" << GetLinkedList(slist2, 6)->data << endl;
	cout << "第 7 个元素为：" << GetLinkedList(slist2, 7)->data << endl;

	return 0;
}
