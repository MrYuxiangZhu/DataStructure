// ThreadBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ThreadBinaryTree.h"

int main()
{
    ThrBiTree tree = NULL;
    ThrBiTree pre = NULL; /*始终指向刚刚访问过的结点*/
    printf("输入前序二叉树:\n");
    CreateTree(tree);
    InitThreading(tree, pre);
    printf("输出中序序列:\n");
    InOrderTraverse(tree);

    return 0;
}
