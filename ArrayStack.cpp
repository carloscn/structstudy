//
// Created by delvis on 9/29/18.
//

#include "ArrayStack.h"

ArrayStack::ArrayStack( int capacity )
{
    this->array = new DyArray(capacity);
}

ArrayStack::ArrayStack()
{
    this->array = new DyArray();
}

int ArrayStack::getSize()
{
    return this->array->getSize();
}

bool ArrayStack::isEmpty()
{
    return array->isEmpty();
}

int ArrayStack::getCapicity()
{
    return array->getCapacity();
}

void ArrayStack::push(int e)
{
    array->addLast(e);
}

int ArrayStack::pop()
{
    return array->removeLast();
}

int ArrayStack::peek()
{
    return array->getLast();
}

string ArrayStack::toString()
{
    string d;

    std::cout << "Stack:" << endl;
    std::cout << "[ " ;
    for (int i = 0; i < array->getSize(); i ++ ) {
        std::cout << array->get(i);
        if ( i != array->getSize() - 1 )
            std::cout << ", ";
    }
    std::cout << " ] top " << endl;

    return d;
}
