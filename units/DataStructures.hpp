//shaked1mi@gmail.com

#pragma once
#include <cstddef>

struct Vertex {
    int data;
    int vertex;
    Vertex* next;
};

struct Edge {
    int src;
    int dest;
    int weight;
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


class UnionFind{
    private:
    int size;
    int* rank;
    int* parent;

    public:
    UnionFind(int n);

    ~UnionFind()
    {
        delete[] rank;
        delete[] parent;
    }

    int find(int x);
    void unionSets(int x, int y);
    bool connected(int x, int y);
};
