//
// Created by delvis on 9/29/18.
//

#ifndef STRUCTOR_ARRAYSTACK_H
#define STRUCTOR_ARRAYSTACK_H


#include "LineStack.h"
#include "DyArray.h"

class ArrayStack: public LineStack {

public:

    ArrayStack(int capacity);
    ArrayStack();
    ~ArrayStack();

    int pop() override;
    int getSize() override;
    bool isEmpty() override;
    void push(int e) override;
    int peek() override;
    int getCapicity();
    string toString();


private:
    DyArray *array;

};


#endif //STRUCTOR_ARRAYSTACK_H
