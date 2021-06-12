// JosephCircle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "JosephCircle.h"

using namespace std;

int main()
{
	JosephCircleList joseph = nullptr;
	int person = 0;
	int key = 0;
	int array[5] = { 1, 2, 3, 4, 5 };
	joseph = JosephCircleListCreate(joseph, array[0]);
	joseph = JosephCircleListCreate(joseph, array[1]);
	joseph = JosephCircleListCreate(joseph, array[2]);
	joseph = JosephCircleListCreate(joseph, array[3]);
	joseph = JosephCircleListCreate(joseph, array[4]);

	//cout << joseph << endl;
	//cout << joseph->pre << endl;
	//cout << joseph->next << endl;
	//cout << joseph->next->pre << endl;
	//cout << joseph->next->next << endl;
	//cout << joseph->next->next->pre << endl;
	//cout << joseph->next->next->next << endl;
	//cout << joseph->next->next->next->pre << endl;
	//cout << joseph->next->next->next->next << endl;
	//cout << joseph->next->next->next->next->pre << endl;
	//cout << joseph->next->next->next->next->next << endl;
	cout << "从第几个人开始报数(k>1且k<5): ";
	cin >> person;
	cout << endl;

	cout << "数到几的人出列: ";
	cin >> key;
	cout << endl;

	JosephCircleKickOut(joseph, person, key);
	return 0;
}
