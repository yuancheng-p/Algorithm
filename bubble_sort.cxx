/*
 * Bubble sort
 * Mar 16 2014
 */

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int * bubbleSort(int* a, int length)
{

    for (int i = 0; i < length; ++i)
    {
        for (int j = 1; j < length; ++j)
        {
            if (a[j-1] > a[j])
            {
                swap(a[j-1], a[j]);
            }
        }
    }
    return a;
}

int main()
{
    int a[5] = {10, 2, 3, 4, 5};

    cout << "Before bubble sort:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << ";";
    }
    cout << endl;

    cout << "After bubble sort:" << endl;
    int *b = bubbleSort(a, 5);
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << ";";
    }
    return 0;
}
