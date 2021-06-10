// NewSingleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "NewSingleLinkedList.h"

using namespace std;

typedef struct _Teacher
{
	LinkedListNode node;
	char name[32];
	int age;
}Teacher;

int main()
{
	Teacher teacher[5] =
	{
		{{nullptr}, "teacher1", 20},
		{{nullptr}, "teacher2", 30},
		{{nullptr}, "teacher3", 40},
		{{nullptr}, "teacher4", 50},
		{{nullptr}, "teacher5", 60},
	};

	SingleLinkedList* TList = SingleLinkedListCreate();
	SingleLinkedListInsert(TList, &teacher[0], 1);
	SingleLinkedListInsert(TList, &teacher[1], 2);
	SingleLinkedListInsert(TList, &teacher[2], 3);
	SingleLinkedListInsert(TList, &teacher[3], 4);
	SingleLinkedListInsert(TList, &teacher[4], 5);

	cout << "插入后链表" << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 1))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 1))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 2))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 2))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 3))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 3))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 4))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 4))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 5))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 5))->age << endl;

	cout << "插入后的链表长度: " << GetSingleLinkedListLength(TList) << endl;

	SingleLinkedListDelete(TList, 3);
	SingleLinkedListDelete(TList, 4);

	cout << "删除后的链表" << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 1))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 1))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 2))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 2))->age << endl;
	cout << ((Teacher*)GetSingleLinkedList(TList, 3))->name << "'s age is " << ((Teacher*)GetSingleLinkedList(TList, 3))->age << endl;
	
	cout << "删除后的链表长度: " << GetSingleLinkedListLength(TList) << endl;

	cout << "清空链表" << endl;
	SingleLinkedListClear(TList);
	cout << "清空链表后的链表长度: " << GetSingleLinkedListLength(TList) << endl;

	SingleLinkedListDestroy(TList);

	return 0;
}
