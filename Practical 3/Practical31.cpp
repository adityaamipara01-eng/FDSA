#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Print array
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int marks[100];

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    int bubble[100], selection[100], insertion[100];

    for (int i = 0; i < n; i++)
    {
        bubble[i] = marks[i];
        selection[i] = marks[i];
        insertion[i] = marks[i];
    }

    bubbleSort(bubble, n);
    selectionSort(selection, n);
    insertionSort(insertion, n);

    cout << "\nBubble Sort: ";
    printArray(bubble, n);

    cout << "Selection Sort: ";
    printArray(selection, n);

    cout << "Insertion Sort: ";
    printArray(insertion, n);

    return 0;
}