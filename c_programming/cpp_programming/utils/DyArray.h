/*
 * dyarray.h
 *
 *  Created on: Sep 26, 2018
 *      Author: root
 */

#ifndef DYARRAY_H_
#define DYARRAY_H_

#include <iostream>
#include <string>

using std::string;

class DyArray {

public:
    // value:
    DyArray( int capacity );
    DyArray();


    int getSize();
    int getCapacity();
    bool isEmpty();
    void add( int index, int e );
    void addLast( int e );
    void addFirst( int e );
    int get( int index );
    void set( int index, int e );
    bool contains( int e );
    int find( int e );
    int remove( int index );
    int removeFirst();
    int removeLast();
    void removeElement( int e );
    int getLast();
    int getFirst();
    string toString();
    virtual ~DyArray();

private:

    //values
    int *data;
    int size;
    int capacity;
    // functions:
    void resize( int newCapacity );
    bool  indexIlleagle( int index );
    unsigned long long length(int *data);
};

#endif /* DYARRAY_H_ */
