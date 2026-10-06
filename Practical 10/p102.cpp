#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int SIZE = 10;
    vector<int> shelves[SIZE];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:" << endl;

    for (int i = 0; i < n; i++)
    {
        int code;
        cin >> code;

        int index = code % SIZE;
        shelves[index].push_back(code);
    }

    cout << "\nFinal shelf contents:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (int j = 0; j < (int)shelves[i].size(); j++)
                cout << shelves[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
