#include <iostream>
using namespace std;

class TrayStack
{
private:
    int *stack;
    int top;
    int capacity;

public:
    TrayStack(int n)
    {
        capacity = n;
        stack = new int[capacity];
        top = -1;
    }

    void push(int tray)
    {
        if (top == capacity - 1)
        {
            cout << "Error: Stack is full. Tray cannot be placed.\n";
            return;
        }

        top++;
        stack[top] = tray;
        cout << "Tray " << tray << " placed.\n";
        cout << "Top tray: " << stack[top] << "\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack is empty. No tray can be taken.\n";
            return;
        }

        cout << "Tray " << stack[top] << " taken.\n";
        top--;

        if (top == -1)
            cout << "Top tray: empty\n";
        else
            cout << "Top tray: " << stack[top] << "\n";
    }

    ~TrayStack()
    {
        delete[] stack;
    }
};

int main()
{
    int n, choice, tray;

    cout << "Enter maximum number of trays: ";
    cin >> n;

    TrayStack s(n);

    do
    {
        cout << "\n1. Place tray\n";
        cout << "2. Take tray\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
        }
        else if (choice == 2)
        {
            s.pop();
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