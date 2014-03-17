/*
 * Find out the position of the biggest number in a double matrix
 * Mar 16 2014
 */

#include <iostream>
using namespace std;

// the 4 in the params is inevitable.
int findLargestNum(int m[][4], int raw, int col, int *x, int *y)
{
    int max = m[0][0];
    *x = 0;
    *y = 0;
    for (int i = 0; i < raw; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (m[i][j] > max)
            {
                max = m[i][j];
                *x = i;
                *y = j;
            }
        }
    }

    return max;
}

int main()
{
    const int RAW = 3;
    const int COL = 4;
    int a[RAW][COL] =
    {
        {2, 5, 6},
        {5, 9, 1},
        {6, 10, 2}
    };

    int x = 0;
    int y = 0;

    int max = findLargestNum(a, RAW, COL, &x, &y);
    cout << "max = " << max << endl;
    cout << "x:" << x << "  y:" << y << endl;

    return 0;
}
