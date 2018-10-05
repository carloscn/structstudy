//
// Created by delvis on 10/3/18.
//

#include "LoopQueue.h"

LoopQueue::LoopQueue() {

    data = (int*)malloc(sizeof(int) * 10);
    front = 0;
    tail = 0;
    size = 0;
    capacity = 11;
}

LoopQueue::LoopQueue(int capacity) {

    data = (int*)malloc(sizeof(int) * (capacity + 1));
    front = 0;
    tail = 0;
    size = 0;
    this->capacity = capacity;

}

void LoopQueue::queue(int e) {

    if ((tail + 1) % getCapacity() == front)
        resize(getCapacity() * 2);
    data[tail] = e;
    tail = (tail + 1 ) % getCapacity();
    size ++;

}

int LoopQueue::dequeue() {

    if (isEmpty())
        return NULL;
    int ret = data[front];
    data[front] = NULL;
    front = (front + 1) % getCapacity();
    size --;
    if (size == getCapacity()/4 && getCapacity() /2 != 0)
        resize(getCapacity()/2);

    return ret;
}

int LoopQueue::getFront() {

    if (isEmpty())
        return NULL;

    return data[front];
}

int LoopQueue::getSize() {
    return size;
}

bool LoopQueue::isEmpty() {
    return (front == tail);
}

int LoopQueue::getCapacity() {
    return capacity;
}

void LoopQueue::resize(int newCapactiy) {

    int *newData = (int*)malloc(sizeof(int)*(newCapactiy + 1));
    for (int i = 0; i < size; i ++)
        newData[i] = data[(i + front) % getCapacity()];
    data = newData;
    front = 0;
    tail = size;
    capacity = newCapactiy;
}

void LoopQueue::toString() {

    std::cout << "Queue: size :" << size << " Capacity: " << getCapacity() << endl;
    std::cout << "Head -> [ " ;
    for (int i = front; i != tail; i = (i + 1) % getCapacity() ) {
        std::cout << data[i];
        if ( (i + 1) % size != tail )
            std::cout << ", ";
    }
    std::cout << " ] -> Tail " << endl;
}
