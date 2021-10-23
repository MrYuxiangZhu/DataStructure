// SequenceList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "SequenceList.h"

Status InitSqList(SqList& List)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		List.data[i] = 0;
	}

	List.length = 0;
	return OK;
}

Status GetElem(const SqList List, int i, ElemType& elem)
{
	if (i < 1 || i > List.length)
	{
		std::cout << "输入位置错误" << std::endl;
		return ERROR;
	}
	elem = List.data[i - 1];

	return OK;
}

Status InsertElem(SqList& List, int i, ElemType elem)
{
	if (List.length == MAX_SIZE) /*顺序线性表已满*/
	{
		std::cout << "顺序线性表已满" << std::endl;
		return ERROR;
	}

	if (i < 1 || i  > List.length + 1) /*当i不在范围内时*/
	{
		std::cout << "输入位置错误" << std::endl;
		return ERROR;
	}

	if (i <= List.length) /*若插入数据不在表尾*/
	{
		for (int k = List.length - 1; k >= i - 1; --k) /*将要插入位置后的数据元素向后移动一位*/
		{
			List.data[k + 1] = List.data[k];
		}

	}
	List.data[i - 1] = elem;/*将新元素插入*/
	List.length++;
	return OK;
}

Status LocateElem(const SqList List, ElemType elem)
{
	for (int i = 0; i < List.length; ++i)
	{
		if (List.data[i] == elem) //查找成功，返回序号i + 1
		{
			return i + 1;
		}
	}

	return ERROR;	//查找失败，返回ERROR
}

Status DeleteElem(SqList& List, int i)
{
	if (i < 1 || i > List.length)
	{
		std::cout << "输入位置错误" << std::endl;
		return ERROR;
	}

	for (int k = i - 1; k < List.length - 1; ++k) /*被删除元素之后的元素前移一位*/
	{
		List.data[k] = List.data[k + 1];
	}

	List.length--;

	return OK;
}

void display(SqList& List)
{
	std::cout << "顺序表为：";
	for (int i = 0; i < List.length; ++i)
	{
		std::cout << List.data[i] << " ";
	}

	std::cout << std::endl;
}
