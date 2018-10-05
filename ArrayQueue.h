//
// Created by delvis on 10/1/18.
//

#ifndef STRUCTOR_ARRAYQUEUE_H
#define STRUCTOR_ARRAYQUEUE_H


#include "LineQueue.h"
#include "DyArray.h"
#include <iostream>
#include <string>

using namespace std;

class ArrayQueue : public LineQueue{

public :

    ArrayQueue();

    ArrayQueue(int capacity);

    void queue(int e) override;

    int dequeue() override;

    int getFront() override;

    int getSize() override;

    bool isEmpty() override;

    int getCapacity();

    void toString();

private:

    DyArray *array;

};


#endif //STRUCTOR_ARRAYQUEUE_H
