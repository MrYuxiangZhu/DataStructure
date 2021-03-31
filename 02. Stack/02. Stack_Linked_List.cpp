// Stack_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define ElemType	int

//栈结点设计
//单个结点设计，数据和下一个指针
typedef struct ListNode
{
	ElemType data;
	struct ListNode* next;
}ListNode;

//创建栈，分别为头结点top指针和计数的count
typedef struct Stack
{
	ListNode* top;
	int count;
}Stack, *StackLinkedList;

//创建栈
StackLinkedList stack_linked_list_create()
{
	Stack* sta = NULL;
	sta = (Stack*)malloc(sizeof(Stack));
	if (NULL == sta) 
	{ 
		printf("创建失败！");
	}
	else
	{
		sta->count = 0;
		sta->top = NULL;
	}

	return sta;
}

//压栈
StackLinkedList push_stack(Stack* sta, ElemType elem)
{
	if (NULL == sta) { return NULL; }
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->data = elem;
	ptr->next = sta->top;	//先入栈的放在最下面
	sta->top = ptr;
	sta->count++;

	return sta;
}

//出栈
StackLinkedList pop_stack(Stack* sta)
{
	if (NULL == sta->top) 
	{
		cout << "栈错误!" << endl;
		return NULL; 
	}

	ListNode* ptr = NULL;
	ptr = sta->top;
	cout << "pop : " << ptr->data << endl;
	sta->top = sta->top->next;
	free(ptr);
	sta->count--;

	return sta;
}

//遍历栈，输出栈的所有元素
void show_stack(Stack* sta)
{
	if (NULL == sta->top)
	{
		cout << "栈错误!" << endl;
		return;
	}

	ListNode* ptr = NULL;
	ptr = sta->top;

	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}

int main()
{
	Stack* sta = NULL;
	sta = stack_linked_list_create();
	int n = 5;
	int input[6] = {10, 20, 30, 40, 50, 60};
	for (int i = 0; i < 5; ++i)
	{
		push_stack(sta, input[i]);
	}

	show_stack(sta);
	pop_stack(sta);
	show_stack(sta);

	return 0;
}