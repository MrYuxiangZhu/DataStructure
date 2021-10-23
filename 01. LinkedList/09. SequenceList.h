#pragma once
#include <iostream>

#define OK				0
#define ERROR			-1
#define MAX_SIZE		100 /*存储空间最大分配量*/
typedef int ElemType;		/*设定数据元素类型*/
typedef int Status;			/*函数结果状态，如OK*/

typedef struct
{
	ElemType data[MAX_SIZE];/*数组存储数据元素*/
	int length;	/*线性表当前长度*/
}SqList;

/*初始化顺序表*/
Status InitSqList(SqList& List);
/*获取顺序表中元素*/
Status GetElem(const SqList List, int i, ElemType& elem);
/*顺序表中插入元素*/
Status InsertElem(SqList& List, int i, ElemType elem);
/*在顺序表中查找元素elem，返回序号*/
Status LocateElem(const SqList List, ElemType elem);
/*顺序表中删除第i元素*/
Status DeleteElem(SqList& List, int i);
/*显示顺序表*/
void display(SqList& List);