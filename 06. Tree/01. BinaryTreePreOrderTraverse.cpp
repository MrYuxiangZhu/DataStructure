﻿// 二叉树先序非递归遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>

#define ElemType char

typedef struct BiTNode
{
	ElemType data;	//数据域
	struct BiTNode* lchild, * rchild;		//左右孩子指针
}BiTNode, * BiTree;

//构建树的函数
void CreateBiTree(BiTree* Tree)
{
	*Tree = (BiTNode*)malloc(sizeof(BiTNode));
	/*第一层*/
	(*Tree)->data = 'A';
	(*Tree)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*Tree)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	/*第二层*/
	(*Tree)->lchild->data = 'B';
	(*Tree)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*Tree)->lchild->rchild = NULL;

	(*Tree)->rchild->data = 'C';
	(*Tree)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*Tree)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	/*第三层*/
	(*Tree)->lchild->lchild->data = 'D';
	(*Tree)->lchild->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*Tree)->lchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	(*Tree)->rchild->lchild->data = 'E';
	(*Tree)->rchild->lchild->lchild = NULL;
	(*Tree)->rchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	(*Tree)->rchild->rchild->data = 'F';
	(*Tree)->rchild->rchild->lchild = NULL;
	(*Tree)->rchild->rchild->rchild = NULL;

	/*第四层*/
	(*Tree)->lchild->lchild->lchild->data = 'G';
	(*Tree)->lchild->lchild->lchild->lchild = NULL;
	(*Tree)->lchild->lchild->lchild->rchild = NULL;

	(*Tree)->lchild->lchild->rchild->data = 'H';
	(*Tree)->lchild->lchild->rchild->lchild = NULL;
	(*Tree)->lchild->lchild->rchild->rchild = NULL;

	(*Tree)->rchild->lchild->rchild->data = 'I';
	(*Tree)->rchild->lchild->rchild->lchild = NULL;
	(*Tree)->rchild->lchild->rchild->rchild = NULL;
}
//模拟操作结点元素的函数，输出结点本身的数值
void DisplayElem(BiTNode* elem)
{
	std::cout << elem->data << " ";
}

/*先序遍历*/
void PreOrderTraverse(BiTree T)
{
	BiTNode* top = T;
	std::stack<BiTNode*> sta;
	while (top || !sta.empty())
	{
		if (top)
		{
			DisplayElem(top);

			if (top->rchild)
			{
				sta.push(top->rchild);
			}
			top = top->lchild;
		}
		else
		{
			top = sta.top();
			sta.pop();
		}
	}
}

/*先序遍历*/
void PreOrderTraverse1(BiTree T)
{
	std::stack<BiTNode*> sta;
	sta.push(T);
	while (!sta.empty())
	{
		BiTNode* top = sta.top();
		sta.pop();
		while (top)
		{
			DisplayElem(top);
			if (top->rchild)
			{
				sta.push(top->rchild);
			}

			top = top->lchild;
		}
	}
}

int main()
{
	BiTree Tree;
	CreateBiTree(&Tree);
	std::cout << "先序遍历" << std::endl;
	PreOrderTraverse(Tree);
	std::cout << std::endl;
	PreOrderTraverse1(Tree);
	std::cout << std::endl;

	return 0;
}
