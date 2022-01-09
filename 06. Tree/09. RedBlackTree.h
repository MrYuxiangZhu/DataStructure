#pragma once
#include <iostream>

using namespace std;

#ifndef _NODISCARD
#define _NODISCARD [[nodiscard]]
#endif

typedef int ElemType;

typedef enum
{
	RED = 0,
	BLACK
}COLOR_TYPE;

typedef struct _RBNode
{
	struct _RBNode* lchild;
	struct _RBNode* rchild;
	struct _RBNode* parent;
	ElemType   data;
	COLOR_TYPE color;
}RBNode, *RBTree;

typedef struct _Queue
{
	struct _Queue* next;
	struct _RBNode* node;
}Queue;

Queue* front = NULL;
Queue* rear = NULL;

_NODISCARD RBNode* Front()
{
	return front->node;
}

_NODISCARD bool IsEmpty()
{
	return front ? false : true;
}

void DeQueue()
{
	if (IsEmpty()) return;
	Queue* temp = front;
	front = front->next;
	free(temp);
}

void EnQueue(RBNode* node)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (NULL == queue) return;
	queue->node = node;
	queue->next = NULL;

	if (NULL == front && NULL == rear)
	{
		front = rear = queue;
		return;
	}

	rear->next = queue;
	rear = queue;
}

void LevelOrder(RBTree root)
{
	if (NULL == root) return;
	EnQueue(root);
	while (!IsEmpty())
	{
		RBNode* top = Front();
		std::cout << top->data << std::endl;
		if (top->lchild)
		{
			EnQueue(top->lchild);
		}
		if (top->rchild)
		{
			EnQueue(top->rchild);
		}
		DeQueue();
	}
}

RBNode* FindMax(RBTree root)
{
	RBNode* node = root;
	while (NULL != node->rchild)
	{
		node = node->rchild;
	}

	return node;
}

RBNode* FindMin(RBTree root)
{
	RBNode* node = root;
	while (NULL != node->lchild)
	{
		node = node->lchild;
	}

	return node;
}

RBNode* RBTreeSearch(RBTree root, ElemType data)
{
	if (NULL == root || root->data == data)
	{
		return root;
	}

	RBNode* node = root;
	while (NULL != node)
	{
		if (node->data > data)
		{
			node = node->lchild;
		}
		else if (node->data < data)
		{
			node = node->rchild;
		}
		else
		{
			break;
		}
	}

	return node;
}

void LeftRotate(RBTree& root, RBTree& node)
{
	RBTree temp = node->rchild;
	node->rchild = temp->lchild;

	if (temp->lchild)
	{
		temp->lchild->parent = node;
	}

	temp->parent = node->parent;

	if (NULL == node->parent)
	{
		root = temp;
	}
	else if (node == node->parent->lchild)
	{
		node->parent->lchild = temp;
	}
	else
	{
		node->parent->rchild = temp;
	}

	temp->lchild = node;
	node->parent = temp;
}

void RightRotate(RBTree& root, RBTree& node)
{
	RBTree temp = node->lchild;
	node->lchild = temp->rchild;

	if (temp->rchild)
	{
		temp->rchild->parent = node;
	}

	temp->parent = node->parent;

	if (NULL == node->parent)
	{
		root = temp;
	}
	else if (node == node->parent->lchild)
	{
		node->parent->lchild = temp;
	}
	else
	{
		node->parent->rchild = temp;
	}

	temp->rchild = node;
	node->parent = temp;
}

void RBTreeInsertBalance(RBTree root, RBTree node)
{
	RBTree grand_parent = NULL;
	RBTree parent = NULL;
	while (NULL != root && node != root && node->color != COLOR_TYPE::BLACK && node->parent->color == RED)
	{
		parent = node->parent;
		grand_parent = node->parent->parent;

		if (parent == grand_parent->lchild)	/*父结点是左子结点*/
		{
			RBNode* uncle = grand_parent->rchild;
			if (NULL != uncle && uncle->color == COLOR_TYPE::RED) /*叔叔结点是红色*/
			{
				grand_parent->color = COLOR_TYPE::RED;
				parent->color = COLOR_TYPE::BLACK;
				uncle->color = COLOR_TYPE::BLACK;
				node = grand_parent;
			}
			else /*叔叔结点是黑色或者无叔叔结点*/
			{
				if (node == parent->rchild)
				{
					LeftRotate(root, parent);
					node = parent;
					parent = node->parent;
				}

				RightRotate(root, grand_parent);
				parent->color = COLOR_TYPE::BLACK;
				grand_parent->color = COLOR_TYPE::RED;
				node = parent;
			}
		}
		else /*父结点是右子结点*/
		{
			RBNode* uncle = grand_parent->lchild;
			if (NULL != uncle && uncle->color == COLOR_TYPE::RED)
			{
				grand_parent->color = COLOR_TYPE::RED;
				parent->color = COLOR_TYPE::BLACK;
				uncle->color = COLOR_TYPE::BLACK;
				node = grand_parent;
			}
			else
			{
				if (node == parent->lchild)
				{
					RightRotate(root, parent);
					node = parent;
					parent = node->parent;
				}

				LeftRotate(root, grand_parent);
				parent->color = COLOR_TYPE::BLACK;
				grand_parent->color = COLOR_TYPE::RED;
				node = parent;
			}
		}
	}

	root->color = COLOR_TYPE::BLACK;
}

