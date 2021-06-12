#pragma once

#define ERROR (-1)
#define ElemType int

typedef struct _JosephCircleList
{
	struct _JosephCircleList* pre;//前结点
	struct _JosephCircleList* next;//后结点
	ElemType person;
}JosephCircleNode, *JosephCircleList;

JosephCircleList JosephCircleListCreate(JosephCircleList slist, ElemType elem);	//建立约瑟夫环
   
JosephCircleList JosephCircleListDelete(JosephCircleList slist, int pos);	//删除一个结点

JosephCircleList JosephCircleListInsert(JosephCircleList slist, ElemType elem, int pos);//向约瑟夫环插入

JosephCircleList GetJosephCircleListHeader(JosephCircleList slist, ElemType hperson);	//获取约瑟夫环头结点

int GetJosephCircleListLength(JosephCircleList slist);	//获取约瑟夫环长度

void JosephCircleKickOut(JosephCircleList slist, ElemType hperson, int key);//踢出局

void DisplayJosephCircleList(JosephCircleList slist);