/*
shaked1mi@gmail.com
Shaked Michael
318772191
*/

#include "DataStructures.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Inserts a number to the queue
 */
void Queue::enqueue(int data)
{
    if(rear < capacity - 1)
        array[++rear] = data;
    else
        cerr << "The queue is full!\n";
}

/**
 * @brief Removes a number from the queue
 */
void Queue::dequeue()
{
    if(!isEmpty())
        front++;
    else
        cerr << "The queue is empty. Can't dequeue\n";
}

/**
 * @brief If the queue is empty it returns true
 */
bool Queue::isEmpty()
{
    if(front > rear)
        return true;

    return false;
}

/**
 * @brief Returns the first item in the queue without deleting it
 */
int Queue::peek()
{
    if(isEmpty())
        return -1;
    
    return array[front];
}


int Queue::getCapacity()
{
    return capacity;
}