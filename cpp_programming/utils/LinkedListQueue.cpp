//
// Created by delvis on 10/6/18.
//

#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListQueue::queue(int i) {
    if (tail == NULL) {
        tail = new Node(i);
        head = tail;
    } else {
        tail->next = new Node(i);
        tail = tail->next;
    }
    size ++;
}

int LinkedListQueue::dequeue() {

    if (isEmpty()) {
        std::cout << ("Cannot dequeue e, queue is empty; size:") << size;
        throw std::range_error("Cannot dequeue, queue is empty;");
    }
    Node *retNode = head;
    head = head->next;
    retNode->next = NULL;
    if (head == NULL)
        tail = NULL;
    size --;

    return retNode->e;
}

int LinkedListQueue::getFront() {
    if (isEmpty())
        throw std::range_error("Cannot get front, queue is empty;");
    return head->e;
}

int LinkedListQueue::getSize() {
    return size;
}

bool LinkedListQueue::isEmpty() {
    return size == 0;
}

void LinkedListQueue::toString() {

    std::cout << "Queue: size :" << size << endl;
    std::cout << "Head:[ " ;

    for (Node *cur = head; cur != NULL; cur = cur->next) {
        std::cout << cur->e;
        std::cout << "->";
    }
    std::cout << " ]:Tail " << endl;
}

