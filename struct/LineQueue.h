//
// Created by delvis on 10/1/18.
//

#ifndef STRUCTOR_LINEQUEUE_H
#define STRUCTOR_LINEQUEUE_H


class LineQueue {

public :
    virtual void queue(int) = 0;
    virtual int dequeue() = 0;
    virtual int getFront() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual int dataLength(int *data) {
        return sizeof(data)/ sizeof(data[0]);
    }

};

#endif //STRUCTOR_LINEQUEUE_H
