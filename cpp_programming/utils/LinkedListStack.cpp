//
// Created by delvis on 10/6/18.
//

#include "LinkedListStack.h"

LinkedListStack::LinkedListStack() {
    list = new LinkedList();
}

void LinkedListStack::push(int i) {
    list->addFirst(i);
}

int LinkedListStack::pop() {
    return list->removeFirst();
}

int LinkedListStack::peek() {
    return list->getFirst();
}

int LinkedListStack::getSize() {
    return list->getSize();
}

bool LinkedListStack::isEmpty() {
    return list->isEmpty();
}

void LinkedListStack::toString() {
    std::cout << "Stack: top " ;
    list->toString();
}

