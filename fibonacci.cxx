/*
 * Print the first MAX fibonacci numbers
 * Mar 16 2014
 */

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 25

int main()
{
    int f[MAX] = {1, 1};
    int  max = MAX;

    for (int i = 2; i < max; ++i)
    {
        f[i] = f[i-1]+ f[i-2];
    }

    for (int i = 0; i < max; ++i)
    {
        cout << f[i];
        if ((i+1) % 5 == 0)
        {
            cout << endl;
        } else {
            cout << setw(8);
        }
    }

    return 0;
}
