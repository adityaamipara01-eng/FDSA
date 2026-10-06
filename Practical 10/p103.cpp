#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of student IDs: ";
    cin >> n;

    cout << "Enter student IDs:" << endl;

    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;

        int h1 = id % SIZE;
        int h2 = 7 - (id % 7);

        bool inserted = false;

        for (int j = 0; j < SIZE; j++)
        {
            int index = (h1 + j * h2) % SIZE;

            if (table[index] == -1)
            {
                table[index] = id;
                inserted = true;
                break;
            }
        }

        if (!inserted)
            cout << "Table is full. ID " << id
                 << " cannot be inserted." << endl;
    }

    cout << "\nFinal hash table:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
