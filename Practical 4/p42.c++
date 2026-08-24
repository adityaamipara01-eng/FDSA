#include <iostream>
using namespace std;

class Node
{
public:
    int token;
    Node *next;

    Node(int t)
    {
        token = t;
        next = NULL;
    }
};

class PatientQueue
{
    Node *head;

public:
    PatientQueue()
    {
        head = NULL;
    }

    void insertFront(int token)
    {
        Node *newNode = new Node(token);

        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int token)
    {
        Node *newNode = new Node(token);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int token, int position)
    {
        if (position <= 1 || head == NULL)
        {
            insertFront(token);
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp->next != NULL && count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        Node *newNode = new Node(token);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->token << " ";

            if (temp->next != NULL)
            {
                cout << "-> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    PatientQueue q;

    q.insertEnd(10);
    q.display();

    q.insertEnd(20);
    q.display();

    q.insertFront(30);
    q.display();

    q.insertAtPosition(50, 2);
    q.display();

    q.insertAtPosition(60, 4);
    q.display();

    return 0;
}