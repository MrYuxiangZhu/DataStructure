#include <iostream>
#include <deque>
#include "BinaryTreeTraverse.h"

using namespace std;

void CreateBinaryTree(BiTree& Tree)
{
	Tree = (BiTNode*)malloc(sizeof(BiTNode));
	
	Tree->data = 1;
	Tree->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->lchild->data = 2;
	Tree->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->rchild->data = 3;
	Tree->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->lchild->lchild->data = 4;
	Tree->lchild->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->lchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->lchild->rchild->data = 5;
	Tree->lchild->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->lchild->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->rchild->lchild->data = 6;
	Tree->rchild->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->rchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->rchild->rchild->data = 7;
	Tree->rchild->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	Tree->rchild->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	Tree->lchild->lchild->lchild->data = 8;
	Tree->lchild->lchild->lchild->lchild = NULL;
	Tree->lchild->lchild->lchild->rchild = NULL;

	Tree->lchild->lchild->rchild->data = 9;
	Tree->lchild->lchild->rchild->lchild = NULL;
	Tree->lchild->lchild->rchild->rchild = NULL;

	Tree->lchild->rchild->lchild->data = 10;
	Tree->lchild->rchild->lchild->lchild = NULL;
	Tree->lchild->rchild->lchild->rchild = NULL;

	Tree->lchild->rchild->rchild->data = 11;
	Tree->lchild->rchild->rchild->lchild = NULL;
	Tree->lchild->rchild->rchild->rchild = NULL;

	Tree->rchild->lchild->lchild->data = 12;
	Tree->rchild->lchild->lchild->lchild = NULL;
	Tree->rchild->lchild->lchild->rchild = NULL;

	Tree->rchild->lchild->rchild->data = 13;
	Tree->rchild->lchild->rchild->lchild = NULL;
	Tree->rchild->lchild->rchild->rchild = NULL;

	Tree->rchild->rchild->lchild->data = 14;
	Tree->rchild->rchild->lchild->lchild = NULL;
	Tree->rchild->rchild->lchild->rchild = NULL;

	Tree->rchild->rchild->rchild->data = 15;
	Tree->rchild->rchild->rchild->lchild = NULL;
	Tree->rchild->rchild->rchild->rchild = NULL;
}

void PreOrderTraverse(BiTree& Tree)
{
	if (Tree)
	{
		DisplayNode(Tree);
		PreOrderTraverse(Tree->lchild);
		PreOrderTraverse(Tree->rchild);
	}
}

void InOrderTraverse(BiTree& Tree)
{
	if (Tree)
	{
		InOrderTraverse(Tree->lchild);
		DisplayNode(Tree);
		InOrderTraverse(Tree->rchild);
	}
}

void PostOrderTraverse(BiTree& Tree)
{
	if (Tree)
	{
		PostOrderTraverse(Tree->lchild);
		PostOrderTraverse(Tree->rchild);
		DisplayNode(Tree);
	}
}

void DequeTraverse(BiTree& Tree)
{
	deque<BiTNode*> BDeque;
	BDeque.emplace_back(Tree);//根结点进队列
	while (!BDeque.empty())
	{
		BiTNode* Node = BDeque.front(); //队列头结点
		DisplayNode(Node);
		BDeque.pop_front(); //队列头结点出队

		if (Node->lchild)
		{
			BDeque.emplace_back(Node->lchild); //左孩子入队
		}

		if (Node->rchild)
		{
			BDeque.emplace_back(Node->rchild);//右孩子入队
		}
	}
}

void DisplayNode(BiTNode* Node)
{
	cout << Node->data << " ";
}