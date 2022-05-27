#include <iostream>

typedef struct _AVLNode
{
    int data;
    int height;
    struct _AVLNode* lchild;
    struct _AVLNode* rchild;
}AVLNode, *AVLTree;

/*获取树高度*/
int Height(AVLTree Tree)
{
    return nullptr == Tree ? 0 : Tree->height;
}

/*获取平衡因子*/
int GetBalance(AVLTree Tree)
{
    return (nullptr == Tree) ? 0 : (Height(Tree->lchild) - Height(Tree->rchild));
}

/*查找最小值*/
AVLTree FindMin(AVLTree Tree)
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

/*查找最大值*/
AVLTree FindMax(AVLTree Tree)
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

/*LL型， 右旋*/
AVLTree LL_Rotate(AVLTree Tree)
{
    if (nullptr == Tree) return nullptr;

    AVLTree Root = Tree->lchild;
    Tree->lchild = Root->rchild;
    Root->rchild = Tree;
    
    Tree->height = std::max(Height(Tree->lchild), Height(Tree->rchild)) + 1;
    Root->height = std::max(Height(Root->lchild), Height(Root->rchild)) + 1;

    return Root;
}

/*RR型，左旋*/
AVLTree RR_Rotate(AVLTree Tree)
{
    if (nullptr == Tree) return nullptr;

    AVLTree Root = Tree->rchild;
    Tree->rchild = Root->lchild;
    Root->lchild = Tree;

    Tree->height = std::max(Height(Tree->lchild), Height(Tree->rchild)) + 1;
    Root->height = std::max(Height(Root->lchild), Height(Tree->rchild)) + 1;

    return Root;
}

/*LR型*/
AVLTree LR_Rotate(AVLTree Tree)
{
    if (nullptr == Tree) return nullptr;
    Tree->lchild = RR_Rotate(Tree->lchild);
    return LL_Rotate(Tree);
}

/*RL型*/
AVLTree RL_Rotate(AVLTree Tree)
{
    if (nullptr == Tree) return nullptr;
    Tree->rchild = LL_Rotate(Tree->rchild);
    return RR_Rotate(Tree);
}

/*插入结点*/
AVLTree Insert(AVLTree Tree, int key)
{
    if (nullptr == Tree)
    {
        Tree = (AVLNode*)malloc(sizeof(AVLNode));
        Tree->data = key;
        Tree->lchild = nullptr;
        Tree->rchild = nullptr;
        Tree->height = 1;
        return Tree;
    }

    if (Tree->data > key)
    {
        Tree->lchild = Insert(Tree->lchild, key);
    }
    else if (Tree->data < key)
    {
        Tree->rchild = Insert(Tree->rchild, key);
    }
    else
    {
        return Tree;
    }

    Tree->height = std::max(Height(Tree->lchild), Height(Tree->rchild)) + 1;

    int balance = GetBalance(Tree);

    if (balance > 1 && key < Tree->lchild->data) /*LL型*/
    {
        return LL_Rotate(Tree);
    }
    else if (balance < -1 && key > Tree->rchild->data) /*RR型*/
    {
        return RR_Rotate(Tree);
    }
    else if (balance > 1 && key > Tree->lchild->data) /*LR型*/
    {
        return LR_Rotate(Tree);
    }
    else if (balance < -1 && key < Tree->rchild->data) /*RL型*/
    {
        return RL_Rotate(Tree);
    }

    return Tree;
}

/*删除结点*/
AVLTree Delete(AVLTree Tree, int key)
{
    if (nullptr == Tree)
    {
        return nullptr;
    }

    if (Tree->data > key)
    {
        Tree->lchild = Delete(Tree->lchild, key);
    }
    else if (Tree->data < key)
    {
        Tree->rchild = Delete(Tree->rchild, key);
    }
    else
    {
        if (nullptr != Tree->lchild && nullptr != Tree->rchild)
        {
            AVLTree Max = FindMax(Tree->lchild);
            Tree->data = Max->data;
            Tree->lchild = Delete(Tree->lchild, Max->data);
        }
        else if (nullptr == Tree->lchild && nullptr != Tree->rchild)
        {
            AVLNode* Node = Tree;
            Tree = Tree->rchild;
            free(Node);
        }
        else if (nullptr != Tree->lchild && nullptr == Tree->rchild)
        {
            AVLNode* Node = Tree;
            Tree = Tree->lchild;
            free(Node);
        }
        else
        {
            free(Tree);
            Tree = nullptr;
            return Tree;
        }
    }

    Tree->height = std::max(Height(Tree->lchild), Height(Tree->rchild)) + 1;
    int balance = GetBalance(Tree);

    if (balance > 1 && GetBalance(Tree->lchild) >= 0) /*LL型*/
    {
        return LL_Rotate(Tree);
    }
    else if (balance < -1 && GetBalance(Tree->rchild) <= 0) /*RR*/
    {
        return RR_Rotate(Tree);
    }
    else if (balance > 1 && GetBalance(Tree->lchild) < 0) /*LR型*/
    {
        return LR_Rotate(Tree);
    }
    else if (balance < -1 && GetBalance(Tree->rchild) > 0) /*RL型*/
    {
        return RL_Rotate(Tree);
    }

    return Tree;
}
