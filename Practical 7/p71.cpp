#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int arr[100];
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int n)
    {
        capacity = n;
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token)
    {
        if (count == capacity)
        {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve()
    {
        if (count == 0)
        {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;

        front = (front + 1) % capacity;
        count--;

        if (count == 0)
        {
            front = 0;
            rear = -1;
        }

        if (count > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Front token: None" << endl;
    }
};

int main()
{
    int n, operations;

    cout << "Enter queue capacity: ";
    cin >> n;

    CircularQueue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    cout << endl;

    for (int i = 0; i < operations; i++)
    {
        string operation;

        cout << "Enter operation (join/serve): ";
        cin >> operation;

        if (operation == "join")
        {
            int token;

            cout << "Enter token number: ";
            cin >> token;

            q.join(token);
        }
        else if (operation == "serve")
        {
            q.serve();
        }
        else
        {
            cout << "Error: Invalid operation" << endl;
        }

        cout << endl;
    }

    return 0;
}