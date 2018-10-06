//
// Created by delvis on 10/6/18.
//

#ifndef STRUCTOR_LINKEDLISTSTACK_H
#define STRUCTOR_LINKEDLISTSTACK_H


#include "LineStack.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class LinkedListStack : public LineStack{
public :
    LinkedListStack();

    void push(int i) override;

    int pop() override;

    int peek() override;

    int getSize() override;

    bool isEmpty() override;

    void toString();
private:
    LinkedList *list;

};


#endif //STRUCTOR_LINKEDLISTSTACK_H
