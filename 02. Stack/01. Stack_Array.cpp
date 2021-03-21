// Stack_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>

#define MAX_NUM	100

using namespace std;

//结点设计
typedef struct
{
	int data[MAX_NUM];
	int top;
}Stack, *StackArray;

//创建
StackArray stack_init()
{
	Stack* sta = (Stack*)malloc(sizeof(Stack));
	if (NULL == sta) { return NULL; }
	memset(sta, 0, sizeof(Stack));
	sta->top = -1;
	return sta;
}

//入栈push
void push(Stack* sta, int data)
{
	sta->data[++(sta->top)] = data;
	cout << "入栈数据为" << sta->data[sta->top] << endl;
}

//出栈pop
void pop(Stack* sta)
{
	if (sta->top < 0) { return; }
	cout << "出栈数据为" << sta->data[sta->top] << endl;
	sta->data[sta->top--] = 0;	//将该数据清空
}

//打印栈元素
void display(Stack* sta)
{
	if (NULL == sta) { return; }
	if (-1 == sta->top) { return; }
	for (int cnt = sta->top; cnt >= 0; --cnt)
	{
		cout << "第" << cnt + 1 << "个元素为: " << sta->data[cnt] << endl;
	}
}

int main()
{
	int elem = 0;
	int length = 0;
	int pos = 1;
	Stack* stack = NULL;
	stack = stack_init();
	cout << "请输入压入栈元素个数" << endl;
	cin >> length;
	while (pos <= length)
	{
		cout << "请输入第" << pos++ << "个数据" << endl;
		cin >> elem;
		push(stack, elem);
	}

	display(stack);
	pop(stack);
	pop(stack);
	display(stack);

	return 0;
}
