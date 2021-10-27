#pragma once

typedef char TElemType;

typedef enum
{
	Link = 0,
	Thread,
}PointerTag;

/*线索二叉树结点结构体*/
typedef struct _ThrBiTNode
{
	TElemType data;//结点数据
	struct _ThrBiTNode* lchild;//左孩子指针
	struct _ThrBiTNode* rchild;//右孩子指针
	PointerTag ltag;
	PointerTag rtag;
}ThrBiTNode, *ThrBiTree;

void InitThreading(ThrBiTree node, ThrBiTree& pre);

void CreateTree(ThrBiTree& tree);

void InOrderTraverse(ThrBiTree tree);