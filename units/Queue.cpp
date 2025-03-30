#include "DataStructures.hpp"
#include <iostream>

using namespace std;

void Queue::enqueue(int data)
{
    if(rear < capacity - 1)
        array[++rear] = data;
    else
        cerr << "The queue is full!\n";
}

void Queue::dequeue()
{
    if(!isEmpty())
        front++;
    else
        cerr << "The queue is empty. Can't dequeue\n";
}

bool Queue::isEmpty()
{
    if(front > rear)
        return true;

    return false;
}


int Queue::peek()
{
    if(isEmpty())
        return -1;
    
    return array[front];
}

void Queue::setCapacity(int capacity)
{
    this->capacity = capacity;
    delete[] this->array;
    this->array = new int[capacity];
}

int Queue::getCapacity()
{
    return capacity;
}