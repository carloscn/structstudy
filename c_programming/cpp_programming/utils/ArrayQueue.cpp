//
// Created by delvis on 10/1/18.
//

#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() {
    array = new DyArray();
}

ArrayQueue::ArrayQueue(int capacity) {
    array = new DyArray[capacity];
}

void ArrayQueue::queue(int e) {
    array->addLast(e);
}

int ArrayQueue::dequeue() {
    return array->removeFirst();
}

int ArrayQueue::getFront() {
    return array->getFirst();
}

int ArrayQueue::getSize() {
    return array->getSize();
}

bool ArrayQueue::isEmpty() {
    return array->isEmpty();
}

int ArrayQueue::getCapacity() {
    return array->getCapacity();
}

void ArrayQueue::toString() {

    std::cout << "Queue:" << endl;
    std::cout << "Head -> [ " ;
    for (int i = 0; i < array->getSize(); i ++ ) {
        std::cout << array->get(i);
        if ( i != array->getSize() - 1 )
            std::cout << ", ";
    }
    std::cout << " ] -> Tail " << endl;
}


