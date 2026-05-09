#include <iostream>
using namespace std;

struct Node
{
    int jobId;
    int pages;
    Node* next;
};


class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue();

    void enqueue(int jobId, int pages);
    void dequeue();
    void peek();
    void display();
    void totalPages();
};
