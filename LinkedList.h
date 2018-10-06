//
// Created by delvis on 10/5/18.
//

#ifndef STRUCTOR_LINKEDLIST_H
#define STRUCTOR_LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class LinkedList {

public :


    LinkedList();
    int getSize();
    bool isEmpty();
    void addFirst(int e);
    void addElementByIndex(int index, int e);
    void addLast(int e);
    int get(int index);
    int getFirst();
    int getLast();
    void set(int index, int e);
    bool contains(int e);
    int del(int index);
    int removeFirst();
    int removeLast();
    void toString();

private :


    Node *head;
    Node *dummyHead;
    int size;



};


#endif //STRUCTOR_LINKEDLIST_H