RBTree RBTreeInsert(RBTree root, int data)
{
	RBNode* parent = NULL;
	RBNode* temp = root;

	while (NULL != temp)
	{
		parent = temp;
		if (data < temp->data) /*继续访问左子结点*/
		{
			temp = temp->lchild;
		}
		else if (data > temp->data) /*继续访问右子结点*/
		{
			temp = temp->rchild;
		}
		else /*无需更新结点*/
		{
			break;
		}
	}

	if (NULL == parent) /*根结点*/
	{
		RBNode* node = (RBNode*)malloc(sizeof(RBNode));
		if (NULL == node) return root;
		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		node->parent = NULL;
		node->color = COLOR_TYPE::BLACK;
		root = node;
	}
	else if (parent && parent->data != data)
	{
		RBNode* node = (RBNode*)malloc(sizeof(RBNode));
		if (NULL == node) return root;
		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		node->parent = parent;
		node->color = COLOR_TYPE::RED;
		
		if (node->data < parent->data)
		{
			parent->lchild = node;
		}
		else
		{
			parent->rchild = node;
		}
		RBTreeInsertBalance(root, node);
	}

	return root;
}

void RBTreeDeleteBalance(RBTree& root, RBTree& node)
{
	while (root != node && node->color == COLOR_TYPE::BLACK)
	{
		if (node == node->parent->lchild)
		{
			RBNode* brother = node->parent->rchild;
			if (COLOR_TYPE::RED == brother->color)
			{
				brother->color = COLOR_TYPE::BLACK;
				node->parent->color = COLOR_TYPE::BLACK;
				LeftRotate(root, node->parent);
				brother = node->parent->rchild;
			}

			if (brother->lchild->color == COLOR_TYPE::BLACK && brother->rchild->color == COLOR_TYPE::BLACK)
			{
				brother->color = COLOR_TYPE::RED;
				node = node->parent;
			}
			else
			{
				if (brother->rchild->color == COLOR_TYPE::BLACK)
				{
					brother->lchild->color = COLOR_TYPE::BLACK;
					brother->color = COLOR_TYPE::RED;
					RightRotate(root, brother);
					brother = node->parent->rchild;
				}

				brother->color = node->parent->color;
				node->parent->color = COLOR_TYPE::BLACK;
				brother->rchild->color = COLOR_TYPE::BLACK;
				LeftRotate(root, node->parent);
				node = root;
			}
		}
		else
		{
			RBNode* brother = node->parent->lchild;
			if (COLOR_TYPE::RED == brother->color)
			{
				brother->color = COLOR_TYPE::BLACK;
				node->parent->color = COLOR_TYPE::BLACK;
				RightRotate(root, node->parent);
				brother = node->parent->lchild;
			}

			if (brother->lchild->color == COLOR_TYPE::BLACK && brother->rchild->color == COLOR_TYPE::BLACK)
			{
				brother->color = COLOR_TYPE::RED;
				node = node->parent;
			}
			else
			{
				if (brother->lchild->color == COLOR_TYPE::BLACK)
				{
					brother->rchild->color = COLOR_TYPE::BLACK;
					brother->color = COLOR_TYPE::RED;
					LeftRotate(root, brother);
					brother = node->parent->lchild;
				}

				brother->color = node->parent->color;
				node->parent->color = COLOR_TYPE::BLACK;
				brother->lchild->color = COLOR_TYPE::BLACK;
				RightRotate(root, node->parent);
				node = root;
			}
		}
	}

	node->color = COLOR_TYPE::BLACK;
}

void RBTreeTransPlat(RBTree& root, RBTree& node, RBTree& other)
{
	if (NULL == node->parent)
	{
		root = other;
	}
	else if (node = node->parent->lchild)
	{
		node->parent->lchild = other;
	}
	else
	{
		node->parent->rchild = other;
	}

	if (NULL != other)
	{
		other->parent = node->parent;
	}
}

RBTree RBTreeDelete(RBTree& root, RBNode* node)
{
	RBNode* nodex = NULL;
	RBNode* nodey = node;
	COLOR_TYPE tcolor = node->color;
	if (NULL == node->lchild)
	{
		nodex = node->rchild;
		RBTreeTransPlat(root, node, node->rchild);
	}
	else if (NULL == node->rchild)
	{
		nodex = node->lchild;
		RBTreeTransPlat(root, node, node->lchild);
	}
	else
	{
		nodey = FindMin(node->rchild);
		tcolor = nodey->color;
		nodex = nodey->rchild;

		if (node == nodey->parent)
		{
			nodex->parent = nodey;
		}
		else
		{
			RBTreeTransPlat(root, nodey, nodey->rchild);
			nodey->rchild = node->rchild;
			nodey->rchild->parent = nodey;
		}

		RBTreeTransPlat(root, node, nodey);
		nodey->lchild = node->lchild;
		nodey->lchild->parent = nodey;
		nodey->color = node->color;
	}

	if (tcolor == COLOR_TYPE::BLACK)
	{
		RBTreeDeleteBalance(root, nodex);
	}

	return root;
}
