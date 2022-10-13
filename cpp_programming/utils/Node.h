//
// Created by delvis on 10/6/18.
//

#ifndef STRUCTOR_NODE_H
#define STRUCTOR_NODE_H
#include <iostream>

class Node {

public:

    int e;
    Node *next;

    Node(int e, Node *next) {
        this->e = e;
        this->next = next;
    }

    Node(int e) {
        this->e = e;
        this->next = NULL;
    }

    Node() {
        this->e = NULL;
        this->next = NULL;
    }

};
#endif //STRUCTOR_NODE_H
