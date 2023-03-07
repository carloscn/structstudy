//
// Created by delvis on 10/5/18.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    head = NULL;
    size = 0;
    dummyHead = new Node(NULL, NULL);
}

int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return size == 0;
}

void LinkedList::addElementByIndex(int index, int e) {

    if (index < 0 || index > size)
        throw std::range_error("Error: index over the the linked list range.\n");

    Node *pre = dummyHead;
    for (int i = 0; i < index; i++)
        pre = pre->next;
    Node *node = new Node(e);
    node->next  = pre->next;
    pre->next = node;
    size ++;
}
void LinkedList::addFirst(int e) {

    addElementByIndex(0, e);
}

void LinkedList::addLast(int e) {
    addElementByIndex(size, e);
}

int LinkedList::del(int index) {

    if (index < 0 || index > size)
        throw std::range_error("Error: index over the the linked list range.\n");

    Node *pre = dummyHead;
    for (int i = 0; i < index; i++)
        pre = pre->next;
    Node *del = pre->next;
    pre->next = del->next;
    del->next = NULL;
    size--;

    return del->e;
}

int LinkedList::removeFirst() {
    return del(0);
}

int LinkedList::removeLast() {
    return del(size - 1);
}

void LinkedList::toString() {

    Node *cur = dummyHead->next;
    while(cur != NULL) {
        std::cout << cur->e << " -> ";
        cur = cur->next;
    }
    std::cout << "NULL | Size is " << getSize() << endl;

}

int LinkedList::get(int index) {

    if (index < 0 || index >= size)
        throw std::range_error("range error!\n");

    Node *cur = dummyHead;
    for (int i = 0; i < index; i++)
        cur = cur->next;

    return cur->e;
}

int LinkedList::getFirst() {
    return get(0);
}

int LinkedList::getLast() {
    return get(size - 1);
}

void LinkedList::set(int index, int e) {

    if (index < 0 || index >= size)
        throw std::range_error("error range");
    Node *cur = dummyHead->next;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    cur->e = e;
}

bool LinkedList::contains(int e) {

    Node *cur = dummyHead->next;

    while(cur != NULL) {
        if (cur->e == e)
            return true;
        cur->next = cur;
    }
    return false;
}
