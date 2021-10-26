#pragma once

#define TElemType int

typedef struct _BiTNode
{
	TElemType data;
	struct _BiTNode* lchild;
	struct _BiTNode* rchild;
}BiTNode, *BiTree;

void CreateBinaryTree(BiTree& Tree);

void PreOrderTraverse(BiTree& Tree);

void InOrderTraverse(BiTree& Tree);

void PostOrderTraverse(BiTree& Tree);

void DequeTraverse(BiTree& Tree);

void DisplayNode(BiTNode* Node);