#include <iostream>
#include "JudgeLinkedListIntersect.h"

using namespace std;

int main()
{
    LinkedList list1 = LinkedListInit();
    LinkedList list2 = LinkedListInit();
    LinkedList list3 = LinkedListInit();
    LinkedListCreateByHeader(list1, 1);
    LinkedListCreateByHeader(list1, 2);
    LinkedListCreateByHeader(list1, 3);
    LinkedListCreateByHeader(list1, 4);

    LinkedListCreateByHeader(list2, 1);
    LinkedListCreateByHeader(list2, 2);
    LinkedListCreateByHeader(list2, 3);
    LinkedListCreateByHeader(list3, 4);

    list3 = list1;

    cout << "链表1：" << endl;
    display(list1);
    cout << "链表2：" << endl;
    display(list2);

    cout << "链表是否相交：" << (LinkedListIntersectByEnum(list1, list2) ? "true" : "false") << endl;
    cout << "链表是否相交：" << (LinkedListIntersectByStack(list1, list3) ? "true" : "false") << endl;
    cout << "链表是否相交：" << (LinkedListIntersectByLength(list1, list3) ? "true" : "false") << endl;
    cout << "链表是否相交：" << (LinkedListIntersectByLength(list2, list3) ? "true" : "false") << endl;

    return 0;
}
