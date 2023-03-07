//
// Created by delvis on 10/3/18.
//

#ifndef STRUCTOR_LOOPQUEUE_H
#define STRUCTOR_LOOPQUEUE_H


#include "LineQueue.h"
#include "DyArray.h"
#include <iostream>
#include <string>

using namespace std;

class LoopQueue : public LineQueue {

public:
    LoopQueue();

    LoopQueue(int capacity);

    void queue(int e) override;

    int dequeue() override;

    int getFront() override;

    int getSize() override;

    bool isEmpty() override;

    int getCapacity();

    void toString();

private:
    int datalenght;
    int *data;
    int front, tail;
    int size;
    int capacity;

    void resize(int newCapactiy);

};


#endif //STRUCTOR_LOOPQUEUE_H
