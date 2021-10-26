// BinaryTreeTraverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BinaryTreeTraverse.h"

using namespace std;

int main()
{
    BiTree Tree;
    CreateBinaryTree(Tree);
    cout << "先序遍历二叉树：";
    PreOrderTraverse(Tree);
    cout << endl;
    cout << "中序遍历二叉树：";
    InOrderTraverse(Tree);
    cout << endl;
    cout << "后序遍历二叉树：";
    PostOrderTraverse(Tree);
    cout << endl;
    cout << "层次遍历二叉树：";
    DequeTraverse(Tree);
    cout << endl;

    return 0;
}
