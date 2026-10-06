#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle registration numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        int reg;
        cin >> reg;

        int index = reg % SIZE;
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;

            if (index == start)
            {
                cout << "Parking lot is full. Vehicle " << reg
                     << " cannot be parked." << endl;
                break;
            }
        }

        if (table[index] == -1)
            table[index] = reg;
    }

    cout << "\nFinal parking slots:" << endl;
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
