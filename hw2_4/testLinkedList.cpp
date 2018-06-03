/*
    JTSK-320111
    testLinkedList.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "LinkedList.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){
    DoublyLinkedList<int> lst;

    //push three element back
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    cout << "push_back: 1" << endl;
    cout << "push_back: 2" << endl;
    cout << "push_back: 3" << endl;

    cout << "back: " << lst.back() << endl;
    cout << "front: " << lst.front() << endl;

    lst.push_front(4);
    cout << "push_front: 4" << endl;
    cout << "back: " << lst.back() << endl;
    cout << "front: " << lst.front() << endl;

    return 0;
}
    
