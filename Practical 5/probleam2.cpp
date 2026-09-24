#include <iostream>
#include <string>
using namespace std;

struct StudentNode
{
    string name;
    StudentNode *next;
    StudentNode *previous;

    StudentNode(string studentName)
    {
        name = studentName;
        next = nullptr;
        previous = nullptr;
    }
};

class SinglyCircularList
{
private:
    StudentNode *last;

public:
    SinglyCircularList()
    {
        last = nullptr;
    }

    void joinAtBeginning(string name)
    {
        StudentNode *newNode = new StudentNode(name);

        if (last == nullptr)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void joinAtEnd(string name)
    {
        StudentNode *newNode = new StudentNode(name);

        if (last == nullptr)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    bool insertAtPosition(string name, int position)
    {
        if (position < 1)
        {
            return false;
        }

        if (position == 1)
        {
            joinAtBeginning(name);
            return true;
        }

        if (last == nullptr)
        {
            return false;
        }

        StudentNode *current = last->next;
        for (int count = 1; count < position - 1; count++)
        {
            current = current->next;
            if (current == last->next)
            {
                return false;
            }
        }

        StudentNode *newNode = new StudentNode(name);
        newNode->next = current->next;
        current->next = newNode;

        if (current == last)
        {
            last = newNode;
        }
        return true;
    }

    bool leave(string name)
    {
        if (last == nullptr)
        {
            return false;
        }

        StudentNode *previous = last;
        StudentNode *current = last->next;

        do
        {
            if (current->name == name)
            {
                if (current == previous)
                {
                    last = nullptr;
                }
                else
                {
                    previous->next = current->next;
                    if (current == last)
                    {
                        last = previous;
                    }
                }
                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        } while (current != last->next);

        return false;
    }

    void display()
    {
        cout << "Singly circular list: ";

        if (last == nullptr)
        {
            cout << "empty\n";
            return;
        }

        StudentNode *first = last->next;
        StudentNode *current = first;
        do
        {
            cout << current->name;
            current = current->next;
            if (current != first)
            {
                cout << " -> ";
            }
        } while (current != first);

        cout << " -> back to " << first->name << "\n";
    }

    ~SinglyCircularList()
    {
        while (last != nullptr)
        {
            leave(last->next->name);
        }
    }
};

class DoublyCircularList
{
private:
    StudentNode *first;

public:
    DoublyCircularList()
    {
        first = nullptr;
    }

    void joinAtBeginning(string name)
    {
        StudentNode *newNode = new StudentNode(name);

        if (first == nullptr)
        {
            first = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }
        else
        {
            StudentNode *last = first->previous;
            newNode->next = first;
            newNode->previous = last;
            last->next = newNode;
            first->previous = newNode;
            first = newNode;
        }
    }

    void joinAtEnd(string name)
    {
        StudentNode *newNode = new StudentNode(name);

        if (first == nullptr)
        {
            first = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }
        else
        {
            StudentNode *last = first->previous;
            newNode->next = first;
            newNode->previous = last;
            last->next = newNode;
            first->previous = newNode;
        }
    }

    bool insertAtPosition(string name, int position)
    {
        if (position < 1)
        {
            return false;
        }

        if (position == 1)
        {
            joinAtBeginning(name);
            return true;
        }

        if (first == nullptr)
        {
            return false;
        }

        StudentNode *current = first;
        for (int count = 1; count < position - 1; count++)
        {
            current = current->next;
            if (current == first)
            {
                return false;
            }
        }

        StudentNode *newNode = new StudentNode(name);
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        return true;
    }

    bool leave(string name)
    {
        if (first == nullptr)
        {
            return false;
        }

        StudentNode *current = first;
        do
        {
            if (current->name == name)
            {
                if (current->next == current)
                {
                    first = nullptr;
                }
                else
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    if (current == first)
                    {
                        first = current->next;
                    }
                }
                delete current;
                return true;
            }
            current = current->next;
        } while (current != first);

        return false;
    }

    void display()
    {
        cout << "Doubly circular list: ";

        if (first == nullptr)
        {
            cout << "empty\n";
            return;
        }

        StudentNode *current = first;
        do
        {
            cout << current->name;
            current = current->next;
            if (current != first)
            {
                cout << " -> ";
            }
        } while (current != first);

        cout << " -> back to " << first->name << "\n";
    }

    ~DoublyCircularList()
    {
        while (first != nullptr)
        {
            leave(first->name);
        }
    }
};

void displayBoth(SinglyCircularList &singly, DoublyCircularList &doubly)
{
    singly.display();
    doubly.display();
}

int main()
{
    SinglyCircularList singly;
    DoublyCircularList doubly;
    int choice;
    int position;
    string name;

    do
    {
        cout << "1. Join at beginning\n";
        cout << "2. Join at end\n";
        cout << "3. Join at position\n";
        cout << "4. Leave circle\n";
        cout << "5. Display circle\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter student name: ";
            getline(cin, name);
            singly.joinAtBeginning(name);
            doubly.joinAtBeginning(name);
            displayBoth(singly, doubly);
            break;

        case 2:
            cout << "Enter student name: ";
            getline(cin, name);
            singly.joinAtEnd(name);
            doubly.joinAtEnd(name);
            displayBoth(singly, doubly);
            break;

        case 3:
            cout << "Enter position (starting from 1): ";
            cin >> position;
            cin.ignore();
            cout << "Enter student name: ";
            getline(cin, name);

            if (singly.insertAtPosition(name, position))
            {
                doubly.insertAtPosition(name, position);
                cout << "Student joined.\n";
            }
            else
            {
                cout << "Position is not valid. Nothing was inserted.\n";
            }
            displayBoth(singly, doubly);
            break;

        case 4:
            cout << "Enter student name to leave: ";
            getline(cin, name);

            if (singly.leave(name))
            {
                doubly.leave(name);
                cout << "Student left the circle.\n";
            }
            else
            {
                cout << "Student not found.\n";
            }
            displayBoth(singly, doubly);
            break;

        case 5:
            displayBoth(singly, doubly);
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}