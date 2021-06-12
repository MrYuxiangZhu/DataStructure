// StackLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StackList.h"

using namespace std;

typedef struct _Teacher
{
	LinkedListNode* node;
	int age;
}Teacher;

int main()
{
	StackList* stack = StackListCreate();
	Teacher teacher[5] =
	{
		{ nullptr, 10 },
		{ nullptr, 20 },
		{ nullptr, 30 },
		{ nullptr, 40 },
		{ nullptr, 50 }
	};
	
	StackListPush(stack, &teacher[0]);
	StackListPush(stack, &teacher[1]);
	StackListPush(stack, &teacher[2]);
	StackListPush(stack, &teacher[3]);
	StackListPush(stack, &teacher[4]);
	cout << (*(Teacher*)StackListPop(stack)).age << endl;
	cout << (*(Teacher*)StackListPop(stack)).age << endl;
	cout << (*(Teacher*)StackListPop(stack)).age << endl;
	cout << (*(Teacher*)StackListPop(stack)).age << endl;
	cout << (*(Teacher*)StackListPop(stack)).age << endl;
	return 0;
}
