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

    cout << "����1��" << endl;
    display(list1);
    cout << "����2��" << endl;
    display(list2);

    cout << "�����Ƿ��ཻ��" << (LinkedListIntersectByEnum(list1, list2) ? "true" : "false") << endl;
    cout << "�����Ƿ��ཻ��" << (LinkedListIntersectByStack(list1, list3) ? "true" : "false") << endl;
    cout << "�����Ƿ��ཻ��" << (LinkedListIntersectByLength(list1, list3) ? "true" : "false") << endl;
    cout << "�����Ƿ��ཻ��" << (LinkedListIntersectByLength(list2, list3) ? "true" : "false") << endl;

    return 0;
}
