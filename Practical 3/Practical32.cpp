#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of buckets: ";
    cin >> n;
    int a[n];
    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zero++;
        else if (a[i] == 1)
            one++;
        else
            two++;
    }
    int i = 0;
    while (zero > 0)
    {
        a[i] = 0;
        i++;
        zero--;
    }
    while (one > 0)
    {
        a[i] = 1;
        i++;
        one--;
    }
    while (two > 0)
    {
        a[i] = 2;
        i++;
        two--;
    }
    cout << "Sorted Colour Codes: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}