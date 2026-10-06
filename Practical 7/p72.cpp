#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node *next;

    Node(int p)
    {
        patient = p;
        next = nullptr;
    }
};

class PatientQueue
{
private:
    Node *front;
    Node *rear;

public:
    PatientQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void arrive(int patient)
    {
        Node *newNode = new Node(patient);

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend()
    {
        if (front == nullptr)
        {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
            cout << "Front patient: None" << endl;
        }
        else
        {
            cout << "Front patient: " << front->patient << endl;
        }
    }

    ~PatientQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    PatientQueue q;

    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++)
    {
        string operation;

        cout << "Enter operation (arrive/attend): ";
        cin >> operation;

        if (operation == "arrive")
        {
            int patient;

            cout << "Enter patient number: ";
            cin >> patient;

            q.arrive(patient);
        }
        else if (operation == "attend")
        {
            q.attend();
        }
        else
        {
            cout << "Error: Invalid operation" << endl;
        }

        cout << endl;
    }

    return 0;
}