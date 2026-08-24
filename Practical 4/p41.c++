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

    void deleteValue(int token)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->token == token)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL && temp->next->token != token)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            Node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->token;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        reversePrint(temp->next);

        cout << temp->token << " ";
    }

    void printReverse()
    {
        reversePrint(head);
        cout << endl;
    }
};

int main()
{
    PatientQueue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);

    q.insertFront(100);

    q.insertAtPosition(200, 3);

    cout << "Queue from front to back: ";
    q.display();

    q.deleteValue(102);

    cout << "After deleting 102: ";
    q.display();

    cout << "Queue from last to first: ";
    q.printReverse();

    return 0;
}