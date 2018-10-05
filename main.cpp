//============================================================================
// Name        : dy_array.cpp
// Author      : carlos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DyArray.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
#include "LinkedList.h"

using namespace std;

void testDyArray(void) {
    int capacity;

    std::cout << "input the array capacity: ";
    std::cin >> capacity;

    DyArray *array = new DyArray(capacity);

    std::cout << "the capacity is :" << capacity << "\n";
    for (int i = 0; i < 10 ; i ++) {
        try {
            array->add(i,i);
        }catch(std::range_error *e) {
            std::cout << e;
        }
    }
    std::cout << "finish!\n";
    std::cout << array->toString();

    try {
        array->add(5,10);
    }catch(std::range_error *e) {

        std::cout << "error\n";
    }
    std::cout << array->toString();

    try {
        array->remove(5);
    }catch(std::range_error *e) {
        std::cout << "error\n";
    }
    std::cout << array->toString();

    try {
        array->removeElement(9);
    }catch(std::range_error *e) {
        std::cout << "error\n";
    }

    std::cout << array->toString();
    try {
        array->remove(4);
    }catch(std::range_error *e) {
        std::cout << "error\n";
    }
    std::cout << array->toString();

    for (int i = 0; i < 500; i ++) {
        try {
            array->add(i,i);
        }catch(std::range_error *e) {
            std::cout << "error\n";
        }
    }
    std::cout << array->toString();
}


void testArrayStack(void)
{

    ArrayStack *stack = new ArrayStack();

    for ( int i = 0; i < 200; i++ ) {
        stack->push(i);
        stack->toString();
    }
    for ( int i = 0; i < 200; i++ ) {
        stack->pop();
        stack->toString();
    }
}

void testArrayQueue(void) {

    ArrayQueue *queue = new ArrayQueue();

    for ( int i = 0; i < 10; i ++) {
        queue->queue(i);
        queue->toString();
    }
    for ( int i = 0; i < 10; i ++) {
        queue->dequeue();
        queue->toString();
    }
}

void testLoopQueue(void)
{
    LoopQueue *queue = new LoopQueue(10);

    for ( int i = 0; i < 40; i ++) {
        if ( i % 3 != 0) {
            queue->queue(i);
            queue->toString();
        }else {
            queue->dequeue();
            queue->toString();
        }
    }
}

void testLinkedList(void)
{
    LinkedList *list = new LinkedList();

    for (int i = 0; i < 10; i++) {
        list->addFirst(i);
        list->toString();
    }

    list->addElementByIndex(2, 666);
    list->toString();

    list->del(7);
    list->toString();


}

int main(void)
{
    //testDyArray();
    //testArrayStack();
    //testArrayQueue();
    //testLoopQueue();
    testLinkedList();
    return 0;
}


