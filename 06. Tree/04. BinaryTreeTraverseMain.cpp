// BinaryTreeTraverse.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "BinaryTreeTraverse.h"

using namespace std;

int main()
{
    BiTree Tree;
    CreateBinaryTree(Tree);
    cout << "���������������";
    PreOrderTraverse(Tree);
    cout << endl;
    cout << "���������������";
    InOrderTraverse(Tree);
    cout << endl;
    cout << "���������������";
    PostOrderTraverse(Tree);
    cout << endl;
    cout << "��α�����������";
    DequeTraverse(Tree);
    cout << endl;

    return 0;
}
