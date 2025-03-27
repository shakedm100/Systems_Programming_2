#pragma once
#include <cstddef>

struct Vertice {
    int data;
    int vertex;
    Vertice* next;
};

class Queue
{
    private:
        int capacity;
        int* array;
        int rear;
        int front;

    public:

        Queue(int capacity) : capacity(capacity)
        {
            array = new int[capacity];
            rear = -1;
            front = 0;
        }

        Queue()
        {
            capacity = 0;
            array = new int[0];
            rear = -1;
            front = 0;
        }

        ~Queue()
        {
            delete[] array;
        }

        void enqueue(int data);
        void dequeue();
        int peek();
        bool isEmpty();
        void setCapacity(int capacity);
        int getCapacity();
};

