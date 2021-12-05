// 二叉树后序非递归遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

/*后序遍历*/
void ProOrderTraverse(BiTree T)
{
	std::stack<BiTNode*> sta;
	BiTNode* top = T;
	BiTNode* vis = nullptr;/*临时变量，记录上一个访问到的结点，因为从右边访问根结点，
						   必定是右子树已经遍历结束，此时上一个访问的结点必定是右子树的根结点*/
	while (top || !sta.empty())
	{
		if (top)
		{
			sta.push(top);
			top = top->lchild;
		}
		else
		{
			top = sta.top();//只读取根结点，不对栈内结点进行操作
			if (top->rchild && top->rchild != vis)//没有对右子树进行操作过
			{
				top = top->rchild;
				sta.push(top);
				top = top->lchild;
			}
			else
			{
				sta.pop();
				DisplayElem(top);//对top进行访问，可以进行打印等操作
				vis = top;//记录当前访问的是p结点
				top = nullptr;//把p置空，进入下一次循环，直到栈内无元素，且p为空时遍历完成
			}
		}
	}
}

int main()
{
	BiTree Tree;
	CreateBiTree(&Tree);
	std::cout << "后序遍历" << std::endl;
	ProOrderTraverse(Tree);
	std::cout << std::endl;
	return 0;
}