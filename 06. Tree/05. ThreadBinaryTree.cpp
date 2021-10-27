#include <iostream>
#include "ThreadBinaryTree.h"

void InitThreading(ThrBiTree node, ThrBiTree& pre)
{
	if (node)
	{
		InitThreading(node->lchild, pre);/*递归左子树线索化*/
		if (!node->lchild)			/*如果当前结点没有左孩子，左标志位设为1，左指针域指向上一个结点pre*/
		{
			node->ltag = Thread;	/*前驱线索*/
			node->lchild = pre;		/*指向前驱结点*/
		}

		if (pre && !pre->rchild)	/*如果pre没有右孩子，右标志位设为1，右指针域指向当前结点*/
		{
			pre->rtag = Thread;
			pre->rchild = node; /*指向当前结点*/
		}

		pre = node;
		InitThreading(node->rchild, pre);//右子树线索化
	}
}

void CreateTree(ThrBiTree& tree)
{
	char data;
	std::cin >> data;
	if (data != '#')
	{
		if (!(tree = (ThrBiTNode*)malloc(sizeof(ThrBiTNode)))) 
		{
			printf("申请结点空间失败");
			return;
		}
		else 
		{
			tree->data = data;//采用前序遍历方式初始化二叉树
			tree->ltag = Link;
			tree->rtag = Link;
			CreateTree(tree->lchild);//初始化左子树
			CreateTree(tree->rchild);//初始化右子树
		}
	}
	else
	{
		tree = NULL;
	}
}

void InOrderTraverse(ThrBiTree tree)
{
	while (tree)
	{
		/*一直遍历左孩子*/
		while (tree->ltag == Link)
		{
			tree = tree->lchild;
		}

		std::cout << tree->data << std::endl;

		/*当结点右标志位为1时，直接找到后继结点*/
		while (tree->rtag == Thread && tree->rchild != NULL)
		{
			tree = tree->rchild;
			std::cout << tree->data << std::endl;
		}

		//否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
		tree = tree->rchild;
	}
}
