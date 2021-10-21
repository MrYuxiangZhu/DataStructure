#include <stack>
#include "JudgeLinkedListIntersect.h"

using namespace std;

bool LinkedListIntersectByEnum(LinkedList List1, LinkedList List2)
{
	LinkedList p1 = List1;
	LinkedList p2 = List2;
	//逐个遍历 L1 链表中的各个节点
	while (p1)
	{
		//遍历 L2 链表，针对每个 p1，依次和 p2 所指节点做比较
		while (p2)
		{
			//p1、p2 中记录的就是各个节点的存储地址，直接比较即可
			if (p1 == p2)
			{
				return true;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	return false;
}

bool LinkedListIntersectByStack(LinkedList List1, LinkedList List2)
{
	stack<LinkedListNode*> sta1;
	stack<LinkedListNode*> sta2;
	while (List1)
	{
		sta1.push(List1);
		List1 = List1->next;
	}

	while (List2)
	{
		sta2.push(List2);
		List2 = List2->next;
	}

	while (!sta1.empty() && !sta2.empty())
	{
		if (sta1.top() == sta2.top())
		{
			return true;
		}
		sta1.pop();
		sta2.pop();
	}

	return false;
}

bool LinkedListIntersectByLength(LinkedList List1, LinkedList List2)
{
	LinkedList pLong = List1;
	LinkedList pShort = List2;
	LinkedList pTemp = nullptr;
	int lens1 = 0;
	int lens2 = 0;

	while (pLong)
	{
		pLong = pLong->next;
		lens1++;
	}

	while (pShort)
	{
		pShort = pShort->next;
		lens2++;
	}

	// 重置pLong和pShort，使pLong代表较长的链表，pShort代表较短的链表
	int diff = abs(lens1 - lens2);

	if (lens1 < lens2)
	{
		pLong = List2;
		pShort = List1;
	}
	else
	{
		pLong = List1;
		pShort = List2;
	}

	//在pLong链表中找到和pShort等长度的子链表
	pTemp = pLong;

	while (diff && pTemp)
	{
		pTemp = pTemp->next;
		diff;
	}

	//逐个比较pTemp和pShort链表中的节点是否相同
	while (pTemp && pShort)
	{
		if (pTemp == pShort)
		{
			return true;
		}

		pTemp = pTemp->next;
		pShort = pShort->next;
	}

	return false;
}