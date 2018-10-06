//
// Created by delvis on 10/6/18.
//

#ifndef STRUCTOR_LINKEDLISTQUEUE_H
#define STRUCTOR_LINKEDLISTQUEUE_H


#include "LineQueue.h"
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;
class LinkedListQueue : public LineQueue {
public:

    LinkedListQueue();

    void queue(int i) override;

    int dequeue() override;

    int getFront() override;

    int getSize() override;

    bool isEmpty() override;

    void toString();

private:
    Node *head, *tail;
    int size;

};


#endif //STRUCTOR_LINKEDLISTQUEUE_H
