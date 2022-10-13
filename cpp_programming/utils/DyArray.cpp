/*
 * dyarray.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: root
 */

#include "DyArray.h"


DyArray::DyArray() {
    // TODO Auto-generated constructor stub
    this->data = new int[10];
    this->capacity = 10;
    this->size = 0;
}

DyArray::DyArray( int capacity )
{
    this->capacity = capacity;
    this->data = new int[this->capacity];
    std::cout << "@dyArray : size of is:" << this->capacity << "\n";
    this->size = 0;
}

DyArray::~DyArray() {
    // TODO Auto-generated destructor stub
}

bool DyArray::indexIlleagle(int index)
{
    if ( (index < 0) || (index > this->size) ) {
        throw std::range_error("Error: index over the array capacity\n");
        return false;
    }
    return true;
}
unsigned long long DyArray::length(int *data)
{
    unsigned long long length;
    length = sizeof data * sizeof(int);

    return length;
}
int DyArray::getCapacity(void)
{
    return this->capacity;
}

int DyArray::getSize(void)
{
    return this->size;
}

bool DyArray::isEmpty(void)
{
    return size == 0;
}

void DyArray::add( int index, int ele )
{
    if ( !this->indexIlleagle(index) )
        return;

    if ( this->size == this->capacity )
        this->resize( 2 * this->capacity );

    for ( int i = this->size - 1; i >= index; i -- )
        *(this->data + i + 1) = *(this->data + i);

    *(this->data + index) = ele;
    this->size ++;
}

void DyArray::addLast( int ele )
{
    this->add(this->size,ele);
}

void DyArray::addFirst( int ele )
{
    this->add(0,ele);
}

int DyArray::get(int index)
{
    if ( !this->indexIlleagle(index) )
        return -1;

    return *(this->data + index );
}

void DyArray::set(int index, int ele)
{
    if ( !this->indexIlleagle(index) )
        return;

    *(this->data + index) = ele;
}

bool DyArray::contains(int ele)
{
    for (int i = 0; i < this->size; i ++ ) {
        if ( this->data[i] == ele )
            return true;
    }
    return false;
}

int DyArray::find(int ele)
{
    for (int i = 0; i < this->size; i ++) {
        if ( this->data[i] == ele )
            return i;
    }
    return -1;
}

int DyArray::remove(int index)
{
    if ( !this->indexIlleagle(index) )
        return -1;

    int ret = this->data[index];
    for (int i = index + 1; i < this->size; i ++ )
        this->data[i - 1] = this->data[i];
    this->size --;
    this->data[this->size] = NULL;

    if ( this->size <= this->capacity / 4  && this->capacity /2 != 0 )
        this->resize( this->capacity / 2 );

    return ret;
}

int DyArray::removeFirst()
{
    return this->remove(0);
}

int DyArray::removeLast()
{
    return this->remove(this->size - 1);
}

void DyArray::removeElement(int ele)
{
    int index = this->find(ele);
    if ( index != -1 )
        this->remove(index);
}

int DyArray::getLast()
{
    return get(size - 1);
}

int DyArray::getFirst()
{
    return get(0);
}

string DyArray::toString()
{
    string str;

    std::cout << "Array: Size = " << this->size << ", capacity = " << this->capacity << "\n";
    std::cout << "[ ";
    for (int i = 0; i < this->size; i ++) {
        std::cout << this->data[i];
        if( i != this->size - 1 )
            std::cout << ", ";
    }
    std::cout << " ]\n";

    return str;
}

void DyArray::resize(int newCapacity)
{
    int *newData = new int[newCapacity];
    this->capacity = newCapacity;
    for ( int i =0; i < this->size; i ++ )
        newData[i] = this->data[i];
    this->data = newData;
}














