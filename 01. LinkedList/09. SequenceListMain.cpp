#include <iostream>
#include "SequenceList.h"
using namespace std;

int main()
{
	SqList List;
	InitSqList(List);
	std::cout << "插入顺序表" << std::endl;
	InsertElem(List, 1, 1);
	InsertElem(List, 2, 2);
	InsertElem(List, 3, 3);
	display(List);
	std::cout << "查找顺序表元素" << std::endl;
	std::cout << "元素序号：" << LocateElem(List, 3) << std::endl;
	std::cout << "删除顺序表" << std::endl;
	DeleteElem(List, 2);
	display(List);
	return 0;
}
