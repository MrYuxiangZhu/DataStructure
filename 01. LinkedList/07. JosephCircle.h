#pragma once

#define ERROR (-1)
#define ElemType int

typedef struct _JosephCircleList
{
	struct _JosephCircleList* pre;//ǰ���
	struct _JosephCircleList* next;//����
	ElemType person;
}JosephCircleNode, *JosephCircleList;

JosephCircleList JosephCircleListCreate(JosephCircleList slist, ElemType elem);	//����Լɪ��
   
JosephCircleList JosephCircleListDelete(JosephCircleList slist, int pos);	//ɾ��һ�����

JosephCircleList JosephCircleListInsert(JosephCircleList slist, ElemType elem, int pos);//��Լɪ�򻷲���

JosephCircleList GetJosephCircleListHeader(JosephCircleList slist, ElemType hperson);	//��ȡԼɪ��ͷ���

int GetJosephCircleListLength(JosephCircleList slist);	//��ȡԼɪ�򻷳���

void JosephCircleKickOut(JosephCircleList slist, ElemType hperson, int key);//�߳���

void DisplayJosephCircleList(JosephCircleList slist);