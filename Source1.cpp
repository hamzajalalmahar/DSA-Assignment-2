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



Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int jobId, int pages)
{
    Node* newNode = new Node();

    newNode->jobId = jobId;
    newNode->pages = pages;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "\nJob Added Successfully!";
    cout << "\nJob ID: " << jobId << " | Pages: " << pages << "\n";
}

void Queue::dequeue()
{
    if (front == NULL)
    {
        cout << "\nQueue is Empty!\n";
        return;
    }

    Node* temp = front;

    cout << "\nPrinted Job:";
    cout << "\nJob ID: " << front->jobId << " | Pages: " << front->pages << "\n";

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

void Queue::peek()
{
    if (front == NULL)
    {
        cout << "\nQueue is Empty!\n";
        return;
    }

    cout << "\nNext Job:";
    cout << "\nJob ID: " << front->jobId << " | Pages: " << front->pages << "\n";
}

void Queue::display()
{
    if (front == NULL)
    {
        cout << "\nQueue is Empty!\n";
        return;
    }

    Node* temp = front;

    cout << "\nPending Print Jobs:\n";

    while (temp != NULL)
    {
        cout << "Job ID: " << temp->jobId
            << " | Pages: " << temp->pages << endl;

        temp = temp->next;
    }
}

void Queue::totalPages()
{
    if (front == NULL)
    {
        cout << "\nNo Pending Pages!\n";
        return;
    }

    Node* temp = front;
    int total = 0;

    while (temp != NULL)
    {
        total += temp->pages;
        temp = temp->next;
    }

    cout << "\nTotal Pending Pages: " << total << "\n";
}

