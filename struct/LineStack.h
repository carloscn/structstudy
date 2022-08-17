//
// Created by delvis on 9/29/18.
//

#ifndef STRUCTOR_LINESTACK_H
#define STRUCTOR_LINESTACK_H

#include <iostream>
#include <string>

using namespace std;

class LineStack {

public :

    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    //virtual void test() const final {};

private:
    string mStrName;
};


#endif //STRUCTOR_LINESTACK_H
