// 二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

#define ElemType int

using namespace std;

typedef struct BiTNode
{
	ElemType data;	//数据域
	struct BiTNode* lchild, * rchild;		//左右孩子指针
}BiTNode, * BiTree;

/*二叉搜索树插入结点*/
BiTree BSTInsert(BiTree& Tree, ElemType key)
{
	if (nullptr == Tree) /*空树或者遍历到叶子结点*/
	{
		Tree = (BiTNode*)malloc(sizeof(BiTNode));
		Tree->data = key;
		Tree->lchild = nullptr;
		Tree->rchild = nullptr;
	}
	else if (Tree->data > key)/*如果key小于当前结点的值，则插入左结点*/
	{
		Tree->lchild = BSTInsert(Tree->lchild, key);
	}
	else if (Tree->data < key)/*如果key大于当前结点的值，则插入右结点*/
	{
		Tree->rchild = BSTInsert(Tree->rchild, key);
	}

	return Tree;
}

/*二叉搜索树查找最小值*/
BiTree FindMin(BiTree Tree)
{
	if (nullptr == Tree)
	{
		return nullptr;
	}
	else if (nullptr == Tree->lchild)
	{
		return Tree;
	}
	else
	{
		return FindMin(Tree->lchild);
	}
}

/*二叉搜索树查找最大值*/
BiTree FindMax(BiTree Tree)
{
	if (nullptr == Tree)
	{
		return nullptr;
	}
	else if (nullptr == Tree->rchild)
	{
		return Tree;
	}
	else
	{
		return FindMax(Tree->rchild);
	}
}

/*二叉树搜索树删除结点*/
BiTree BSTDelete(BiTree& Tree, ElemType key)
{
	if (nullptr == Tree)
	{
		return nullptr;
	}
	else if (Tree->data > key)/*在该结点左子树查找结点key*/
	{
		Tree->lchild = BSTDelete(Tree->lchild, key);
	}
	else if (Tree->data < key)/*在该结点右子树查找结点key*/
	{
		Tree->rchild = BSTDelete(Tree->rchild, key);
	}
	else /*找到结点key*/
	{
		if (Tree->lchild && Tree->rchild) /*同时拥有左右子树*/
		{
			/*找到左子树最大值*/
			BiTNode* Max = FindMax(Tree->lchild);/*左子树找到最大值结点*/
			Tree->data = Max->data;/*用左子树最大值替换当前结点值*/
			Tree->lchild = BSTDelete(Tree->lchild, Max->data);/*删除左子树最大值结点*/
		}
		else if (!Tree->lchild && Tree->rchild) /*只有右子树*/
		{
			BiTNode* Node = Tree;
			Tree = Tree->rchild;
			free(Node);
		}
		else if (Tree->lchild && !Tree->rchild) /*只有左子树*/
		{
			BiTNode* Node = Tree;
			Tree = Tree->lchild;
			free(Node);
		}
		else /*没有左右子树*/
		{
			free(Tree);
			Tree = nullptr;
		}
	}

	return Tree;
}

/*二叉搜索树查找元素*/
BiTree Find(BiTree Tree, ElemType key)
{
	if (nullptr == Tree)
	{
		return nullptr;
	}
	else if (Tree->data > key) /*查找左子树*/
	{
		return Find(Tree->lchild, key);
	}
	else if (Tree->data < key) /*查找右子树*/
	{
		return Find(Tree->rchild, key);
	}
	else/*查找的key*/
	{
		return Tree;
	}
}

/*输出结点值*/
void DisplayElem(BiTNode* elem)
{
	std::cout << elem->data << " ";
}

/*二叉树前序遍历*/
void PreOrderTraverse(BiTree Tree)
{
	BiTNode* top = Tree;
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

int main()
{
	BiTree BTree = NULL;
	std::vector<int> vec = { 62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50 };
	for (auto iter : vec)
	{
		BSTInsert(BTree, iter);
	}

	std::cout << "插入后的二叉树前序遍历: ";
	PreOrderTraverse(BTree);
	std::cout << std::endl;

	std::cout << "最小值: " << FindMin(BTree)->data << std::endl;
	std::cout << "最大值: " << FindMax(BTree)->data << std::endl;

	BTree = BSTDelete(BTree, 50);
	std::cout << "删除50后的二叉树前序遍历: ";
	PreOrderTraverse(BTree);
	std::cout << std::endl;

	std::cout << "查找元素48结果: " << (nullptr == Find(BTree, 48) ? "false" : "true") << std::endl;
	std::cout << "查找元素50结果: " << (nullptr == Find(BTree, 50) ? "false" : "true") << std::endl;

	return 0;
}