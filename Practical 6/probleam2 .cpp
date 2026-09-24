#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node *next;

    Node(string p)
    {
        page = p;
        next = nullptr;
    }
};

class Browser
{
private:
    Node *top;

public:
    Browser()
    {
        top = nullptr;
    }

    void visit(string page)
    {
        Node *newNode = new Node(page);
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << "\n";
        cout << "Current page: " << top->page << "\n";
    }

    void back()
    {
        if (top == nullptr || top->next == nullptr)
        {
            cout << "No previous page available.\n";
            cout << "Current page: " << top->page << "\n";
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;

        cout << "Back pressed.\n";
        cout << "Current page: " << top->page << "\n";
    }

    ~Browser()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Browser browser;
    int choice;
    string page;

    do
    {
        cout << "\n1. Visit page\n";
        cout << "2. Back\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter page: ";
            cin >> page;
            browser.visit(page);
        }
        else if (choice == 2)
        {
            browser.back();
        }
        else if (choice == 0)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}