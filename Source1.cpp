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

int main()
{
    Queue q;
    int choice, jobId, pages;

    do
    {
        cout << "\n========== Printer Queue System ==========\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Job\n";
        cout << "3. Show Next Job\n";
        cout << "4. Display All Jobs\n";
        cout << "5. Show Total Pages\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Job ID: ";
            cin >> jobId;
            cout << "Enter Pages: ";
            cin >> pages;
            q.enqueue(jobId, pages);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            q.totalPages();
            break;

        case 6:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}